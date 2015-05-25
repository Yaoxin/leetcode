#include <stdio.h>
#include <stdlib.h>

int countPrimes(int n)
{
	int i, j, count = 0;
	if(n <= 1)
	{
		return 0;
	}
	/*if(n == 2 || n == 3)
	{
		return 1;
	}*/
	for(i = 2; i <= n; i++)
	{
		for(j = 2; j * j <= n; j++)
		{
			if(i % j == 0)
			{
				break;
			}
		}
		if(j * j > n)
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int n = 1000000;
	int result = countPrimes(n);
	printf("result = %d\n", result);
	return 0;
}
