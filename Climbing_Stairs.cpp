#include <iostream>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
    	if(n < 3)
    		return n;
    	int x = 1, y = 2;
    	int temp = 0;
    	for(int i = 3; i <= n; i++)
    	{
    		temp = x + y;
    		x = y;
    		y = temp;
    	}

    	return y;
    }
};