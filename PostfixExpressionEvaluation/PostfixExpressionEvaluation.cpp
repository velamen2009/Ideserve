/*
Evaluate the value of a Postfix expression, also known as expression in Reverse Polish Notation.
Given: An array of strings, every string being either an operand or an operator, in Reverse Polish Notation, find out the value of the expression.

Assumptions: The given postfix expression will be a valid expression.
1. String operands will be valid Integers (positive or negative)
2. Operators will be valid operators in: + - / *
3. 0 will not be passed as a divisor for division operation.

Example:
Input:
20    30    +
Output: 
50

Input:
5    1    2    +    4    *    +    3    -
Output: 
14

Note: Input is an array of strings to allow numbers with multiple digits as operands.
For example "20", "45" etc.
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class PostfixExpressionEvalution{
public:
	static void Evalution(vector<string>& inVec){
		stack<int> st;
		for(int i=0; i<inVec.size(); ++i){
			cout<<inVec[i];
			string op = inVec[i];
			if(op=="+" || op=="-" || op=="*" || op=="/"){
				int val1 = st.top();
				st.pop();
				int val2 = st.top();
				st.pop();
				if("+"==op){st.push(val2+val1);}
				if("-"==op){st.push(val2-val1);}
				if("*"==op){st.push(val2*val1);}
				if("/"==op){st.push(val2/val1);}
			}
			else{
				st.push(atoi(op.c_str()));
			}
		}
		cout<<" = "<<st.top()<<endl;
	}
	
	static void Evalution2(vector<string>& inVec){
		stack<int> st;
		int result=0;
		string exp="";
		char buffer [33];
		for(int i=0; i<inVec.size(); ++i){
			string op = inVec[i];
			if(op=="+" || op=="-" || op=="*" || op=="/"){
				int val1 = st.top();
				st.pop();

				if(""==exp){
					int val2 = st.top();
					st.pop();
					if("+"==op){
						result=val2+val1;
						exp=string(itoa(val2,buffer,10))+"+"+string(itoa(val1,buffer,10));
					}
					if("-"==op){
						result=val2-val1;
						exp=string(itoa(val2,buffer,10))+"-"+string(itoa(val1,buffer,10));
					}
					if("*"==op){
						result=val2*val1;
						exp=string(itoa(val2,buffer,10))+"*"+string(itoa(val1,buffer,10));
					}
					if("/"==op){
						result=val2/val1;
						exp=string(itoa(val2,buffer,10))+"/"+string(itoa(val1,buffer,10));
					}
				}
				else{
					if("+"==op){
						result+=val1;
						exp=exp+"+"+string(itoa(val1,buffer,10));;
					}
					if("-"==op){
						result-=val1;
						exp=exp+"-"+string(itoa(val1,buffer,10));;
					}
					if("*"==op){
						result*=val1;
						exp="("+exp+")"+"*"+string(itoa(val1,buffer,10));;
					}
					if("/"==op){
						result/=val1;
						exp="("+exp+")"+"/"+string(itoa(val1,buffer,10));;
					}
				}
			}
			else{
				st.push(atoi(op.c_str()));
			}
		}
		cout<<exp<<" = "<<result<<endl;
	}
};

int main(){
	string a[] = {"5", "1","2","+","4","*","+","3","-"};
	vector<string> inVec(a, a+sizeof(a)/sizeof(a[0]));
	PostfixExpressionEvalution::Evalution(inVec);
	
	PostfixExpressionEvalution::Evalution2(inVec);
	return 0;
}