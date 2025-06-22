class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> dig_num = {{'2',"abc"},{'3',"def"},
                        {'4',"ghi"},{'5',"jkl"},{'6',"mno"},
                        {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string> ret;
        for (char c: digits) {
            string letters = dig_num[c];
            if (ret.size() == 0) {
                for (char l:letters) {
                    string s;
                    s += l;
                    ret.push_back(s);
                }
            }
            else {
                int n = ret.size();
                for (int i=0; i<n; i++) {
                    string s = ret.front();
                    ret.erase(ret.begin()); 
                    for (char l:letters) {
                        string new_s = s;
                        new_s += l;
                        ret.push_back(new_s);
                    }
                }
            }
        }
        return ret;
    }
};