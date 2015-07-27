#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	std::vector<int> v;
    	if(nums.size() < 2)
    		return v;
    	int value = 1;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		value *= nums[i];
    		v.push_back(value);
    	}

    	value = 1;
    	for (int i = v.size() - 1; i > 0; i--)
    	{
    		v[i] = v[i - 1]*value;
    		value *= nums[i];
    	}
    	v[0] = value;
        
        return v;
    }
};
