#include<bits/stdc++.h>
using namespace std;

struct state {
    int x, y, step;
};

int n, m;
char a[105][105];
bool is_bad[105][105][4];
bool visited[105][105][4];

int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1};

int get_laser(char c) {
    if(c == '^') return 0;
    if(c == '>') return 1;
    if(c == 'v') return 2;
    if(c == '<') return 3;
    return -1;
}

bool is_valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool block(char c) {
    return (c == '#' || c == '^' || c == '>' || c == 'v' || c == '<');
}

void solve() {
    if (!(cin >> n >> m)) return;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) {
                is_bad[i][j][k] = false;
                visited[i][j][k] = false;
            }
        }
    }

    int startX, startY, endX, endY;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'S') {
                startX = i; startY = j;
            } else if(a[i][j] == 'G') {
                endX = i; endY = j;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int flag = get_laser(a[i][j]);
            if(flag != -1) {
                for(int t = 0; t < 4; t++) {
                    int cur = (flag + t) % 4;
                    int nx = i + dx[cur];
                    int ny = j + dy[cur];
                    while(is_valid(nx, ny) && !block(a[nx][ny])) {
                        is_bad[nx][ny][t] = true;
                        nx += dx[cur];
                        ny += dy[cur];
                    }
                }
            }
        }
    }

    queue<state> q;
    q.push({startX, startY, 0});
    visited[startX][startY][0] = true;

    while(!q.empty()) {
        state curr = q.front();
        q.pop();

        if(curr.x == endX && curr.y == endY) {
            cout << curr.step << endl;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            int nStep = curr.step + 1;
            int nMod = nStep % 4;

            if(is_valid(nx, ny) && !block(a[nx][ny]) && !is_bad[nx][ny][nMod] && !visited[nx][ny][nMod]) {
                visited[nx][ny][nMod] = true;
                q.push({nx, ny, nStep});
            }
        }
    }
    cout << "impossible" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (!(cin >> t)) return 0;
    while(t--) {
        solve();
    }
    return 0;
}