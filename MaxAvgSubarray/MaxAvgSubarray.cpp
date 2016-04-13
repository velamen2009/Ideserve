/*
Given an integer array and a number k, print the maximum sum subarray of size k.
Maximum average subarray of size k is a subarray (sequence of contiguous elements in the array) for which the average is maximum among all subarrays of size k in the array.
Average of k elements = (sum of k elements)/k
Since k > 0, the maximum sum subarray of size k will also be maximum average subarray of size k. So, the problem reduces to finding maximum sum subarray of size k in the array.
*/

//http://www.ideserve.co.in/learn/maximum-average-subarray

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class MaxAvgSubarray{
public:
	static vector<int> MaxSubArray(int k, vector<int>& iVec){
		vector<int> rtVec;
		int sum = 0;
		int max = 0;
		int maxindex = 0;
		for(int i=0; i<k; ++i){
			max+=iVec[i];
		}
		sum=max;
		for(int j=k; j<iVec.size(); ++j){
			sum-=iVec[j-k];
			sum+=iVec[j];
			if(sum>max){
				max=sum;
				maxindex = j-k+1;
			}
		}
		for(int i=0; i<k; ++i){
			rtVec.push_back(iVec[maxindex+i]);
		}
		return rtVec;
	}
};

int main(){
	srand(time(NULL));
	vector<int> iVec;
	for(int i=0; i<10; ++i){
		int value = rand()%10-5;
		iVec.push_back(value);
		cout<<value<<"\t";
	}
	cout<<endl;
	int k=3;
	vector<int> vec = MaxAvgSubarray::MaxSubArray(3, iVec);
	for(int i=0; i<vec.size(); ++i){
		cout<<vec[i]<<"\t";
	}
	cout<<endl;
	return 0;
}