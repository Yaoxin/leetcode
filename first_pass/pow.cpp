#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
    	if(n == 0)
    	{
    		return 1;
    	}
    	if(n < 0)
    	{
    		n = - n;
    		x = 1 / x;
    	}

    	double pow = 1;
    	while(n)
    	{
    		if(n % 2 == 1)
    		{
    			pow *= x;
    		}
    		x *= x;
    		n /= 2;
    	}

    	return pow;

    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	//double a = s.myPow(2, 3);
	double a = s.myPow(2, 3);
	cout << a << endl;
	return 0;
}