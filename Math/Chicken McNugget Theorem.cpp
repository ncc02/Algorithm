// Problem: https://codeforces.com/contest/1526/problem/B



// Suggest:

// X = A * 111 + B * 11 

// https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem



// Code:

#include<bits/stdc++.h>

#define int long long

#define pb push_back

#define oo LLONG_MAX

#define FOR(i, a, b) for(int i=a; i<=b; i++)

using namespace std;



const int N= 1000111;

int t, a;



string f(){

	FOR(i, 0, a/111)

	FOR(j, 0, a/11)

		if (111*i + 11*j == a) return "YES";

	return "NO";

}



void solve(){

	cin >> a;

	int x = 111*11-111-11;

	if (a > x) cout<<"YES";

	else

		cout<<f();

	cout<<"\n";

}



int32_t main(){



	ios::sync_with_stdio(false);

	cin.tie(nullptr);



	cin >> t;



	while(t--){



		solve();

	}

}