/**
 * https://neps.academy/problem/469
 * Chuva
 * Grafos, graph, bfs, grid
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

int n, m;

const vector<pair<int, int>> moves = {
    {1, 0},
    {0, 1},
    {0, -1}
};

bool ehValid(int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

void solve() {
    cin >> n >> m;

    pii start;
    vector<string> grid(n);

    for(int i=0;i<n;i++) {
        cin >> grid[i];

        for(int j=0;j<m;j++) {
            if(grid[i][j] == 'o') start = {i, j};
        }
    }

    queue<pii> fila;
    fila.push(start);

    pii resp = {-1, -1};
    while(!fila.empty()) {
        pii atual = fila.front();
        
        fila.pop();
        grid[atual.f][atual.s] = 'o';

        for(int i=0;i<moves.size(); i++ ) {
            int x = atual.f + moves[i].f, y = atual.s + moves[i].s;

            if(!ehValid(x, y)) continue;

            if(grid[x][y] != '.') continue;

            if(i == 0) {
                fila.push({x, y});
                grid[x][y] = 'o';
                break;
            } else {
                if(!ehValid(atual.f+1, atual.s)) continue;

                if(grid[atual.f+1][atual.s] != '#') continue;

                fila.push({x, y});
                grid[x][y] = 'o';
            }
        }
    }

    for(auto linha:grid) {
        cout << linha << endl;
    }
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}