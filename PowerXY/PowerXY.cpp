/*
Given a positive integer, find if it can be expressed by integers x and y as x^y where
y > 1 and x > 0.
Please check out another solution to the problem here:
Check if a number can be expressed as x raised to power y | Set 1

Example:
Consider the number: 125
Since 125 can be written as x^y where x = 5, y = 3, so return true.
Consider the number: 120
As 120 cannot be expressed as x^y for any integers x > 0 and y > 1, so return false.
*/

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

class PowerXY{
public:
	static bool Power(int z){
		int max = (int)sqrt(z);
		for(int x=2; x<=max; ++x){
			int left = z;
			int y=0;
			while(left>=x){
				if(0==left%x){
					left/=x;
					++y;
				}
				else{
					break;
				}
			}
			if(1==left){
				cout<<x<<"^"<<y<<" = "<<z<<endl;
				return true;
			}
		}
		cout<<"No x^y = "<<z<<endl;
		return false;
	}
	/*
Instead of repeated divisions as given in previous method, we can apply mathematical formula as described:
Given a number a, we have to find integers x and y, such that:
     a = x^y
If we take log on both sides, we get:
     log a = log (x^y)
     log a = y log x
     y = log a / log x
Hence, we have to find an integer x for which RHS gives an integer y.

Algorithm:
1: Starting with i = 2, if (log a / log i) is an integer then return true.
2: Else increment i by 1 till i < √a.
3: If no such i is found, return false.
	*/
	static bool isPowerMath(int z){
		 for (int i = 2; i <= sqrt(z); ++i) {
            double value = log2(z) / log2(i);
            if ((value - (int) value) < 0.000000001) {
                return true;
            }
        }
        return false;
	}
}; 

int main(){
	srand(time(NULL));
	PowerXY::Power(125);
	PowerXY::Power(120);
	for(int i=0; i<10; ++i){
		PowerXY::Power(rand()%200);
	}
	return 0;
}