#include<bits/stdc++.h>
#define int long long
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

int n;

int phi(int n) { //https://vnspoj.github.io/wikivn/algebra/phi-function
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int32_t main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	while(cin >> n && n){
		if (n==1) cout<<0<<"\n";
		else cout<<phi(n)<<"\n";
	}
 
}