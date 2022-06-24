#include "matrix.hpp"

std::mt19937 mt(time(NULL));
std::uniform_real_distribution<float> dist(-1, 1);


Matrix::Matrix(){
    this->rows = 1;
    this->cols = 1;
    this->values.resize(1, 0);    
}

Matrix::Matrix(size_t numRows, size_t numCols, std::string fill){
    this->rows = numRows;
    this->cols = numCols;

    if(fill == "zeros"){
        this->values.resize(numCols*numRows, 0);
    }else if(fill == "ones"){
        this->values.resize(numCols*numRows, 1);
    }else if(fill == "random"){
        this->values.resize(numCols*numRows, 0);
        for(size_t i = 0; i < this->rows; i++){
            for(size_t j = 0; j < this->cols; j++){
                this->set(dist(mt), i, j);
            }
        }
    }
}

Matrix::Matrix(std::vector<float> vec, size_t numRows, size_t numCols){
    this->rows = numRows;
    this->cols = numCols;
    this->values.assign(vec.begin(), vec.begin() + vec.size());
}

Matrix::~Matrix(){}

void Matrix::print(){
    std::cout << std::setprecision(5);
    std::cout << std::fixed;
    std::cout << "\n";
    for(size_t i = 0; i < this->rows; i++){
        std::cout << "|";
        for(size_t j = 0; j < this->cols; j++){
            std::cout << std::setw(10) << (*this)(i,j) << " ";
        }
        std::cout << "|\n";
    }
    std::cout << "\n";
}

void Matrix::set(float value, size_t row, size_t col){
    this->values.at(col + this->cols*row) = value;
}

void Matrix::set(std::vector<float> vec, size_t idx, bool row){
    if(row){
        for(size_t j = 0; j < this->cols; j++){
            this->set(vec.at(j), idx, j);
        }
    }else{
        for(size_t i = 0; i < this->rows; i++){
            this->set(vec.at(i), i, idx);
        }
    }  
}

void Matrix::set(Matrix matrix){
    this->rows = matrix.rows;
    this->cols = matrix.cols;
    this->values.assign(matrix.values.begin(), matrix.values.begin() + matrix.values.size());
}

bool Matrix::equalTo(Matrix matrix){
    if(this->rows == matrix.rows && this->cols == matrix.cols){
        for(size_t i = 0; i < matrix.rows; i++){
            for(size_t j = 0; j < matrix.cols; j++){
                if((*this)(i,j) != matrix(i,j))
                    return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

size_t Matrix::numRows(){
    return this->rows;
}

size_t Matrix::numCols(){
    return this->cols;
}

std::vector<float>* Matrix::getValues(){
    return &values;
}

void Matrix::setRows(size_t newRows){
    rows = newRows;
}

void Matrix::setCols(size_t newCols){
    cols = newCols;
}


Matrix Matrix::add(float value){
    Matrix result(this->rows, this->cols);

    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.set((*this)(i,j) + value, i, j);
        }
    }

    return result;
}

Matrix Matrix::add(Matrix matrix){
    if(this->rows != matrix.rows || this->cols != matrix.cols)
        throw std::invalid_argument("Matrices must have the same format");

    Matrix result(this->rows, this->cols);

    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.set((*this)(i,j) + matrix(i,j), i, j);
        }
    }
    return result;
}

Matrix Matrix::subtract(float value){
    Matrix result(this->rows, this->cols, "zeros");

    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.set((*this)(i,j) - value, i, j);
        }
    }
    return result;
}

Matrix Matrix::subtract(Matrix matrix){
    if(this->rows != matrix.rows || this->cols != matrix.cols)
        throw std::invalid_argument("Matrices must have the same format");

    Matrix result(this->rows, this->cols, "zeros");

    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.set((*this)(i,j) - matrix(i,j), i, j);
        }
    }
    return result;
}

Matrix Matrix::multiply(float value){
    Matrix result(this->rows, this->cols, "zeros");

    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.set((*this)(i, j)*value, i, j);
        }
    }

    return result;
}

Matrix Matrix::multiply(Matrix matrix){
    if(this->cols != matrix.rows)
        throw std::invalid_argument("First matrix column size must match second matrix row size");

    Matrix result(this->rows, matrix.cols, "zeros");

    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < matrix.cols; j++){
            float dotProd = (*this)(i,true).dotProduct(matrix(j, false).transpose());
            result.set(dotProd, i, j);
        }
    }

    return result;
}

Matrix Matrix::divide(float value){
    Matrix result(this->rows, this->cols, "zeros");

    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.set((*this)(i, j)/value, i, j);
        }
    }
    return result;
}

float Matrix::dotProduct(Matrix matrix){
    if(this->rows != matrix.rows || this->cols != matrix.cols)
        throw std::invalid_argument("Matrices must have the same format");

    float dotProd = 0;
    for(size_t i = 0; i < matrix.rows; i++){
        for(size_t j = 0; j < matrix.cols; j++){
            dotProd += (*this)(i,j) * matrix(i,j);
        }
    }

    return dotProd;
}

