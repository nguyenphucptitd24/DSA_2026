#include<bits/stdc++.h>
using namespace std;
int n, a[15][15];
vector<string> res;
bool found = false;
void backtrack(int i, int j, string path){
	if(i == n - 1 && j == n - 1){
		found = true;
		res.push_back(path);
	}
	if((a[i + 1][j] == 1) && (i + 1 < n) ){
		backtrack(i + 1, j, path + 'D');
	}
	if((a[i][j + 1] == 1) && (j + 1 < n) ){
		backtrack(i, j + 1, path + 'R');
	}
}
int main (){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		found = false;
		if (a[0][0] == 1) {
            backtrack(0, 0, "");
        }
		if(found){
			for(string path : res){
				cout << path << " ";
			}
		}
		else{
			cout << -1;
		}
		res.clear();
		cout << endl;
	}
	return 0;
}