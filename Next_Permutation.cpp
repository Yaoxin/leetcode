#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
	//字典序 比较简单
    void nextPermutation(vector<int>& nums) {
    	if(nums.size() == 0)
    		return ;
		int i = 0, j = 0;
		for(i = nums.size() - 1; i >= 1; i--)
		{
			if(nums[i] > nums[i - 1])
				break;
		}

		if(i == 0)
		{
			reverse(nums.begin(), nums.end());
			return;
		}

		for(j = nums.size() - 1; j >= 1; j--)
		{
			if(nums[j] > nums[i - 1])
				break;
		}
		swap(nums[j], nums[i - 1]);
		reverse(nums.begin() + i, nums.end());
    }
};

int main(int argc, char const *argv[])
{
	//int a[] = {1, 2, 3, 4};
	int a[] = {1, 3, 2};
	std::vector<int> v(a, a + 3);
	Solution s;
	std::vector<vector<int> > out;
	s.nextPermutation(v);
	cout << " [";
	for (int i = 0; i < v.size(); ++i)
	{
		cout << " "<<v[i];
	}
	cout << " ]"<<endl;
	return 0;
}