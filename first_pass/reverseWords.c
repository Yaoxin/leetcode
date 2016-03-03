#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reverseWords(char *s) {
	char temp[64] = {0};
	int count  = 0;
	int sum = strlen(s);
	char *end = NULL;
	int i = 0;
	while(sum > 0)
	{
		end = s + strlen(s);
		while(*end != ' ')
		{
			end--;
			count++;
		}
		memcpy(temp, end + 1, count);
		temp[count] = ' ';
		for(i = count + 1; i > 0; i--)
		{
			*(end + i) = *end;
		}
		for(i = 0; i < count + 1; i++)
		{
			*(end + 
		}




		memmove(s + count, s, count + 1);
		memcpy(s, temp, count + 1);
		sum -= count + 1;
	}    
}

int main(int argc, char const *argv[])
{
	//char a[] = "hello world fyliu";
	char *a = malloc(128);
	memset(a, 0, 128);
	strcpy(a, "hello world fyliu");
	reverseWords(a);
	printf("%s\n", a);
	return 0;
}