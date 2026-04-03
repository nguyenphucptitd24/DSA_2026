#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b.begin(), b.end());
		int i = 0;
		while(i < n){
			if(a[i] == b[i]){
				i++;
			}
			else{
				cout << i + 1 << " ";
				break;
			}
		}	
		int j = n - 1;
		while(j > i){
			if(a[j] == b[j]){
				j--;
			}
			else{
				cout << j + 1 << endl;
				break;
			}
		}
	}
	return 0;
}