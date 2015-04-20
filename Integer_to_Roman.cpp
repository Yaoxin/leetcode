#include <iostream>


using namespace std;

/*
算法核心
I X C M
 V L D

*/


//very ugly,hmm
class Solution {
public:
    string intToRoman(int num) {
    	char map[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    	string out;
    	int i = 0;
    	int temp = 0;
    	while(num)
    	{
    		temp = num%10;
    		if(temp < 4)
    		{
    			while(temp--)
    			{
    				out = map[i] + out;
    			}
    		}
    		else if(temp == 4)
    		{
    			out = map[i + 1] + out;
    			out = map[i] + out;
    		}
    		else if(temp == 5)
    		{
    			out = map[i + 1] + out;
    		}
    		else if(temp > 5 && temp < 9)
    		{
    			temp -= 5;
    			while(temp--)
    			{
    				out =  map[i] + out;
    			}
    			out = map[i + 1] + out;
    		}
    		else if(temp == 9)
    		{
    			out = map[i + 2] + out;
    			out = map[i] + out;
    		}
    		else
    		{

    		}
    		i +=2;
    		num /= 10;
    	}

    	return out;
        
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string a = s.intToRoman(3999);
	cout << a << endl;
	return 0;
}