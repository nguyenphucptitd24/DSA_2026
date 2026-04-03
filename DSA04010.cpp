#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long max_val = -1e18;
		long long current_sum = 0;
		for(int i = 0; i < n; i++){
			current_sum += a[i];
			if(current_sum > max_val){
				max_val = current_sum;
			}
			if(current_sum < 0){
				current_sum = 0;
			}
		}
		cout << max_val << endl;
	}
	return 0;
}