class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x%10==0 && x!=0))
            return false;
        if (x >= 0 && x <= 9)
            return true;
        int rev = 0;
        
        while( x ) {
            int dig = x%10;
            x = x/10;
            rev = rev*10 + dig;
            if (rev == x) 
                return true;
            else if (rev > x) {
                if (x!=0 && x == rev/10)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};