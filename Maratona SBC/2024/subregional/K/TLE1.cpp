#include <bits/stdc++.h>

#define db(x) cout << #x << ": " << x << endl
#define endl "\n"

typedef long long ll;

using namespace std;

int n;

vector<vector<int>> back(int i, int soma, int target, vector<vector<int>>& res, vector<int>& a) {
    if (soma == target) {
        for (int j = i; j < n; j++) {
            res[1].push_back(a[j]);
        }
        return res;
    }
    if (i == n) {
        res[0].clear();
        res[1].clear();
        return res;
    }

    vector<vector<int>> novo_a(res.begin(), res.end());
    novo_a[1].push_back(a[i]);
    auto res_a = back(i + 1, soma, target, novo_a, a);

    vector<vector<int>> novo_b(res.begin(), res.end());
    novo_b[0].push_back(a[i]);
    auto res_b = back(i + 1, soma + a[i], target, novo_b, a);

    if (!res_a[0].empty()) {
        return res_a;
    }
    return res_b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> a(n);
    int soma = 0;
    for (auto& i : a) {
        cin >> i;
        soma += i;
    }

    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }

    if (soma % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> opa(2, vector<int>());
    auto res = back(0, 0, soma / 2, opa, a);

    if (res[0].size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    int soma_resto = 0;
    for (auto x : res[1]) soma_resto += x;

    if (soma_resto != soma / 2) {
        cout << -1 << endl;
        return 0;
    }

    // for(auto x:res[0]) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // for(auto x:res[1]) {
    //     cout << x << " ";
    // }
    // cout << endl;

    int soma_a = 0, soma_b = 0;
    sort(res[0].begin(), res[0].end());
    sort(res[1].begin(), res[1].end());

    int flag = 0;
    while (res[0].size() != 0 || res[1].size() != 0) {
        while (!res[0].empty() && soma_a <= soma_b) {
            if (flag) cout << " ";
            flag = 1;
            cout << res[0][res[0].size() - 1];
            soma_a += res[0][res[0].size() - 1];
            res[0].pop_back();
        }

        while (!res[1].empty() && soma_b < soma_a) {
            if (flag) cout << " ";
            flag = 1;
            cout << res[1][res[1].size() - 1];
            soma_b += res[1][res[1].size() - 1];
            res[1].pop_back();
        }
    }
    cout << endl;

    return 0;
}
