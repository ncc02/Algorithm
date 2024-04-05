//https://onlinejudge.org/external/100/10000.pdf

#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define oo LLONG_MAX
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

const int N= 1000111;
int t, n, s, res, ff, test;
vector<int> a[N];
int F[N];

void reset(){
    res = 0;
    FOR(i, 1, n) a[i].clear();
}

void sslp(int s){
    queue<int> q; q.push(s); 
    
    FOR(i, 1, n) F[i]= -oo; F[s] = 0;
    vector<int> inQ(n+1, false);
    
    while(not q.empty()){
        
        int u = q.front(); q.pop(); inQ[u] = false;
        
        for(auto v:a[u])
            if (F[v] < F[u] + 1){
                
                if (not inQ[v]) {
                    q.push(v);  
                    inQ[v] = true;
                }

                F[v] = F[u] + 1;
            }
    }
}

void solve(){
    reset();    
        
    cin >> s; int u,v;
    while(cin >> u >> v){
        if (u==0 && v==0) break;
        a[u].pb(v);
    }
    sslp(s);
    int res = -oo, last= 0;
    FOR(i, 1, n) 
    if (res < F[i]){
        last = i;
        res= max(res, F[i]);    
    }
    cout<<"Case "<<test<<": The longest path from "<<s<<" has length "<<res<<", finishing at "<<last<<".\n\n";
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> n && n){
        ++test;
        solve();
    }
}