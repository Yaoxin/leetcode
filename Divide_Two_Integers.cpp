#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <cstdlib>


using namespace std;

class Solution {
public:
	//任何一个整数都可以转换成2的幂为底的一组线性组合
	//num = a_0 * 2^0 + a_1 * 2^1 + ... + a_n * 2^n

    long divide(int dividend, int divisor) {
    	if(divisor == 0 || (dividend == -2147483648 && divisor == -1))
    		return INT_MAX;

    	bool isneg = false;
    	if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
    	{
    		isneg = true;
    	}
    	long long up = abs((long long)divisor);
    	long long original = abs((long long)dividend);
    	long count = 0;
    	long res = 0;

    	while(up <= (original >> 1))
    	{
    		up <<= 1;
    		count++;
    	}
    	while(count >= 0)
    	{
    		if(original >= up)
    		{
    			original -= up;
    			res += 1ll<<count;
    		}
    		up >>= 1;
    		count--;
    	}

    	return isneg?-res:res;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a = s.divide(-1, 1);
	cout << a << endl;
	return 0;
}