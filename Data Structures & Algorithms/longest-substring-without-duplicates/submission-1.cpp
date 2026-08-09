class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n = s.length();
        int left = 0;
        int right = 0;
        int ans = 0;
        while(right<n) {
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
                st.insert(s[right]);
                right++;
                ans = max(ans,right-left);
        }
        return ans;
    }
};
