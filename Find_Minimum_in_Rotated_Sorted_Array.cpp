#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
    	if(!nums.size())
    		return 0;
    	int i = 0;
    	for (i = 1; i < nums.size(); ++i)
    	{
    		if(nums[i - 1] > nums[i])
    			break;
    	}

    	cout << "i" << i<<endl;

    	if(i < nums.size())
    		return nums[i];
    	else
    	{
    		return nums[0];
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {1};
	std::vector<int> v(a, a + 1);
	int b = s.findMin(v);
	cout << b << endl;
	return 0;
}

