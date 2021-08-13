/*-------------------------------------------------------------------------------
FILE NAME:      Matrix.h
DESCRIPTION:    CS 202 - Proj 3
USAGE:          ./matrix_math1               // Interactive mode
COMPILER:       GNU g++ compiler on Linux
NOTES:          Header file for program
Modification    History:
Author                  Date            Version
------------------      -----------     -----------
Christopher Zinser      2020-11-09      v1
						2020-11-10      v2
						2020-11-11      Final
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

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstring>
using namespace std;

template <class T>
class Matrix
{
	protected:
		int rows;
		int cols;
		T **array;
	
	public:	
		Matrix();
		Matrix(int rows, int cols);
		Matrix(const Matrix<T>&);
		~Matrix();
		Matrix<T>& operator = (const Matrix<T> &);
		
		T get(int i, int j) const;
		
		void set(int i, int j, T k);
		void display();
		
		
		template<class T1>
		friend ostream& operator << (ostream &, const Matrix<T1> &);
		template<class T1>
		friend istream& operator >> (istream &, Matrix<T1> &);
		


};

	int open_file(ifstream &, string , int &);
	int write_file(ofstream & , string , int &);
	int arg_count( int , int , int &);


#endif

template <class T>
class Matrix_ops: public Matrix<T>
{
	private:
		using Matrix<T> :: rows;
		using Matrix<T> :: cols;
		using Matrix<T> :: array;
	public:
		using Matrix<T>:: Matrix;
		using Matrix<T> :: operator=;
		
	//	Matrix_ops(): Matrix<T>(){}
	//	Matrix_ops(int rows, int cols) : Matrix<T>(rows, cols) {}
	//	Matrix_ops(const Matrix_ops<T>&m);
		
		Matrix_ops<T> operator + (const Matrix_ops<T> &);
		Matrix_ops<T> operator * (const Matrix_ops<T> &);
		Matrix_ops<T> operator - (const Matrix_ops<T> &);
		Matrix_ops<T> operator / (const Matrix_ops<T> &);
		
		void inv(double n);
		void sub_mat(int,int);
		double det();
		
		Matrix_ops<T> operator * (int num);
		Matrix_ops<T> operator / (int num);

		
		
		bool operator == (const Matrix_ops<T> &);
};