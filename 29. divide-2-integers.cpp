class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        long dvd = (long)dividend;
        long dvs = (long)divisor;

        // Determine final sign
        bool positive = (dvd < 0) == (dvs < 0);

        // Work entirely with negative numbers
        dvd = dvd > 0 ? -dvd : dvd;
        dvs = dvs > 0 ? -dvs : dvs;

        int q = 0;
        while (dvd <= dvs) {
            long temp = dvs;
            int multiple = 1;
            while ((temp << 1) >= dvd && (temp << 1) < 0) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            q += multiple;
        }
        return positive ? q : -q;
    }
};
