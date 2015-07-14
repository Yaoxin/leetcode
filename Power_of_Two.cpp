#include <iostream>

using namespace std;



class Solution {
public:
	//bit manipulation
    bool isPowerOfTwo(int n) {
    	if(n < 0)
    		return false;
    	int count = 0;
    	for(int i = 0; i < 31; i++)
    	{
    		if(((1 << i) & n) != 0)
    			count++; 
    	}

    	if(count == 1)
    		return true;
    	return false;
    }
};


//看到网上有个答案是n &=(n - 1);  return n==0 感觉挺巧妙的


int main(int argc, char const *argv[])
{
	Solution s;
	bool out = s.isPowerOfTwo(-2147483646);
	cout << out << endl;
	cout << INT_MAX << endl;
	return 0;
}