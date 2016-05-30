#include "common/help.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(!nums.size())
        {
            return false;
        }
        set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution s = Solution();
    int a[] = {1};
    std::vector<int> v(a, a + 1); 
    cout << s.containsDuplicate(v);
    return 0;
}