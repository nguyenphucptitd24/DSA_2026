#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<string> unique_name;
vector<string> current;
void backtrack(int start_idx, int k_left){
	if(k_left == 0){
		for(const string &name : current){
			cout << name << " ";
		}
		cout << endl;
		return;
	}
	for(int i = start_idx; i <= (int)unique_name.size() - k_left; i++){
		current.push_back(unique_name[i]);
		backtrack(i + 1, k_left - 1);
		current.pop_back();
	}
}
int main (){
	cin >> n >> k;
	set<string> save;
	for(int i = 0; i < n; i++){
		string name; cin >> name;
		save.insert(name);
	}
	for(const string &name : save){
		unique_name.push_back(name);
	}
	backtrack(0, k);
	return 0;
}