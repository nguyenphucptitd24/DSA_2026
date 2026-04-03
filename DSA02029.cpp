#include<bits/stdc++.h>
using namespace std;
void backtrack(int n, string nguon, string dich, string trung_gian){
	if(n == 1){
		cout << nguon << " -> " << dich << endl;
		return;
	}
	backtrack(n - 1, nguon, trung_gian, dich);
	cout << nguon << " -> " << dich << endl;
	backtrack(n - 1, trung_gian, dich, nguon);
}
int main (){
	int n;
	cin >> n;
	backtrack(n, "A", "C", "B");
	return 0;
}