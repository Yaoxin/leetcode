#include "common/help.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        if(len < 2) {
            return (len == 1 && nums[0] == val) ? 0 : len; 
        }
        std::vector<int>::iterator iter = nums.begin();
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            if(*i == val) {
                leetcode_swap(*iter, *i);
                iter++;
            }
        }
        nums.assign(iter, nums.end());
        return nums.size();        
    }
};

int main(int argc, char const *argv[])
{
   Solution s = Solution();
   int a[] = {3, 2, 2, 3};
   std::vector<int> v(a, a+4);
   cout << s.removeElement(v, 3) << endl;
   print_vector(v);
    return 0;
}