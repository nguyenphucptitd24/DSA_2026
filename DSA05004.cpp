#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int a[MAXN];
int memo[MAXN];
int LIS(int i){
	if(memo[i] != -1){
		return memo[i];
	}
	int res = 1;
	for(int j = 0; j < i; j++){
		if(a[i] > a[j]){
			res = max(res, LIS(j) + 1);
		}	
	}
	return memo[i] = res;
}
int main (){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	fill(memo, memo + n, -1);
	int maxLength = 1;
	for(int i = 0; i < n; i++){
		maxLength = max(maxLength, LIS(i));
	}
	cout << maxLength;
	return 0;
}