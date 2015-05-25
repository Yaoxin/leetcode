#include <iostream>

using namespace std;

class Solution {
public:
	/*
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	if(E <A && F < B && G > C && H > D)
    		return (H - F) *(G - E);
    	if(A < E && B < F && C > G && D > H)
    		return (C - A) * (D - B);
    	if(((C < E) || (G < A)) && ((F > D) || (B > H)))
    		return (C - A) * (D - B) + (H - F)*(G - E);
    	int a = (A < E)?((C - A)-(E - A )):(G - A);
    	int b = (D > H)?((D - B) - (D - H)):(D - F);
    	return (C - A) * (D - B) + (H - F)*(G - E) - a * b;      
    }
    */

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

    	int length = 0, width = 0;
    	if(G < A || C < E)
    	{
    		length = 0;
    	}		
  	 	else
    	{
    		length = ((G < C)?G:C) - ((A < E)?E:A);
    	}

    	if(F > D || H < B)
    	{
    		width = 0;
    	}
    	else
    	{
    		width = ((D > H)?H:D) - ((F > B)?F:B);
    	}
    	cout << length << " " << width << endl;
    	return (C - A) * (D - B) + (H - F)*(G - E) - length * width; 
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	int out = s.computeArea(-2, -2, 2, 2, -2, -2, 2, 2);
	cout << out << endl;
	return 0;
}