#include<bits/stdc++.h>
using namespace std;
char s;
int k;
vector<char> character;
char res[20];
void backtrack(int start_idx, int current_len){
	if(current_len == k){
		for(int i = 0; i < k; i++){
			cout << res[i];
		}
		cout << endl;
		return;
	}
	for(int i = start_idx; i < character.size(); i++){
		res[current_len] = character[i];
		backtrack(i, current_len + 1);
	}
}
int main(){
	if (!(cin >> s >> k)) return 0;
	for(char i = 'A'; i <= s; i++){
		character.push_back(i);
	}
	backtrack(0, 0);
	return 0;
}