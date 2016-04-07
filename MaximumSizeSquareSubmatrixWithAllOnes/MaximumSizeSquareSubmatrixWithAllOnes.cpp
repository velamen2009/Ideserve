#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class MaximumSizeSquareSubmatrixWithAllOnes{
public:
	MaximumSizeSquareSubmatrixWithAllOnes(int m, int n):inRow(m), inCol(n){
		srand(time(NULL));
		for(int i=0; i<m*n; ++i){
			inVec.push_back(rand()%2);
			countVec.push_back(0);
		}
	}
	
	int maxSize(){
		int maxSize = 0;
		for(int i=0; i<inRow; ++i){
			for(int j=0; j<inCol; ++j){
				if(i==0 || j==0){
					countVec[i*inRow+j] = inVec[i*inRow+j];
					maxSize = maxSize>countVec[i*inRow+j] ? maxSize : countVec[i*inRow+j];
				}
				else if(inVec[i*inRow+j]==0){
					countVec[i*inRow+j] = inVec[i*inRow+j];
				}
				else{
					countVec[i*inRow+j] = 1 + min(
						countVec[(i-1)*inRow+(j-1)]
						,countVec[(i-1)*inRow+j]
						,countVec[i*inRow+(j-1)]
					);
					maxSize = maxSize>countVec[i*inRow+j] ? maxSize : countVec[i*inRow+j];
				}
			}
		}
		return maxSize;
	}
	
	int min(int a, int b, int c){
		return (a<=b && a<=c) ? a : (b<c ? b : c);
	}
	
	void printMatrix(){
		for(int i=0; i<inRow; ++i){
			for(int j=-0; j<inCol; ++j){
				cout<<inVec[i*inRow+j]<<"\t";
			}
			cout<<endl;
		}
	}
	
private:
	int inRow;
	int inCol;
	vector<int> inVec;
	vector<int> countVec;
};

int main(){
	MaximumSizeSquareSubmatrixWithAllOnes Mones(6,6);
	Mones.printMatrix();
	cout<<"The max ones matrix size is:\n"<<Mones.maxSize()<<endl;
	return 0;
}