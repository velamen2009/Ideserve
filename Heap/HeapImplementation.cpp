#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

template <typename T>
struct Node{
	T value;
};

template <typename T>
class Heap{
public:
	Heap(){}
	Heap(T a[], int length){
		for(int i=0; i<length; ++i){
			Node<T> node;
			node.value = a[i];
			data.push_back(node);
		}
		for(int i=length/2-1; i>=0; --i){
			Sink(i, length);
		}
		cout<<"constructing...:"<<endl;
		print_tree_graph();
	}
	void Insert(T value){
		cout<<"Inserting: "<<endl;;
		Node<T> node;
		node.value = value;
		data.push_back(node);
		Swim(data.size()-1);
		print_tree_graph();
	}
	void Change(int k, T value){
		if(k<0 || k>data.size()-1){
			return;
		}
		cout<<"Changing..:"<<endl;
		data[k].value = value;
		Swim(k);
		Sink(k, data.size());
		print_tree_graph();
	}
	void Remove(){
		cout<<"Removing max: "<<endl;
		Swap(0, data.size()-1);
		data.erase(data.begin()+data.size()-1);
		Sink(0, data.size());
		print_tree_graph();
	}
	bool Empty(){data.Empty();}
	int Size(){ return data.size();}
	void Sort(){
		for(int i=data.size()-1; i>0; --i){
			Swap(0, i);
			Sink(0, i);
		}
		print_tree_graph();
	}
	void print_tree_graph(){
		int depth = (int)log2(data.size())+1;
		//cout<<"The depth of the tree is: "<<depth<<endl;
		int length = data.size();
		int index=0;
		for(int n=0; n<depth; ++n){
			int space = pow(2, depth-n-1)-1;
			int interval = pow(2, depth-n)-1;
			for(int s=0; s<space; ++s){
				cout<<" ";
			}
			for(int j=0; j<pow(2,n)&&index<length; ++j, ++index){
				cout<<data[index].value;
				for(int i=0; i<interval; ++i){
					cout<<" ";
				}
			}
			cout<<endl;
		}
	}
private:
	void Swim(int k){
		while(k>0){
			if(Compare(k, (k-1)/2)){
				Swap(k, (k-1)/2);
			}
			k=(k-1)/2;
		}
	}
	void Sink(int k, int size){
		while(2*k+1<size){
			int j=2*k+1;
			if(j+1<size&&Compare(j+1,j)){
				++j;
			}
			if(Compare(j, k)){
				Swap(k,j);
			}
			k=j;
		}
	}
	bool Compare(int i, int j){
		return data[i].value > data[j].value;
	}
	void Swap(int i, int j){
		Node<T> temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}
private:
	vector<Node<T> > data;
};

int main(){
	int a[10] = {1,3,5,7,9,2,4,6,8,0};
	Heap<int> iHeap(a,10);
	iHeap.Insert(10);
	iHeap.Remove();
	iHeap.Change(8, 99);
	//iHeap.Sort();
	return 0;
}