#include <bits/stdc++.h>

#define ll long long

using namespace std;

bool daPraComer(vector<ll> &pipocas, ll C, ll T, ll chute) {
    bool resp = true;

    ll Ci = 1;
    ll capacidade_max_competidor = T * chute;
    ll competidor_atual = capacidade_max_competidor;

    for (ll i = 0; i < pipocas.size(); i++) {
        if (pipocas[i] > capacidade_max_competidor) {
            resp = false;
            break;
        }

        if (competidor_atual >= pipocas[i]) {
            competidor_atual -= pipocas[i];
        } else {
            // Um competidor nao pode parar de comer o saco na metade la ele
            Ci++;
            competidor_atual = capacidade_max_competidor - pipocas[i];
        }

        if (Ci > C) {
            resp = false;
            break;
        }
    }

    return resp;
}

int main() {
    ll N, C, T;
    cin >> N >> C >> T;

    vector<ll> pipocas(N);
    for (auto &p : pipocas)
        cin >> p;

    ll esq = 1, dir = 1e9 + 10, meio, resp = 0;
    while (esq < dir) {
        meio = (esq + dir) / 2;

        if (daPraComer(pipocas, C, T, meio)) {
            dir = meio;
            resp = meio;
        } else {
            esq = meio + 1;
        }
    }

    cout << esq << endl;

    return 0;
}
