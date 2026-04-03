#include<bits/stdc++.h>
using namespace std;
int n, k;
char res[25];
int cnt = 0;
void Try(int pos){
	if(pos > n){
		if(cnt % k == 0){
			for(int i = 1; i <= n; i++){
				cout << res[i];
			}
			cout << endl;
		}
		cnt++;
		return;
	}
	for(char i = '0'; i <= '1'; i++){
		res[pos] = i;
		Try(pos + 1);
	}
}
int main (){
	cin >> n >> k;
	Try(1);
	return 0;
}