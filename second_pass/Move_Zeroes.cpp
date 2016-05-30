#include "common/help.h"


void print_vector(string msg, std::vector<int> v)
{
    cout << msg << " ";
    for(std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0 or nums.size() == 1)
        {
            return;
        }
        std::vector<int>::iterator first = nums.begin();
        std::vector<int>::iterator second = nums.begin() + 1;
        while(second != nums.end() )
        {
            if(*first != 0 )
            {
                ++first;
                ++second;
            }
            else
            {
                if(*second != 0)
                {
                    int temp = *first;
                    *first = *second;
                    *second = temp;
                    ++first;
                    ++second;
                }
                else
                {
                    ++second;
                }
            }
        }        
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {0, 0 , 3, 4};
    std::vector<int> v(a, a + 4);
    Solution s = Solution();
    s.moveZeroes(v);
    print_vector("out", v);
    return 0;
}

