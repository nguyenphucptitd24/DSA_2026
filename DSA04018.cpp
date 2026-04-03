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
		int left = 0, right = n - 1, result = n;
		while(left <= right){
			int mid = left + (right - left) / 2;
			if(a[mid] == 1){
				result = mid;
				right = mid - 1;
			}
			if(a[mid] == 0){
				left = mid + 1;
			}
		}
		cout << result << endl;
	}
	return 0;
}