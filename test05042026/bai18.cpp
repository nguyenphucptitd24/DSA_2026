#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(n < 3){
		cout << n << endl;
		return;
	}
	multiset<int> window;
	int left = 0;
	int maxLen = 0;
	for(int right = 0; right < n; right++){
		window.insert(a[right]);
		while(window.size() >= 3){
			auto it = window.begin();
			long long min1 = *it;
			long long min2 = *(++it);
			long long maxVal = *window.rbegin();
			if(min1 + min2 > maxVal){
				break;
			}
			else{
				window.erase(window.find(a[left]));
				left++;	
			}
		}
		maxLen = max(maxLen, (int)window.size());
	}
	cout << maxLen << endl;
}
int main (){
	solve();
	return 0;
}
