#include <bits/stdc++.h>

#define db(x) cout << #x << ": " << x << endl
#define endl "\n"

using namespace std;

char reval(int num) {
    return (char)(num + '0');
}

// tinha na lib
string dec_bin(int& num) {
    int index = 0;
    string res;

    if (num == 0) return "0";

    while (num > 0) {
        res.push_back(reval(num % 2));
        index++;
        num /= 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> uns(30);  // porque 10^9 em binario vai dar 30 char
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        string binario = dec_bin(a[i]);

        for (int j = binario.size() - 1, k = uns.size() - 1; j >= 0; j--, k--) {
            uns[k] += binario[j] == '1';
        }
    }

    int flag = 0;
    for (int i = 0; i < n; i++) {
        string local = "";

        for (int j = 0; j < uns.size(); j++) {
            if (uns[j] == 0) {
                local += '0';
            } else {
                uns[j]--;
                local += '1';
            }
        }

        if (flag) cout << " ";
        flag = 1;
        cout << (stoi(local, nullptr, 2));
    }
    cout << endl;

    return 0;
}
