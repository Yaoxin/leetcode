#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

回朔法思路：
	全排列算法思路
	（A B C D）的全排列
	 A 后面跟 B C D的全排列
	 B 后面跟 A C D的全排列
	 C 后面跟 A B D的全排列
	 D 后面跟 A B C的全排列

字典序法思路：
	具体算法思想 请见《算法分析与设计》
	生成组合对象的算法章节

*/

class Solution {
public:
	void permute_helper(int pos, vector<int> &nums, vector<vector<int> > &out)
	{
		if(pos == nums.size())
			out.push_back(nums);
		for(int i = pos; i < nums.size(); i++)
		{
			swap(nums[pos], nums[i]);
			permute_helper(pos + 1, nums, out);
			swap(nums[pos], nums[i]);
		}
	}

	//生成排列 n!种
    vector<vector<int> > permute(vector<int>& nums) {
    	std::vector<vector<int> > out;
    	permute_helper(0, nums, out);
    	return out;
    }

    vector<vector<int> >permute_alphabet_order(vector<int>& nums)
    {
    	vector<vector<int> > out;
    	if(nums.size() == 0)
    		return out;
    	sort(nums.begin(), nums.end());

    	while(true)
    	{
    		out.push_back(nums);
    		int i = 0, j = 0;
    		for(i = nums.size() - 1; i >= 1; i--)
    		{
    			if(nums[i] > nums[i - 1])
    				break;
    		}

    		if(i == 0)
    		{
    			return out;
    		}

    		for(j = nums.size() - 1; j >= 1; j--)
    		{
    			if(nums[j] > nums[i - 1])
    				break;
    		}

    		swap(nums[j], nums[i - 1]);
    		reverse(nums.begin() + i, nums.end());
    	}
    }
};





int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3, 4};
	std::vector<int> v(a, a + 4);
	Solution s;
	std::vector<vector<int> > out;
	//out = s.permute(v);
	out = s.permute_alphabet_order(v);
	cout << "[ " << endl;
	for (int i = 0; i < out.size(); ++i)
	{
		cout << "	[";
		for(int j = 0; j < out[i].size(); ++j)
		{
			cout << " "<<out[i][j];
		}
		cout << " ]"<<endl;
	}
	cout << "] "<<endl;
	return 0;
}