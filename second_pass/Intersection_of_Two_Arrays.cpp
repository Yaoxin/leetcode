#include "common/help.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::set<int> s1;
        std::vector<int> v;
        for (int i = 0; i < nums1.size(); ++i)
        {
            s1.insert(nums1[i]);
        }

        for (int i = 0; i < nums2.size(); ++i)
        {
            if(s1.find(nums2[i]) != s1.end())
            {
                s1.erase(nums2[i]);
                v.push_back(nums2[i]);
            }
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    int a1[] = {1, 2, 2, 1};
    int a2[] = {2, 2};
    std::vector<int> v1(a1, a1 + 4);
    std::vector<int> v2(a2, a2 + 2);
    Solution s;
    print_vector(s.intersection(v1, v2));
    return 0;
}