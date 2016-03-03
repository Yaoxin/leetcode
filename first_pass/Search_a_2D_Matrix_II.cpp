#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
    	if(matrix.size() == 0)
    		return false;
    	if(matrix[0].size() == 0)
    		return false;
    	int y = matrix[0].size() - 1;

    	for(int i = 0; i < matrix.size(); i++)
    	{
            while (y >= 0 && matrix[i][y] > target)
            {
                y -= 1;
            }
            if(y < 0)
                return false;
            if(matrix[i][y] == target)
                return true;
    	}
    	return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<vector<int> > v;
    int a[] = {1, 1};
    std::vector<int> test(a, a + 2);
    v.push_back(test);
    bool out = s.searchMatrix(v, 0);
    cout <<out << endl;
    return 0;
}


