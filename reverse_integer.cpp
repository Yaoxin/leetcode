#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    //怎样预防溢出
    int reverse(int x) {
    	int temp = 0;
    	int in = abs(x);
    	long long out = 0;
        int i = 1;
        if(x == -2147483648)
            return 0;

    	while(in/10 != 0)
    	{
    		temp = in%10;
     		if(temp != 0)
    		{

    			out = out * 10*i + temp;
                i = 1;
    		}
            else
            {
                i *= 10;
            }
    		in = in/10;
    	}

    	out = out *10*i + in;
        if(out > 2147483647)
            out = 0;

    	return x > 0 ?out:-out;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int test = s.reverse(-2147483648);
	cout << test << endl;
	
	return 0;
}