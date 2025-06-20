class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size())
            return findMedianSortedArrays(B, A);

        int m = A.size();
        int n = B.size();
        int low = 0, high = m;
        int len = m + n;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            int maxLeftA = (i == 0) ? INT_MIN : A[i - 1];
            int minRightA = (i == m) ? INT_MAX : A[i];
            int maxLeftB = (j == 0) ? INT_MIN : B[j - 1];
            int minRightB = (j == n) ? INT_MAX : B[j];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) /
                           2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0;
    }
};