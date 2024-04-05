// https://atcoder.jp/contests/abc209/tasks/abc209_d
#include<bits/stdc++.h>
#define pb push_back
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

const int N= 1000111; 
int n, u, v;
int visited[N];
vector<int> a[N];
int F[N];

    int q;
    
    
void reset(){
    FOR(i, 1, n) visited[i]= false, a[i].clear(), F[i]= 0;
}

void bfs(int s){
    queue<int> q; q.push(s); visited[s] = true; F[s] = 0;   
    
    while(!q.empty()){
        u = q.front(); q.pop();
        
        for(auto v:a[u])
            if (!visited[v]){
                    
                visited[v] = true;
                q.push(v);
                F[v] = F[u] + 1;
            } 

    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> n;
    reset();
    
        cin >> q; 
    
    FOR(i, 1, n-1) {cin >> u >> v; a[u].pb(v); a[v].pb(u);}
    
    bfs(1);
    
        FOR(i, 1, q){
            cin >> u >> v;
            
            int d = abs(F[u] - F[v]);
            if (d%2) cout<<"Road"; else cout<<"Town"; cout<<"\n";
        }
    
}