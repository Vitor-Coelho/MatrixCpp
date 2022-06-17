# MatrixCpp
 
Matrix class created to allow other applications, such as neural networks, sattelite studies and game development.

## Methods

The library permits using most matrix operations. The ideia is to feed the code and create other operations over time when needed. For now, it has:

1. Addition and subtraction  
    - `matrixObj1 += matrixObj2;`  
    - `matrixObj1 + matrixObj2;`  
    - `matrixObj++;`  

    - `matrixObj1 -= matrixObj2;`  
    - `matrixObj1 - matrixObj2;`  
    - `matrixObj--;`  

2. Multiplication by another matrix or value  
    - `matrixObj1 * matrixObj2;`  
    - `matrixObj1 *= matrixObj2;`  

    - `matrixObj * value;`  
    - `matrixObj *= value;`  

3. Dividing by value   
    - `matrixObj / value;`  
    - `matrixObj /= value;`  

4. Transposing  
    - `matrixObj.transpose();`  

5. Dot product  
    - `matrixObj1.dotProduct(matrixObj2);`  
    - `dotProduct(matrixObj1, matrixObj2);`  

6. Applying functions  
    - `matrixObj.applyFunction(float function(float));`  

7. Inserting and appending  
    - `matrixObj1.insert(Matrix matrixObj2, size_t idx, bool row=true);`  
    - `append(Matrix toAppend, bool row);`  

8. Definition and equality comparison  
    - `matrixObj1 = matrixObj2;`  
    - `matrixObj1 == matrixObj2;`  

9. Accessing values  
    - `matrixObj(size_t row, size_t col)`  
    - `matrixObj(size_t idx, bool row)`  
