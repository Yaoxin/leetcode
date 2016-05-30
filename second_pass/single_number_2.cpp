#include "common/help.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; ++i)
        {
            for(std::vector<int>::iterator iter = nums.begin(); iter < nums.end(); ++iter)
            {
                if((*iter >> i) & 1)
                {
                    count[i]++;
                }
            }
            result |= ((count[i]%3) << i); 
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {3, 4, 3, 3, 2, 2, 2};
    std::vector<int> v(a, a + 7);
    Solution s = Solution();
    int result = s.singleNumber(v);
    cout << result << endl;
    return 0;
}