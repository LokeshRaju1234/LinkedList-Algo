class Solution {
public:
int SUM(vector<int>& weights)
{
    int sum = 0;
    for(int ele : weights)
    {
        sum += ele;
    }
    return sum;
}
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int capacity = *max_element(weights.begin(),weights.end());
        int maxRange = SUM(weights);
        int low = capacity,high = maxRange;
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            int reqTime = reqdays(weights,mid);
            if(reqTime <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int reqdays(vector<int>& edges,int cap)
    {
        int days = 1,load = 0;

        for(int i = 0;i < edges.size();i++)
        {
            if(load + edges[i] > cap)
            {
                load = edges[i];
                days++;
            }
            else
            {
                load += edges[i];
            }
        }

        return days;
    }
};