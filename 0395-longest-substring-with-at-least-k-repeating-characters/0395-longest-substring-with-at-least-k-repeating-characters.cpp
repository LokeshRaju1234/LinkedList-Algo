class Solution {
public:
    int longestSubstring(string s, int k) 
    {
    int len = 0;
    vector<int>freq(128,0);
    for(int i = 0;i <s.size();i++)
    {
        freq[s[i]]++;
    }
    for(int i = 0;i < s.size();i++)
    {
        if(freq[s[i]] < k)
        {
            int left = longestSubstring(s.substr(0,i),k);
            int right = longestSubstring(s.substr(i + 1),k);
            return max(left,right);
        }
    }

    return s.size();
    }
};