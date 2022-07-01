# MatrixCpp
 
Matrix class created to allow other applications, such as neural networks, sattelite studies and game development.

## Methods

The library permits using most matrix operations. The ideia is to feed the code and create other operations over time when needed. For now, it has:

1. Creating a matrix
    - `Matrix()` | Creates a 1x1 zero-valued matrix  
    - `Matrix(size_t numRows, size_t numCols, const char * fill)` | Fill may be "zeros" or "ones", "zeros" by default  
    - `Matrix(size_t numRows, size_t numCols, dist_t dist)` | Dist is a random library distribution to create a random matrix  
    - `Matrix(std::vector<T> vec, size_t numRows, size_t numCols)` | Create a matrix based in a vector  

2. Addition and subtraction  
    When adding or subtracting matrices, they must have the same format (element-wise), same number of rows (column-wise) or same number of columns (row-wise)
    - `matrixObj1 + matrixObj2`  
    - `matrixObj1 - matrixObj2`

    Adding and subtracting by a value is applied element-wise
    - `matrixObj + value`
    - `matrixObj - value`

    Increments or decrements all values element-wise
    - `matrixObj++`  
    - `matrixObj--`  

3. Multiplication by another matrix or value  
    - `matrixObj1 * matrixObj2` | Column size of first matrix must match row size of second matrix (matrix product)
    - `matrixObj  * value` | Multiplying by a value is applied element-wise
    - `matrixObj1.multiply(matrixObj2)` | The matrices must have the same format (element-wise), same number of rows (column-wise) or same number of columns (row-wise)

4. Dividing by value   
    - `matrixObj / value` | Dividing by a value is applied element-wise
    - `matrixObj1.divide(matrixObj2)` | The matrices must have the same format (element-wise), same number of rows (column-wise) or same number of columns (row-wise)

5. Transposing  
    - `matrixObj.transpose()`  

6. Absolute value  
    - `matrixObj.abs()` | Returns the matrix with the absolute value of each element  

7. Dot product and sum
    - `matrixObj1.dotProduct(matrixObj2)`  
    - `matrixObj.sum()` | Returns the sum of all elements

8. Applying functions  
    - `matrixObj.applyFunction(float function(float))` | It applies the function to the matrix element-wise and returns the new matrix  
    - `matrixObj.applyFunction(Matrix function(Matrix), how=MATRIX_WISE);` | Applies the function matrix-wise, row-wise or column-wise and return the new matrix

9. Inserting and appending  
    - `matrixObj1.insert(Matrix matrixObj2, size_t idx, bool row=true)` | Inserts another matrix row-wise or column-wise in idx  
    - `matrixObj1.append(Matrix matrixObj2, bool row)` | Appends another matrix row-wise or column-wise  

10. Delete  
    - `matrixObj.del(size_t startIdx, size_t endIdx, bool row=true)` | Deletes rows or columns in indexes [startIdx, endIdx] (inclusive)  

11. Definition and equality comparison  
    - `matrixObj1 = matrixObj2`  
    - `matrixObj1 == matrixObj2`  

12. Accessing values  
    - `matrixObj(size_t row, size_t col)` | Returns the value in (row, col)
    - `matrixObj(size_t idx, bool row)` | Returns a row-matrix or column-matrix of index  
    - `matrixObj(size_t startRow, size_t endRow, size_t startCol, size_t endCol);` | Returns a matrix (boundaries are inclusive)  

13. Statistics
    - `matrixObj.max()` | Returns the maximum value  
    - `matrixObj.min()` | Returns the minimum value  
    - `matrixObj.mean()` | Returns the mean value  
    - `matrixObj.median()` | Returns the median value  
    - `matrixObj.maxIdx()` | Returns the maximum value index  
    - `matrixObj.minIdx()` | Returns the maximum value index
  