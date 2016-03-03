#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//time limit
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	for(int i = 0; i < nums.size(); i++)
    	{
    		for(int j = i+1; j <= i + k && j < nums.size(); j++)
    		{
    			if(abs(nums[i] - nums[j]) <= t)
    				return true;
    		}
    	}

    	return false;
    }

    
};