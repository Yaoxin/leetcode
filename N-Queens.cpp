#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
	//若两个皇后的摆放位置分别是（i,xi）和（j,xj），
	//在棋盘上斜率为-1的斜线上，满足条件i-j=xi-xj;在棋盘上斜率为1的斜线上，满足条件i+j=xi+xj
	//|i-xi|≠ |j-xj|

/*
	bool valid(vector<string> &elem, int row, int col)
	{
		vector<int> v;
		int pos;
		for(int i = 0; i < elem.size(); ++i)
		{
			pos = elem[i].find_first_of("Q");
			v.push_back(pos);
		}

		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i] == col ||abs(i - row) == abs(v[i] - col))
				return false;
		}
		return true;
	}
*/

	//斜率为1的对角线，row1 + 1 = row2 , col1 + 1 = col2
	//斜率为-1的对角线， row1 + 1 = row2 , col1 - 1 = col2 
	bool valid(vector<string> &elem, int row, int col)
	{
		for(int i = 0; i < row; ++i)
		{
			if(elem[i][col] == 'Q')
				return false;
		}

		for(int i = row - 1, j = col - 1; i >=0 && j >= 0;i--,j--)
		{
			if(elem[i][j] == 'Q')
				return false;
		}

		for(int i = row - 1, j = col + 1; i >= 0 && j <= size; i--,j++)
		{
			if(elem[i][j] == 'Q')
			{
				return false;
			}
		}

		return true;

	}

	void nquees(int cur, vector<vector<string> > &out, vector<string> &elem)
	{
		if(size == cur)
		{
			out.push_back(elem);
			return;
		}

		//set<int> s;
		string str;
		for(int i = 0; i < size; i++)
		{
			if(valid(elem, cur, i))
			{
				cout << "("<<cur << i<<")"<<endl;
				str.clear();
				str.append(size, '.');
				str.replace(i, 1, 1, 'Q');
				cout << str << endl;
				elem.push_back(str);

				/*
				if(size == cur)
				{
					out.push_back(elem);
					elem.pop_back();
					return;
				}
				*/
				nquees(cur + 1, out, elem);
				elem.pop_back();
			}			
		}
	}

	//n皇后的递归实现
    vector<vector<string> > solveNQueens(int n) {
    	size = n;
    	vector<vector<string> > out;
    	vector<string> elem;
    	nquees(0, out, elem);
        return out;
    }

private:
	int size;
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<vector<string> > out;
	out = s.solveNQueens(5);
	cout << out.size() << endl;
	return 0;
}