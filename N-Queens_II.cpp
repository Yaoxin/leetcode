#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	//backtracking
	bool ValidPos(int pos, int end, vector<int> &vec)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			if(pos == vec[i])
				return false;
		}

		//斜率为-1
		for(int i = vec.size() - 1, j = pos; i >= 0 && j > 0; i--, j--)
		{
			if(vec[i] == j -1)
				return false;
		}

		//斜率为1
		for (int i = vec.size() - 1, j = pos; i >= 0 && j < end - 1; i--, j++)
		{
			if(vec[i] == j+1)
				return false;
		}

		return true;
	}

	void dfs(int row, int end, vector<int> &vec, int &total)
	{
		if(row == end)
			total++;
		for(int i = 0; i < end; i++)
		{
			if(ValidPos(i, end, vec))
			{
				vec.push_back(i);	
				dfs(row + 1, end, vec, total);
				vec.pop_back();
			}
		}
	}

    int totalNQueens(int n) {
    	vector<int> vec;
    	int total = 0;
    	dfs(0, n, vec, total);
    	return total;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int count = s.totalNQueens(5);
	cout <<count << endl;
	return 0;
}
