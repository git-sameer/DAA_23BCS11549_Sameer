// Using KMP (Knuth–Morris–Pratt)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Build LPS (Longest Prefix Suffix) array
vector<int> buildLPS(const string &pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);

    int len = 0; // length of previous longest prefix suffix
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Search
vector<int> KMP(const string &text, const string &pattern) {
    vector<int> result;
    int n = text.size(), m = pattern.size();

    if (m == 0 || m > n) return result;

    vector<int> lps = buildLPS(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }

        if (j == m) {
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return result;
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    vector<int> matches = KMP(text, pattern);

    if (matches.empty())
        cout << "Pattern not found\n";
    else {
        cout << "Pattern found at indices: ";
        for (int pos : matches)
            cout << pos << " ";
        cout << endl;
    }

    return 0;
}
