//https://www.mathvn.com/2020/01/cong-thuc-tinh-tong-cac-uoc-nguyen.html
#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
using namespace std;

int sum_div(int n) {
    map<int, int> cnt;
    
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            cnt[i]++;
            n /= i;
        }
    }
    if (n != 1) {
        cnt[n]++;
    }
    
    int res = 1;
    for(auto p:cnt)
    	res *= (pow(p.X, p.Y+1) - 1) / (p.X - 1);
    return res;
}	

int n;

int32_t main(){
	cin >> n;
	cout << sum_div(n);
}
