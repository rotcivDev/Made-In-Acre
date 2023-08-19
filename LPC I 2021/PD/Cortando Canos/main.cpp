/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/1798
 * PD, programação dinamica
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define db(x) cout << #x << ": " << x << endl
#define db_pair(x) cout << #x << ": " << x.f << ", " << x.s << endl
#define printv(vector)                             \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define print_map(map)                      \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define FOR(i, a, b) for (ll i = a; i < (b); ++i)
#define foreach(a, b) for (auto&(a) : (b))
#define rep(i, n) FOR(i, 0, n)
#define Rep(i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define log(x) cout << x << endl

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

ll lucro(vector<pll>& canos, ll sizeCano) {
    vll memo(1e4 + 10, 0);
    memo[0] = 0;

    rep(i, sizeCano + 1) {
        foreach (cano, canos) {
            if (i < cano.f) continue;

            memo[i] = max(memo[i], cano.s + memo[i - cano.f]);
        }
    }

    return memo[sizeCano];
}

int main(int argc, char** argv) {
    SPEED;

    ll qtdCanos, sizeCano;
    read(qtdCanos, sizeCano);

    vector<pll> canos(qtdCanos);
    rep(i, qtdCanos) {
        read(canos[i].f, canos[i].s);
    }

    log(lucro(canos, sizeCano));

    return 0;
}
