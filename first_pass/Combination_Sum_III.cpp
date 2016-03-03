#include <iostream>
#include <vector>

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
	void dfs(vector<vector<int> >&out, vector<int> item, int index, int k, int target)
	{
		int sum = sum_helper(item);
		if(sum == target)
		{
			if(item.size() == k)
			{
				out.push_back(item);
			}
			return;
		}
		if(sum > target)
		{
			return;
		}
		for(int i = index; i < 10; ++i)
		{
			if(item.size() == k)
				break;
			item.push_back(i);
			dfs(out, item, i + 1, k, target);
			item.pop_back();

			if(sum_helper(item) + i >= target)
				break;
		}
	}

    vector<vector<int> > combinationSum3(int k, int n) {
    	vector<vector<int> > out;
        int sum = 0, i = k;
        while(i--)
        {
        	sum += (9 - i);
        }

        if(sum < n)
        	return out;

        std::vector<int> item;
    	dfs(out, item, 1, k, n);
    	return out;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<vector<int> > out;
	out = s.combinationSum3(3, 9);
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

