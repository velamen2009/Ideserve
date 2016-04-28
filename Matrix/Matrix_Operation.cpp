/*
Matrix operation
*/

#include<vector>
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <assert.h>     /* assert */

using namespace std;

class Matrix{
public:
	Matrix(int row, int col):_row(row),_col(col){
		p = new int*[_row];
		for(int i=0; i<_row; ++i){
			p[i] = new int[_row];

			for(int j=0; j<_col; ++j){
				p[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix& rhs){
		_row = rhs._row;
		_col = rhs._col;
		p = new int*[_row];
		for(int i=0; i<_row; ++i){
			p[i] = new int[_row];

			for(int j=0; j<_col; ++j){
				p[i][j] = rhs.p[i][j];
			}
		}
	}
	void accept(vector<int>& vec){
		for(int i=0; i<_row; ++i){
			for(int j=0; j<_col; ++j){
				p[i][j]=vec[i*_row+j]; 
			}
		}
	}
	void print(){
		for(int i=0; i<_row; ++i){
			for(int j=0; j<_col; ++j){
				cout<<p[i][j]<<" "; 
			}
			cout<<endl;
		}
		cout<<endl;
	}

	Matrix& operator+=(const Matrix& rhs){
		for(int i = 0; i < _row; i++){
			for(int j = 0; j < _col; j++){
				p[i][j] += rhs.p[i][j]; 
			} 
		}
		return *this;
	}
	Matrix& operator-=(const Matrix& rhs){
		for(int i = 0; i < _row; i++){
			for(int j = 0; j < _col; j++){
				p[i][j] -= rhs.p[i][j]; 
			} 
		}
		return *this;
	}
	friend Matrix& operator+ (Matrix& lhs, const Matrix& m1);
	friend Matrix& operator- (Matrix& lhs, const Matrix& m1);
	friend Matrix& operator* (const Matrix& lhs, const Matrix& m1);
private:
	int **p;
	int _row;
	int _col;
};

Matrix& operator+ (Matrix& lhs, const Matrix& m1){
	return (lhs += m1);
}
Matrix& operator- (Matrix& lhs, const Matrix& m1){
	return (lhs -= m1);
}

Matrix& operator* (const Matrix& lhs, const Matrix& m1){
	Matrix rt(lhs._row, m1._col);
	for(int i = 0; i < rt._row; i++){
		for(int j = 0; j < rt._col; j++){
			for(int k = 0; k < rt._col; ++k){
				rt.p[i][j] += lhs.p[i][k]*m1.p[k][j];
			}
		} 
	}
	return rt;
}

int main(){
	srand(time(NULL));
	vector<int> vec;
	int row = 2;
	int col = 2;
	for(int i=0; i<row; ++i){
		for(int j=0; j<col; ++j){
			vec.push_back(rand()%10);
		}
	}
	Matrix matrix1(row, col);
	matrix1.accept(vec);
	matrix1.print();
	
	Matrix matrix2(matrix1);
	(matrix1*matrix2).print();
	(matrix1+matrix2).print();
	matrix1.print();
	matrix2.print();
	return 0;
}
