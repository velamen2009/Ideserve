#include <iostream>
#include <string>

using namespace std;

const int stack_size_step = 10;

template <typename T>
class MyStack{
public:
	MyStack():N(0){
		capacity = stack_size_step;
		data = new T[capacity];
	}
	~MyStack(){delete [] data;}
	void push(T t){
		if(isFull()){
			resize(capacity+stack_size_step);
		}
		data[N++]=t;
	}
	bool isFull(){
		return N==capacity?true:false;
	}
	int size(){
		return N;
	}
	int maxcap(){
		return capacity;
	}
	void resize(int max){
		capacity = max;
		T* a = new T[capacity];
		for(int n=0; n!=N; ++n){
			a[n] = data[n];
		}
		delete [] data;
		data = a;
	}
	T top() const{
		return data[N-1];
	}
	void pop(){
		if(0==N){
			cout<<"The stack is empty!"<<endl;
			return;
		}
		--N;
		if(N<capacity-stack_size_step){
			resize(capacity-stack_size_step);
		}
	}
private:
	T* data;
	int N;
	int capacity;

private:
	MyStack(const MyStack&);
	MyStack& operator=(const MyStack&);
};

int main(){
	string a[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
	MyStack<string> strStack;
	for(int i=0; i!=100; ++i){
		strStack.push("a");
		cout<<strStack.size()<<"\t"<<strStack.maxcap()<<endl;
	}
	
	for(int i=0; i!=100; ++i){
		strStack.pop();
		cout<<strStack.size()<<"\t"<<strStack.maxcap()<<endl;
	}
}