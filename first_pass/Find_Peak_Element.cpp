#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool IsPeak(vector<int> v, int index)
	{
		if(index > 0 && v[index - 1] > v[index])
		{
			return false;
		}
		if(index < v.size() - 1 && v[index] < v[index + 1])
		{
			return false;
		}
		return true;
	}

    int findPeakElement(vector<int>& nums) {
    	int mid = 0;
    	int left = 0;
    	int right = nums.size() - 1;

    	while(left <= right)
    	{
    		mid = left + (right - left)/2;
    		if(IsPeak(nums, mid))
    		{
    			return mid;
    		}
    		else if(mid > 0 && nums[mid - 1] > nums[mid])
    		{
    			right = mid - 1;
    		}
    		else if(mid < nums.size() - 1 && nums[mid] < nums[mid + 1])
    		{
    			left = mid + 1;
    		}
    	}

    	return -1;
        
    }
};

