class Solution {
public:
    int myAtoi(string s) {
        set<char> numbers = {'0','1','2','3','4','5','6','7','8','9'};
        bool started = false;
        bool signFound = false;
        bool positive = true;
        int dig;
        int num = 0;
        // int cnt = 0;
        for (char c: s) {
            if (numbers.find(c) != numbers.end()) // number found
            {
                if (!started) started = true;
                dig = c-48;
                if (positive && (num > INT_MAX/10 || (num == INT_MAX/10 && dig > 7))) {
                    num = INT_MAX;
                    break;
                }
                else if (!positive && (num < INT_MIN/10 || (num == INT_MIN/10 && dig > 8))) {
                    num = INT_MIN;
                    break;
                }
                else {
                    if (positive)
                        num = num*10 + dig;
                    else 
                        num = num*10 - dig;
                }
            }
            else if (started) {    // encountered non dig character after starting
                break;
            }
            else {
                if (c == '-'){
                    positive = false;
                    started = true;
                }  
                else if (c == '+') {
                    positive = true;
                    started = true;
                }
                else if (c == ' ') {
                    continue;
                }
                else if (started == false) {
                    break;
                }
            }
        }
        // if (!positive && num != INT_MIN) {
        //     num *= -1;
            
        // }
        return num;
        
    }
    
};