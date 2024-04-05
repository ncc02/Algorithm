
// QBMST - Cây khung nhỏ nhất ( HEAP )
// Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm n đỉnh và m cạnh, các đỉnh được đánh số từ 1 tới n và các cạnh được đánh số từ 1 tới m. Hãy tìm cây khung nhỏ nhất của đồ thị G
// Input
// Dòng 1: Chứa hai số n, m (1 <= n <= 10000; 1 <= m <= 15000)
// M dòng tiếp theo, dòng thứ i có dạng ba số nguyên u, v, c. Trong đó (u, v) là chỉ số hai đỉnh đầu mút của cạnh thứ i và c trọng số của cạnh đó (1 <= u, v <= n; 0 <= c <= 10000).
// Output
// Gồm 1 dòng duy nhất: Ghi trọng số cây khung nhỏ nhất
// Example
// Input:
// 6 9
// 1 2 1
// 1 3 1
// 2 4 1
// 2 3 2
// 2 5 1
// 3 5 1
// 3 6 1
// 4 5 2
// 5 6 2

// Output:
// 5
// Root: https://vn.spoj.com/problems/QBMST/

// CODE
#include<bits/stdc++.h>
#define N 1000111
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

int n,m;
int fa[N];

struct Arr{
 int u,v,w; 
}; 
Arr a[N];
bool cmd(Arr a, Arr b){
 return a.w < b.w; 
}

int root(int u){
 return fa[u]=( fa[u]==u ? u : root(fa[u]) ); 
}
void join(int u, int v){
 fa[root(u)]=root(v); 
}

void Scanf(){
 cin >> n >> m;
 FOR(i, 1, m)
  cin >> a[i].u >> a[i].v >> a[i].w;
}
void Reset(){
 FOR(i, 1, n) fa[i]= i;
}
void Solve(){
 int ans=0;
 FOR(i, 1, m)
  if (root(a[i].u) != root(a[i].v)){
   
   join(a[i].u, a[i].v);
   ans+= a[i].w;
   if (--n == 1) break; 
  }
 cout<<ans; 
}

int main(){
 Scanf();
 Reset();
 sort(a+1, a+1+m, cmd); // m
 Solve();
}
