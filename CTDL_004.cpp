#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[105];
vector<int> res;
int cnt = 0;
void Try(int pos, int last_idx){
	if(pos == k){
		cnt++;
		return;
	}
	for(int i = last_idx + 1; i <= n; i++){
		if(res.empty() || a[i] > res.back()){
			res.push_back(a[i]);
			Try(pos + 1, i);
			res.pop_back();
		}
	}
}
int main (){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	Try(0,0);
	cout << cnt;
	return 0;
}