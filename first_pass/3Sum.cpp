#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	vector<vector<int> > out;
    	sort(nums.begin(), nums.end());
    	int target = 0;
    	int j = 0, k = 0;
    	for (int i = 0; i < nums.size(); ++i)
    	{
    		target = 0 - nums[i];
    		j = i + 1;
    		k = nums.size() - 1;
    		while(j < k)
    		{
    			if(nums[j] + nums[k] == target)
    			{
    				out.push_back({nums[i], nums[j], nums[k]});
    				j++;
    				while(j < k && nums[j] == nums[j -1])
    					j++;
    				k--;
    				while(j < k && nums[k] == nums[k + 1])
    					k--;
    			}
    			else if(nums[j] + nums[k] > target)
    			{
    				k--;
    				while(j < k && nums[k] == nums[k +1])
    					k--;

    			}
    			else
    			{
    				j++;
    				while(j < k && nums[j] == nums[j - 1])
    					j++;
    			}
    		}
    	}

    	return out;
    }
};

//-2 0 1 1 2
int main(int argc, char const *argv[])
{
	Solution s;
	int a[] ={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,
		3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,
		10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,
		-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector<int> v(a, a + sizeof(a)/4);
	std::vector<vector<int> > out;
	out = s.threeSum(v);
	for (int i = 0; i < out.size(); ++i)
	{
		for(int j = 0; j < 3; j++)
			cout << " "<<out[i][j];
		cout << endl;
	}


	return 0;
}


