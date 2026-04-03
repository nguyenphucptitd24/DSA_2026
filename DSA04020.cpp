#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int left = 0, right = n - 1, check = 0;
		while(left <= right){
			int mid = left + (right - left)/2;
			if(a[mid] == k){
				cout << mid + 1<< endl;
				check = 1;
				break;
			}
			else if(a[mid] > k){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		if(check == 0) cout << "NO\n";
	}
	return 0;
}