#include <iostream>
#include "matrix.hpp"

using namespace std;


int main(){
    std::normal_distribution<float> dist(0, 1);

    Matrix<float> matrix(3, 3, dist);
    Matrix<float> matrixColumn(3, 1, dist);
    Matrix<float> matrixRow(1, 3, dist);
    Matrix<float> matrixResult(std::vector<float>({1, 1, 1}), (size_t) 1, (size_t) 3);


    cout << "\n*** Testing matrices ***\n";
    matrix.print();
    matrixColumn.print();
    matrixRow.print();
    matrixResult.print();

    cout << "\n*** Testing append, insert e del ***\n";
    cout << "Append row\n";
    matrixResult = matrix.append(matrixRow, ROW);
    matrixResult.print();

    cout << "Insert row\n";
    matrixResult = matrix.insert(matrixRow, 1, ROW);
    matrixResult.print();

    cout << "Del row\n";
    matrixResult = matrix.del(0, 1, ROW);
    matrixResult.print();
    
    cout << "Append column\n";
    matrixResult = matrix.append(matrixColumn, COLUMN);
    matrixResult.print();

    cout << "Insert column\n";
    matrixResult = matrix.insert(matrixColumn, 1, COLUMN);
    matrixResult.print();

    cout << "Del column\n";
    matrixResult = matrix.del(0, 1, COLUMN);
    matrixResult.print();


    cout << "\n*** Testing access operators ***\n";
    cout << "\nElement access\n";
    cout << "Matrix(1,2) = " << matrix((size_t) 1, (size_t) 2);

    cout << "\n\nRow access\n";
    matrixResult = matrix(0, ROW);
    matrixResult.print();

    cout << "Column access\n";
    matrixResult = matrix(0, COLUMN);
    matrixResult.print();

    cout << "Matrix access\n";
    matrixResult = matrix(0, 1, 0, 1);
    matrixResult.print();

    cout << "\n*** Testing equality ***\n";
    cout << (matrix == matrixResult) << endl;
    matrixResult = matrix;
    cout << (matrix == matrixResult) << endl;

    cout << "\n*** Testing operations ***\n";
    matrixResult = Matrix<float>(matrix.numRows(), matrix.numCols(), dist);
    matrixResult.print();
    matrixResult = matrixResult + matrixResult;
    matrixResult.print();
    matrixResult = matrixResult * 2;
    matrixResult.print();
    cout << "Dot product: " << matrixResult.dotProduct(Matrix<float>(matrixResult.numRows(), matrixResult.numCols(), (std::string) "ones")) << endl;
    cout << "Sum: " << matrixResult.sum() << endl;
    matrix = Matrix<float>(matrix.numRows(), matrix.numCols(), (std::string) "ones");
    matrixResult = Matrix<float>(matrix.numRows(), matrix.numCols(), (std::string) "ones");
    matrixResult = matrix * matrixResult;
    matrixResult.print();

    cout << "\n*** Testing applying function and transposing ***\n";
    matrixResult = Matrix<float>(matrix.numRows(), matrix.numCols(), (std::string) "ones") * 2;
    matrixResult = matrixResult.applyFunction([](float x){return 1/x;});
    matrixResult.print();

    matrixResult = Matrix<float>(matrix.numRows(), matrix.numCols(), dist).abs();
    matrixResult = matrixResult.applyFunction([](Matrix<float> x){return x/x.sum();}, ROW_WISE);
    matrixResult.print();

    matrixResult = Matrix<float>(matrix.numRows(), matrix.numCols(), dist).abs();
    matrixResult = matrixResult.applyFunction([](Matrix<float> x){return x/x.sum();}, COLUMN_WISE);
    matrixResult.print();

    matrixResult = Matrix<float>(matrix.numRows(), matrix.numCols(), dist);
    matrixResult.print();
    matrixResult = matrixResult.transpose();
    matrixResult.print();

    cout << "\n*** Testing inplace operations ***\n";
    matrixResult = Matrix<float>(matrix.numRows(), matrix.numCols(), (std::string) "ones");
    matrixResult.print();
    matrixResult += matrixResult;
    matrixResult.print();
    matrixResult++;
    matrixResult.print();
    matrixResult -= 2;
    matrixResult.print();
    matrix = Matrix<float>(matrix.numRows(), matrix.numCols(), (std::string) "ones");
    matrixResult = Matrix<float>(matrix.numRows(), matrix.numCols(), (std::string) "ones");
    matrixResult *= matrix;
    matrixResult.print();

    cout << "\n*** Testing statistics operations ***\n";
    matrix = Matrix<float>(1, 5, dist);
    matrix.print();
    
    cout << "Max: " << matrix.max() << endl;
    cout << "Min: " << matrix.min() << endl;
    cout << "Mean: " << matrix.mean() << endl;
    cout << "Median: " << matrix.median() << endl;
    cout << "Max idx: " << matrix.maxIdx() << endl;
    cout << "Min idx: " << matrix.minIdx() << endl;

    return 0;
}
