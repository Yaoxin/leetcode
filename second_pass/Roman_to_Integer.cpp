#include "common/help.h"


class Solution {
public:
    int romanToInt(string s) {
        char pre = 0;
        int num = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            switch (s[i]) {
                case 'M':
                    if(pre == 'C')
                        num -= 200;
                    num += 1000;
                    pre = 'M';
                    break;
                case 'D':
                    if(pre == 'C')
                        num -= 200;
                    num += 500;
                    pre = 'D';
                    break;
                case 'C':
                    if(pre == 'X')
                        num -= 20;
                    num += 100;
                    pre = 'C';
                    break;
                case 'L':
                    if(pre == 'X')
                        num -= 20;
                    num += 50;
                    pre = 'L';
                    break;
                case 'X':
                    if(pre == 'I')
                        num -= 2;
                    num += 10;
                    pre = 'X';
                    break;
                case 'V':
                    if(pre == 'I')
                        num -= 2;
                    num += 5;
                    pre = 'V';
                    break;
                case 'I':
                    num += 1;
                    pre = 'I';
                    break;
            }
        }
        return num;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    int num = s.romanToInt("MDCLXVI");
    cout << num << endl;
    return 0;
}