#include <bits/stdc++.h>

using namespace std;

vector<int> start = {0,1,2,3,8,0,0,4,7,6,5}, state(11), A(11);

vector<int> revL(vector<int>A){
	vector<int> temp = A;
	temp[1] = A[4];
	temp[4] = A[8];
	temp[8] = A[9];
	temp[9] = A[6];
	temp[6] = A[2];
	temp[2] = A[1];
	return temp;
}

vector<int> revR(vector<int>A){
	vector<int> temp = A;
	temp[2] = A[5];
	temp[5] = A[9];
	temp[9] = A[10];
	temp[10] = A[7];
	temp[7] = A[3];
	temp[3] = A[2];
	return temp;
}

void solve(){
	vector<int> start = {0,1,2,3,8,0,0,4,7,6,5}, state(11), temp(11), rotR(11), rotL(11);
	start[0] = state[0] = 1;
	for (int i = 1; i <= 10; i++) cin >> state[i];
	queue<vector<int>> res;
	queue<int>ans;
	int cnt = 1;
	if (state == start){
		cout << 0;
		return;
	}
	res.push(state);
	ans.push(1);
	while (true){
		temp = res.front();
		res.pop();
		int tmpans = ans.front();
		ans.pop();
		rotR = revR(temp);
		rotL = revL(temp);
		if (rotR == start || rotL == start) {
			cout << tmpans;
			return;
		}
		res.push(rotR);
		res.push(rotL);
		ans.push(tmpans+1);
		ans.push(tmpans+1);
	}
}

int main() {
	solve();
	return 0;
}