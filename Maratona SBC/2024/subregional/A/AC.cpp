#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1001; i >= 0; i--) {
        if (n * i + (n - 1) <= k) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
