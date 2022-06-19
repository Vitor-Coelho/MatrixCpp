# MatrixCpp
 
Matrix class created to allow other applications, such as neural networks, sattelite studies and game development.

## Methods

The library permits using most matrix operations. The ideia is to feed the code and create other operations over time when needed. For now, it has:

1. Addition and subtraction  
    When adding or subtracting matrices, they must have the same format.
    - `matrixObj1 + matrixObj2;`  
    - `matrixObj1 - matrixObj2;`

    Adding and subtracting by a value is applied element-wise.
    - `matrixObj + value;`
    - `matrixObj - value;`

    Increments or decrements all values element-wise.
    - `matrixObj++;`  
    - `matrixObj--;`  

2. Multiplication by another matrix or value  
    - `matrixObj1 * matrixObj2;` | Column size of first matrix must match row size of second matrix.
    - `matrixObj  * value;` | Multiplying by a value is applied element-wise.

3. Dividing by value   
    - `matrixObj / value;` | Dividing by a value is applied element-wise.

4. Transposing  
    - `matrixObj.transpose();`  

5. Dot product  
    - `matrixObj1.dotProduct(matrixObj2);`  
    - `dotProduct(matrixObj1, matrixObj2);`  

6. Applying functions  
    - `matrixObj.applyFunction(float function(float));` | It applies the function to the matrix element-wise.  

7. Inserting and appending  
    - `matrixObj1.insert(Matrix matrixObj2, size_t idx, bool row=true);` | Inserts another matrix row-wise or column-wise in idx.  
    - `append(Matrix toAppend, bool row);` | Appends another matrix row-wise or column-wise.  

8. Delete  
    - `del(size_t startIdx, size_t endIdx, bool row=true);` | Deletes rows or columns in indexes [startIdx, endIdx] (inclusive).  

9. Definition and equality comparison  
    - `matrixObj1 = matrixObj2;`  
    - `matrixObj1 == matrixObj2;`  

10. Accessing values  
    - `matrixObj(size_t row, size_t col)` | Returns the value in (row, col).
    - `matrixObj(size_t idx, bool row)` | Returns a row-matrix or column-matrix of index.  
