// Problem: http://uva.onlinejudge.org/external/108/10827.pdf

// Code Accepted:

#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

const int N= 1001;
int n, t;
int a[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;   
    while(t--){
        
        cin >> n;   FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];

        
        FOR(i, 1, n) FOR(j, 1, n) a[i+n][j] = a[i][j+n] = a[i+n][j+n] = a[i][j];    
                
        
        FOR(i, 1, 2*n) FOR(j, 1, 2*n) a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        
        int s= -1000111000;
        FOR(x, 1, n) FOR(y, 1, n) FOR(z, x, x+n-1) FOR(t, y, y+n-1)
                s = max(s, a[z][t] - a[x-1][t] - a[z][y-1] + a[x-1][y-1]);
        cout<< s <<"\n";
    }
}