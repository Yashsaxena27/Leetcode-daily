#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;
        a %= MOD;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int sumOfNumbers(int l, int r, int k) {
        long long D = r - l + 1;

        long long digitSum = (1LL * (l + r) * D / 2) % MOD;

        long long part1 = power(D, k - 1);
        long long part2 = (power(10, k) - 1 + MOD) % MOD;

        long long inv9 = power(9, MOD - 2);

        long long result = digitSum;
        result = (result * part1) % MOD;
        result = (result * part2) % MOD;
        result = (result * inv9) % MOD;

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, r, k;
    cin >> l >> r >> k;

    Solution sol;
    cout << sol.sumOfNumbers(l, r, k) << "\n";

    return 0;
}