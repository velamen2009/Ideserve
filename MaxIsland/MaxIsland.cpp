#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class MaxIsland{
public:
	MaxIsland(int m, int n):inRow(m), inCol(n){
		srand(time(NULL));
		for(int i=0; i<m*n; ++i){
			inVec.push_back(rand()%2);
			countVec.push_back(0);
		}
	}
	
	int maxIslandNum(){
		int maxSize = 0;
		for(int i=0; i<inRow; ++i){
			for(int j=-0; j<inCol; ++j){
				if(countVec[i*inRow+j]==1 || inVec[i*inRow+j]==0){
					continue;
				}
				else
				{
					setVisited(i, j);
					++maxSize;
				}
			}
		}
		return maxSize;
	}
	
	void setVisited(int row, int col){
		for(int i=row-1; i<=row+1; ++i){
			if(i<0 || i>=inRow){
				continue;
			}
			for(int j=col-1; j<=col+1; ++j){
				if(j<0 || j>=inCol){
					continue;
				}
				if(inVec[i*inRow+j]==0 || countVec[i*inRow+j]==1){
					continue;
				}
				countVec[i*inRow+j]=1;
				setVisited(i, j);
			}
		}
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
	MaxIsland Mones(6,6);
	Mones.printMatrix();
	cout<<"The number of islands is:\n"<<Mones.maxIslandNum()<<endl;
	return 0;
}