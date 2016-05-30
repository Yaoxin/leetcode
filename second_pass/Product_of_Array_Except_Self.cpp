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
    vector<int> productExceptSelf(vector<int>& nums) {
        int all = 1;
        int count = 0;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            if(*i != 0)
            {
                all *= *i;
            }
            else
            {
                count++;
            }
        }
        std::vector<int> v;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            if(count == 0)
            {
                v.push_back(all / *i);
            }
            else if (count == 1)
            {
                if(*i == 0)
                {
                    v.push_back(all);
                }
                else
                {
                    v.push_back(0);
                }
            }
            else
            {
                v.push_back(0);
            }
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4}; 
    std::vector<int> v(a, a + 4);
    Solution s = Solution();
    std::vector<int> r = s.productExceptSelf(v);
    print_vector("out", r);

    return 0;
}