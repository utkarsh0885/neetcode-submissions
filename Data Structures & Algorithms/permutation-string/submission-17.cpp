class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>freq1,freq2;
        if(s1.length() > s2.length()) return false;
        for(char c : s1) freq1[c]++;
        int left = 0;
        for(int right = 0;right < s2.length();right++) {
            freq2[s2[right]]++;

            if(right-left+1 > s1.length()) {
                freq2[s2[left]]--;
                if(freq2[s2[left]] == 0)
                freq2.erase(s2[left]);
                left++;
            }

                if(right-left+1 == s1.length()) {
                    if(freq1 == freq2) {
                        return true;
                    }
                }
        }
        return false;
    }
};
