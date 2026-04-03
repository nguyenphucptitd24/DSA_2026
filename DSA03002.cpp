#include<bits/stdc++.h>
using namespace std;
string cong(string a, string b){
	string res = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry > 0){
    	int tong = carry;
    	if(i >= 0){
    		tong += (a[i] - '0');
    		i--;
		}
		if(j >= 0){
			tong += (b[j] - '0');
			j--;
		}
		res += to_string(tong % 10);
		carry = tong / 10;
	}
	reverse(res.begin(), res.end());
	return res;
}
int main (){
	string s1, s2;
	cin >> s1 >> s2;
	string min1 = "";
	string min2 = "";
	string max1 = "";
	string max2 = "";
	int n = s1.size(), m = s2.size();
	for(int i = 0; i < n; i++){
		if(s1[i] == '6'){
			min1 += '5';
		}
		else{
			min1 += s1[i];
		}
	}
	for(int i = 0; i < m; i++){
		if(s2[i] == '6'){
			min2 += '5';
		}
		else{
			min2 += s2[i];
		}
	}
	
	for(int i = 0; i < n; i++){
		if(s1[i] == '5'){
			max1 += '6';
		}
		else{
			max1 += s1[i];
		}
	}
	for(int i = 0; i < m; i++){
		if(s2[i] == '5'){
			max2 += '6';
		}
		else{
			max2 += s2[i];
		}
	}
	cout << cong(min1, min2) << " " << cong(max1, max2);
	return 0;
}