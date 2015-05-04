//Given an array S of n integers, find three integers in S such that the sum
//is closest to a given number, target. Return the sum of the three integers. 
//You may assume that each input would have exactly one solution.

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;


class Solution {
public:
	// O(n^2)
    int threeSumClosest(vector<int> &num, int target) {
    	sort(num.begin(), num.end());
    	int ret = num[0] + num[num.size() - 1] + num[1];
    	int sum = 0;
    	int j = 0, k = 0;
    	for(int i= 0; i < num.size(); i++)
    	{
    		j = i + 1;
    		k = num.size() - 1;
    		while( j < k)
    		{
    			sum = num[i] + num[j] + num[k];
    			if(abs(sum - target) < abs(ret - target))
                {
    			
                    cout << "sum " << sum << " " << "ret" << ret<<" " << endl;
    				ret = sum;
    			}

    			if(sum - target < 0)
    			{
    				j++;
    			}
    			else if(sum - target == 0)
    			{
    				return ret;
    			}
    			else
    			{
    				k--;
    			}
    		}
       	}
        return ret;
    }
};



int main(int argc, char const *argv[])
{
	srand(4347);
    int a[] = {1,2,4,8,16,32,64,128};
    std::vector<int> v(a, a + 8);

    /*
	for(int i = 0; i < 300; i++)
	{
		v.push_back(rand() % 100);	
    }
    */
    Solution test;
    int sum = test.threeSumClosest(v, 82);
    cout << sum << endl;

	return 0;
}
