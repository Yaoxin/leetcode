#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//采用字典序法可解
     vector<vector<int> >permute_alphabet_order(vector<int>& nums)
    {
    	vector<vector<int> > out;
    	if(nums.size() == 0)
    		return out;
    	sort(nums.begin(), nums.end());

    	while(true)
    	{
    		out.push_back(nums);
    		int i = 0, j = 0;
    		for(i = nums.size() - 1; i >= 1; i--)
    		{
    			if(nums[i] > nums[i - 1])
    				break;
    		}

    		if(i == 0)
    		{
    			return out;
    		}

    		for(j = nums.size() - 1; j >= 1; j--)
    		{
    			if(nums[j] > nums[i - 1])
    				break;
    		}

    		swap(nums[j], nums[i - 1]);
    		reverse(nums.begin() + i, nums.end());
    	}
    }
};