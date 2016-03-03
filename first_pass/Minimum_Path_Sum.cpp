#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//二维DP
    int minPathSum(vector<vector<int> >& grid) {
    	if(grid.size() == 0)
    		return 0;
    	if(grid[0].size() == 0)
    		return 0;

    	std::vector<int> dp(grid[0].size(), 0);
    	dp[0] = grid[0][0];
    	for(int i = 1; i < grid[0].size(); i++)
    	{
    		dp[i] = dp[i - 1] + grid[0][i];
    	}

    	for(int i = 1; i < grid.size(); i++)
    	{
    		dp[0] += grid[i][0];
    		for(int j = 1; j < grid[i].size(); j++)
    		{
    			dp[j] = min(dp[j - 1] + grid[i][j], dp[j] + grid[i][j]);
    		}
    	}

    	return dp[grid[0].size() - 1];
    }
};


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}