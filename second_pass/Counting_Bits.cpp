#include "common/help.h"

class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> v(num + 1, 0);
        v[1] = 1;
        for (int i = 2; i <= num; ++i)
        {
            v[i] = i % 2 + v[i/2];
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    print_vector(s.countBits(5));     
    return 0;
}