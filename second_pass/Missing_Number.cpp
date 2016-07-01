#include "common/help.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1 = ((nums.size() + 1) * nums.size()) / 2;
        int sum2 = 0;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            sum2 += *i; 
        }
        return sum1 - sum2;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {0, 1, 2, 3, 4, 6};
    std::vector<int> v(a, a + 6);
    Solution s = Solution();
    int missing = s.missingNumber(v);
    cout << missing << endl;
    return 0;
}