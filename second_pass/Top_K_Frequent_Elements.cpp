#include "common/help.h"


//hash + heap
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> result;
        if (!nums.size())
        {
            return result;
        }
        std::map<int, int> m;
        for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
        {
            m[*i] += 1;
            
        }
        std::vector<pair<int, int> > v;
        for(std::map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
            v.push_back(make_pair(iter->second, iter->first));
        }
        make_heap(v.begin(), v.end());
        while(k--) {
            result.push_back(v.front().second);
            pop_heap(v.begin(), v.end());
            v.pop_back();
        }
        return result;        
    }
};

//[1, 1, 1, 2, 2, 3] 
//[1, 2]


