# MatrixCpp
 
Matrix class created to allow other applications, such as neural networks, sattelite studies and game development.

## Methods

The library permits using most matrix operations. The ideia is to feed the code and create other operations over time when needed. For now, it has:

1. Addition and subtraction  
&emsp;- `matrixObj1 += matrixObj2;`  
&emsp;- `matrixObj1 + matrixObj2;`  
&emsp;- `matrixObj ++;`  

&emsp;- `matrixObj1 -= matrixObj2;`  
&emsp;- `matrixObj1 - matrixObj2;`  
&emsp;- `matrixObj --;`  

2. Multiplication by another matrix or value  
&emsp;- `matrixObj1 * matrixObj2;`  
&emsp;- `matrixObj1 *= matrixObj2;`  

&emsp;- `matrixObj * value;`  
&emsp;- `matrixObj *= value;`  

3. Dividing by value   
&emsp;- `matrixObj / value;`  
&emsp;- `matrixObj /= value;`  

4. Transposing  
&emsp;- `matrixObj.transpose();`  

5. Dot product  
&emsp;- `matrixObj1.dotProduct(matrixObj2);`  
&emsp;- `dotProduct(matrixObj1, matrixObj2);`  

6. Applying functions  
&emsp;- `matrixObj.applyFunction(float function(float));`  

7. Inserting and appending  
&emsp;- `matrixObj1.insert(Matrix matrixObj2, size_t idx, bool row=true);`  
&emsp;- `append(Matrix toAppend, bool row);`  

8. Definition and equality comparison  
&emsp;- `matrixObj1 = matrixObj2;`  
&emsp;- `matrixObj1 == matrixObj2;`  

9. Accessing values  
&emsp;- `matrixObj(size_t row, size_t col)`  
&emsp;- `matrixObj(size_t idx, bool row)`  
