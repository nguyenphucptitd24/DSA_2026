#include<bits/stdc++.h>
using namespace std;

const int maxN = 100005;
vector<int> adj[maxN];
int low[maxN], num[maxN], tru[maxN];
int timeDFS = 0, cnt = 0;

void dfs(int u, int pre) {
    int child = 0;
    num[u] = low[u] = ++timeDFS;

    for (int v : adj[u]) {
        if (v == pre) continue;

        if (!num[v]) {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > num[u]) {
                cnt++;
            }

            if (pre != 0 && low[v] >= num[u]) {
                tru[u] = 1;
            }
        } else {
            low[u] = min(low[u], num[v]);
        }
    }

    if (pre == 0 && child > 1) {
        tru[u] = 1;
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    timeDFS = 0;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        num[i] = low[i] = tru[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            dfs(i, 0);
        }
    }

    int ar_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (tru[i]) ar_cnt++;
    }

    cout << ar_cnt << " " << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}