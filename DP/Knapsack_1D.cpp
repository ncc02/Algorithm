/*
Problem	  Verdict	Lang	Time	Best	Rank	Submit Time
 | discuss10819 - Trouble of 13-Dots	 Accepted	C++11	0.040	0.000	415	1 mins ago

Suggest:
- DP knapsack range m+200
- Get result with 3 case:
+ m <= 1800
+ 1801 <= m <= 2000
+ m >= 2001

Code implenment by suggest:
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1000111];
int b[1000111];

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	while(cin >> m >> n){
		for(int i=1; i<=n; i++) cin >> a[i] >> b[i];
		
		vector<int> f(m+201, 0);
			
		for(int i=1; i<=n; i++)
			for(int j=m+200; j>=a[i]; j--)
				if (f[j - a[i]] > 0 || j == a[i])
						f[j] = max(f[j], f[j - a[i]] + b[i]);
		
		int res = 0;
		for(int i=0; i<=m; i++)
			res = max(res, f[i]);
	
		if (1801 <= m <= 2000){
			for(int i=2001; i<=m+200; i++)
				res = max(res, f[i]);
		}
			
		if (m >= 2001){
			for(int i=0; i<=m+200; i++)
				res = max(res, f[i]);
		}
							
		cout<<res<<"\n";
	}
}
