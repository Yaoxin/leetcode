#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int n = nums.size();
    	if(n < 4)
    	{
    		if(n < 2)
    			return n == 0 ?0:nums[0];
    		else
    			return n == 2?max(nums[0], nums[1]):max(nums[0], max(nums[1], nums[2]));
    	}


    	std::vector<int> dp(n, 0);
    	dp[1] = nums[1];
    	dp[2] = max(nums[1], nums[2]); 
    	for(int i = 3; i < n; i++)
    	{
    		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    	}
    	int sum = dp[n - 1];

    	dp[2] = nums[2];
    	dp[3] = max(nums[2], nums[3]);
    	for(int i = 4; i < n - 1; i++)
    	{
    		dp[i] = max(dp[i -1], dp[i - 2] + nums[i]);
    	} 

    	return max(dp[n - 2] + nums[0], sum);
        
    }
};

int main(int argc, char const *argv[])
{
	int a[] = {1,1,1};
	//int a[] = {1, 5, 2, 5, 3, 6};
	std::vector<int> v(a, a + 3);
	Solution s;
	int max = s.rob(v);
	cout << max << endl;
	return 0;
}