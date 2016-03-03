#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:

	//采用二分查找
    int searchInsert(vector<int>& nums, int target) {
    	int start = 0;
    	int end = nums.size() - 1;
    	int mid = 0;
    	int expect = 0;
    	while(start <= end)
    	{
    		mid = start + (end - start)/2;
    		if(target == nums[mid])
    		{
    			return mid;
    		}
    		else if(target < nums[mid])
    		{
    			end = mid - 1;
    			expect = mid;
    		}
    		else
    		{
    			start = mid + 1;
    			expect = start;
    		}
    	}

    	return expect;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {1,3,5,6};
	int a2[] = {1, 3};
	std::vector<int> v(a, a + 4);
	std::vector<int> v2(a2, a2 + 2);
	int pos = s.searchInsert(v, 2);
	cout << pos << endl;
	return 0;
}