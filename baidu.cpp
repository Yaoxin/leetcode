/*
 * baidu.cpp
 *
 *  Created on: 2015年3月12日
 *      Author: Pure
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
    	vector<int>::iterator iter;
    	vector<int>::iterator backup;
    	int m = 0, n = 0;
    	for(iter = arr.begin(); iter != arr.end(); iter++)
    	{
    		if(*iter % 2 == 0)
    		{
    			m++;
    		}
    		else
    		{
    			n++;
    		}
    	}

    	cout << m << " " << n << endl;

    	iter = (m > n)?++arr.begin():arr.begin();
    	backup = (m > n)?arr.begin():++arr.begin();
    	int type = (m > n)?1:0;
    	 n = (m > n)?n:m;

    	int counter = (m > n)?0:2;
    	int a = 0;

    	cout << *iter << " " << *backup << endl;

    	while(backup != arr.end() && a <= 2*n -1)
    	{
    		if(*iter % 2 == type)
    		{
    			iter++;
    			iter++;
    			a += 2;
    		}
    		else
    		{
    			if(*backup % 2 == type)
    			{
    				m = *iter;
    				*iter = *backup;
    				*backup = m;
    			}
				if(counter >= 2*n -1)
				{
					backup++;
					counter++;
				}
				else
				{
					backup++;
					backup++;
					counter += 2;
				}
    		}

    		cout << "while " << *iter << " "<< *backup << endl;
    	}
    }
};


void test1(void)
{
	int array[] = {7, 7, 9, 5, 1, 6, 7, 9, 3, 2, 6};
		vector<int> vec(array, array + 11);
		class Solution test;
		test.oddInOddEvenInEven(vec, 11);

		vector<int>::iterator iter;
		for(iter = vec.begin(); iter != vec.end(); iter++)
		{
			cout << *iter << endl;
		}
}




int MatrixBinary(int M[5][5], int x, int rb,int re,int cb,int ce)
{
	int rm = (rb + re)/2;
	int cm = (cb + ce)/2;

	if(rb > re || cb > ce)
	{
		return 0;
	}

	if(x == M[rm][cm])
	{
		cout << "row = " << rm << ", cline = " << cm;
		return 1;
	}

	if(x > M[rm][cm])
	{
		return MatrixBinary(M, x, rm, re, cm + 1, ce) || MatrixBinary(M,x ,rm + 1, re, cb, ce);
	}
	else
	{
		return MatrixBinary(M,x, rb,re,cb,cm - 1) || MatrixBinary(M,x, rb,rm - 1,cb,ce);
	}
}

void test2(void)
{
	int M[5][5]=
	{
	    { 1, 2, 3, 4, 5},
	    { 6, 7, 8, 9,10},
	    {11,12,13,14,15},
	    {16,17,18,19,20},
	    {21,22,23,24,25}
	};

	MatrixBinary(M, 24 ,0, 5, 0, 5);

	return;

}



















int main()
{
//	test1();
	test2();
}














