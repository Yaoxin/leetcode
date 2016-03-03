#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
		//回溯法
		void dfs(int n, int k, vector<vector<int> > &comon, vector<int> &elem, int cur)
		{
			if(k == 0)
			{
				comon.push_back(elem);
			}
			else
			{
				for (int i = cur; i <= n; ++i)
				{
					elem.push_back(i);
					dfs(n, k - 1, comon, elem, i + 1);
					elem.pop_back();
				}
			}
		}


    vector<vector<int> > combine(int n, int k) {
    	std::vector<vector<int> > comon;
    	std::vector<int> elem;
    	dfs(n, k, comon, elem, 1);
    	return comon;
    }
};



int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<vector<int> > v;
	v = s.combine(5, 3);
	cout << "{"<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout <<"    [";
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << " "<<v[i][j];
		}
		cout << "]"<<endl;
	}
	cout << "}"<<endl;
	return 0;
}

