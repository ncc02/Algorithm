#include<bits/stdc++.h>
using namespace std;

int n, m;

int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
      res = (res + k) % i;
    return res + 1;
}
//OR a[i] = (a[i-1] + k - 1) % (n+i-1) 

int main(){
	cin >> n >> m;
	cout<<josephus(n, m);
	
}

//UVA 305
//#include<bits/stdc++.h>
//using namespace std;
//
//bool PUBG(int n, int m){//return index of array
//
//	bool found = true;
//	int pos = 0;
//
//	for(int i=1; i<=n; i++){
//		
//		pos = (pos + m - 1) % (2*n-i+1);
//
//		if (pos + 1 <= n){
//
//			found = false;
//		}
//	}
//
//	return found;
//}
//
//
//int main(){
//	for(int i=1; i<14; i++)
//		for(int j=i+1; ; j++)	
//			if (PUBG(i, j)) {
//				cout<<i<<" - "<<j<<"\n";
//				break;
//			}
//}
