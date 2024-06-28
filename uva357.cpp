#include <iostream>
#include <vector>

using namespace std;

unsigned long long countWays(unsigned long long amount) {
    vector<unsigned long long> dp(amount + 1, 0);
    dp[0] = 1;

    vector<unsigned long long> coins = {1, 5, 10, 25, 50};

    for (unsigned long long coin : coins) {
        for (unsigned long long i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    unsigned long long n;
    
    while (cin >> n) {
        unsigned long long result = countWays(n);

        if (result == 1) {
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        } else {
            cout << "There are " << result << " ways to produce " << n << " cents change." << endl;
        }
    }

    return 0;
}