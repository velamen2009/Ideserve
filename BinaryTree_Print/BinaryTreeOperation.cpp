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
	
	void print_tree(){
		int index = 0;
		int n = 0;
		int length = tree.size();
		cout<<length<<endl;
		while(index<length){
			for(int j=0; j<pow(2, n)&& index<length; ++j, ++index){
				if(tree[index]==0){
					cout<<"#"<<"\t";
				}
				else{
					cout<<tree[index]->data<<"\t";
				}
			}
			cout<<endl;
			++n;
		}
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
	
	void preorder(){
		_preorder(root);
		cout<<endl;
	}
	
	void preorder_norecursion(){
		stack<TreeNode<T>*> _stack;
		_stack.push(root);
		while(!_stack.empty()){
			TreeNode<T>* top = _stack.top();
			_stack.pop();
			cout<<top->data<<"\t";
			if(0!=top->right){
				_stack.push(top->right);
			}
			if(0!=top->left){
				_stack.push(top->left);
			}
		}
		cout<<endl;
	}
	
	void midorder(){
		_midorder(root);
		cout<<endl;
	}
	
	void midorder_norecursion(){
		stack<TreeNode<T>*> _stack;
		TreeNode<T>* node = root;
		while(!_stack.empty() || 0!=node){
			if(0!=node){
				_stack.push(node);
				node=node->left;
			}
			else{
				TreeNode<T>* top = _stack.top();
				_stack.pop();
				cout<<top->data<<"\t";
				node = top->right;
			}
		}
	}
	
	void postorder(){
		_postorder(root);
		cout<<endl;
	}
	
	void postorder_norecursion(){
		stack<TreeNode<T>*> _stack;
		TreeNode<T>* node = root;
		while(!_stack.empty()||0!=node){
			if(0!=node){
				_stack.push(node);
				node=node->right;
			}
			else{
				
			}
		}
	}
	
private:
	void _preorder(TreeNode<T>* node){
		if(0==node){
			return;
		}
		cout<<node->data<<"\t";
		_preorder(node->left);
		_preorder(node->right);
	}
	void _midorder(TreeNode<T>* node){
		if(0==node){return;}
		_midorder(node->left);
		cout<<node->data<<"\t";
		_midorder(node->right);
	}
	void _postorder(TreeNode<T>* node){
		if(0==node){return;}
		_postorder(node->left);
		_postorder(node->right);
		cout<<node->data<<"\t";
	}
private:
	TreeNode<T>* root;
	vector<TreeNode<T>*> tree;
};

int main(){
	int a[] = {1,2,3,4,-9999,5,6,-9999,-9999,-9999,-9999,-9999,7,8};
	vector<int> inVec;
	inVec.assign(a, a+sizeof(a)/sizeof(a[0]));
	BinaryTree<int> tree(inVec);
	tree.print_tree_graph();
	tree.preorder();
	tree.midorder();
	tree.postorder();
	tree.preorder_norecursion();
	tree.midorder_norecursion();
	
	return 0;
}