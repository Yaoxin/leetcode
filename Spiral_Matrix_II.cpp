#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void helper(vector<vector<int> >&out, int row_start, int row_end, int col_start, int col_end, int start)
	{
		if(row_start > row_end || col_start > col_end)
		{
			return;
		}
		for (int i = col_start; i <= col_end; ++i)
		{
			out[row_start][i] = start++;
		}

		for(int i = row_start + 1; i <= row_end; i++)
		{
			out[i][col_end] = start++;
		}

		for(int i = col_end - 1; i >= col_start; i--)
		{
			out[row_end][i] = start++;
		}

		for(int i = row_end - 1; i > row_start; i--)
		{
			out[i][col_start] = start++;
		}

		helper(out, row_start + 1, row_end - 1, col_start + 1, col_end - 1, start);
	}
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> > out_null;
    	if(n == 0)
    		return out_null;

    	vector<vector<int> >out(n,  vector<int>(n, 0));
    	int row_start = 0;
    	int row_end = n - 1;
    	int col_start = 0;
    	int col_end = n - 1;
    	helper(out, row_start, row_end, col_start, col_end, 1);
    	return out;
        
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<vector<int> > v;
	v = s.generateMatrix(4);

	cout << "[ "<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout << "	[";
		for(int j = 0; j < v[i].size(); j++)
		{
			cout << "	"<<v[i][j];
		}
		cout << "]"<<endl;
	}
	cout << "] "<<endl;

	return 0;
}