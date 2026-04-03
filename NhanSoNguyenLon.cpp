#include<bits/stdc++.h>
using namespace std;
string add(string a, string b){
	string res = "";
	int i = a.size() - 1, j = b.size() - 1, carry = 0;
	while(i >= 0 || j >= 0 || carry){
		int sum = carry;
		if(i >= 0) sum += a[i--] - '0';
		if(j >= 0) sum += b[j--] - '0';
		res += (sum % 10) + '0';
		carry = sum / 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

string minus_str(string a, string b){
	string res = "";
	int i = a.size() - 1, j = b.size() - 1, borrow = 0;
	while(a.size() > b.size()) b = "0" + b;
	for(int i = a.size() - 1; i >= 0; i--){
		int sub = (a[i] - '0') - (b[i] - '0') - borrow;
		if(sub < 0){	
			sub += 10;
			borrow = 1;
		}
		else{
			borrow = 0;
		}
		res += (sub + '0');
	}
	while(res.size() > 1 && res.back() == 0) res.pop_back();
	reverse(res.begin(), res.end());
	return res;
}

string multiple(string x, string y){
	// Làm cho độ dài 2 chuỗi bằng nhau bằng cách thêm '0' vào trước
	int n = max (x.size(), y.size());
	while(x.size() < n) x = "0" + x;
	while(y.size() < n) y = "0" + y;
	
 	// ĐIỀU KIỆN DỪNG: Nếu số có 1 chữ số, nhân trực tiếp
 	if(n == 1) return to_string((x[0] - '0') * (y[0] - '0'));
 	
	// Chia đôi độ dài (nếu n lẻ, phần đầu sẽ nhỏ hơn phần sau 1 đơn vị)
	int mid = n / 2;
	int n_mid = n - mid;
	string xh = x.substr(0, mid);
	string xl = x.substr(mid);
	string yh = y.substr(0, mid);
	string yl = y.substr(mid);
	
	// Đệ quy tính 3 giá trị cần thiết
	string a = multiple(xh, yh);
	string d = multiple(xl, yl);
	
	// P3 = (Xh + Xl) * (Yh + Yl)
	string sumX = add(xh, xl);
	string sumY = add(yh, yl);
	string e = multiple(sumX, sumY);
	
	// Tính thành phần ở giữa: mid_term = P3 - P1 - P2
	string mid_term = minus_str(minus_str(e,a), d);
	
	// Dịch chuyển các thành phần theo đúng lũy thừa của 10
    // a = a * 10^(2 * n_high)
    for(int i = 0; i < 2 * n_mid; i++){
    	a += "0";
    }
    
    // mid_term = mid_term * 10^(n_high)
    for(int i = 0; i < n_mid; i++){
    	mid_term += "0";
    }
    // Kết quả cuối cùng = a + mid_term + d
    string result = add(add(a, mid_term), d);
    // Xóa số 0 thừa ở đầu kết quả cuối cùng
    while(result.size() > 1 && result[0] == '0') result.erase(0, 1);
    return result;
}
int main (){
	string s1, s2;
	cin >> s1 >> s2;
	string tich = multiple(s1, s2);
	cout << tich << endl;
	return 0;
}