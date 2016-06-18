#include "common/help.h"

class Solution {
public:
    // max(n-1) ? max(n-2) + nums[n] 
    // max(0) = nums[0]
    // max(1) = nums[0] > nums[1] ? nums[0]:nums[1]
    int rob(vector<int>& nums) {
        int vec_len = nums.size();
        if(vec_len == 0 || vec_len == 1) {
            return vec_len > 0 ? nums[0] : 0;
        }
        int max[2] = {nums[0], nums[0] > nums[1] ? nums[0] : nums[1]};
        for (int i = 2; i < vec_len; ++i)
        {
            int temp = max[1];
            max[1] = (max[0] + nums[i]) > max[1] ? (max[0] + nums[i]) : max[1];
            max[0] = temp;
        }
        return max[1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    int a[] = {3, 7, 12, 6, 2, 18};
    std::vector<int> v(a, a + 6);
    int num = s.rob(v);
    cout << num << endl;


    return 0;
}