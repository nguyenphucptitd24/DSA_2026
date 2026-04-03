#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> &a, int k, int n){
	for(int i = 0; i < k; i++){
		if(a[i] != n - k + i + 1){
			return true;
		}
	}
	return false;
}
int countElements(vector<int>& old_v, vector<int>& new_v) {
    unordered_set<int> st(old_v.begin(), old_v.end());
    int count = 0;
    for (int x : new_v) {
        if (st.find(x) == st.end()) {
            count++;
        }
    }
    return count;
}
int main (){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(k);
		int flag = 1;;
		for(int i = 0; i < k; i++){
			cin >> a[i];
		}
		vector<int> b = a;

		if(!check(a, k, n)){
			cout << k << endl;
			flag = 0;
		}
		if(flag == 1){
			int cnt = 0;
			int i = k - 1;
			while(a[i] == n - k + i + 1){
				i--;
			}
			a[i]++;
			if(i < 0) cout << k << endl;
			else{
				for(int j = i + 1; j < k; j++){
					a[j] = a[j - 1] + 1;
				}
				cout << countElements(b, a) << endl;
			}
		}
	}
	return 0;
}