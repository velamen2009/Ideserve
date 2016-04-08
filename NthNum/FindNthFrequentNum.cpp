/*
Given an array of numbers and a positive integer 'n', find 'n'th most frequent occurring number in that array. If there are more than one numbers which are occurring 'n'th most frequently, then you can return any one of such integers.

Example:  For the input array {1,2,2,2,4,4,4,4,5,5,5,5,5,7,7,8,8,8,8}
if n = 1, then the output returned should be 5 because it is the most frequent number,
if n = 2, output can be either 4 or 8 since any of these numbers could be considered as the 2nd most frequent number,
if n = 3, again output can be either 4 or 8
if n = 4, output should be 2.
*/

#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

bool Compare(pair<int, int> it1, pair<int, int> it2){
	return it1.second > it2.second;
}

class FindNthNum{
public:
	FindNthNum(vector<int>& inVec){
		map<int,int>::iterator it;
		for(vector<int>::iterator itVec = inVec.begin(); itVec!=inVec.end(); ++itVec){
			it=_map.find(*itVec);
			if(it!=_map.end()){
				_map[*itVec]++;
			}
			else{
				_map.insert(pair<int, int>(*itVec, 1));
			}
		}
		for(map<int,int>::iterator it=_map.begin(); it!=_map.end(); ++it){
			_vec.push_back(pair<int, int>(it->first, it->second));
		}
		sort(_vec.begin(), _vec.end(), Compare);
	}
	void Print(){
		for(map<int,int>::iterator it=_map.begin(); it!=_map.end(); ++it){
			cout<<it->first<<"\t"<<"=>"<<"\t"<<it->second<<endl;
		}
	}
	int Find(int n){
		if(n<1 || n>_vec.size()){
			return -1;
		}
		else{
			return _vec[n-1].first;
		}
		return -1;
	}
private:
	map<int, int> _map;
	vector<pair<int, int> > _vec;
};

int main(){
	srand(time(NULL));
	vector<int> iVec;
	for(int i=0; i<20; ++i){
		iVec.push_back(rand()%10);
	}
	
	FindNthNum f(iVec);
	f.Print();
	for(int i=0; i<20; ++i){
		cout<<"The "<<i<<"th number is: "<<f.Find(i)<<endl;
	}
	return 0;
}