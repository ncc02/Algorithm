//  11080 - Place the Guards
#include<bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1000111;
int t, V, E, u, v;
vector<int> a[N];

void reset(){
	
	for(int i=0; i<V; i++) a[i].clear();
}

int process(){

	int r = 0;
	queue<int> q;
	vector<int> color(V);
	
	for(int i = 0; i<V; i++)
	if (color[i] == 0){
		
		q.push(i); color[i] = 1; 
		unordered_map<int, int> cnt;
		cnt[1]++;
		
		while(not q.empty()){
	
			u = q.front(); q.pop();
			
			for(auto v:a[u])
			if (color[v] == 0){
				
				q.push(v);
				
				color[v] = 3 - color[u];
				cnt[3-color[u]]++;
			} 
			else if (color[v] == color[u]) return -1;
		}
		
			
		r += min(cnt[1], (cnt[2] == 0 ? 1000111000 : cnt[2]));
	}
	
	return r;
}

void input(){
	
	ios::sync_with_stdio(false); cin.tie(nullptr);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin >> t;
	while(t--){
		
		cin >> V >> E; 
		for(int i=0; i<E; i++){
			
			cin >> u >> v;
			a[u].pb(v);
			a[v].pb(u);
		}
		
		if (E == 0) cout<<V<<"\n";
			else cout<<process()<<"\n";
		
		reset();
	}
	
}

int main(){
	input();
	
}
