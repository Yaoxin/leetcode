#include <iostream>
#include <stack>
#include <vector>

using namespace std;



class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	stack<int> st;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if(st.empty())
    			st.push(nums[i]);
    		else
    		{
    			if(st.top() != nums[i])
    			{
    				st.pop();
    			}
    			else
    			{
    				st.push(nums[i]);
    			}
    		}
    	}

    	return st.top();
    }

    //看见其它的解法，一个是map计数，一个是快排
};