#include "common/help.h"

/*
class Solution {
public:
    int maxProfitOne(std::vector<int> &prices, int start, int stop)
    {
        int ans = 0;
        int min = prices[start];
        for(int i = start + 1; i <= stop; i++ )
        {
            if(prices[i] < min)
            {
                min = prices[i];
            }
            else if(prices[i] - min > ans)
            {
                ans = prices[i] - min;
            }
        }
        return ans;
    }

    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            int tmp = maxProfitOne(prices, 0, i) + maxProfitOne(prices, i, prices.size() - 1);
            if (ans < tmp)
            {
                ans = tmp;
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if (length == 0)
        {
            return 0;
        }
        int *head = new int[length];
        head[0] = 0;
        int low = prices[0];
        int ans = 0;
        for (int i = 1; i < length; ++i)
        {
            if(low > prices[i])
            {
                low = prices[i];
            }
            else if(prices[i] - low > ans)
            {
                ans = prices[i] - low;
            }
            head[i] = ans;
        }

        int *  tail = new int[length];
        tail[length - 1] = 0;
        int high = prices[length -1];
        ans = 0;
        for(int i = length - 2; i >= 0; i--)
        {
            if(high < prices[i])
            {
                high = prices[i];
            }
            else if(high - prices[i] > ans)
            {
                ans = high - prices[i];
            }
            tail[i] = ans;
        }

        ans = 0;
        for (int i = 0; i < length; ++i)
        {
            int tmp = head[i] + tail[i];
            if (tmp > ans)
            {
                ans = tmp;
            }
        }
        return ans;        
    }
};


