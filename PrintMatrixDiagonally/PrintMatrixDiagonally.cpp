#include <iostream>
#include <vector>

using namespace std;

class PrintMatrixDiagonally{
public:
	PrintMatrixDiagonally(int m, int n):inRow(m), inCol(n), outRow(m-1+n), outCol(m){
		for(int i=1; i<=m*n; ++i){
			inMatrix.push_back(i);
		}
		for(int i=0; i<outRow*outCol; ++i){
			outMatrix.push_back(0);
		}
	}
	
	void solution(){
		int newRow = 0;
		int newCol = 0;
		int colMax = inRow;
		
		for(int iRow=0; iRow<inRow; ++iRow){
			colMax -= 1;
			for(int iCol=0; iCol<inCol; ++iCol){
				int value = inMatrix[iRow*inCol+iCol];
				newRow = iRow+iCol;
				newCol = iCol;
				if(newCol>colMax){
					newCol = colMax;
				}
				outMatrix[newRow*outCol+newCol] = value;
			}
		}
	}
	
	void pintMatrix(){
		cout<<"The input matrix is: \n";
		for(int i=0; i<inRow; ++i){
			for(int j=0; j<inCol; ++j){
				cout<<inMatrix[i*inCol+j]<<"\t";
			}
			cout<<endl;
		}
		
		cout<<"The output matrix is: \n";
		for(int i=0; i<outRow; ++i){
			for(int j=0; j<outCol; ++j){
				if(outMatrix[i*outCol+j]==0){
					cout<<"*"<<"\t";
				}
				else{
					cout<<outMatrix[i*outCol+j]<<"\t";
				}
			}
			cout<<endl;
		}
	}

private:
	int inRow;
	int inCol;
	int outRow;
	int outCol;
	vector<int> inMatrix;
	vector<int> outMatrix;
};

int main(){
	PrintMatrixDiagonally pM(4,5);
	pM.solution();
	pM.pintMatrix();
	return 0;
}