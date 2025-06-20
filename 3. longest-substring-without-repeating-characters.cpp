class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int max_len = 0;
        unordered_set<char> sub;
        int i=0;
        for (int j=0;j<s.length();j++) {
            while(sub.find(s[j])!=sub.end()) {     // if j is in the subset, then reduce window
                sub.erase(s[i]);
                i++;
            }
            sub.insert(s[j]);
            // j++;
            max_len = sub.size()>max_len?sub.size():max_len;
        }
        return max_len;
    }
};