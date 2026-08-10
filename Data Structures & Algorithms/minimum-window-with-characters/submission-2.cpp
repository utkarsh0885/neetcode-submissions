class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>window,need;
        for(char c : t)
        need[c]++;
        int left = 0;
        int have = 0;
        int start = 0;
        int ans = INT_MAX;

        for(int right = 0;right<s.length();right++) {
            char c = s[right];
            window[c]++;
            if(need.count(c) && window[c] == need[c])
            have++;

            while(have == need.size()) {
                if(right-left+1<ans) {
                    ans = right-left+1;
                    start = left;
                }
                window[s[left]]--;
                if(need.count(s[left]) && window[s[left]] < need[s[left]]) {
                    have--;
                }
                left++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(start,ans);
    }
};
