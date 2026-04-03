#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> value;
vector<int> arr;
bool check = 0;
void backtrack(int pos, int current_value){
	if(current_value == k){
		check = 1;
		cout << "[";
		for (int i = 0; i < value.size(); i++){
            cout << value[i] << (i == value.size() - 1 ? "" : " ");
        }
		cout << "] ";
		return;
	}
	for(int i = pos; i < n; i++){
		if(current_value + arr[i] <= k){
			value.push_back(arr[i]);
			backtrack(i + 1, current_value + arr[i]);
			value.pop_back();
		}
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		arr.resize(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		value.clear();
		check = 0;
		sort(arr.begin(), arr.end());
		backtrack(0, 0);
		if(!check) cout << -1;
		check = false;
		cout << endl;
	}
	return 0;
}