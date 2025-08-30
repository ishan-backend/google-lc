class Solution {
public:
    long long flowerGame(int n, int m) {
        // parity of x+y
        // if odd, Alice wins, else Bob wins
        // such pairs 1 <= x <= n and 1 <= y <= m

        int oddXCount = (n+1)/2;
        int evenXCount = n/2;
        int oddYCount = (m+1)/2;
        int evenYCount = m/2;

        // Alice wins if (x+y) is odd, also odd + even = odd
        return 1LL * oddXCount * evenYCount + 1LL * evenXCount * oddYCount;
    }
};