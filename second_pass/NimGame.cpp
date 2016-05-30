#include "common/help.h"

class Solution {
public:
    bool canWinNim(int n) {
        if (n == 0)
        {
            return true;
        }
        else
        {
            return n%4 != 0;
        }        
    }
};