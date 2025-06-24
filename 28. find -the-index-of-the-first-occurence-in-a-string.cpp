class Solution {
public:
    int strStr(string haystack, string needle) {
        int first_ind = -1;
        int m = needle.length();
        int n = haystack.length();

        for (int i = 0; i < n; i++) {
            int im = 0;
            if (haystack[i] == needle[im]) {
                im++;
                int in = i+1;
                while (haystack[in] == needle[im] && im < m && in < n) {
                    in++;
                    im++;
                }
                if (im == m) {
                    first_ind = i;
                    break;
                }
            }   
        }
        return first_ind;
    }
};