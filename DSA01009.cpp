#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<char> res; 
vector<string> ans;

bool check() {
    int so_cum_K = 0;
    int hien_tai = 0;
    for (int i = 0; i < n; i++) {
        if (res[i] == 'A') {
            hien_tai++;
        } else {
            if (hien_tai == k) so_cum_K++;
            else if (hien_tai > k) return false;
            hien_tai = 0;
        }
    }
    if (hien_tai == k) so_cum_K++;
    else if (hien_tai > k) return false;
    
    return so_cum_K == 1;
}

void Try(int pos) {
    if (pos == n) {
        if (check()) {
            string s = "";
            for (char x : res) s += x;
            ans.push_back(s);
        }
        return; 
    }

    for (char i = 'A'; i <= 'B'; i++) {
        res.push_back(i);
        Try(pos + 1);
        res.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if (!(cin >> n >> k)) return 0;
    
    Try(0);
    
    cout << ans.size() << endl;
    
    for (string x : ans) {
        cout << x << endl;
    }
    
    return 0;
}