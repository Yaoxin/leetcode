#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	//very simple
    int findKthLargest(vector<int>& nums, int k) {
    	if(nums.size() == 0 || k < 1)
    		return -1;
    	vector<int> small;
    	vector<int> big;

    	for(int i = 1; i < nums.size(); i++)
    	{
    		if(nums[i] < nums[0])
    			small.push_back(nums[i]);
    		else
    			big.push_back(nums[i]);
    	}

    	if(k == big.size() + 1)
    	{
    		return nums[0];
    	}

    	if(k <= big.size())
		{
			return findKthLargest(big, k);
		}
		else
		{
			return findKthLargest(small,  k - big.size() - 1);
		}      
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int a[] = {2, 5, 11, 7, 3, 8};
	std::vector<int> v(a, a + 6);
	int out = s.findKthLargest(v, 1);
	cout << out << endl;
	return 0;
}