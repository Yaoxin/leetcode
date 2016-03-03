#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	//刚开始连题意都理解错了。
	//
    int maxProfit(vector<int>& prices) {
    	if(prices.size() == 0)
    		return 0;
    	int low = prices[0];
    	int sum = 0;
    	for (int i = 1; i < prices.size(); ++i)
    	{
    		if(prices[i] < low)
    		{
    			low = prices[i];
    		}
    		else
    		{
    			if(prices[i] - low > sum)
    			{
    				sum = prices[i] - low;
    			}
    		}
    	}

    	return sum;
    }
};