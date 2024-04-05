//  Problem	UVA: 10199 - Tourist Guide

// Algorithm by VNOI: https://vnoi.info/wiki/algo/graph-theory/Depth-First-Search-Tree.md#%E1%BB%A9ng-d%E1%BB%A5ng-c%C3%A2y-dfs-trong-b%C3%A0i-to%C3%A1n-t%C3%ACm-kh%E1%BB%9Bp-c%E1%BA%A7u

#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<=b; i++)
 
using namespace std;
 
const int maxN = 10010;

int n, m, test=0;
bool joint[maxN];
int timeDfs = 0, bridge = 0;
int low[maxN], num[maxN];
vector <int> g[maxN];
 
void dfs(int u, int pre) {
    int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            //if (low[v] == num[v]) bridge++;
            child++;
            if (u == pre) { // Nếu u là đỉnh gốc của cây DFS
                if (child > 1) joint[u] = true;
            }
            else if (low[v] >= num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}

void reset(){
    bridge= 0, timeDfs= 0;
    FOR(i, 1, n) low[i] = num[i] = 0, joint[i]= false, g[i].clear();
} 

void testcase() {
    if (test++) cout<<"\n";
    reset();
    
    unordered_map<string, int> encoding;
    unordered_map<int, string> decoding;
    FOR(i, 1, n){
        string s; cin >> s;
        encoding[s] = i;
        decoding[i] = s;
    }   
    
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string u, v;
        cin >> u >> v;
        
        int uu = encoding[u];
        int vv = encoding[v];
        
        g[uu].push_back(vv);
        g[vv].push_back(uu);
    }
    for (int i = 1; i <= n; i++) 
        if (!num[i]) dfs(i, i);

    int cntJoint = 0; 
    set<string> cities;
    for (int i = 1; i <= n; i++){
        cntJoint += joint[i];
        if (joint[i]) cities.insert(decoding[i]);
    
    }
    cout<<"City map #"<<test<<": "<<cntJoint<<" camera(s) found\n";
    for(auto city:cities) cout<<city<<"\n"; 
} 

int main(){
    while(cin >> n && n){
        testcase();
    }
}