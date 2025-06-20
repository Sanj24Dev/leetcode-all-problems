class Solution {
public:
    string intToRoman(int num) {
        string ret;
        int mul = 1;
        while (num) {
            int dig = num%10;
            num /= 10;
            ret.append(getRoman(dig, mul));
            mul++;
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

    string getRoman(int dig, int mul) {
        string ret;
        if (mul == 1) {
            if (dig == 1)
                ret.append("I");
            else if (dig == 2)
                ret.append("II");
            else if (dig == 3)
                ret.append("III");
            else if (dig == 4)
                ret.append("IV"); 
            else if (dig == 5)
                ret.append("V");
            else if (dig == 6)
                ret.append("VI");
            else if (dig == 7)
                ret.append("VII");
            else if (dig == 8)
                ret.append("VIII");
            else if (dig == 9)
                ret.append("IX");
        }
        else if (mul == 2) {
            if (dig == 1)
                ret.append("X");
            else if (dig == 2)
                ret.append("XX");
            else if (dig == 3)
                ret.append("XXX");
            else if (dig == 4)
                ret.append("XL"); 
            else if (dig == 5)
                ret.append("L");
            else if (dig == 6)
                ret.append("LX");
            else if (dig == 7)
                ret.append("LXX");
            else if (dig == 8)
                ret.append("LXXX");
            else if (dig == 9)
                ret.append("XC");
        }
        else if (mul == 3) {
            if (dig == 1)
                ret.append("C");
            else if (dig == 2)
                ret.append("CC");
            else if (dig == 3)
                ret.append("CCC");
            else if (dig == 4)
                ret.append("CD"); 
            else if (dig == 5)
                ret.append("D");
            else if (dig == 6)
                ret.append("DC");
            else if (dig == 7)
                ret.append("DCC");
            else if (dig == 8)
                ret.append("DCCC");
            else if (dig == 9)
                ret.append("CM");
        }
        else if (mul == 4) {
            if (dig == 1)
                ret.append("M");
            else if (dig == 2)
                ret.append("MM");
            else if (dig == 3)
                ret.append("MMM");
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};