#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class WeightedUnion{
	public:
		WeightedUnion(int n){
			id = new int[n];
			sz = new int[n];
			for(int i=0; i!=n; ++i){
				id[i] = i;
				sz[i] = 1;
			}
			count = n;
		}
		~WeightedUnion(){
			delete [] id;
			delete [] sz;
		}
		int size(){
			return count;
		}
		bool isConnected(const int& p, const int& q){
			return find(p)==find(q);
		}
		void unionComponnet(int p, int q){
			int i=find(p);
			int j=find(q);
			if(i==j){return;}
			if(sz[i]<=sz[j]){
				id[i]=j;
				sz[j]+=sz[i];
			}
			else
			{
				id[j]=i;
				sz[i]+=sz[j];
			}
			count--;
		}
	private:
		WeightedUnion(const WeightedUnion& rhs);
		WeightedUnion& operator=(const WeightedUnion& rhs);
		int find(int p){
			while(p!=id[p]){
				p = id[p];
			}
			return p;
		}
	private:
		int count;
		int* id;
		int* sz;
};

int main(int argc, char* argv[]){
	int cnt = atoi(argv[1]);
	srand(time(NULL));
	WeightedUnion wu(100);
	for(int i=0; i!=cnt; ++i){
		int p=rand()%100;
		int q=rand()%100;
		wu.unionComponnet(p, q);
		cout<<"<"<<p<<", "<<q<<">"<<endl;
	}
	cout<<wu.size();
	return 0;
}


//