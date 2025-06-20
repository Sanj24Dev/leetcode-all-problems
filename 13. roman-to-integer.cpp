class Solution {
public:
    int romanToInt(string s) {
        int prev = 0;
        int ret = 0;
        for (char c: s) {
            int dig = getdig(c);
            if (prev < dig)
                dig = dig - prev - prev;
            ret += dig;
            prev = dig;
        }
        return ret;
    }
    int getdig(char c) {
        int dig = 0;
        if (c == 'I')
            dig = 1;
        else if (c == 'V')
            dig = 5;
        else if (c == 'X')
            dig = 10;
        else if (c == 'L')
            dig = 50;
        else if (c == 'C')
            dig = 100;
        else if (c == 'D')
            dig = 500;
        else if (c == 'M')
            dig = 1000;
        return dig;
    }
};