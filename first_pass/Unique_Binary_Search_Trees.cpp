#include <iostream>

using namespace std;

class Solution {
public:
	//O(n^2)
    int numTrees(int n) {
    	if(n <= 0)
    		return 0;
    	int *res = new int[n + 1];
    	for(int i = 0; i < n; i++)
    	{
    	    res[i] = 0;
    	}
    	res[0] = 1;
    	res[1] = 1;
    	for(int i = 2; i <= n; i++)
    	{
    		for(int j = 0; j < i; j++)
    		{
    			res[i] += res[j]*res[i - j - 1];
    		}
    	}

    	return res[n];
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.numTrees(2) << endl;
	return 0;
}

