class Solution {
public:
    string convert(string s, int numRows) {
        string ret = "";
        int i = 0;
        int inc = 1;
        if (numRows == 1) return s;
        vector<string> sl(numRows);
        for (char c:s) {
            sl[i] += c;
            if (i == numRows-1 && inc == 1)
                inc = -1;
            else if (i == 0 && inc == -1)
                inc = 1;
            i += inc;
            cout << c;
        }
        for (string l:sl)
            ret.append(l);
        return ret;
    }
};