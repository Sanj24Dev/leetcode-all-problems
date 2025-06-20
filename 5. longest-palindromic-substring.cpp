class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            int p1 = checkFromCenter(s, i, i);
            int p2 = checkFromCenter(s, i, i + 1);
            len = max(p1, p2);

            if (len > end - start) {
                start = i - ((len - 1) / 2);
                end = i + (len / 2);
            }
        }
        return s.substr(start, end-start+1);
    }

    int checkFromCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};