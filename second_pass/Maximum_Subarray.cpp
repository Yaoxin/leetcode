#include "common/help.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max = numeric_limits<int>::min();
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            sum += *i;
            max = std::max(sum, max);
            sum = std::max(sum, 0);
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::vector<int> v(a, a + 9);
    cout << s.maxSubArray(v) << endl;
    return 0;
}