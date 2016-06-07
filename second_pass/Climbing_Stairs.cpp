
#include "common/help.h"

class Solution {
public:
    //  F(n) = F(n - 1)  + F(n -2)
    //  F(1) = 1
    //  F(2) = 2
    int climbStairs(int n) {
        if(n == 1 || n == 2) {
            return n;
        }
        int x = 1;
        int y = 2;
        for(int i = 3; i <= n; i++) {
            int temp = y;
            y = x + y ;
            x = temp;
        }
        return y;
    }
};