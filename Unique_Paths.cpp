#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	//采用DP
	//res[i][j] = res[i - 1][j] + res[i][j - 1]
    int uniquePaths(int m, int n) {
    	if(m <= 0 || n <= 0)
    		return 0;
    	vector<int> res(n, 0);
    	res[0] = 1;
    	for (int i = 0; i < m; ++i)
    	{
    		for(int j = 1; j <= n; j++)
    		{
    			res[j] +=  res[j - 1]; 
    		}
    	}
    	return res[n - 1];  
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	int a = s.uniquePaths(2, 1);
	cout << a << endl;
	return 0;
}