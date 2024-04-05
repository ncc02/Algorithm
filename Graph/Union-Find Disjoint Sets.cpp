// Problem: https://onlinejudge.org/external/7/793.pdf
// Code Accepted:

 #include<bits/stdc++.h>
#define N 1000111
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

int n,t;
int fa[N];

void Reset(){
 FOR(i, 1, n) fa[i]= i;
}
int root(int u){
 return fa[u]=( fa[u]==u ? u : root(fa[u]) ); 
}
void join(int u, int v){
 fa[root(u)]=root(v); 
}


void Scanf(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
     while(t--){
         cin >> n;
         cin.ignore();
         Reset();
         
         string s;
         int True= 0, False= 0, u, v; 
        while(getline(cin, s)){
        
            if (s=="") break;
            
            char kind= s[0];
            
            string s1= "";
            int i;
            for(i=2; s[i] != ' '; i++) 
                    s1 += s[i];
            u=stoi(s1);
            i++; 
            s1="";
            for(i=i; s[i]; i++) 
                s1 += s[i];
            v=stoi(s1);
            
            
            if (kind == 'c'){
                join(u, v);
            }
            else{
                
                if (root(u) == root(v)){
                    True++;
                }   
                else False++;
            }
        }
        cout<<True<<","<<False<<"\n";
        if (t>0) cout<<"\n";
        
    }
}

int main(){
 Scanf();
}






Problem:  UVA - 11503 

Code Accepted:

#include<bits/stdc++.h>
#define N 1000111
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

int n,t;
unordered_map<string, string> fa;
unordered_map<string, int> cnt;

void Reset(){
 fa.clear();
 cnt.clear();
}
string root(string u){
 return fa[u]=( fa[u]==u ? u : root(fa[u]) ); 
}
void join(string u, string v){  
 if (root(u) == root(v)) return;
 cnt[root(v)] += cnt[fa[root(u)]];
 fa[root(u)] = root(v); 

}


void Scanf(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
     while(t--){
         cin >> n;
        
         Reset();
         string u,v;
         
         while(n--){
            cin >> u >> v;
            
            if (not fa.count(u)) fa[u] = u, cnt[u] = 1;
            if (not fa.count(v)) fa[v] = v, cnt[v] = 1;
            
            join(u, v); 
            cout << cnt[fa[root(u)]] << "\n";
        }
         


        
    }
}

int main(){
 Scanf();
}



