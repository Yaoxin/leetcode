#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	map<int, int > my_map;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		if(my_map.count(nums[i]))
    		{
    			if(i - my_map[nums[i]] <= k)
    				return true;
    		}
    		my_map[nums[i]] = i;
    	}

    	return false;
    }
};