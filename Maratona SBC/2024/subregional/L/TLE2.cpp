#include <bits/stdc++.h>

#define db(x) cout << #x << ": " << x << endl
#define endl "\n"

using namespace std;

char reval(int num) {
    return (char)(num + '0');
}

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

    vector<string> bits(n);
    int maior = 0;

    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        string covertido = dec_bin(valor);
        maior = max((int)covertido.size(), maior);
        bits[i] = covertido;
    }

    vector<list<char>> ans(maior, list<char>());

    for (int i = 0; i < n; i++) {
        auto bit = bits[i];
        string esq(maior - (int)bit.size(), '0');
        string res = esq + bit;

        for (int i = 0; i < maior; i++) {
            if (res[i] == '0')
                ans[i].push_back('0');
            else
                ans[i].push_front('1');
        }
    }

    int flag = 0;
    for (int i = 0; i < n; i++) {
        string local;
        for (int j = 0; j < maior; j++) {
            local += ans[j].front();
            ans[j].pop_front();
        }

        if (flag) cout << " ";
        flag = 1;
        cout << (stoi(local, nullptr, 2));
    }
    cout << endl;

    return 0;
}
