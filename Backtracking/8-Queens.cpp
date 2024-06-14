//UVA 11085 - Back to the 8-Queens
#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<=b; i++)
using namespace std;

vector<vector<int>>a;
vector<int> b;
bool h[100];
bool cc[100];
bool cp[100];


void f(int cot){
	if (cot == 9){
		a.push_back(b);	
		return;
	}
	
	FOR(hang, 1, 8){
		
		if (h[hang] == true) continue;
		if (cc[hang-cot + 8] == true) continue;
		if (cp[hang+cot] == true) continue;
		
		
		h[hang]= true;
		cc[hang-cot + 8] = true;
		cp[hang+cot] = true;
		
		b.push_back(hang);
		f(cot+1);
		
			b.pop_back();
			h[hang]= false;
			cc[hang-cot + 8] = false;
			cp[hang+cot] = false;	
	}
	
}

int main(){
	
	f(1);
//	for(auto vec:a){
//		cout<<"\n";
//		for(auto v:vec) cout<<v<<" ";
//	}
//	cout<<a.size()<<"\n";
//	
	
	vector<int> v(8);
	int cnt = 0;
	while(cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5] >> v[6] >> v[7]){
		int res= 1000111000;
		for(auto vec: a){
			int s = 0;
			for (int i=0; i<vec.size(); i++)
				s += (vec[i] == v[i] ? 0 : 1);
			res = min(res, s);
		}
		cout<<"Case "<<++cnt<<": "<<res<<"\n";
	}
}
