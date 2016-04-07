#include <iostream>

using namespace std;

class Fib{
public:
	static int GetFib(int n){
		if(0==n || 1==n){
			return 1;
		}
		int a =1, b=1, c=0;
		for(int i=2; i<=n; ++i){
			c = a+b;
			a = b;
			b = c;
		}
		return c;
	}
};

int main(){
	int n;
	while(cin>>n){
		if(n<0){
			break;
		}
		cout<<n<<": "<<Fib::GetFib(n)<<endl;
	}
	return 0;
}