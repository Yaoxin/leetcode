#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	//只要有赚就交易
    int maxProfit(vector<int>& prices) {
    	if(prices.size() == 0)
    		return 0;
    	int sum = 0;
    	for (int i = 1; i < prices.size(); ++i)
    	{
    		if(prices[i] > prices[i - 1])
    		{
    			sum += prices[i] - prices[i - 1];
    		}
    	}

    	return sum;
    }
};