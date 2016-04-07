#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(){
	string str = "(1+((2*3)*(4/5)))";
	string strs[] = {"(", "1", "+", "(", "(", "2", "*", "3", ")", "*", "(", "4", "/", "5", ")", ")", ")"};
	stack<string> ops;
	stack<float> vals;
	float result=0;
	
	for(int i=0; i!=sizeof(strs)/sizeof(strs[0]); ++i){
		if("+"==strs[i] || "-"==strs[i] || "*"==strs[i] ||"/"==strs[i]){
			ops.push(strs[i]);
		}
		else if(strs[i]=="("){
			continue;
		}
		else if(")"==strs[i]){
			string op = ops.top();
			ops.pop();
			float val1 = vals.top();
			vals.pop();
			float val2 = vals.top();
			vals.pop();
			if("+"==op){ 
				result = val1+val2;
			}
			else if("-"==op){ 
				result = val1-val2;
			}
			else if("*"==op){ 
				result = val1*val2;
			}
			else if("/"==op){ 
				result = val2/val1;
			}
			vals.push(result);
		}
		else{
			vals.push(atof(strs[i].c_str()));
		}
	}
	cout<<"The result of "<<str<<" is: "<<result<<endl;	
	return 0;
}