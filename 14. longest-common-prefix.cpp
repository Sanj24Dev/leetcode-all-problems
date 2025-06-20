class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = "";
        char check;
        bool not_same = false;
        int i = 0;
        int j = 0;
        while(1) {
            if (j < strs[i].size()) {
                if (i == 0) {
                    check = strs[i][j];
                }
                else {
                    if (strs[i][j] != check) {
                        not_same = true;
                    }
                }
            }
            else {
                break;
            }
            i++;
            if (i == n) {
                if (not_same == true)
                    break;
                i = 0;
                j++;
                prefix += check;
            }
        }
        return prefix;
    }
};