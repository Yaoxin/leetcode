#include "common/help.h"


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            n ^= *i;
        }
        return n;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {3, 4, 3, 4, 1};
    std::vector<int> nums(a, a +5);
    Solution s = Solution();
    int n = s.singleNumber(nums);
    printf("%d\n", n);


    return 0;
}