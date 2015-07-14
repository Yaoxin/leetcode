#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.size() == 0)
    		return false;
    	if(matrix[0].size() == 0)
    		return false;
    	int y = matrix[0].size();

    	for(int i = 0; i < matrix.size(); i++)
    	{
    		if(matrix[i][j] > target)
    			y -= 1;
    		if(matrix[i][j] == target)
    			return true;
    	}

    	return false;
    }
};