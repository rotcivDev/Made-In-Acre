/**
 * [Link]
 * [Título da questão]
 * [Assuntos]
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) \
    if (DEBUG) cout << #x << ": " << x.f << ", " << x.s << endl
#define dbvector(vector)                           \
    {                                              \
        cout << #vector << " = ";                  \
        for (auto& it : vector) cout << it << " "; \
        cout << endl;                              \
    }
#define dbmap(map)                          \
    for (auto e : map)                      \
        cout << e.first << " " << e.second; \
    cout << endl
#define all(x) begin(x), end(x)
#define pb push_back
#define pf push_front
#define endl "\n"
#define f first
#define s second
#define MOD 1e9 + 7
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool isbetween(int from, int to, int test) {
    for (int i = from; i <= to; i++) {
        if (i > 12) i = 1;
        if (i == test) return true;
    }

    return false;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    pii alice = {min(a, b), max(a, b)};
    pii bob = {min(c, d), max(c, d)};

    if (alice.f == bob.f && alice.s == bob.s) {
        cout << "YES" << endl;
        return;
    }

    if (isbetween(alice.f, alice.s, bob.f) && !isbetween(alice.f, alice.s, bob.s)) {
        cout << "YES" << endl;
        return;
    }

    if (isbetween(alice.f, alice.s, bob.s) && !isbetween(alice.f, alice.s, bob.f)) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

int main(int argc, char** argv) {
    SPEED;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
