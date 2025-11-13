// Find frequency of elements in a given array in O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    vector<int> order;

    for (int elmnt : arr) {
        if (freq[elmnt] == 0) {
            order.push_back(elmnt);
        }
        freq[elmnt]++;
    }

    cout << "\nFrequency of elements:\n";
    for (int elmnt : order) {
        cout << elmnt << ": " << freq[elmnt] << endl;
    }

    return 0;
}
