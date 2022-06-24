#include <iostream>
#include "matrix.hpp"

using namespace std;


int main(){
    Matrix matrix(3, 3, (string) "random");
    Matrix matrixColumn(3, 1, (string) "random");
    Matrix matrixRow(1, 3, (string) "random");
    Matrix matrixResult;


    cout << "\n*** Testing matrices ***\n";
    matrix.print();
    matrixColumn.print();
    matrixRow.print();


    // cout << "\n*** Testing append, insert e del ***\n";
    // cout << "Append row\n";
    // matrixResult = matrix.append(matrixRow, ROW);
    // matrixResult.print();

    // cout << "Insert row\n";
    // matrixResult = matrix.insert(matrixRow, 1, ROW);
    // matrixResult.print();

    // cout << "Del row\n";
    // matrixResult = matrix.del(0, 1, ROW);
    // matrixResult.print();
    
    // cout << "Append column\n";
    // matrixResult = matrix.append(matrixColumn, COLUMN);
    // matrixResult.print();

    // cout << "Insert column\n";
    // matrixResult = matrix.insert(matrixColumn, 1, COLUMN);
    // matrixResult.print();

    // cout << "Del column\n";
    // matrixResult = matrix.del(0, 1, COLUMN);
    // matrixResult.print();


    // cout << "\n*** Testing access operators ***\n";
    // cout << "\nElement access\n";
    // cout << "Matrix(1,2) = " << matrix((size_t) 1, (size_t) 2);

    // cout << "\nRow access\n";
    // matrixResult = matrix(0, ROW);
    // matrixResult.print();

    // cout << "Column access\n";
    // matrixResult = matrix(0, COLUMN);
    // matrixResult.print();

    // cout << "\n*** Testing equality ***\n";
    // cout << (matrix == matrixResult) << endl;
    // matrixResult = matrix;
    // cout << (matrix == matrixResult) << endl;

    // cout << "\n*** Testing operations ***\n";
    // matrixResult = Matrix(matrix.numRows(), matrix.numCols(), "ones");
    // matrixResult.print();
    // matrixResult = matrixResult + matrixResult;
    // matrixResult.print();
    // matrixResult = matrixResult * 2;
    // matrixResult.print();
    // cout << "Dot product: " << matrixResult.dotProduct(Matrix(matrixResult.numRows(), matrixResult.numCols(), "ones")) << endl;
    // cout << "Sum: " << matrixResult.sum() << endl;
    // matrix = Matrix(matrix.numRows(), matrix.numCols(), "ones");
    // matrixResult = Matrix(matrix.numRows(), matrix.numCols(), "ones");
    // matrixResult = matrix * matrixResult;
    // matrixResult.print();

    // cout << "\n*** Testing applying function and transposing ***\n";
    // matrixResult = Matrix(matrix.numRows(), matrix.numCols(), "ones") * 2;
    // matrixResult = matrixResult.applyFunction([](float x){return 1/x;});
    // matrixResult.print();

    // matrixResult = Matrix(matrix.numRows(), matrix.numCols(), "random");
    // matrixResult.print();
    // matrixResult = matrixResult.transpose();
    // matrixResult.print();

    cout << "\n*** Testing inplace operations ***\n";
    matrixResult = Matrix(matrix.numRows(), matrix.numCols(), "ones");
    matrixResult.print();
    matrixResult += matrixResult;
    matrixResult.print();
    matrixResult++;
    matrixResult.print();
    matrixResult -= 2;
    matrixResult.print();
    matrix = Matrix(matrix.numRows(), matrix.numCols(), "ones");
    matrixResult = Matrix(matrix.numRows(), matrix.numCols(), "ones");
    matrixResult *= matrix;
    matrixResult.print();

    return 0;
}
