#include <iostream>
#include <cassert>

using namespace std;

/*
void swap(int *a, int *b )
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
*/

/*n^2*/
int nozeroarray(int *a, int n)
{
	assert(a != NULL);
	int i = 0, j = 0;

	while(i < n)
	{
		if(a[i] == 0)
		{
			for(j = i; j < n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			a[j - 1] = 0;
		}
		i++;
	}
}


int ReverseBits(unsigned int a )
{
	unsigned int temp1 = 0;
	unsigned int temp2 = 0;
	for(int i = 0; i < 16; i++)
	{
		 temp1 = (1 << i) & a;
		 temp2 = (1 << (31 - i)) & a;
		if(temp1 > 0 && temp2 <= 0)
		{
			a &= ~(1 << i);
			a |= 1 << (31 -i);
		}
		else if(temp2 >0 && temp1 <= 0) 
		{
			a |= 1<< i;
			a &= ~(1 << (31 -i));
		}
	}

	return a;
}



int main(int argc, char const *argv[])
{
/*
	int a[] = {1,0,2,3,4,0};
	nozeroarray(a, 6);

	for(int i = 0; i < 6; i++)
		{cout << a[i] << endl;}
*/

	unsigned int b = ReverseBits(43261596);
	cout << b << endl;

	return 0;
}


