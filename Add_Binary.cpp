#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	int m = a.length();
    	int n = b.length();
    	int carry =  0;
    	string out;
    	int num;
    	char temp = '0';

    	while(m > 0 && n > 0)
    	{
    		num = a[m - 1] - '0' + b[n - 1] - '0' + carry;
    		switch (num)
    		{
    			case 3:
    				carry = 1;
    				temp = '1';
    				break;
    			case 2:
    				carry = 1;
    				temp = '0';
    				break;
    			case 1:
    				carry = 0;
    				temp = '1';
    				break;
    			case 0:
    				carry = 0;
    				temp = '0';
    				break;
    			default:
    				break;
    		}
    		out.insert(0, 1, temp);
    		m--;
    		n--;
    	}

    	int x = (m > n)?m:n;
    	string c = (m > n)?a:b;

    	while(x > 0)
    	{
    		num = c[x - 1] - '0' + carry;
    		if(num == 2)
    		{
    			carry = 1;
    			temp = '0';
    		}
    		else if(num == 1)
    		{
    			carry = 0;
    			temp = '1';
    		}
    		else
    		{
    			carry = 0;
    			temp = '0';
    		}
    		out.insert(0, 1, temp);
    		x--;
    	}

    	if(carry == 1)
    		out.insert(0, 1, '1');

    	return out;        
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	string out = s.addBinary("11", "1");
	cout << out << endl;

	return 0;
}