#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//backtracking
	void dfs(vector<vector<int> >&out, vector<int> item, vector<int> &nums, int index)
	{
		out.push_back(item);
		for(int i = index; i < nums.size(); i++)
		{
			if(i > index && nums[i] == nums[i - 1])
				continue;
			item.push_back(nums[i]);
			dfs(out, item, nums, i + 1);
			item.pop_back();
		}
	}
	
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    	vector<vector<int> > out;
    	if(nums.size() == 0)
    		return out;
    	sort(nums.begin(), nums.end());
    	vector<int> item;
    	dfs(out, item, nums, 0);
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {1, 2, 3};
	vector<int> nums(a, a + 3);
	vector<vector<int> > out;
	out = s.subsetsWithDup(nums);
	cout << "[ "<<endl;
	for (int i = 0; i < out.size(); ++i)
	{
		cout << "	[";
		for(int j = 0; j < out[i].size(); j++)
		{
			cout << "	"<<out[i][j];
		}
		cout << "]"<<endl;
	}
	cout << "] "<<endl;
	return 0;
}