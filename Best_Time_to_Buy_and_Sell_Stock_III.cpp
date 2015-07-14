#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//把prices[] 分成两部分prices[0...m] 和 prices[m...length]  
	//要做n次划分，时间复杂度O(N^2)
	//但是可通过DP，将时间的复杂度降到O(n)

    int maxProfit(vector<int>& prices) {
    	if(prices.size() == 0)
    		return 0;

    	//O(n)
    	int low = prices[0];
    	int res = 0;
    	std::vector<int> forward(prices.size(), 0);
    	for (int i = 1; i < prices.size(); ++i)
    	{
    		if(low > prices[i])
    			low = prices[i];
    		else
    			if(prices[i] - low > res)
    				res = prices[i] - low;
    		forward[i] = res;
    	}

    	//O(n)
    	res = 0;
    	int high = prices[prices.size() - 1];
    	std::vector<int> opposite(prices.size(), 0);
    	for (int i = prices.size() -2; i >= 0; i--)
    	{
    		if(high < prices[i])
    			high = prices[i];
    		else
    			if(res < high - prices[i])
    				res = high - prices[i];
    		opposite[i] = res;
    	}

    	//O(n)
    	res = 0;
    	for (int i = 0; i < prices.size(); ++i)
    	{
    		cout << forward[i] << " "<< opposite[i]<<endl;
    		res = max(res, forward[i] + opposite[i]);
    	}

    	return res;
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {1, 1, 0};
	std::vector<int> v(a, a + 3);
	int n = s.maxProfit(v);
	cout << n << endl;
	return 0;
}