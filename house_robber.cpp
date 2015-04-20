#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;


class Solution {
public:
	//it is error.
    int rob_bak(vector<int> &num) {
    	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    	for(int i = 0; i < num.size(); i++)
    	{
    		if(i % 2 != 0)
    		{
    			sum1 += num[i];
    		}
    		else
    		{
    			sum2 += num[i];
    		}

    		if(i % 3 == 0)
    		{
    			sum3 += num[i];
    		}
    		else if(i %3 == 2 )
    		{
    			sum4 += num[i];
    		}
    		else
    		{
    			sum5 += num[i];
    		}
    	}
    	int m = max(sum1, sum2);
    	m = max(m, sum3);
    	m = max(m, sum4);
    	m = max(m, sum5);

    	return m;
    }

    //dp 
    // dp[i] = max(dp(i - 1), dp(i - 2) + num[i])
    // dp[0] = num[0]
    //dp[1] = max(num[0], num[1])
    int rob(vector<int> &num) {
    	if(num.size() <= 1)
    	{
    		return (num.size() == 0)?0:num[0];
    	}
    	std::vector<int> dp;
    	dp.push_back(num[0]);
    	dp.push_back(max(num[0], num[1]));
    	for(int i = 2; i < num.size(); i++)
    	{
    		dp.push_back(max(dp[i - 1], dp[i - 2] + num[i]));    	
    	}

    	return dp[num.size() - 1];
    }
};



int main(int argc, char const *argv[])
{
	srand(5406);
	std::vector<int> v;
	for (int i = 0; i < 20; ++i)
	{
		v.push_back(rand()%100);
	}
	Solution s;
	int max = s.rob(v);
	cout << max << endl;
	return 0;
}