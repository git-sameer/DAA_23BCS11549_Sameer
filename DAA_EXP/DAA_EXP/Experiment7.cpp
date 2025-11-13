// 0-1 Knapsack

#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Sum 0 is always possible (by selecting no elements)
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target];
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    if (isSubsetSum(arr, target))
        cout << "Subset with sum " << target << " exists!" << endl;
    else
        cout << "No subset with sum " << target << " found!" << endl;

    return 0;
}
