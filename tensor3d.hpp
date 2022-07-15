#ifndef TENSOR3D_H
#define TENSOR3D_H

#include "matrix.hpp"


/* Class definitions */
template <typename T> class Tensor3D{
    private:
        size_t rows, cols, channels;
        std::vector<Matrix<T>> data;

    public:
        Tensor3D();
        Tensor3D(size_t numRows, size_t numCols, size_t numChannels, std::string fill="zeros");
        template<typename dist_t> Tensor3D(size_t numRows, size_t numCols, size_t numChannels, dist_t dist);
        Tensor3D(std::vector<Matrix<T>> data);
        ~Tensor3D();

        void print();

        void set(T value, size_t row, size_t col, size_t channel);
        void set(Matrix<T> matrix, size_t channel);
        void set(Tensor3D<T> tensor);

        bool equalTo(Tensor3D tensor);

        size_t numRows();
        size_t numCols();
        size_t numChannels();
        std::vector<Matrix<T>>* getValues();

        void setRows(size_t newRows);
        void setCols(size_t newCols);
        void setChannels(size_t newChannels);

        Tensor3D filter(Tensor3D filter, size_t stride, bool padding);

        Tensor3D applyFunction(T function(T));
        Tensor3D insert(Matrix<T> toAppend, size_t channel);
        Tensor3D append(Matrix<T> toAppend);
        Tensor3D del(size_t startChannel, size_t endChannel);

        // Overloaded operators
        T operator()(size_t row, size_t col, size_t channel);
        Matrix<T> operator()(size_t channel);
        Tensor3D operator()(size_t startChannel, size_t endChannel);

        void operator=(Tensor3D matrix);
        bool operator==(Tensor3D matrix);
};


/* Constructors and destructor */
template <typename T>
Tensor3D<T>::Tensor3D(){    // DONE
    this->rows = 0;
    this->cols = 0;
    this->channels = 0;
    this->data.clear();
}

template <typename T>
Tensor3D<T>::Tensor3D(size_t numRows, size_t numCols, size_t numChannels, std::string fill){    // DONE
    this->rows = numRows;
    this->cols = numCols;
    this->channels = numChannels;

    for(size_t i = 0; i < channels; i++)
        this->data.push_back(Matrix<T>(numRows, numCols, fill));
}

template <typename T>
template <typename dist_t>
Tensor3D<T>::Tensor3D(size_t numRows, size_t numCols, size_t numChannels, dist_t dist){ // DONE
    this->rows = numRows;
    this->cols = numCols;
    this->channels = numChannels;

    for(size_t i = 0; i < channels; i++)
        this->data.push_back(Matrix<T>(numRows, numCols, dist));
}

template <typename T>
Tensor3D<T>::Tensor3D(std::vector<Matrix<T>> tensor){   // DONE
    this->rows = numRows;
    this->cols = numCols;
    this->channels = tensor.size();
    this->data.assign(tensor.begin(), tensor.end());
}

template <typename T>
Tensor3D<T>::~Tensor3D(){}  // DONE



/* Getters and Setters */
template <typename T>
size_t Tensor3D<T>::numRows(){  // DONE
    return this->rows;
}

template <typename T>
size_t Tensor3D<T>::numCols(){  // DONE
    return this->cols;
}

template <typename T>
size_t Tensor3D<T>::numChannels(){  // DONE
    return this->channels;
}

template <typename T>
std::vector<Matrix<T>>* Tensor3D<T>::getValues(){   // DONE
    return &data;
}

template <typename T>
void Tensor3D<T>::setRows(size_t newRows){  // DONE
    rows = newRows;
}

template <typename T>
void Tensor3D<T>::setCols(size_t newCols){  // DONE
    cols = newCols;
}

template <typename T>
void Tensor3D<T>::setChannels(size_t newChannels){  // DONE
    channels = newChannels;
}

template <typename T>
void Tensor3D<T>::set(T value, size_t row, size_t col, size_t channel){ // DONE
    this->set(((*this)(channel)).set(value, row, col), channel);
}

template <typename T>
void Tensor3D<T>::set(Matrix<T> matrix, size_t channel){    // DONE
    this->data.at(channel) = matrix;
}

template <typename T>
void Tensor3D<T>::set(Tensor3D tensor){ // DONE
    this->rows = tensor.rows;
    this->cols = tensor.cols;
    this->channels = tensor.channels;
    this->data.assign(tensor.data.begin(), tensor.data.begin() + tensor.data.size());
}


/* Print matrix */
template <typename T>
void Tensor3D<T>::print(){  // DONE
    for(size_t idx = 0; idx < channels; idx++){
        std::cout << "Channel " << idx << ":" << std::endl;
        ((*this)(idx)).print();
    }
}


/* Equality comparison */
template <typename T>
bool Tensor3D<T>::equalTo(Tensor3D matrix){ // DONE
    for(size_t idx = 0; idx < channels; idx++){
        if(!(*this)(idx) == matrix(idx))
            return false;
    }
    return true;
}

template <typename T>
Tensor3D<T> Tensor3D<T>::filter(Tensor3D filter, size_t stride, bool padding){  // DONE
    Tensor3D result = *this;
    
    for(size_t idx = 0; idx < channels; idx++){
        result.set((*this)(idx).filter(filter(idx), stride, padding), idx);
    }    

    return result;
}

template <typename T>
Tensor3D<T> Tensor3D<T>::applyFunction(T function(T)){  // DONE
    Tensor3D result = *this;

    for(size_t idx = 0; idx < channels; idx++){
        result.set((*this)(idx).applyFunction(function), idx);
    }

    return result;
}


/* Inserting, appending and deleting */
template <typename T>
Tensor3D<T> Tensor3D<T>::insert(Matrix<T> toAppend, size_t channel){    // DONE
    Tensor3D result = *this;

    result.data.insert(toAppend, 1, result.data.begin() + channel);
    
    return result;
}

template <typename T>
Tensor3D<T> Tensor3D<T>::append(Matrix<T> toAppend){    // DONE
    return this->insert(toAppend, this->numChannels());
}

template <typename T>
Tensor3D<T> Tensor3D<T>::del(size_t startChannel, size_t endChannel){   // DONE
    // Start idx and end idx are inclusive [startIdx, endIdx]
    Tensor3D result = *this;

    result.data.erase(result.data.begin()+startChannel, result.data.begin()+endChannel+1);
    
    return result;
}


/* Overloaded operators */
template <typename T>
Matrix<T> Tensor3D<T>::operator()(size_t channel){  // DONE
    return this->data.at(channel);
}

template <typename T>
Tensor3D<T> Tensor3D<T>::operator()(size_t startChannel, size_t endChannel){    // DONE
    Tensor3D result(this->rows, this->cols, endChannel - startChannel + 1);

    for(size_t idx = 0; idx < result.numChannels(); idx++){
        result.set((*this)(startChannel + idx), idx);
    }
    
    return result;
}

template <typename T>
T Tensor3D<T>::operator()(size_t row, size_t col, size_t channel){  // DONE
    return (*this)(channel)(row, col);
}

template <typename T>
void Tensor3D<T>::operator=(Tensor3D tensor){this->set(tensor);}    // DONE

template <typename T>
bool Tensor3D<T>::operator==(Tensor3D tensor){return this->equalTo(tensor);}    // DONE

#endif
