#include<bits/stdc++.h>
 
using namespace std;

vector<int> a;
int tab[100][5000];

bool dp(int n, int sum, vector<int>& indices) {   
    if (sum == 0)
        return true;
        
    if (n <= 0)
        return false;
    
    auto &p = tab[n - 1][sum];
    if(p != -1) return p;
  
    if (a[n - 1] > sum)
        return p = dp(n - 1, sum, indices);

    if (dp(n - 1, sum, indices))
        return p = true;

    if (dp(n - 1, sum - a[n - 1], indices)) {
        indices.push_back(n - 1);
        return p = true;
    }
    
    return p = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(tab, -1, sizeof(tab));

    int n; cin >> n;
    a.resize(n);

    int soma = 0;
    for(auto &x : a) {
        cin >> x;
        soma += x;
    }

    if(soma % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    int target = soma / 2;
    vector<int> indices;
    
    auto tem = dp(n, target, indices);
    if(!tem) {
        cout << -1 << endl;
        return 0;
    }

    int soma_a = 0, soma_b = 0;
    vector<vector<int>> res(2, vector<int>());
    for(int i = n - 1; i >= 0; i--) {
        if(i == indices.back()) {
            res[0].push_back(a[i]);
            indices.pop_back();
        } else {
            res[1].push_back(a[i]);
        }
    }
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
