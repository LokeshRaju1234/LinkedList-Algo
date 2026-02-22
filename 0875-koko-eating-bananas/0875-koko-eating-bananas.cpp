class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1,high = *max_element(piles.begin(),piles.end());

        int reqtime = INT_MAX;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(reqTime(piles,mid,h))
            {
                reqtime = min(reqtime,mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return reqtime;
    }

    bool reqTime(vector<int>& piles,int hourly,int deadline)
    {
        int totalhours = 0;

        for(int i = 0;i < piles.size();i++)
        {
            totalhours += ceil((double)piles[i] / (double) hourly);
        }
        return (totalhours <= deadline);
    }
};