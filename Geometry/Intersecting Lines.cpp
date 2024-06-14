/* 378 Intersecting Lines
 y = ax + b
 a = a , b = b => //
 a = a, b != b => =
 else => X
*/
#include<bits/stdc++.h>
using namespace std;

struct Point{
	double x, y;
};

struct Line{ 
	
	//Kind = 1, 2, 3, 4
	//<1> y = ax + b
	//<2> x = ?
	//<3> y = ?
	//<4> Point 
	
	int kind;
	double a, b;
	double x, y;
};

Line create_line(Point A, Point B){
	Line AB;
	
	if (A.x == B.x && A.y == B.y){ // AB is Point 
		
		AB.kind = 4;
		AB.x = A.x;
		AB.y = B.y;
		
		return AB;
	}
	
	if (A.x == B.x){ // AB is x = ?
		AB.kind = 2;
		AB.x = A.x;
		
		return AB;
	}
	
	if (A.y == B.y){ // AB is y = ?
		AB.kind = 3;
		AB.y = A.y;
		
		return AB;
	}
	
	AB.kind = 1;
	AB.a = (A.y - B.y) / (A.x - B.x);
	AB.b = A.y - AB.a * A.x;
	return AB;  	//AB is y = ax + b
}

void find_intersecting(Line AB, Line CD, Point A, Point B, Point C, Point D){
//	cout<<"\n-----------------\n";	
//	cout<<AB.a<<" "<<AB.b<<"\n";
//	cout<<CD.a<<" "<<CD.b<<"\n";
//	cout<<"-----------------\n";
	
	if (AB.kind == 1){ // y = ax + b
	
		if (CD.kind == 1){
			
			//Find point
			double a = AB.a - CD.a;
			double b = CD.b - AB.b;
			double x = b / a;
			double y = AB.a * x + AB.b;
			if (isinf(x) && isinf(y)) cout<<"NONE\n";
			else if(isnan(x) && isnan(y)) cout<<"LINE\n";
				else cout << "POINT "<<fixed<<setprecision(2)<<x<<" "<<y<<"\n";	
			return;	
		}
		
		if (CD.kind == 2){ // x = ? 
			
			double x = CD.x;
			double y = AB.a * x + AB.b;
			cout << "POINT "<<fixed<<setprecision(2)<<x<<" "<<y<<"\n";	
			return;
		}
		
		if (CD.kind == 3){ // y = ? 
			
			double y = CD.y;
			double x = (y - AB.b) / AB.a;
			cout << "POINT "<<fixed<<setprecision(2)<<x<<" "<<y<<"\n";	
			return;
		}	
			
	}
	
	
	if (AB.kind == 2){ //x
		
	
		if (CD.kind == 2){ //x
			if (AB.x == CD.x) cout<<"LINE\n";	
			else
				cout<<"NONE\n";
			return;
		}
	
		if (CD.kind == 3){//y
			double x = AB.x;
			double y = CD.y;
			cout << "POINT "<<fixed<<setprecision(2)<<x<<" "<<y<<"\n";
			return;
		}
		
	}
	
	if (AB.kind == 3 && CD.kind == 3){ // y y
		if (AB.y == CD.y) cout<<"LINE\n";	
		else
			cout<<"NONE\n";
		return;
	}
	
	find_intersecting(CD, AB, C, D, A, B); //only 1 call because return
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout<<"INTERSECTING LINES OUTPUT\n";
	int t; cin >> t;
	while(t--){
		
		Point A, B, C, D;
		cin >> A.x >> A.y;
		cin >> B.x >> B.y;
		cin >> C.x >> C.y;
		cin >> D.x >> D.y;
		
		Line AB = create_line(A, B);
		Line CD = create_line(C, D);
		find_intersecting(AB, CD, A, B, C, D);
	}
	cout<<"END OF OUTPUT\n";
}
