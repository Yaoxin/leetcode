#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	//二维数组查找, 递归
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
    	int row_start = 0, row_end = matrix.size() - 1;
    	int col_start = 0, col_end = matrix[0].size() - 1;
    	//cout << row_start << " "<< row_end << endl;
    	//cout << col_start << " "<< col_end << endl;

    	bool out = search_handle(matrix, target, row_start, row_end, col_start, col_end);
    	return out;
    }
private:
	bool search_handle(vector<vector<int> >&matrix, int target, int row_start, int row_end, int col_start, int col_end)
	{
		if(row_start > row_end || col_start > col_end)
			return false;
		if(row_start == row_end && col_start == col_end)
		{
			if(matrix[row_start][col_start] != target)
				return false;
			else
				return true;
		}

		int row_mid = (row_start == row_end)?row_start:(row_start + (row_end - row_start)/2);
		int col_mid = (col_start == col_end)?col_start:(col_start + (col_end - col_start)/2);

		//printf("%d %d %d\n", row_mid, col_mid);
		cout << row_mid << " " << col_mid << endl;
		cout << matrix[row_mid][col_mid] << endl;
		if(matrix[row_mid][col_mid] == target)
			return true;
		else if(matrix[row_mid][col_mid] < target)
			return search_handle(matrix, target, row_mid + 1, row_end, col_start, col_mid) || \
				search_handle(matrix, target, row_mid, row_end, col_mid + 1, col_end);
		else
			return search_handle(matrix, target, row_start, row_mid, col_start, col_mid - 1) || \
				search_handle(matrix, target, row_start, row_mid - 1, col_mid, col_end);
	}
};

//mini test 
int main(int argc, char const *argv[])
{
	Solution s;
	/*
	int a[5][6]; 
	vector<vector<int> >example;
	for (int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 6; j++)
		{
			a[i][j] = i * 6 + j + 1;
		}
	}

	std::vector<int> v1(a[0], a[0] + 6);
	std::vector<int> v2(a[1], a[1] + 6);
	std::vector<int> v3(a[2], a[2] + 6);
	std::vector<int> v4(a[3], a[3] + 6);
	std::vector<int> v5(a[4], a[4] + 6);

	example.push_back(v1);
	example.push_back(v2);
	example.push_back(v3);
	example.push_back(v4);
	example.push_back(v5);
	*/
	std::vector<int> v(1, 1);
	vector<vector<int> >example;
	example.push_back(v);


	for (int i = 0; i < example.size(); ++i)
	{
		for(int j = 0; j < example[i].size(); ++j)
		{
			cout << " "<< example[i][j];
		}
		cout << endl;
	}

	bool out = s.searchMatrix(example, 9);
	cout << out << endl;
	return 0;
}