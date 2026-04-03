#include<bits/stdc++.h>
using namespace std;
struct Job{
	int s, p;
};
bool compare(Job a, Job b){
	if(a.s != b.s){
		return a.s < b.s;
	}
	return a.p > b.p;
}
int main (){
	int n;
	while(cin >> n){
		vector<Job> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i].s >> v[i].p;
		}
		sort(v.begin(), v.end(), compare);
		priority_queue<int, vector<int>, greater<int>> pq;
		for(int i = 0; i < n; i++){
			if(pq.size() < (size_t)v[i].s){
				pq.push(v[i].p);
			}
			else if (!pq.empty() && v[i].p > pq.top()){
				pq.pop();
				pq.push(v[i].p);
			}
		}
		long long res = 0;
		while(!pq.empty()){
			res += pq.top();
			pq.pop();
		}
		cout << res << endl;
	}
	return 0;
}