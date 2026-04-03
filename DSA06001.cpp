#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<int> maxx, minn;
		sort(a.begin(),a.end());
		int left = 0;
	    int right = n - 1;
	
	    while (left <= right) {
	        if (left == right) {
	            cout << a[left] << " ";
	        } else {
	            cout << a[right] << " " << a[left] << " ";
	        }
	        left++;
	        right--;
	    }
	    cout << endl;
	}
	return 0;
}