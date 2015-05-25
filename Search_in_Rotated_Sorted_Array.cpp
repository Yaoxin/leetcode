#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if(nums.size() == 0)
    		return -1;
    	int begin = 0;
    	int end = nums.size() - 1;
    	int mid = (begin + end)/2;
    	while(begin <= end)
    	{
    		mid = (begin + end)/2;
    		if(nums[mid] == target)
    			return mid;
    		if(nums[mid] > nums[end])
    		{
    			if(nums[mid] > target && target > nums[end] )
    			{
    				end = mid - 1;
    			}
    			else
    			{
    				begin = mid + 1;
    			}
    		}
    		else
    		{
    			if(nums[mid] < target  && target < nums[end])
    			{
    				begin = mid + 1;
    			}
    			else
    			{
    				end = mid - 1;
    			}
    		}
    	}

    	return -1;
    }
};