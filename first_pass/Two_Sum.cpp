#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	//nlog(n) + n
    vector<int> twoSum(vector<int>& nums, int target) {
    	std::vector<int> v;
    	if(nums.size() == 0 || nums.size() == 1)
    	{
    		return v;
    	}
    	std::vector<int> dup(nums);
    	sort(dup.begin(), dup.end());
    	int begin = 0;
    	int end = nums.size() - 1;
    	while(begin < end)
    	{
    		if(dup[begin] + dup[end] > target)
    		{
    			end--;
    		}
    		else if(dup[begin] + dup[end] < target)
    		{
    			begin++;
    		}
    		else
    		{
    			break;
    		}
    	}

    	if(begin == end)
    	{
    		return v;
    	}

    	for (int i = 0; i < nums.size(); ++i)
    	{
    		if(nums[i] == dup[begin] || nums[i] == dup[end])
    		{
    			v.push_back(i + 1);
    		}
    	}

    	return v;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {2, 7, 11, 15};
	std::vector<int> v(a, a + 4);
	std::vector<int> out;
	out = s.twoSum(v, 9);
	cout << "[ ";
	for (int i = 0; i < out.size(); ++i)
	{
		cout << out[i]<<" "; 
	}
	cout << "]"<< endl;
	return 0;
}