#include <iostream>
//#include <unordered_map>
#include <map>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	std::map<int, bool> map;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		map[nums[i]] = true;
    	}

    	int max = 0;
    	int rtv = 0;
    	int left = 0, right = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
        	if(map[nums[i]] == true)
        	{
        		max = 1;
        		map[nums[i]] = false;

        		left = nums[i] - 1;
        		while(map.count(left) != 0 && map[left] == true)
        		{
        			max++;
        			map[left] = false;
        			left--;
        		}

        		right = nums[i] + 1;
        		while(map.count(right) != 0 && map[right] == true)
        		{
        			max++;
        			map[right] = false;
        			right++;
        		}
        	}
        	if(rtv < max)
			{
				rtv = max;
			}
        }

        return rtv;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {100, 4, 200, 1, 3, 2};
	/*
	std::vector<int> nums(a, a + 6);
	int test = s.longestConsecutive(nums);
	cout << test << endl;
	*/
	set<int> my_set;
	for (int i = 0; i < 6; ++i)
	{
		my_set.insert(a[i]);
	}
	
	set<int>::iterator iter;
	for (iter = my_set.begin(); iter != my_set.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}