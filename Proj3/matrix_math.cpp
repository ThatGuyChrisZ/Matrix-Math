/*-------------------------------------------------------------------------------
FILE NAME:      matrix_math1.cpp
DESCRIPTION:    CS 202 - Proj 3
USAGE:          ./matrix_math1               // Interactive mode
COMPILER:       GNU g++ compiler on Linux
NOTES:          Driver for matrix program
Modification    History:
Author                  Date            Version
------------------      -----------     -----------
Christopher Zinser      2020-11-10      v1
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

#include "Matrix.cpp"

const char PROGRAMMER_NAME[] = "Christopher Zinser";

typedef unsigned char byte;

#define TYPE double
//#define TYPE int
//#define TYPE byte


/* -----------------------------------------------------------------------------
FUNCTION:          main
DESCRIPTION:       drives the program
RETURNS:           int
NOTES:             none
----------------------------------------------------------------------------- */

int main(int argc, char* argv[])
{
	int err = 0;
	ifstream infile1, infile2;
	ofstream outfile;
	string cmd, name;
	
	Matrix_ops<double> mat1, mat2, mat3;
	
	if(arg_count(argc, 2, err)) return err;
	
	while(--argc){
		cmd = *++argv;
		cout << "argc = " << argc << "  " << *argv << endl;
		
		if(cmd == "-inp"){
			if(arg_count(--argc, 1, err)) return err;
			name= *++argv;
			open_file(infile1, name, err);
			if(err) return err;
			cout<< "Entering File Read" << endl;
			infile1 >> mat1;
			cout<< "Outputting Mat1:" <<endl;
			cout<< mat1;

		}
		
		if(cmd == "-sub"){
			if(arg_count(--argc, 1, err)) return err;
			name= *++argv;
			open_file(infile1, name, err);
			if(err) return err;
			cout<< "Entering File Read" << endl;
			infile1 >> mat1;
			cout<< "Outputting Mat1:" <<endl;
			cout<< mat1;
			
			int i = atoi(*++argv);
			int j = atoi(*++argv);
			//cout<< "i = "<< i << "j ="<< j << endl;
			cout << "Submatrix: mat2" << endl;
			mat1.sub_mat(i,j);
			cout << mat1 << endl;
			//cout<< "exited" << endl;
			argc-=2;
			//cout<< "argc = "<< argc << endl;
			mat3 = mat1;
		

		}
		
		if(cmd == "-out"){
			cout<< "-out found" << endl;
			if(arg_count(--argc, 1, err)) return err;
			name = *++argv;
			write_file(outfile,name,err);
			if(err) return err;
		}
		
		if(argc >= 3){
			if(strcmp(argv[1],"+")==0 || strcmp(argv[1],"-")==0 || strcmp(argv[1],"x")==0 || strcmp(argv[1],"/")==0 || strcmp(argv[1],"==")==0){
				if(arg_count(--argc, 2 ,err)) return err;
				name = *argv;
				open_file(infile1, name, err);
				infile1 >> mat1;
				
	
	
	
				cmd = *++argv;
				char convert = cmd[0];
				cout << "cmd = " << cmd << endl;
				//cout << "convert = " << convert << endl;
				if(infile1){
					cout << "Input test: mat1" << endl;
					cout << mat1;
				}
			
				name = *++argv;
				open_file(infile2, name, err);
				if(infile2)
					infile2 >> mat2;
				--argc;
				//if(err) return err;
				if(infile2){
					cout << "Input test: mat2" << endl;
					cout << mat2;
					switch(convert){
						case '+':
							mat3=mat1+mat2;
							if(mat3 == mat1) return 0;
							cout<<"Addition: "<< endl<< mat3 << endl;
						break;
						
						case '-':
							mat3=mat1-mat2;
							if(mat3 == mat1) return 0;
							cout<<"Subtraction: "<< endl<< mat3 << endl;
						break;
						
						case '=':
							if(mat1 == mat2){
								cout<< "The matrixes are equal" << endl;
							}else{
								cout<< "The matrixes are not equal" << endl;
							}
						break;
							
						case 'x':
							mat3=mat1*mat2;
							if(mat3 == mat1) return 0;
							cout<<"Multiplication: "<< endl<< mat3 << endl;
						break;
							
						case '/':
							//mat3=mat1-mat2;
						break;
						
						
					}
				}else{
					switch(convert){						
						case 'x':
							mat3 = mat1 * (double)atoi(*argv);
							cout<<"Scalar Multiplication: "<< endl<< mat3 << endl;
						break;
						
						case '/':
							mat3 = mat1 / (double)atoi(*argv);
							cout<<"Scalar Division: "<< endl<< mat3 << endl;
						break;
						
						default:
							cout<< "Unknown Operation" << endl;
						break;
						
					}
				
				}
				if(err) return err;
			}else{
				cout<< "Unknown Operation" << endl;
				break;
			}
			//bef
		}else{
			if(argc == 1){
				if(strcmp(argv[0],"-h")==0){
					cout<< "Help Menu"<<endl;
					cout<< "$ stands for input"<< endl;
					cout<< "./matrix_math -inp $matrix reads input file"<<endl
						<<	"./matrix_math $cmds...-out $string write out result to named output file"<<endl
						<<	"./matrix_math $Matrix + $Matrix Read and add 2 matrix files and display result."<<endl
						<<	"./matrix_math $Matrix - $Matrix Read and subtract 2 matrix files and display result."<<endl
						<<	"./matrix_math $Matrix x $Matrix Read and multiply 2 matrix files and display result."<<endl
						<<	"./matrix_math $Matrix x $interger Read matrix file, multiply by n and display result."<<endl
						<<	"./matrix_math $Matrix / $interger Read matrix file, divide bynand display result."<<endl
						<<	"./matrix_math $Matrix == $Matrix Read 2 matrix files and test for equality."<<endl
						<<	"./matrix_math -sub $Matrix $interger $interger Get the submatrix of a matrix."<<endl;
						return 0;
				}
			}else{
				cout << "Unknown operation. Use ./matrix_math -h for help" << endl;
				return 0;


			}
		}
		
	}
	


	//double returned = mat2.det();
	//cout << "___________________________________________"<< endl;
	//cout<< returned << endl;
	
	
	
	//cout << "Copy constructor test: Matrix <T>mat4 = mat2;" << endl;
	//Matrix<double> mat4 = mat2;
	//cout << mat4;
	

	//if(outfile) outfile << mat4;
	if(outfile){
	outfile << mat3<<endl;
	outfile.close();
	}
	if(infile1){
	infile1.close();
	}
	if(infile2){
	infile2.close();
	}
	
	cout<< endl<<
	"Programmed by: "<< PROGRAMMER_NAME << " -- "<<
	__DATE__<<" "<<__TIME__ << endl;
	cout<< endl;
	
	return 0;
}

int open_file(ifstream &infile, string name, int & err){
	
		string filename = "DATA/";
		filename+= name;
		filename+=".mtx";
		infile.open(filename.c_str());
		
		if(!infile){
			cout<<  "\nError opening file: " << filename << "\n\n";
			err = 2;			
		}
		else cout << "Opened: " << filename << endl;
		
		return err;
}

int write_file(ofstream & outfile, string name, int &err){
	string filename= "DATA/";
	filename += name;
	filename += ".mtx";
	outfile.open(filename.c_str());
	
	if(!outfile){
		cout<< "\nError opening file: " << filename << "\n\n";
		err=2;
	}
	else cout << "Outpost: " << filename << endl;
	
	return err;
}



int arg_count( int argc, int num, int &err){
	if(argc < num){
		cout<< "Not enough Arguments ?\n\n";
		err=1;
	}
	return err;
}

