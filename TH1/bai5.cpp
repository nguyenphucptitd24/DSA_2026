#include<bits/stdc++.h>
using namespace std;
long long length[50];
long long countA_total[50];
void compute(){
	length[0] = 1; countA_total[0] = 1;
	length[1] = 1; countA_total[1] = 0;
	for(int i = 2; i <= 45; i++){
		length[i] = length[i - 1] + length[i - 2];
		countA_total[i] = countA_total[i - 1] + countA_total[i - 2];
	}
}
long long countA_in_k(int n, long long k){
	if (k <= 0) return 0;
	if(n == 0) return 1;
	if(n == 1) return 0;
	if(k <= length[n - 1]){
		return countA_in_k(n - 1, k);
	}
	else{
		return countA_total[n - 1] + countA_in_k(n - 2, k - length[n - 1]);
	}
}
int main (){
	compute();
	int t;
	cin >> t;
	while(t--){
		int n;
		long long k;
		cin >> n >> k;
		cout << countA_in_k(n, k) << endl;
	}
	return 0;
}