//UVA 191 Intersection
//https://www.geeksforgeeks.org/program-for-point-of-intersection-of-two-lines/
#include <bits/stdc++.h>
#define oo LLONG_MAX
#define int long long
using namespace std;

int t;

struct Point{
	double x, y;
};

struct Equation{
	double a, b, c;
};

struct Line{
	double a=oo, b=oo, y= oo, x= oo;	
};

Line create_line(Point P, Point Q){ 	
	Equation e1;
	e1.a = P.x;
	e1.b = 1;
	e1.c = P.y;
	
	Equation e2;
	e2.a = Q.x;
	e2.b = 1;
	e2.c = Q.y;		
	
	double c = e1.c - e2.c; 
	double a = e1.a - e2.a;
	Line PQ;
	
	if (a == 0) { // x = a 
		PQ.x = e1.a;
		return PQ;
	}
	if (c == 0) { // y = c
		PQ.y = e1.c;
		return PQ;
	}
	
	
	PQ.a = c / a;
	PQ.b = P.y - PQ.a * P.x;
	return PQ;
}

bool cut(Line PQ, Line AB, Point A, Point B){
	Point O;
	O.x = oo;
	O.y = oo; 
	if (PQ.x != oo && AB.y != oo){
		O.x = PQ.x;
		O.y = AB.y;
	}
	else if (PQ.y != oo && AB.x != oo){
		O.x = AB.x;
		O.y = PQ.y;
	}
	else {

		double a = PQ.a - AB.a;
		double b = AB.b - PQ.b;
		O.x = b / a;
		O.y = PQ.a * O.x + PQ.b;

	}
	double x_min = min(A.x, B.x);
	double x_max = max(A.x, B.x);
	double y_min = min(A.y, B.y);
	double y_max = max(A.y, B.y);
	
//	if ((x_min <= O.x && O.x <= x_max) && (y_min <= O.y && O.y <= y_max))
//	cout<<A.x<<" "<<A.y<<" "<<B.x<<" "<<B.y<<"\n";
	
	return (x_min <= O.x && O.x <= x_max) && (y_min <= O.y && O.y <= y_max); 
}

bool cum(Point P, Point Q, Point A, Point D){
	double x_min = min(A.x, D.x);
	double x_max = max(A.x, D.x);
	double y_min = min(A.y, D.y);
	double y_max = max(A.y, D.y);
	return (x_min <= P.x && P.x <= x_max) && (x_min <= Q.x && Q.x <= x_max) && (y_min <= P.y && P.y <= y_max) && (y_min <= Q.y && Q.y <= y_max);
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> t;
	while(t--){
		Point P, Q, A, B, C, D;
		cin >> P.x >> P.y >> Q.x >> Q.y >> A.x >> A.y >> C.x >> C.y;
		B.x = C.x;
		B.y = A.y;
		D.x = A.x;
		D.y = C.y;
		
		
		Line PQ = create_line(P, Q);
		Line AB = create_line(A, B);
		Line BC = create_line(B, C);
		Line CD = create_line(C, D);
		Line AD = create_line(A, D);

		if (cut(PQ, AB, A, B) ||  cut(PQ, BC, B, C) || cut(PQ, CD, C, D) || cut(PQ, AD, A, D) || cum(P, Q, A, D)) cout<<"T\n";
			else cout<<"F\n";
		
	}
}
