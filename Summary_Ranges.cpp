#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	std::vector<string> out;
    	if(nums.size() == 0)
    		return out;
    	int pre = nums[0];
    	int last = pre;
    	string item = to_string(nums[0]) + "->";
    	for (int i = 1; i < nums.size(); ++i)
    	{
    		if(nums[i] == pre + 1)
    		{
    			pre = nums[i];
    		}
    		else
    		{
    			last = atoi(item.c_str());
    			if(pre == last)
    			{
    				out.push_back(to_string(pre));
    			}
    			else
    			{
    				item += to_string(pre);
    				out.push_back(item);
    			}
    			pre = nums[i];
    			item = to_string(nums[i]) + "->";
    		}
    	}

    	last = atoi(item.c_str());
    	if(pre == last)
    	{
    		out.push_back(to_string(pre));
    	}
    	else
    	{
    		item += to_string(pre);
    		out.push_back(item);
    	}

		return out;        
    }
};