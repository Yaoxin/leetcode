#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	int start = 0, end = nums.size() - 1;
    	int mid = 0;
    	int range_start =-1, range_end = -1;
    	while(start < end)
    	{
    		mid = start + (end - start)/2;
    		if(nums[mid] < target)
    		{
    			start = mid + 1;
    		}
    		else
    		{
    			end = mid;
    		}
    	}

    	if(nums[start] == target)
    	{
    		range_start = start;
    	}
    	else
    	{
    		range_start = -1;
    	}

    	



        
    }
};