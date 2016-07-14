#include "common/help.h"

void show_vector(std::vector<std::vector<int> > v);


class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        if (n == 0 )
        {
            return;
        }
        vector<vector<int> > v(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                v[j][n - 1 - i] = matrix[i][j];
            }
        }
        // show_vector(v);
        matrix = v;
    }
};

void show_vector(std::vector<std::vector<int> > v) {
    int m = v.size();
    if(m == 0) {
        return;
    }
    int n = v[0].size();
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << " "<< v[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2};
    int b[] = {3, 4};
    std::vector<int> v1(a, a + 2);
    std::vector<int> v2(b, b + 2);
    std::vector<vector<int> > v;
    v.push_back(v1);
    v.push_back(v2);
    show_vector(v);
    Solution s = Solution();
    s.rotate(v);
    show_vector(v);

    return 0;
}