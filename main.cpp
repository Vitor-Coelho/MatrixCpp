#include <iostream>
#include "matrix.hpp"

using namespace std;


int main(){
    Matrix matrix1(3, 3, (string) "ones");
    Matrix matrix2(3, 3, (string) "random");

    matrix1.print();
    matrix2.print();

    matrix1 = matrix1 + matrix2;

    matrix1.print();

    cout << matrix1.dotProduct(matrix2);

    return 0;
}
