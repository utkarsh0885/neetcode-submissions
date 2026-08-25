class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;

        while(l <= h) {
            int mid = l + (h - l) / 2;

            for(int i=0;i<n;i++) {

            if(nums[i] == target) {
                return i;
            }else if(nums[i] < target) {
                l = mid + 1;
            }else {
                h = mid - 1;
            }
        }
        }
        return -1;
    }
};
