#include<bits/stdc++.h>
#define int long long
#define X first
#define Y second
#define oo 1000111000123456789LL
#define eps 0.0000000001
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define DOW(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;

int pow(int a, int b, int m);
int gcd(int a, int b);
int lcm(int a, int b);
bool isEqual(double a, double b);

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
vector<int> vec;
vector<ii> vi;
vector<iii> vii;
vector<iiii> viiii;

string s, ss, sss;
int x, y, z, t;
const int M = 1e9 + 7;

const int N = 1000111;
int T, n, m;
int a[N], b[N];





int32_t main(){	ios::sync_with_stdio(false); cin.tie(nullptr); 
	// freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	cin >> T;

	while(T--){


	}
}






//int binary_search(int l, int r){
//	
//	while(r-l+1 >= 3){
//	
//		int mid = (l + r) / 2;
//		
//		if (true) mid = l;
//		else mid = r;		
//	}
//	
//	FOR(mid, l, r){
//		
//		if (true) return mid;
//	} 
//	
//	return -1;		
//}


bool isEqual(double a, double b) {
    return fabs(a - b) < eps;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int pow(int a, int b, int m) {
    if (b == 0) return 1;
    
	int x = pow(a, b / 2, m);
    
	if (b % 2 == 0)
        return (x * x) % m;
        
    return (((x * x) % m) * a) % m;
}


