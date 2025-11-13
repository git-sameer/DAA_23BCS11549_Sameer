// Naive String Search

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findOccurrences(const string &S, const string &P) {
    vector<int> positions;
    int n = S.size();
    int m = P.size();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (S[i + j] != P[j])
                break;
        }
        if (j == m)
            positions.push_back(i);
    }
    return positions;
}

int main() {
    string S, P;

    cout << "Enter text: ";
    getline(cin, S);

    cout << "Enter pattern: ";
    getline(cin, P);

    vector<int> result = findOccurrences(S, P);

    if (result.empty())
        cout << "Pattern not found\n";
    else {
        cout << "Pattern found at indices: ";
        for (int pos : result)
            cout << pos << " ";
        cout << endl;
    }

    return 0;
}
