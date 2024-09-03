#include <bits/stdc++.h>

#define db(x) cout << #x << ": " << x << endl
#define endl "\n"

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    vector<vector<int>> matriz(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> matriz[i][j];

    // Caso 0
    bool ehZero = true;
    bool ehUm = true;
    bool ehDois = true;
    bool ehTres = true;
    for (int i = 0; i < N; i++)
        if (!is_sorted(matriz[i].begin(), matriz[i].end())) {
            ehZero = false;
            break;
        }

    for (int i = 0; i < N; i++)
        for (int j = 1; j < N; j++)
            if (matriz[j][i] < matriz[j - 1][i]) {
                ehZero = false;
                break;
            }

    if (ehZero) {
        cout << 0 << endl;
        return 0;
    }

    // Caso 1
    for (int i = 0; i < N; i++) {
        for (int j = N - 1 - 1; j >= 0; j--) {
            if (matriz[i][j] < matriz[i][j + 1]) {
                ehUm = false;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 1; j < N; j++)
            if (matriz[j][i] < matriz[j - 1][i]) {
                ehUm = false;
                break;
            }

    if (ehUm) {
        cout << 1 << endl;
        return 0;
    }

    // Caso 2
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1 - 1; j >= 0; j--)
            if (matriz[j][i] < matriz[j + 1][i]) {
                ehDois = false;

                break;
            }
    }

    for (int i = 0; i < N; i++) {
        for (int j = N - 1 - 1; j >= 0; j--) {
            if (matriz[i][j] < matriz[i][j + 1]) {
                ehDois = false;

                break;
            }
        }
    }

    if (ehDois) {
        cout << 2 << endl;
        return 0;
    }

    cout << 3 << endl;

    return 0;
}
