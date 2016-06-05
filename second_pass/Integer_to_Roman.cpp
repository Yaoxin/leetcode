#include "common/help.h"


class Solution {
public:
    string intToRoman(int num) {
        string s;
        char * roman[4][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",},
            {"", "M", "MM", "MMM",},
        };
        s.append(roman[3][num / 1000 % 10]);
        s.append(roman[2][num / 100 % 10]);
        s.append(roman[1][num / 10 % 10]);
        s.append(roman[0][num % 10]);

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string out = s.intToRoman(1666);
    cout << out << endl;
    return 0;
}