/*
Write a program that takes from standard input an expression without left parentheses
and prints the equivalent infix expression with the parentheses inserted. For
example, given the input:
1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )
your program should print
( ( 1 + 2 ) * ( ( 3 - 4 ) * ( 5 - 6 ) )
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
	string str = "1+2)*3-4)*5-6)))";
	string strs[] = {"1", "+", "2", ")", "*", "3", "-", "4", ")", "*", "5", "-", "6", ")", ")", ")"};
	stack<string> ops;
	stack<string> vals;
	
	for(int i=0; i!=sizeof(strs)/sizeof(strs[0]); ++i){
		if("+"==strs[i] || "-"==strs[i] || "*"==strs[i] ||"/"==strs[i]){
			ops.push(strs[i]);
		}
		else if(")"==strs[i]){
			string op = ops.top();
			ops.pop();
			string val1 = vals.top();
			vals.pop();
			string val2 = vals.top();
			vals.pop();
			vals.push("("+val2+op+val1+strs[i]);
		}
		else{
			vals.push(strs[i]);
		}
	}
	cout<<vals.top()<<endl;
	return 0;
}