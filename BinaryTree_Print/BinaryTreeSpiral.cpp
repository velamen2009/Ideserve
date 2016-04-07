#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

const int invalid = -9999;

template <typename T>
struct TreeNode{
	TreeNode():left(0), right(0){}
	T data;
	TreeNode* left;
	TreeNode* right;
};

template <typename T>
class BinaryTree{
public:
	BinaryTree(vector<T> invec){
		if(invec.size()==0){
			root = 0;
			return;
		}
		for(int i=0; i<invec.size(); ++i){
			if(invec[i] == invalid){
				tree.push_back(0);
				continue;
			}
			TreeNode<T>* p = new TreeNode<T>();
			p->data = invec[i];
			tree.push_back(p);
			int parentindex = (i-1)/2;
			if(parentindex>=0){
				TreeNode<T>* parent = tree[parentindex];
				if(i%2==0){
					parent->right = p;
				}
				else{
					parent->left = p;
				}
			}
		}
		root = tree[0];
	}
	void print_tree_graph(){
		int depth = (int)log2(tree.size())+1;
		cout<<"The depth of the tree is: "<<depth<<endl;
		int length = tree.size();
		int index=0;
		for(int n=0; n<depth; ++n){
			int space = pow(2, depth-n-1)-1;
			int interval = pow(2, depth-n)-1;
			for(int s=0; s<space; ++s){
				cout<<" ";
			}
			for(int j=0; j<pow(2,n)&&index<length; ++j, ++index){
				if(tree[index]==0){
					cout<<"#";
				}
				else{
					cout<<tree[index]->data;
				}
				for(int i=0; i<interval; ++i){
					cout<<" ";
				}
			}
			cout<<endl;
		}
	}
	void spiralLevelOrder(){
		stack<TreeNode<T>*> evenStack;
		stack<TreeNode<T>*> oddStack;
		TreeNode<T>* node = root;
		evenStack.push(node);
		while(!evenStack.empty() || !oddStack.empty()){
			while(!evenStack.empty()){
				node = evenStack.top();
				cout<<node->data<<"\t";
				if(0!=node->right){
					oddStack.push(node->right);
				}
				if(0!=node->left){
					oddStack.push(node->left);
				}
				evenStack.pop();
			}
			while(!oddStack.empty()){
				node = oddStack.top();
				cout<<node->data<<"\t";
				if(0!=node->left){
					evenStack.push(node->left);
				}
				if(0!=node->left){
					evenStack.push(node->right);
				}
				oddStack.pop();
			}
		}
		cout<<endl;
	}
	
private:

private:
	TreeNode<T>* root;
	vector<TreeNode<T>*> tree;
};

int main(){
	int a[] = {0,1,2,4,5,3,6,-9999,-9999,7,8,-9999,-9999,9};
	vector<int> inVec;
	inVec.assign(a, a+sizeof(a)/sizeof(a[0]));
	BinaryTree<int> tree(inVec);
	tree.print_tree_graph();
	tree.spiralLevelOrder();
	
	return 0;
}