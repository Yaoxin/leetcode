#include "common/help.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        return search_insert_impl(nums, target, start, nums.size() - 1);
    }

    int search_insert_impl(std::vector<int> &nums, int target, int start, int end) {
        int left = start;
        int right = end;
        if(left > right) {
            return 0;
        }
        int mid = (left + right) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            if(mid + 1 > right){
                return mid + 1;
            }
            if(nums[mid + 1] > target) {
                return mid + 1;
            } else {
                return search_insert_impl(nums, target, mid + 1, right);
            }
        } else {
            if(mid -1 < left) {
                return mid > 0 ? mid : 0;
            }
            if(nums[mid - 1] < target) {
                return mid;
            }else {
                return search_insert_impl(nums, target, left, mid - 1);
            }
        }
    }
};




