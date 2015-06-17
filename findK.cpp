#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partfunc(vector<int> &v, int left, int right, int index)
{
	int ret = left;
	int value = v[index];

	swap(v[right], v[index]);
	for (int i = left; i < right; ++i)
	{
		if(v[i] > value)
		{
			swap(v[ret], v[i]);
			ret++;
		}
	}
	swap(v[ret], v[right]);

	return ret;
}

//这个时间复杂度近似O(n)
int findKMax(vector<int> &v,int left,int right, int k)
{
	int index = 0;
	int radomIndex = left + 1;
	index = partfunc(v, left, right, radomIndex);
	cout << "index "<< index << endl;
	if(index < k)
	{
		return findKMax(v, index + 1, right, k);
	}
	if(index > k)
	{
		return findKMax(v, left, index - 1, k);
	}

	return index;
}


int main(int argc, char const *argv[])
{
	int a[] = {8,3,4,1,9,7,6,10};
	std::vector<int> v(a, a + 8);
	int KMax = findKMax(v,0, v.size() - 1, 3);

	cout << v[KMax] << endl;

	cout << "[ ";
	for (int i = 0; i < v.size(); ++i)
	{
		cout << " "<< v[i];
	}
	cout << "]"<<endl;

	return 0;
}