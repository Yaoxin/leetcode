#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:

	void helper(vector<int> &v, vector<vector<int> >& matrix, int row_start, int row_end, int col_start, int col_end)
	{
		if(row_start > row_end || col_start > col_end)
			return;
		for(int i = col_start; i <= col_end;  i++)
		{
			v.push_back(matrix[row_start][i]);
		}

		for(int i = row_start + 1; i <= row_end; i++)
		{
			v.push_back(matrix[i][col_end]);
		}


		for(int i = col_end - 1; i >= col_start && row_start != row_end; i--)
		{
			v.push_back(matrix[row_end][i]);
		}

		for(int i = row_end - 1; i > row_start && col_start != col_end; i--)
		{
			v.push_back(matrix[i][col_start]);
		}

		helper(v, matrix, row_start + 1, row_end - 1, col_start + 1, col_end - 1);
	}
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
    	std::vector<int> v;
    	if(matrix.size() == 0)
    		return v;
    	if(matrix[0].size() == 0)
    		return v;
    	int row_start = 0;
    	int row_end = matrix.size() - 1;
    	int col_start = 0;
    	int col_end = matrix[0].size() - 1;
    	helper(v, matrix, row_start, row_end, col_start, col_end);
		
		return v;      
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<vector<int> > matrix;
	int a[] = {1, 2, 3};
	std::vector<int> v1(a, a + 3);

	int b[] = {4, 5, 6};
	std::vector<int> v2(b, b + 3);

	int c[] = {7, 8, 9};
	std::vector<int> v3(c, c + 3);

	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);

	cout << "here" << endl;
	std::vector<int> out;
	out = s.spiralOrder(matrix);
	cout << "here 111" << endl;

	for (int i = 0; i < out.size(); ++i)
	{
		cout << out[i] << endl;
	}
	return 0;
}

