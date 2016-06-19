#include "common/help.h"

class Solution {
public:
    int integerBreak(int n) {
        if(n < 4) {
            return n -1;
        }
        int y = n / 3;
        int sum = 1;
        for (int i = 0; i < y; ++i)
        {
            sum *= 3;
        }
        int x= n % 3;
        if(x == 2){
            return sum * 2;
        } else if(x == 1) {
            return sum / 3 * 4;
        } else {
            return sum;
        }        
    }
};