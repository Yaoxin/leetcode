#include "common/help.h"

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int r = 0;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            r ^= *i;
        }
        int last = r & ~(r-1);
        std::vector<int> out(2, 0);
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            if(*i & last)
            {
                out[0] ^= *i;   
            }
            else
            {
                out[1] ^= *i;
            }
        }

        return out;
    }
};