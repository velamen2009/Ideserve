/*
Example: 
Input: 1->7->9->9->9->null(number 99971), 8->9->9->null(number 998).
Output: 9->6->9->0->0->1->null(number 100969)
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <list>

using namespace std;

class SumTwoLinkedList{
public:
	static int AddList(list<int>& list1, list<int>& list2){
		list<int> rtList;
		int length = list1.size()>=list2.size()?list1.size():list2.size();
		int carry = 0;

		list<int>::iterator it1 = list1.begin();
		list<int>::iterator it2 = list2.begin();
		
		for(int i=0; i<length; ++i){
			int value = 0;
			value += carry;
			if(it1!=list1.end()){
				value += *it1;
				++it1;
			}
			if(it2!=list2.end()){
				value += *it2;
				++it2;
			}
			rtList.push_back(value%10);
			carry = value/10;
		}
		if(carry>0){
			rtList.push_back(carry);
		}
		list<int>::iterator it3 = rtList.begin();
		while(it3!=rtList.end()){
			cout<<*it3<<"\t";
			++it3;
		}
		return 0;
	}
};

int main(){
	int a[] = {1,7,9,9,9};
	int b[] = {8,9,9};
	list<int> list1(a,a+5);
	list<int> list2(b,b+3);
	SumTwoLinkedList::AddList(list1, list2);
}
