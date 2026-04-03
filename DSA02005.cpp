#include<bits/stdc++.h>
using namespace std;
string s;
bool visited[100];
string current;
void backtrack(int pos){
	int n = s.length();
	if(pos == n){
		cout << current << " ";
		return;
	}
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			visited[i] = true;
			current.push_back(s[i]);
			backtrack(pos + 1);
			current.pop_back();
			visited[i] = false;
		}
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		sort(s.begin(), s.end());
		memset(visited, false, sizeof(visited));
		current = "";
		backtrack(0);
		cout << endl;
	}
	return 0;
}