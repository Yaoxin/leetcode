#include "common/help.h"

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        if(grid.size() == 0 || (grid.size() != 0 && grid[0].size() == 0)) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        std::vector<int> v(n, 0);
        v[0] = grid[0][0];
        for (int i = 1; i < n; ++i)
        {
            v[i] = v[i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; ++i)
        {
            v[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
            {
                v[j] = ((v[j-1] > v[j]) ? v[j]:v[j-1]) + grid[i][j];                
            }
        }
        return v[n -1];
    }
};

