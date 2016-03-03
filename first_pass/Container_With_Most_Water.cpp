#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//贪心法
class Solution {
public:
    int maxArea(vector<int>& height) {
    	if(height.size() < 2)
    	{
    		return 0;
    	}
    	int sum = 0;
    	int start = 0;
    	int end = height.size() - 1;
 
    	while(start < end)
    	{
    		sum = max(sum,  (end - start) * min(height[start], height[end]));
    		if(height[start] > height[end])
    		{
    			end--;
    		}
    		else
    		{
    			start++;
    		}
    	}

    	return sum;
    }
};