#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
    		return 0;
    	int i = 0;
    	for (i = 1; i < nums.size(); ++i)
    	{
    		if(nums[i - 1] > nums[i])
    			break;
    	}

    	if(i < nums.size())
    		return nums[i];
    	else
    	{
    		return nums[0];
    	}
        
    }
};