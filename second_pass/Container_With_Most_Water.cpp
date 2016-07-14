#include "common/help.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max_area = 0;
        while(i < j) {
            int area = min(height[i], height[j]) * (j - i);
            if(area > max_area) {
                max_area = area;
            }
            if(height[i] < height[j]) {
                int temp = i + 1;
                while(temp < j && height[temp] < height[i]){
                    temp++;
                }
                i = temp;
            } else {
                int temp = j - 1;
                while(temp > i && height[temp] < height[j]) {
                    temp--;
                }
                j = temp;
            }
        }
        return max_area;   
    }
};

int main(int argc, char const *argv[])
{
    // int a[] = {7, 2, 11, 8, 15, 3, 18, 9, 12, 17};
    int a[] = {1, 2, 1};
    std::vector<int> v(a, a+3);
    Solution s = Solution();
    int max_area = s.maxArea(v);
    cout << max_area << endl;
    return 0;
}