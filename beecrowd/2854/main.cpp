/**
 * https://judge.beecrowd.com/pt/problems/view/2854
 * DFS, Backtracking, componentes conexos,
 */

#include <bits/stdc++.h>

using namespace std;

#define SPEED cin.tie(0)->sync_with_stdio(0);
#define DEBUG true
#define db(x) \
    if (DEBUG) cout << #x << ": " << x << endl
#define dbpair(x) cout << #x << ": " << x.f << ", " << x.s << endl
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

class Grafo {
   public:
    int num_vertices;
    map<string, vector<string>> graph;
    set<string> visited;

    Grafo(int n) {
        num_vertices = n;
    }

    void add_edge(string u, string v) {
        graph[u].pb(v);
        graph[v].pb(u);
    }

    void dfs(string u) {
        stack<string> pilha;
        pilha.push(u);
        visited.insert(u);

        while (!pilha.empty()) {
            string atual = pilha.top();
            pilha.pop();

            for (auto vizinho : graph[atual]) {
                if (visited.find(vizinho) != visited.end()) continue;

                pilha.push(vizinho);
                visited.insert(vizinho);
            }
        }
    }

    int components() {
        int resp = 0;
        for (auto vertice : graph) {
            if (visited.find(vertice.f) != visited.end()) continue;

            dfs(vertice.f);
            resp++;
        }

        return resp;
    }
};

void solve() {
    int vertices, arestas;
    cin >> vertices >> arestas;

    Grafo grafo(vertices);

    for (int i = 0; i < arestas; i++) {
        string u, w, v;
        cin >> u >> w >> v;
        grafo.add_edge(u, v);
    }

    cout << grafo.components() << endl;
}

int main(int argc, char** argv) {
    SPEED;

    solve();

    return 0;
}
