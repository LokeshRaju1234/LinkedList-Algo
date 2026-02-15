class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0,h = nums.size() - 1;

        while(l <= h)
        {
            int mid = l + (h - l) / 2;

            if(nums[mid] == target)
            {
                return {mid - 1,mid};
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }

        return {-1,-1};
    }
};