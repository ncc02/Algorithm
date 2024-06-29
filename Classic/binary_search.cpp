//UVA: 11413 - Fill the Containers
#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[1000111];

int main(){
	while(cin >> n >> m){
		
		m = min(n, m);
		
		for(int i=1; i<=n; i++)
			cin >> a[i];
		
		int r = 0;
		for(int i=1; i<=n; i++)
			r += a[i];	
		
		
		int l= 1;
		
		while(r-l+1 >= 3){
			
			int mid = (r + l) / 2;
			int s = 0;
			int container= 0;
			bool bl = false;
			
			for(int i=1; i<=n; i++)
			if (a[i] + s <=  mid){
				s += a[i];	
				bl = true;
			} 
			else{
				if (not bl) {
					container = m + 1;
					break;	
				}
				if (bl) container++;
				bl = false;
				s = 0;
				i--;
			}
			
			if (bl) container++;
			
		//	cout<<"mid container: "<<mid<<" "<<container<<"\n";
			
			if (container > m) l = mid;
			else 
				r = mid;
		}
		
		for(int mid=l; mid<=r; mid++){
			
			int s = 0;
			int container= 0;
			bool bl = false;
			
			for(int i=1; i<=n; i++)
			if (a[i] + s <=  mid){
				s += a[i];	
				bl = true;
			} 
			else{
				if (not bl) {
					container = m + 1;
					break;	
				}
				if (bl) container++;
				bl = false;
				s = 0;
				i--;
			}
			
			if (bl) container++;
			
			if (container <= m){
				cout << mid <<"\n";	
				break;
			}			
			
		}
		
		
	}
	
		
}
