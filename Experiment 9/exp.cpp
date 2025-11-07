#include <iostream>
#include <vector>
using namespace std;

// Naive Pattern Matching
vector<int> findOccurrences(string S, string P) {
    int n = S.length();
    int m = P.length();
    vector<int> positions;

    // Slide pattern over the text
    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        // Check if pattern matches starting from S[i]
        while (j < m && S[i + j] == P[j]) {
            j++;
        }

        // If full match found
        if (j == m) {
            positions.push_back(i);
        }
    }

    return positions;
}

int main() {
    string S, P;

    cout << "Enter the main string S: ";
    getline(cin, S);

    cout << "Enter the pattern P: ";
    getline(cin, P);

    vector<int> results = findOccurrences(S, P);

    cout << "\nPattern found at positions: ";
    if (results.empty()) {
        cout << "None";
    } else {
        for (int pos : results)
            cout << pos << " ";
    }

    cout << endl;
    return 0;
}
