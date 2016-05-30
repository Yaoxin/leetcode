#include "common/help.h"


class Solution {
public:
    bool isAnagram(string s, string t) {
         sort(s.begin(), s.end());
         sort(t.begin(), t.end());
         return s==t;
    }
};

int main(int argc, char const *argv[])
{
    Solution test = Solution();
    string s = "cba";
    string t = "bac";
    cout << test.isAnagram(s, t);
    // cout << s.isAnagram('', '');
    // cout << s.isAnagram('abc', 'cba');
    // cout << s.isAnagram('dao', 'dao');
    return 0;
} 