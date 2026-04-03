#include<bits/stdc++.h>
using namespace std;
int k;
string s;
long long countS = 0;
bool check (string s){
	int soluongdau = 0;
	int maxDepth = 0;
	for(char c : s){
		if(c == '('){
			soluongdau++;
			maxDepth = max(maxDepth, soluongdau);
		}
		else{
			soluongdau--;
		}
		if (soluongdau < 0) return false;
	}
	return (soluongdau == 0 && maxDepth == k);
}
void backtrack(int index, string currentS){
	if(index == s.length()){
		if(check(currentS)){
			countS++;
		}
		return;
	}
	if(s[index] == '?'){
		backtrack(index + 1, currentS + '(');
		backtrack(index + 1, currentS + ')');
	}
	else{
		backtrack(index + 1, currentS + s[index]);
	}
}
int main (){
	cin >> k >> s;
	backtrack(0, "");
	cout << countS << endl;
	return 0;
}