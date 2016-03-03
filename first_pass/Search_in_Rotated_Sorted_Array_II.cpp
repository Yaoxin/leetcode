#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//原则 1 逐渐递减
	//确定值在哪个区间
	//把握好解空间，就可以做好这道题
	bool  search(vector<int>& nums, int target)
	{
		if(nums.size() == 0)
			return false;
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		while(left <= right)
		{
			mid = left + (right - left)/2;
			if(nums[mid] == target)
				return true;
			if(nums[mid] > nums[left]) //递增
			{
				if(nums[mid] > target && target >= nums[left])
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
			else if(nums[mid] < nums[left]) //中间有转折
			{
				if(nums[mid] < target && target <= nums[right])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
			else //nums[mid] == nums[left] 重复
			{
				if(nums[left] == nums[right])
				{
					//O(n)
					for(int i = left; i < right; i++)
					{
						if(nums[i] == target)
						{
							return true;
						}
					}
					return false;
				}
				else if(nums[left] > nums[right])
				{
					if(target > nums[left])
					{
						return false;
					}
					else
					{
						left = mid + 1;
					}
				}
				else
				{
					if(target < nums[left])
					{
						return false;
					}
					else
					{
						left = mid + 1;
					}
				}
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	//int a[] = {4,5,6,7,9,1,2,3};
	int a[] = {5, 1, 3};
	std::vector<int> v(a, a + 3);
	Solution S;
	bool flag = S.search(v, 3);
	cout << flag << endl;

	return 0;
}