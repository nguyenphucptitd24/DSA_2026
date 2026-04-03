#include<bits/stdc++>
using namespace std;
vector<char> character;
char res[20];
char s;
bool checkAE(char c){
	if(c == 'A' || c == 'E') return 1;
	else return 0;
}
bool check (vector<char> c){
	for(int i = 1; i < c.size(); i++){
		if(checkAE(c[i])){
			if( (!checkAE(c[i - 1])) && (!checkAE(c[i + 1])) ){
				return false;
			}
		}
	}
	return true;
}
void backtrack(int start_idx, int current_val){
	if(current_val == (s - 'A')){
		for(int i = 0; i < current_val; i++){
			cout << res[i];
		}
		cout << endl;
		return;
	}
	for(int i = 0; i < s - 'A'; i++){
		
	}
}