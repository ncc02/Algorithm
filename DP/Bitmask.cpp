//https://codeforces.com/problemset/problem/1097/B

#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define oo LLONG_MAX
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

const int N= 1000111;
int t, n;
int a[N];

void solve(){

    cin >> n;
    
    FOR(i, 0, n-1) cin >> a[i];
    
    for(int i=0; i < (1<<n); i++){ //i < 2^n
        
        int s = 0;
        
        for(int j=0; j < n; j++)
            if (i & (1 << j)) s += a[j]; //i & 2^j
                else s -= a[j]; 
        
        if (s % 360 == 0){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}

/*
//This is version more easy,

#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define oo LLONG_MAX
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

const int N= 1000111;
int t, n;
int a[N];

void solve(){

    cin >> n;
    
    FOR(i, 0, n-1) cin >> a[i];
    
    for(int i=0; i < pow(2,n); i++){
        
        string bitmask = bitset<15>(i).to_string().substr(15 - n);
        int k = 0, s = 0;
        
        for(int j=0; bitmask[j]; j++)
            if (bitmask[j] == '1') s += a[j];
                else s -= a[j]; 
        
        if (s % 360 == 0){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
*/