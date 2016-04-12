#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename T>
class Sort{
public:
	Sort(vector<T>& inVec, bool(*comp)(const T&, const T&), void(*swap)(T&,T&)):_pVec(&inVec), cmp(comp), swp(swap){}
	void display(){
		typename vector<T>::iterator it;
		for(it = _pVec->begin(); it!=_pVec->end(); ++it){
			cout<<*it<<"\t";
		}
		cout<<endl;
	}
public:
	void sort_selection(){
		int N = _pVec->size();
		for(int i=0; i<N; ++i){
			int min = i;
			for(int j=i+1; j<N; ++j){
				if(cmp((*_pVec)[min], (*_pVec)[j])){
					min = j;
				}
			}
			swp((*_pVec)[i], (*_pVec)[min]);
		}
	}
	
	void sort_insert(){
		int N = _pVec->size();
		for(int i=1; i<N; ++i){
			for(int j=i; j>0&&cmp((*_pVec)[j-1], (*_pVec)[j]); --j){
				swp((*_pVec)[j], (*_pVec)[j-1]);
			}
		}
	}
	
	void sort_shell(){
		int N = _pVec->size();
		int h = 1;
		while(h<N){
			h=3*h+1;
		}
		while(h>=1){
			for(int i=h; i<N; ++i){
				for(int j=i; j>=h&&cmp((*_pVec)[j-h], (*_pVec)[j]); j-=h){
					swp((*_pVec)[j], (*_pVec)[j-h]);
				}
			}
			h/=3;
		}
	}
	
	void sort_topdown_merge(){
		auxVec.clear();
		for(int i=0; i!=_pVec->size(); ++i){
			auxVec.push_back((*_pVec)[i]);
		}
		_sort_topdown_merge(0, _pVec->size()-1);
	}
	
	void sort_bottomup_merge(){
		auxVec.clear();
		for(int i=0; i!=_pVec->size(); ++i){
			auxVec.push_back((*_pVec)[i]);
		}
		_sort_bottomup_merge();
	}
	
	void sort_quick(){
		_quick_sort(0, _pVec->size()-1);
	}
	
	void sort_heap(){
		int i = _pVec->size()/2-1;
		while(i>=0){
			Sink(i, _pVec->size());
			--i;
		}
		for(int j=_pVec->size()-1; j>0; --j){
			swp((*_pVec)[0],(*_pVec)[j]);
			Sink(0, j);
		}
	}
private:
	void _sort_topdown_merge(int lo, int hi){
		if(hi<=lo){
			return;
		}
		int mid = (hi+lo)/2;
		_sort_topdown_merge(lo, mid);
		_sort_topdown_merge(mid+1, hi);
		top_down_merge(lo, mid, hi);
	}
	
	void top_down_merge(int lo, int mid, int hi){
		int i=lo, j=mid+1;;
		for(int k=lo; k<=hi; ++k){
			//if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
			if(i<=mid && (j>hi||cmp(auxVec[j], auxVec[i]))){
				(*_pVec)[k] = auxVec[i++];
			}
			else{
				(*_pVec)[k] = auxVec[j++];
			}
		}
		for(int k=lo; k<=hi; ++k){
			auxVec[k]=(*_pVec)[k];
		}
	}
	
	void _sort_bottomup_merge(){
		for(int sz=1; sz<_pVec->size(); sz*=2){
			for(int lo=0; lo<_pVec->size()-sz; lo+=2*sz){
				int hi = (_pVec->size()-1 < lo+2*sz-1) ? _pVec->size()-1 : lo+2*sz-1;
				int i=lo;
				int mid = lo+sz-1;
				int j=lo+sz;
				for(int k=lo; k<=hi; ++k){
					if(i<=mid && (j>hi||cmp(auxVec[j], auxVec[i]))){
						(*_pVec)[k] = auxVec[i++];
					}
					else{
						(*_pVec)[k] = auxVec[j++];
					}
				}
				for(int k=lo; k<=hi; ++k){
					auxVec[k]=(*_pVec)[k];
				}
			}
		}
	}
	
	void _quick_sort(int lo, int hi){
		if(hi-lo<1){return;}
		int pivot_index = partition_idx(lo, hi);
		_quick_sort(lo, pivot_index-1);
		_quick_sort(pivot_index+1, hi);
	}
	
	int partition_idx(int lo, int hi){
		int idx = rand()%(hi-lo)+lo;
		T pivot = (*_pVec)[idx];
		swp((*_pVec)[lo], (*_pVec)[idx]);
		int i=lo+1;
		for(int j=i; j<=hi; ++j){
			if(cmp(pivot,(*_pVec)[j])){
				swp((*_pVec)[i],(*_pVec)[j]);
				++i;
			}
		}
		swp((*_pVec)[lo], (*_pVec)[i-1]);
		return i-1;
	}

	void Sink(int i, int size){
		while(2*i+1<size){
			int j=2*i+1;
			if(j+1<size&&cmp((*_pVec)[j+1],(*_pVec)[j])){
				++j;
			}
			if(cmp((*_pVec)[j],(*_pVec)[i])){
				swp((*_pVec)[j],(*_pVec)[i]);
			}
			i=j;
		}
	}
	
private:
	vector<T>* _pVec;
	vector<T> auxVec;
	void(*swp)(T&, T&);
	bool(*cmp)(const T&, const T&);
};

void swap(int& i, int& j){
	int temp = i;
	i = j;
	j = temp;
}

bool compare(const int& i, const int& j){
	return i>j;
}

void makeArray(vector<int>& inVec){
	inVec.clear();
	for(int i=0; i<10; ++i){
		inVec.push_back(rand()%100);
	}
}

int main(){
	srand(time(NULL));
	vector<int> iVec;
	Sort<int> sort(iVec, compare, swap);
	
	//Selection Sort
	makeArray(iVec);
	cout<<"Before selection sort:\n";
	sort.display();
	cout<<"After selection sort:\n";
	sort.sort_selection();
	sort.display();
	
	//Insert Sort
	makeArray(iVec);
	cout<<"Before insert sort:\n";
	sort.display();
	cout<<"After insert sort:\n";
	sort.sort_insert();
	sort.display();
	
	//Shell Sort
	makeArray(iVec);
	cout<<"Before shell sort:\n";
	sort.display();
	cout<<"After shell sort:\n";
	sort.sort_shell();
	sort.display();
	
	//Merge Sort Top Down
	makeArray(iVec);
	cout<<"Before merge sort top-down:\n";
	sort.display();
	cout<<"After merge sort top-down:\n";
	sort.sort_topdown_merge();
	sort.display();
	
	//Merge Sort Bottom Up
	makeArray(iVec);
	cout<<"Before merge sort bottom-up:\n";
	sort.display();
	cout<<"After merge sort bottom-up:\n";
	sort.sort_bottomup_merge();
	sort.display();
	
	//Quick Sort
	//int a[] = {1, 32, 31, 59, 43, 48, 57, 7, 84, 63};
	makeArray(iVec);
	//iVec.assign(a, a1+10);
	cout<<"Before quick sort:\n";
	sort.display();
	cout<<"After quick sort:\n";
	sort.sort_quick();
	sort.display();
	
	makeArray(iVec);
	cout<<"Before heap sort:\n";
	sort.display();
	cout<<"After heap sort:\n";
	sort.sort_heap();
	sort.display();
}