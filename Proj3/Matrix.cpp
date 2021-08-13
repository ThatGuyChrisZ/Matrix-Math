/*-------------------------------------------------------------------------------
FILE NAME:      Matrix.cpp
DESCRIPTION:    CS 202 - Proj 3
USAGE:          ./matrix_math1.cpp               // Interactive mode
COMPILER:       GNU g++ compiler on Linux
NOTES:          Holds member functions
Modification    History:
Author                  Date            Version
------------------      -----------     -----------
Christopher Zinser      2020-11-09      v2
						2020-11-10      v3
						2020-12-01      v5 added documentation
						2020-11-13      Final
						2020-11-15      Final
						2020-11-18      Final
						2020-11-20      Final
						2020-11-21      Final
						2020-11-28      Final
						2020-11-29      Final
						2020-11-30      Final
						2020-11-02      Final
						2020-11-03      Final
						2020-11-04      Final
-------------------------------------------------------------------------------*/
#include "Matrix.h"
/* -----------------------------------------------------------------------------
FUNCTION:          Matrix()
DESCRIPTION:       Default constructor matrix
RETURNS:           n/a
NOTES:             none
----------------------------------------------------------------------------- */
template <class T>
Matrix<T>::Matrix(){
	rows = 0;
	cols = 0;
	
	array = NULL;
	#ifdef TEST
		cout<< "Default constructor: " << rows << " X " << cols << endl;
	#endif
}
/* -----------------------------------------------------------------------------
FUNCTION:          Matrix()
DESCRIPTION:       Generates a matrix with specified interger dimensions
RETURNS:           n/a
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
Matrix<T>::Matrix(int n_rows, int n_cols){
	rows = n_rows;
	cols = n_cols;
	
	array = new T*[rows];
	
	for(int i = 0; i < rows; i++)
		array[i] = new T [cols];
	//cout << "Matrix constructor: "
		// << rows << " X " << cols << endl;
}
/* -----------------------------------------------------------------------------
FUNCTION:          Matrix()
DESCRIPTION:       Generates a matrix using another matrix
RETURNS:           n/a
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
Matrix<T>::Matrix(const Matrix<T> &m){
	//cout << "Making copy" << endl;
	rows = m.rows;
	cols = m.cols;
	
	array = new T * [rows];
	
	#ifdef TEST
		cout << "Copy contructor: "<< rows<< " X "<< cols << endl;
	#endif
	
	for(int i = 0; i < rows; i++){
		array[i] = new T [cols];
		for(int j=0; j < cols; j++){
			array[i][j] = m.array[i][j];
		}
	}
	
	
}
/* -----------------------------------------------------------------------------
FUNCTION:          =
DESCRIPTION:       Overloads the = operator for setting matrixs
RETURNS:           matrix
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T> &m){
	for(int i = 0; i < rows; i++)
		delete [] array[i];
	
	delete [] array;
	
	rows = m.rows;
	cols = m.cols;
	
	array = new T * [rows];
	
#ifdef TEST
	cout << "Asgnment operator = : " << rows << " X " << cols << endl;
#endif 

	for(int i = 0; i < rows; i++){
		
		array[i] = new T [cols];
		for(int j = 0; j < cols; j++){
			array[i][j]=m.array[i][j];
		}
	}
	return *this;
}
/* -----------------------------------------------------------------------------
FUNCTION:          dispay()
DESCRIPTION:       Displays Matrix
RETURNS:           n/a
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
void Matrix<T>::display(){
	cout<< endl;
	for(int i=0; i<rows; i++){
		for(int j = 0; j < cols; j++){
			cout << setw(6) << get(i,j);
		}
		cout<< endl;
	}
	cout<< endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          << operator
DESCRIPTION:       Overloaded << operator for matrix output
RETURNS:           ostream
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
ostream& operator << (ostream &out, const Matrix<T> &mat){
	
	out<< setw(6) << mat.rows << " X " << mat.cols << endl;
	for(int i =0; i < mat.rows; i++){
		for(int j = 0; j< mat.cols; j++){
			//out<< setw(6) << mat.get(i,j);
			out<< setw(6) << mat.array[i][j];
		}
		out<< endl;
	}
	return out;
}

/* -----------------------------------------------------------------------------
FUNCTION:          >> operator
DESCRIPTION:       Overload for matrix input
RETURNS:           istream
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>

istream &operator >> (istream &in, Matrix<T>&m1){
	char let_x;
	int m,n;
	#ifdef TEST
		cout << "Input operator >> : "<< endl;
	#endif
	
	in>> m >> let_x >> n;
	Matrix<T> mat(m,n);
	
	for (int i=0; i < mat.rows; i++)
	{
		for(int j = 0; j< mat.cols; j++){
		in>> mat.array[i][j];
		}
	}
	m1 = mat;
	return in;
}


/* -----------------------------------------------------------------------------
FUNCTION:          inv()
DESCRIPTION:       inverse of matrix
RETURNS:           n/a
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
void Matrix_ops<T>::inv(double n){
	for(int i = 0; i < rows; i++){
		
		//array[i] = new T [cols];
		for(int j = 0; j < cols; j++){
			//array[i][j]=pow(array[i][j],-n);
		}
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          sub_mat()
DESCRIPTION:       creates submatrix
RETURNS:           n/a
NOTES:             none
----------------------------------------------------------------------------- */
template <class T>
void Matrix_ops<T>::sub_mat(int t_row,int t_column){
	Matrix_ops<T> m1=*this;
	t_row-=1;
	t_column-=1;
	Matrix_ops<T> m2(rows-1,cols-1);
	int pr = 0;
	//cout<< "Eliminating row " <<t_row <<endl;
	//cout<< "Eliminating column " <<t_column <<endl;
	//cout<< "Entered with: " << *this<< endl;
	if(t_row < 0){
		cout<< "row must be greater than 0"<< endl;
		return;
	}
	
	if(t_column < 0){
		cout<< "column must be greater than 0"<< endl;
		return;
	}
	
	for(int i = 0; i < rows; i++){
		int pc = 0;
	
		for(int j = 0; j < cols; j++){
			if(i ==t_row){
				//cout<< "target row" << endl;
				i++;
				pr++;
			}
			if(j== t_column){
				//cout<< "target col" << endl;
				j++;
				pc++;
			}
			//cout<< "["<<i-pr<<"]"<<"["<<j-pc<<"]"<<"=" << array[i][j]<< endl;
			m2.array[i-pr][j-pc] = array[i][j];
			
		}
	}
	//cout<< "Ended elmination with " <<endl<<  m2 << endl;
	
	*this = m2;
	for(int i = 0; i < rows; i++){
		m2.array[i] = 0;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          det()
DESCRIPTION:       returns determinant (not functional)
RETURNS:           n/a
NOTES:             none
----------------------------------------------------------------------------- */
template <class T>
double Matrix_ops<T>::det(){
	double returning = 0;
	if(rows == cols){
		
		//cout<< "Can Execute with "<< rows << "rows" << endl;
		if(rows == 3){
			double ups = 0;
			double downs = 0;
			Matrix_ops<T> m2(rows,cols +2);
			for(int i = 0; i< rows; i++){
				for(int j = 0; j< rows; j++){
					m2.array[i][j] = array[i][j];
				}
			}
			//cout<< "Columns Added = " << endl
			//	<< m2 << endl;
			for(int i = 0; i< 3; i++){
				m2.array[i][3] = array[i][0];
				m2.array[i][4] = array[i][1];
			}
			
			for(int i = 0; i< 3; i++){
				downs += m2.array[0][i] * m2.array[1][i+1]*m2.array[2][i+2]; 
				//cout<< m2.array[0][i]<<"*"<< m2.array[1][i+1]<<"*"<<m2.array[2][i+2]<<endl;
			}
			
			for(int i = m2.cols; i> m2.rows -3; i--){
				ups -= m2.array[0][i] * m2.array[1][i-1]*m2.array[2][i-2]; 
				//cout<< m2.array[0][i]<<"*"<< m2.array[1][i-1]<<"*"<<m2.array[2][i-2]<<endl;
			}
			returning = downs+ups;
			//cout<< "Extended = " << endl
			//	<< m2 << endl;
		}
		if(rows == 2){
			
			
		}
		if(rows < 2){
			
		}
		if(rows == 4){
			//cout<< "Entering operations of 4" << endl;
			double top_vals[cols];
			
			for(int i = 0; i< cols; i++){
				top_vals[i] = array[0][i];
			}
			for(int i = 0; i< cols; i++){
				top_vals[i] = array[0][i];
			}
			
			for(int i = 0; i< cols; i++){
				Matrix_ops<T> m2(*this);
				//cout<< "entering sub_mat " << "#"<< i+1 << endl;
				m2.sub_mat(1,i+1);
				//cout<< "Submatrix #" << i+1 << endl << m2 << endl;
				returning += top_vals[i]*m2.det();
				//cout << i+1<< "/"<< cols << endl;
				//cout<< "Returning = " << returning << endl;
				for(int j = 0; j< m2.rows; j++){
					m2.array[j] = 0;
				}
			
			}
			
			
		}
	

	}
	cout<< "Exiting" << endl;
	return returning;
}

/* -----------------------------------------------------------------------------
FUNCTION:          + operator
DESCRIPTION:       Adds 2 matrixs
RETURNS:           Matrix
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
Matrix_ops<T> Matrix_ops<T>::operator + (const Matrix_ops<T> &m1){
	cout<< "Addition Entered" << endl;
	
	

	if(rows == m1.rows && cols == m1.cols){
		Matrix_ops<T> m2(rows,cols);
		for (int i=0; i < rows; i++)
		{
			for(int j = 0; j< cols; j++){
				if(array[i][j] && m1.array[i][j]){
					m2.array[i][j] =array[i][j]+m1.array[i][j];
				}
			}
		}
	
	return m2;
	}else{
		cout<< "Invalid Dimensions" << endl;
		return *this;
	}
	
}



/* -----------------------------------------------------------------------------
FUNCTION:          - operator
DESCRIPTION:       Matrix Subtraction
RETURNS:           matrix
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>

Matrix_ops<T> Matrix_ops<T>::operator - (const Matrix_ops<T> &m1){
	//cout<< "Subtraction Entered" << endl;
	
	
	//cout<<"Entering loop subtraction" << endl;
	if(rows == m1.rows && cols == m1.cols){
		Matrix_ops<T> m2(rows,cols);
		for (int i=0; i < rows; i++)
		{
			for(int j = 0; j< cols; j++){
				if(array[i][j] && m1.array[i][j]){
					m2.array[i][j] =array[i][j]-m1.array[i][j];
				}
			}
		}
	
	return m2;
	}else{
		cout<< "Invalid Dimensions" << endl;
		return *this;
	}
	
}



/* -----------------------------------------------------------------------------
FUNCTION:          * operator
DESCRIPTION:       Multiplies matrixs
RETURNS:           matrix
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>

Matrix_ops<T> Matrix_ops<T>::operator * (const Matrix_ops<T> &m1){
	//cout<< "Multiplication Entered" << endl;
	
	
	//cout<<"Entering loop Multiplication" << endl;
	
		Matrix_ops<T> m2(rows,m1.cols);
		for (int i=0; i < rows; i++)
		{
			for(int j = 0; j< m1.cols; j++){
				int val = 0;
				for(int g = 0; g< cols; g++){
				val +=array[i][g]*m1.array[g][j];
				}
				//cout<<"["<<i<<"]"<<"["<<j<<"]"<<": "<< val << endl;
				m2.array[i][j] = val;
				
			}
			
		}
	//cout<< "m2 mult exit: "<< endl<< m2<< endl;
	return m2;
	
	
}

/* -----------------------------------------------------------------------------
FUNCTION:          * operator
DESCRIPTION:       Multiplies a matrix by a int
RETURNS:           matrix
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
Matrix_ops<T> Matrix_ops<T>::operator * (int num){
		Matrix_ops<T> m2(rows,cols);
		for (int i=0; i < rows; i++)
		{
			for(int j = 0; j< cols; j++){
				if(array[i][j]){
					m2.array[i][j] =array[i][j]* num;
				}
			}
		}
	
	return m2;
	
	
}

/* -----------------------------------------------------------------------------
FUNCTION:          / operator
DESCRIPTION:       Divides matrixs
RETURNS:           matrix
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>

Matrix_ops<T> Matrix_ops<T>::operator / (const Matrix_ops<T> &m1){
	//cout<< "Divison Entered" << endl;
	
	
	//cout<<"Entering loop Division" << endl;
	if(rows == m1.rows && cols == m1.cols){
		Matrix_ops<T> m2(rows,cols);
		for (int i=0; i < rows; i++)
		{
			for(int j = 0; j< cols; j++){
				if(array[i][j] && m1.array[i][j]){
					m2.array[i][j] =array[i][j]/m1.array[i][j];
				}
			}
		}
	
	return m2;
	}else{
		cout<< "Invalid Dimensions" << endl;
		return *this;
	}
	
}

/* -----------------------------------------------------------------------------
FUNCTION:          / operator
DESCRIPTION:       Scalular Division
RETURNS:           matrix
NOTES:             none
----------------------------------------------------------------------------- */


template <class T>
Matrix_ops<T> Matrix_ops<T>::operator / (int num){
	//cout<< "Multiplication Entered" << endl;
	
	
	//cout<<"Entering loop Multiplication" << endl;
	
		Matrix_ops<T> m2(rows,cols);
		for (int i=0; i < rows; i++)
		{
			for(int j = 0; j< cols; j++){
				if(array[i][j]){
					m2.array[i][j] =array[i][j]/ num;
				}
			}
		}
	
	return m2;
	
	
}

/* -----------------------------------------------------------------------------
FUNCTION:          == operator
DESCRIPTION:       Tests equality of 2 matrix's
RETURNS:           bool
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
bool Matrix_ops<T>::operator == (const Matrix_ops<T> &m1){

	
	bool tf = false;
	//cout<<"Entering loop Equality" << endl;
	if(rows == m1.rows && cols == m1.cols){
		//cout<< "Dimensions Equal" << endl;
		tf=true;
		Matrix_ops<T> m2(rows,cols);
		for (int i=0; i < rows; i++)
		{
			for(int j = 0; j< cols; j++){
				
				if(array[i][j] != m1.array[i][j]){
					tf = false;
					//cout<< array[i][j]<<" != "<<m1.array[i][j] << endl;
				}else{
					//cout<< array[i][j]<<" == "<<m1.array[i][j]<< endl;
				}
				
			}
		}
	
	
	}
	return tf;
}

/* -----------------------------------------------------------------------------
FUNCTION:          ~Matrix()
DESCRIPTION:       deconstructor
RETURNS:           n/a
NOTES:             none
----------------------------------------------------------------------------- */

template <class T>
Matrix<T>::~Matrix(){
	//cout<< "Entering Deconstructor" << endl;
	//cout<< "Row Count: " << rows << endl;
	//cout << *this << endl;
	for(int i = 0; i < rows; i++){
		//cout<< "Deleting "<<1 << ": ";
		//cout<< array[i] << endl;
		if(this -> array[i]){
			delete[] array[i];
			array[i] = 0;
		}
		//cout<< "Finished Deleting "<< endl;
	}
	//cout<< "Deleted Rows" << endl;
	
	delete [] array;
	#ifdef TEST
		cout<< "Matrix destructor: "<< rows << " X "<< cols << endl;
	#endif
	//cout<< "Exiting Deconstructor" << endl;
}
