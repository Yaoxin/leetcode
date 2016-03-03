#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	//jpush 面试题
	//回去后的想法
	//略微难过
	vector<vector<int> > threeMulti(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int> > out;
		int i = 0, j = 0, k = 0;
		vector<int> item;
		while(i < nums.size() && (nums[i] * nums[i] * nums[i]) < target )
		{
			j = i + 1;
			k = nums.size() - 1;
			while(j < k)
			{
				if(nums[j] * nums[k] *nums[i] < target)
				{
					for(int t = k; t > j; t--)
					{
						item.clear();
						item.push_back(nums[i]);
						item.push_back(nums[j]);
						item.push_back(nums[t]);
						out.push_back(item);
					}
					j++;
				}
				else
				{
					k--;
				}
			}
			i++;
		}

		return out;
	}
};

int main(int argc, char const *argv[])
{
	int a[] = {20, 21, 22, 23, 24, 25, 26, 27};
	vector<int> v(a, a + 8);
	Solution s;
	vector<vector<int> >out;
	out = s.threeMulti(v, 10000);
	cout << " ["<<endl;
	for (int i = 0; i < out.size(); ++i)
	{
		cout <<" 	";
		for(int j = 0; j < out[i].size(); j++)
		{
			cout << " "<<out[i][j];
		}
		cout<<endl;	
	}
	cout << " ]"<<endl;
	return 0;
}