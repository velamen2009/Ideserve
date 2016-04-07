#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int>& ivec, const int& val, int lo, int hi){
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(val<ivec[mid]){
			hi=mid-1;
		}
		else if(val>ivec[mid]){
			lo=mid+1;
		}
		else{
			return mid;
		}
	}
	return -1;
}
int main(){
	srand(time(NULL));
	vector<int> iVec;
	for(int i=0; i!=10; ++i){
		iVec.push_back(rand()%100+1);
	}
	sort(iVec.begin(), iVec.end());
	for(int j=0; j!=iVec.size(); ++j){
		cout<<iVec[j]<<"\t";
	}
	cout<<endl;
	int val = iVec.at(rand()%10);
	int index = BinarySearch(iVec, val, 0, iVec.size()-1);
	cout<<"The value "<<val<<" is at index: "<<index<<endl;
	return 0;
}