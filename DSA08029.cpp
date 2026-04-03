#include<bits/stdc++.h>
using namespace std;
string rotateL(string s) {
    string res = s;
    res[0] = s[3]; 
    res[1] = s[0]; 
    res[4] = s[1]; 
    res[3] = s[4];
    return res;
}
string rotateR(string s){
	string res = s;
	res[1] = res[4];
	res[2] = res[1];
	res[5] = res[2];
	res[4] = res[5]; 
	return res;
}
void solve(){
	string start = "", target = "";
	for(int i = 0; i < 6; i++){
		cin >> x;
		start += to_string(x);
	}
	for(int i = 0; i < 6; i++){
		cin >> x;
		target += to_string(x);
	}
	if(start == target) cout << 0 << endl;
	queue<string> q;
	map<string, int> dist;
	q.push(start);
	dist[start] = 0;
	while(!q.empty()){
		string u = q.front();
		q.pop();
		if(u == target){
			cout << dist[u] << endl;
			return;
		}
		string vL = rotateL(u);
        if (dist.find(vL) == dist.end()) {
            dist[vL] = dist[u] + 1;
            q.push(vL);
        }
        string vR = rotateR(u);
        
	}
}