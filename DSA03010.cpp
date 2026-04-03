#include<bits/stdc++.h>
using namespace std;
int main (){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for(int i= 0; i < n; i++){
			long long val;
			cin >> val;
			pq.push(val);
		}
		long long total = 0;
		while(pq.size() > 1){
			long long first = pq.top();
			pq.pop();
			long long second = pq.top();
			pq.pop();
			long long current = first + second;
			total += current;
			pq.push(current);
		}
		cout << total << endl;
	}
	return 0;
}