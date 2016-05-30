#include "common/help.h"


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }
        int min = prices[0];
        int ans = 0;
        for (std::vector<int>::iterator i = prices.begin() + 1; i != prices.end(); ++i)
        {
            if(*i < min)
            {
                min = *i;
            }
            else if(*i - min > ans)
            {
                ans = *i - min;
            }
        }
        return ans;
    }
};









