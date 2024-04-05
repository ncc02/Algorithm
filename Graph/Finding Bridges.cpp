// Algo in VNOI: https://vnoi.info/wiki/algo/graph-theory/Depth-First-Search-Tree.md#%E1%BB%A9ng-d%E1%BB%A5ng-c%C3%A2y-dfs-trong-b%C3%A0i-to%C3%A1n-t%C3%ACm-kh%E1%BB%9Bp-c%E1%BA%A7u  



// Problem: http://uva.onlinejudge.org/external/7/796.pdf     



// Important:

// - Num[u]: index dfs to u

// - Low[u] : index dfs to u (but smallest) 



// Example:

// - You dfs 1 -> 2 -> 3->4 but can 2->4  (this num[4] is 4, but low[4] is 3) 



// Fomular: 

// - If (num[v] == low[v]) => (u,v) is bridge



#include<bits/stdc++.h>
#define int long long
#define oo LLONG_MAX
#define pb push_back
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

const int N= 1000111;
int t, n, u, v;
char c;
vector<int> a[N];
set<pair<int, int>> bridge;
int num[N], low[N];

int timeDfs = 0; // Thứ tự duyệt DFS

void dfs(int u, int pre) {
    num[u] = low[u] = ++timeDfs;
    for (int v : a[u]){
        if (v == pre) continue;
        if (!num[v]) {
            
            dfs(v, u);
            
            low[u] = min(low[u], low[v]);
            if (low[v]==num[v]) bridge.insert({min(u,v), max(u,v)});
        }
        else low[u] = min(low[u], num[v]);
    }
} 

void reset(){
    FOR(i, 0, t-1) a[i].clear(), num[i]= 0, low[i]= 0;
    bridge.clear();
    timeDfs = 0;
}

void read(){
    
    cin >> u >> c >> n >> c;
        
    FOR(i, 1, n){
        
        cin >> v;
        a[u].pb(v);
        a[v].pb(u);
    }

}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    while(cin >> t){    
        
        reset();
        FOR(i, 1, t) read();
        
        for (int i = 0; i <= t-1; i++) 
            if (!num[i]) dfs(i, i);
        
        cout << bridge.size() << " critical links" << endl;
        for(auto x:bridge) cout<<x.first<<" - "<<x.second<<"\n";    
        cout<<"\n"; 
    }
}




