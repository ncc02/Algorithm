//UVA 11151 Longest Palindrome
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

int cnt = 0;
string a, b;
int F[1001][1001];

int DP(){
	int n = a.size(), m = b.size();
	
	FOR(i, 1, n)
	FOR(j, 1, m)
		if (a[i-1] == b[j-1]) F[i][j] = F[i-1][j-1] + 1; 
		else F[i][j] = max(F[i-1][j], F[i][j-1]);
		
	return F[n][m];
}

string rev(string s){
	string x = "";
	for(int i=0; s[i]; i++)
		x = s[i] + x;
	return x;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;	cin >> t; getline(cin, a);
	while(t--){
		getline(cin, a);
		b = rev(a);
		
		cout<<DP()<<"\n";
	}
}
