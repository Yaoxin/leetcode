#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	void copy_vector(vector<int> & src, int start, int end, vector<int> &dest)
	{
		for(int i = start; i < end; i++)
		{
			dest.push_back(src[i]);
		}
	}

	double findMinK(vector<int> &nums1, vector<int> &nums2, int k)
	{
		int size1 = nums1.size();
		int size2 = nums2.size();
		if(size1 > size2)
		{
			return findMinK(nums2,  nums1, k);
		}
		if(size1 == 0)
		{
			//cout << nums1[k - 1] << endl;
			return nums2[k - 1];
		}
		if(k == 1)
		{
			//cout << nums1[0] << endl;
			return min(nums1[0], nums2[0]);
		}

		int part = min(k/2, size1);
		int left = k - part;
		vector<int> dest;

		if(nums1[part - 1] > nums2[left - 1])
		{
			copy_vector(nums2, left, size2, dest);
			return findMinK(nums1, dest, k - left);
		}
		else if(nums1[part - 1] < nums2[left - 1])
		{
			copy_vector(nums1, part, size1, dest);
			return findMinK(dest, nums2, left);
		}
		else
		{
			return nums1[part - 1];
		}
	}

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int total = nums1.size() + nums2.size();
    	if(total == 0)
    	{
    		return 0;
    	}
    	if(total & 0x01)
    	{
    		return findMinK(nums1,nums2, total/2 + 1);
    	}
    	else
    	{
    		//cout << findMinK(nums1, nums2, total/2 + 1) << endl; 
    		return (findMinK(nums1, nums2, total/2) + \
    			findMinK(nums1, nums2, total/2 + 1))/2;
    	}
    }
};


int main(int argc, char const *argv[])
{
	int a[] = {1};
	int b[] = {2, 3, 4};
	std::vector<int> v1(a, a + 1);
	//std::vector<int> v1;
	std::vector<int> v2(b, b + 3);
	Solution s;
	double test = s.findMedianSortedArrays(v1, v2);
	cout << test << endl;
	return 0;
}