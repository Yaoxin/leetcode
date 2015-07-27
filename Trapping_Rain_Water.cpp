#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//某个位置的水量是由左高和右高决定的。
    int trap(vector<int>& height) {
    	if(height.size() == 0)
    		return 0;
    	int leftHeight = 0;
    	std::vector<int> left(height.size(), 0);
    	for (int i = 0; i < height.size(); ++i)
    	{
     		left[i] = leftHeight;
    		leftHeight = leftHeight > height[i] ?leftHeight:height[i];
    	}

    	int rightHeight = 0;
    	std::vector<int> right(height.size(), 0);
    	for (int i = height.size() - 1; i >= 0 ; i--)
    	{
    		right[i] = rightHeight;
    		rightHeight = rightHeight > height[i] ? rightHeight:height[i];
    	}

    	int sum = 0;
    	for (int i = 0; i < height.size(); ++i)
    	{
    		sum += min(left[i], right[i]) > height[i]?min(left[i], right[i]) - height[i]:0;
    	}

    	return sum;
    }


    //省空间的做法,从两边开始比较。
    //这个方法非常高效
    int trap_bak(vector<int> & height)
    {
    	int res = 0;
    	int left =0, right = height.size() - 1;
    	int cur = 0;
    	while(left < right)
    	{
    		if(height[left] < height[right])
    		{
    			cur = left + 1;
    			while(cur < right && height[cur] < height[left])
    				res += height[left] - height[cur++];
    			left = cur;
    		}
    		else
    		{
    			cur = right - 1;
    			while(cur > left && height[cur] < height[right])
    				res += height[right] - height[cur--];
    			right = cur;
    		}
    	}

    	return res;
    }
};

int main(int argc, char const *argv[])
{
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	std::vector<int> v(a, a + 12);
	Solution s;
	int num = s.trap_bak(v);
	cout << num << endl;
	return 0;
}