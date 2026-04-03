#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<string> s;
bool visited[10];
int curr[10];
int min_diff = 1e9;
int p[10];
void calculate(){
	int curr_max = -1e9;
	int curr_min = 1e9;
	for(int i = 0; i < n; i++){
		int val = 0;
		for(int j = 0; j < k; j++){
			val = val * 10 + (s[i][p[j]] - '0');
		}
		if(val > curr_max) curr_max = val;
		if(val < curr_min) curr_min = val;
	}
	if(curr_max - curr_min < min_diff){
		min_diff = curr_max - curr_min;
	}
}
void backtrack(int pos){
	if(pos == k){
		calculate();
		return;
	}
	for(int i = 0; i < k; i++){
		if(!visited[i]){
			visited[i] = true;
			p[pos] = i;
			backtrack(pos + 1);
			visited[i] = false;
		}
	}
}
int main (){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		visited[i] = false;
		string a;
		cin >> a;
		s.push_back(a);
	}
	backtrack(0);
	cout << min_diff;
	return 0;
}