
// QBSCHOOL - Đến trường
// Ngày 27/11 tới là ngày tổ chức thi học kỳ I ở trường ĐH BK. Là sinh viên năm thứ nhất, Hiếu không muốn vì đi muộn mà gặp trục trặc ở phòng thi nên đã chuẩn bị khá kỹ càng. Chỉ còn lại một công việc khá gay go là Hiếu không biết đi đường nào tới trường là nhanh nhất.
// Thường ngày Hiếu không quan tâm tới vấn đề này lắm cho nên bây giờ Hiếu không biết phải làm sao cả . Bản đồ thành phố là gồm có N nút giao thông và M con đường nối các nút giao thông này. Có 2 loại con đường là đường 1 chiều và đường 2 chiều. Độ dài của mỗi con đường là một số nguyên dương.
// Nhà Hiếu ở nút giao thông 1 còn trường ĐH BK ở nút giao thông N. Vì một lộ trình đường đi từ nhà Hiếu tới trường có thể gặp nhiều yếu tố khác như là gặp nhiều đèn đỏ , đi qua công trường xây dựng, ... phải giảm tốc độ cho nên Hiếu muốn biết là có tất cả bao nhiêu lộ trình ngắn nhất đi từ nhà tới trường. Bạn hãy lập trình giúp Hiếu giải quyết bài toán khó này.
// Input
// Dòng thứ nhất ghi hai số nguyên N và M.
// M dòng tiếp theo, mỗi dòng ghi 4 số nguyên dương K, U, V, L. Trong đó:
// K = 1 có nghĩa là có đường đi một chiều từ U đến V với độ dài L.
// K = 2 có nghìa là có đường đi hai chiều giữa U và V với độ dài L.
// Output
// Ghi hai số là độ dài đường đi ngắn nhấn và số lượng đường đi ngắn nhất. Biết rằng số lượng đường đi ngắn nhất không vượt quá phạm vì int64 trong pascal hay long long trong C++.
// Example
// Input:
// 3 2
// 1 1 2 3
// 2 2 3 1

// Output:
// 4 1

// Giới hạn:
// 1 ≤ N ≤ 5000
// 1 ≤ M ≤ 20000
// Độ dài các con đường ≤ 32000

// Code sử dụng Dijkstra_heap
// CODE
#include<bits/stdc++.h>
#define long long long
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for(long i=a; i<=b; i++)
using namespace std;

const long oo=(long)1e18;
const int N=1000111;
long n,m;
long k,u,l,v;
long d[N], F[N];
vector<int> a[N], b[N];

void Scanf(){
    cin >> n >> m;
    FOR(i, 1, m){
        cin >> k >> u >> v >> l;
        a[u].pb(v); b[u].pb(l);
        if (k==2){  a[v].pb(u); b[v].pb(l); }
    }
}

void Dijkstra_heap(){
    FOR(i, 1, n) d[i]= oo;
    d[1]= 0; F[1]= 1;

    priority_queue< pair<long, long> > Q;
    Q.push(mp(-d[1], 1));

    while(Q.size()){
        long du=-Q.top().first;
        long u= Q.top().second;
        Q.pop();

        if (du > d[u]) continue;

        for(long i=0; i<a[u].size(); i++){
            long v=a[u][i], val=b[u][i];

            if (d[v] == d[u] + val) F[v]+=F[u];

            if (d[v] > d[u] + val){
                d[v] = d[u] + val;
                F[v] = F[u];
                Q.push(mp(-d[v], v));
            }
        }
    }
    cout<<d[n]<<" "<<F[n];
}

int main(){
    Scanf();
    Dijkstra_heap();
}


// Dijkstra with Map for Vertex is pair<int, int>:
// https://laptrinhthidau.blogspot.com/2024/03/solution-uva-10801-lift-hopping.html
