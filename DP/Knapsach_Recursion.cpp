#include<bits/stdc++.h>
using namespace std;

int n, q, d, m, test;	
int a[1000111];
unordered_map<string, int> F;

int f(int s, int u, int j){
	if (u==m){
		if (s==0) return 1;
		return 0;
	}
	string vec = to_string(s) + "," + to_string(u) + "," + to_string(j); 
	if (F.count(vec)) return F[vec];
	
	int r = 0;
	for(int i=j; i<=n; i++)
		r += f(((s + a[i])%d+d)%d, u+1, i+1);
		
	return F[vec] = r;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while(cin >> n >> q){ if (n==0 && q==0) break;
		
		for(int i=1; i<=n; i++) cin >> a[i];
		cout<<"SET "<<++test<<":\n";
		
		int query= 0;
		while(q--){
			F.clear();
			cin >> d >> m;
			cout<<"QUERY "<<++query<<": "<<f(0, 0, 1)<<"\n";
			
		}
	}	
}
