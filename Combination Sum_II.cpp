#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//backtracking
	int sum_helper(vector<int> &item)
	{
		int sum = 0;
		for (int i = 0; i < item.size(); ++i)
		{
			sum += item[i];
		}
		return sum;
	}
	void dfs(vector<vector<int> >&out, vector<int> item, int index, vector<int> & candidates, int target)
	{
		int sum = sum_helper(item);
		if(sum == target)
		{
			out.push_back(item);
			return;
		}
		if(sum > target)
		{
			return;
		}
		for (int i = index; i < candidates.size(); ++i)
		{
			if(i > index && candidates[i] == candidates[i - 1])
				continue;
			item.push_back(candidates[i]);
			dfs(out, item, i + 1, candidates, target);
			item.pop_back();

			if(sum_helper(item) + candidates[i] > target)
				break;
		}
	}
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    	vector<vector<int> > out;
    	if(candidates.size() == 0 || target < 0)
    		return out;
    	sort(candidates.begin(), candidates.end());
    	std::vector<int> item;
    	dfs(out, item, 0, candidates, target);
    	return out;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {10,1,2,7,6,1,5};
	std::vector<int> v(a, a + 7);
	vector<vector<int> >out;
	out = s.combinationSum2(v, 8);
	cout << "[" << endl;
	for (int i = 0; i < out.size(); ++i)
	{
		cout << "    [";
		for (int j = 0; j < out[i].size(); ++j)
		{
			cout << " "<<out[i][j];
		}
		cout << " ]"<<endl;
	}
	cout << "]" << endl;
	return 0;
}