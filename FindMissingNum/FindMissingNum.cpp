/*
Given an increasing sequence of numbers from 1 to n with only one missing number, how can you find that missing number without traversing the sequence in linear fashion. In other words, time complexity of your algorithm must be less than O(n)?

For example, if the given sequence is 1,2,4,5,6,7,8 then the missing number is 3. If the given sequence is 1,3,4,5 then the missing number is 2. For the input 2,3,4,5 output returned should be 1 as it is the missing number.
*/

#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main(){
	vector<int> inVec;
	for(int i=0; i<100; ++i){
		inVec.push_back(i);
	}
	srand(time(NULL));
	int removed = rand()%100;
	cout<<"The removed index is: "<<removed<<endl;
	inVec.erase(inVec.begin()+removed);
	
	int lo=0;
	int mid=0;
	int hi=inVec.size()-1;
	while(lo<=hi){
		mid=(hi+lo)/2;
		if(mid<inVec[mid]&&mid-1==inVec[mid-1]){
			break;
		}
		else if(mid==inVec[mid]&&mid+1<inVec[mid+1]){
			++mid;
			break;
		}
		else if(mid<inVec[mid]){
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
	
	if(mid==removed){
		cout<<"Found!"<<endl;
	}
	return 0;
}
