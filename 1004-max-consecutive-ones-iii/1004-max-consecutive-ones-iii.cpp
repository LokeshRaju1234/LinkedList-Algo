class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size = nums.size();
        int endingIndex = 0,startingIndex = 0,length = 0,count = 0;

        while(endingIndex < size)
        {
            if(nums[endingIndex] == 0) count++;//you can skip the zeroes
            endingIndex++;

            //shrink window when flip count exceeds k
            while(count > k)
            {
                if(nums[startingIndex] == 0) count--;
                startingIndex++;
            }

            length = max(length,endingIndex - startingIndex);
        }

        return length;
    }
};