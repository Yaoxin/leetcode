#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	if(obstacleGrid.size() == 0)
    		return 0;
    	if(obstacleGrid[0].size() == 0)
    		return 0;

    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();

    	std::vector<vector<int> > dp(m, vector<int>(n, 1));
    	bool status = false;
    	for(int i = 0; i < n; i++)
    	{
    		if(obstacleGrid[0][i] == 1 || status)
    		{
    			dp[0][i] = 0;
    			status = true;
    		}
    	}
    	status = false;
    	for(int j = 0; j < m; j++)
    	{
    		if(obstacleGrid[j][0] == 1 || status)
    		{
    			dp[j][0] = 0;
    			status = true;
    		}
    	}
    	for (int i = 1; i < m; ++i)
    	{
    		for(int j = 1; j < n; j++)
    		{
    			if(obstacleGrid[i][j] == 1)
    			{
    				dp[i][j] = 0;
    			}
    			else
    			{
    				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    			}
    		}
    	}

    	return dp[m - 1][n - 1];
    }
};