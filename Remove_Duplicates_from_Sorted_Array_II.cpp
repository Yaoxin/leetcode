#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size() < 3)
    		return nums.size();
    	int count = 0;
    	int pos = 1;
    	for(int i = 1; i < nums.size(); i++)
    	{
    		if(nums[i - 1] != nums[i])
    		{
    			nums[pos++] = nums[i];
    			count = 1;
    		}
    		else
    		{
    			if(count != 2)
    			{
    				nums[pos++] = nums[i];
    				count = 2;
    			}
    		}
    	}

    	return pos;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {1, 1, 1, 2, 2, 3};
	std::vector<int> nums(a, a + 6);
	int len = s.removeDuplicates(nums);
	cout << len << endl;
	return 0;
}