float Matrix::sum(){
    float sum = 0;
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            sum += (*this)(i,j);
        }
    }
    return sum;
}

Matrix Matrix::transpose(){
    Matrix result(this->cols, this->rows, "zeros");

    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.set((*this)(i,j), j, i);
        }
    }

    return result;
}

Matrix Matrix::applyFunction(float function(float)){
    Matrix result(this->rows, this->cols, "zeros");

    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            result.set(function((*this)(i,j)), i, j);
        }
    }
    return result;
}

Matrix Matrix::insert(Matrix toAppend, size_t idx, bool row){
    Matrix result(*(this->getValues()), this->rows, this->cols);

    if(row){
        if(cols != toAppend.cols)
            throw std::invalid_argument("Matrices must have the same number of columns");

        result.getValues()->insert(result.getValues()->begin()+result.numCols()*idx, 
                                  (*toAppend.getValues()).begin(),
                                  (*toAppend.getValues()).end());

        result.rows = result.rows + toAppend.numRows();

    }else{
        if(rows != toAppend.rows)
            throw std::invalid_argument("Matrices must have the same number of rows");

        size_t end = result.getValues()->size();
        size_t numInserted = 0;
        for(size_t i = 0; i < end; i += cols){
            result.getValues()->insert(result.getValues()->begin() + i + numInserted + idx, (*toAppend.getValues()).at(i/cols));
            numInserted++;
        }

        result.cols = cols + toAppend.numCols();
    }
    
    return result;
}

Matrix Matrix::append(Matrix toAppend, bool row){
    Matrix result(*(this->getValues()), this->rows, this->cols);

    if(row)
        result = result.insert(toAppend, rows, true);
    else
        result = result.insert(toAppend, cols, false);
    
    return result;
}

Matrix Matrix::del(size_t startIdx, size_t endIdx, bool row){
    // Start idx and end idx are inclusive [startIdx, endIdx]
    Matrix result(*(this->getValues()), this->rows, this->cols);

    if(row){
        if(startIdx < 0 || startIdx >= result.rows || endIdx < 0 || endIdx >= result.rows || endIdx < startIdx)
            throw std::invalid_argument("Indexes out of range");

        result.values.erase(result.values.begin() + startIdx*result.cols, result.values.begin() + (endIdx+1)*result.cols);

        result.rows = rows - (endIdx - startIdx + 1);

    }else{
        if(startIdx < 0 || startIdx >= this->cols || endIdx < 0 || endIdx >= this->cols || endIdx < startIdx)
            throw std::invalid_argument("Indexes out of range");

        size_t end = result.values.size();
        size_t numDeleted = 0;
        for(size_t i = 0; i < end; i += cols){
            for(size_t col = startIdx; col <= endIdx; col++){
                result.values.erase(result.values.begin() + i + col - numDeleted);
                numDeleted++;
            }
        }

        result.cols = cols - (endIdx - startIdx + 1);
    }
    
    return result;
}


// TODO: develop the generalized cross product between matrixs
// Matrix Matrix::crossProduct(Matrix matrix){}
// Matrix Matrix::crossProduct(Matrix matrix1, Matrix matrix2){}


// Overloaded operators

float Matrix::operator()(size_t row, size_t col){
    return this->values.at(col + this->cols*row);
}

Matrix Matrix::operator()(size_t idx, bool row){
    
    if(row){
        Matrix result(1, this->cols, "zeros");
        for(size_t j = 0; j < this->cols; j++){
            result.set((*this)(idx, j), 0, j);
        }
        return result;
    }else{
        Matrix result(this->rows, 1, "zeros");
        for(size_t i = 0; i < this->rows; i++){
            result.set((*this)(i, idx), i, 0);
        }
        return result;
    }
}

void Matrix::operator=(Matrix matrix){this->set(matrix);}

bool Matrix::operator==(Matrix matrix){return this->equalTo(matrix);}

Matrix Matrix::operator+(Matrix matrix){return this->add(matrix);}
Matrix Matrix::operator+(float value)  {return this->add(value);}
Matrix Matrix::operator-(Matrix matrix){return this->subtract(matrix);}
Matrix Matrix::operator-(float value)  {return this->subtract(value);}
Matrix Matrix::operator*(Matrix matrix){return this->multiply(matrix);}
Matrix Matrix::operator*(float value)  {return this->multiply(value);}
Matrix Matrix::operator/(float value)  {return this->divide(value);}

void Matrix::operator++(int){(*this) = this->add(1);}
void Matrix::operator--(int){(*this) = this->subtract(1);}

void Matrix::operator+=(Matrix matrix){(*this) = this->add(matrix);}
void Matrix::operator+=(float value)  {(*this) = this->add(value);}
void Matrix::operator-=(Matrix matrix){(*this) = this->subtract(matrix);}
void Matrix::operator-=(float value)  {(*this) = this->subtract(value);}
void Matrix::operator*=(Matrix matrix){(*this) = this->multiply(matrix);}
void Matrix::operator*=(float value)  {(*this) = this->multiply(value);}
void Matrix::operator/=(float value)  {(*this) = this->divide(value);}
