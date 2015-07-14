#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//dp ,记录到达每一行的每个数的最小大小
    int minimumTotal(vector<vector<int> > &triangle) {
    	if(!triangle.size())
    		return 0;
    	std::vector<int> v(triangle.size(), 0);

    	for (int i = 0; i < triangle.size(); ++i)
    	{
    		for(int j = triangle[i].size() - 1; j >= 0; j--)
    		{
    			if(j == triangle[i].size() - 1 && i != 0)
    			{
    				v[j] = v[j - 1] + triangle[i][j];
    			}
    			else if(j == 0)
    			{
    				v[j] += triangle[i][j];
    			}
    			else
    			{
    				v[j] = min(v[j] + triangle[i][j], v[j - 1] + triangle[i][j]);
    			}
    		}
    	}

    	int sum = v[0];
    	for (int i = 1; i < v.size(); ++i)
    	{
    		sum = min(sum, v[i]);
    	}

    	return sum;
    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	std::vector<vector<int> > a;
	int a1[] = {2};
	int a2[] = {3, 4};
	int a3[] = {6, 5, 7};
	int a4[] = {4, 1, 8, 3};
	std::vector<int> v1(a1, a1 + 1);
	std::vector<int> v2(a2, a2 + 2);
	std::vector<int> v3(a3, a3 + 3);
	std::vector<int> v4(a4, a4 + 4);
	a.push_back(v1);
	a.push_back(v2);
	a.push_back(v3);
	a.push_back(v4);
	int min_val = s.minimumTotal(a);
	cout << min_val << endl;
	return 0;
}