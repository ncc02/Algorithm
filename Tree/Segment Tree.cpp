
// MINR - Số nhỏ nhất trong dãy con

// Giới hạn thời gian: 1.0 giây
// Giới hạn bộ nhớ: 128 megabyte

// Cho một mảng gồm n số nguyên a1, a2, a3,..., an. Có m câu hỏi, mỗi câu gồm hai số nguyên 1 ≤ p ≤ r ≤ n, yêu cầu tìm số nguyên nhỏ nhất trong các số ap, ap+1, ..., ar. Hãy cho biết kết quả của m câu hỏi trên.
// Dữ liệu nhập: gồm các dòng sau
// - Dòng thứ nhất là hai số nguyên n, m cách nhau một khoảng trắng (1 ≤ n, m ≤ 105)
// - Dòng thứ hai là n số nguyên a1, a2, a3,..., an cách nhau một khoảng trắng (1 ≤ ai ≤ 109)
// - Trong m dòng tiếp theo, tại dòng thứ i là hai số pi và ri của câu hỏi thứ i tương ứng, hai số cách nhau một khoảng trắng. (1 ≤ pi ≤ ri ≤ n)
// Dữ liệu xuất:
// - Gồm m dòng, mỗi dòng có một số nguyên là kết quả của câu hỏi tương ứng.

// Ví dụ
// input
// 6 4
// 7 5 3 8 6 9
// 1 6
// 1 4
// 1 2
// 4 6
// output
// 3
// 3
// 5
// 6

// CODE
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

const int N=1000111;
const int oo=1000111000;
int n,m;
int A, B;
int a[N], id[4*N], st[4*N];

void build(int id, int l, int r){
    if (l==r){
        st[id]= a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id]=min(st[id*2], st[id*2+1]);
}

int getMIN(int id, int l, int r){
    if (r < A || l > B) return oo;
    if (A <= l && r <= B) return st[id];
    int mid=(l+r)/2;
    return min( getMIN(id*2, l, mid) ,getMIN(id*2+1, mid+1, r) );
}

int main(){
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];

    build(1, 1, n);

    FOR(i, 1, m){
          cin >> A >> B;
        cout<<getMIN(1, 1, n)<<"\n";
    }

}
    


// 11235 Frequent values
// 11235 Frequent values
// UVA Problem : 11235 - Frequent values 
// Link: https://onlinejudge.org/external/112/11235.pdf

// Suggest:
// - Lv0: Use RMQ for with value is frequence of a[i]
// - Lv1: https://algorithmist.com/wiki/UVa_11235
// - Lv2: https://niceproblems.blogspot.com/2012/05/uva-11235-frequent-values.html

// Code Accepted:

#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

const int N=1000111;
const int oo=1000111000;
int n,m;
int A, B;
int a[N], st[4*N];
unordered_map<int, int> cnt, start;

void build(int id, int l, int r){
    if (l==r){
        st[id]= cnt[ a[l] ];
        return;
    }
    int mid=(l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id]=max(st[id*2], st[id*2+1]);
}

int getMAX(int id, int l, int r){
    if (r < A || l > B) return -oo;
    if (A <= l && r <= B) return st[id];
    int mid=(l+r)/2;
    return max( getMAX(id*2, l, mid) ,getMAX(id*2+1, mid+1, r) );
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin >> n && n){
        cin >> m;
        cnt.clear();
        
        FOR(i, 1, n){
            
            cin >> a[i];
            cnt[a[i]]++;
            if (cnt[a[i]]==1) start[a[i]]= i;
        } 
    
        build(1, 1, n);
        
        
        
        FOR(i, 1, m){
            cin >> A >> B;
            if (a[A] == a[B]) cout<<B-A+1<<"\n";
            else{
                int resL = start[  a[A]  ] + cnt[ a[A] ] - A; 
                int resR = B - start[ a[B] ] + 1;
                int ans= max(resL, resR);
                
                
                A= start[ a[ A ] ] + cnt[ a[ A ] ] ;
                B = start[ a[ B ] ] - 1;
                
                cout<<max(ans, getMAX(1, 1, n))<<"\n";
            }
                
        }   
    }
}
    

