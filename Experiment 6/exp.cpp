#include <iostream>
#include <vector>
using namespace std;

// DP-based Subset Sum
bool subsetSum(vector<int> &arr, int sum) {
    int n = arr.size();

    // DP table: dp[i][j] = true if we can make sum j using first i numbers
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Sum = 0 is always possible (empty subset)
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {

            if (arr[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];             // Can't include element
            } else {
                // Either include or exclude the current item
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> sum;

    if (subsetSum(arr, sum))
        cout << "Subset with sum " << sum << " exists.\n";
    else
        cout << "Subset with sum " << sum << " does NOT exist.\n";

    return 0;
}
