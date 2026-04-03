#include<bits/stdc++.h>
using namespace std;
int n;
string name;
vector<string> others;
string res[15];
bool used[15];
void Try(int i){
	for(int j = 0; j < (int)others.size(); j++){
		if(!used[j]){
			res[i] = others[j];
			used[j] = true;
			if(i == (int)others.size() - 1){
				cout << name;
				for(int k = 0; k < (int)others.size(); k++){
					cout << " " << res[k];
				}
				cout << endl;
			}
			else{
				Try(i + 1);
			}
			used[j] = false;
		}
	}
}
int main (){
	cin >> n;
	vector<string> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> name;
	others.clear();
	for(int i = 0; i < n; i++){
		if(a[i] != name){
			others.push_back(a[i]);
		}
	}
	sort(others.begin(), others.end());
	memset(used, false, sizeof(used));
	if(others.empty()){
		cout << name << endl;
	}
	else{
		Try(0);
	}
	return 0;
}