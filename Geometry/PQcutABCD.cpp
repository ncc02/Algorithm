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

struct Equation{ //ax + by = c
	double a, b, c;
};

struct Line{ //y = ax + b
	double a=0, b=0, y= oo, x= oo;	
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
	
	if (a == 0.0) { // x = a 
		PQ.x = e1.a;
	}
	if (c == 0.0) { // y = c
		PQ.y = e1.c;
	}
	if (PQ.x != oo || PQ.y != oo) return PQ;
	
	
	PQ.a = c / a;
	PQ.b = P.y - PQ.a * P.x;
	return PQ;
}

Point P, Q;

bool cut(Line PQ, Line AB, Point A, Point B){//check Line PQ cut Edges
	double x, y, x_min, x_max, y_min, y_max;

	//PQ is a straight
	if (PQ.x != oo && AB.y != oo){
		
		x = PQ.x;
		y = AB.y;
		
		x_min = min(A.x, B.x);
		x_max = max(A.x, B.x);
		y_min = min(P.y, Q.y);
		y_max = max(P.y, Q.y);
		
		return (x_min <= x && x <= x_max) && (y_min <= y && y <= y_max);
	}
	else 
	if (PQ.y != oo && AB.x != oo){ 
	
		y = PQ.y;
		x = AB.x;
		
		x_min = min(P.x, Q.x);
		x_max = max(P.x, Q.x);
		y_min = min(A.y, B.y);
		y_max = max(A.y, B.y);
		
		return (x_min <= x && x <= x_max) && (y_min <= y && y <= y_max);
	}

	//PQ is a cross
	if (AB.x != oo){
		
		x = AB.x;
		y = x*PQ.a + PQ.b;
		
		y_min = min(A.y, B.y);
		y_max = max(A.y, B.y);
		x_min = min(P.x, Q.x);
		x_max = max(P.x, Q.x);
		
		return (x_min <= x && x <= x_max) && (y_min <= y && y <= y_max);
	}
	
	if (AB.y != oo){
		
		y = AB.y;
		x = (y - PQ.b) / PQ.a;
	
		x_min = min(A.x, B.x);
		x_max = max(A.x, B.x);
		y_min = min(P.y, Q.y);
		y_max = max(P.y, Q.y);
		
		return (x_min <= x && x <= x_max) && (y_min <= y && y <= y_max);
	}
}

bool cum(Point P, Point Q, Point A, Point D){ //check Point P,Q in ABCD 
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
		Point A, B, C, D; double ax, ay, cx, cy;
		cin >> P.x >> P.y >> Q.x >> Q.y >> ax >> ay >> cx >> cy;
		
		if (ay > cy){ // give A C
			
			A.x = ax;
			A.y = ay;
			C.x = cx;
			C.y = cy;
			
			B.x = C.x;
			B.y = A.y;
			D.x = A.x;
			D.y = C.y;
		}
		else{//give D B
		
			D.x = ax;
			D.y = ay;
			B.x = cx;
			B.y = cy;
			
			A.x = D.x;
			A.y = B.y;
			C.x = B.x;
			C.y = D.y;
		}
		
		
		Line PQ = create_line(P, Q);
		
		Line AB = create_line(A, B);
		Line BC = create_line(B, C);
		Line CD = create_line(C, D);
		Line AD = create_line(A, D);
	
			
		if (cut(PQ, AB, A, B) ||  cut(PQ, BC, B, C) || cut(PQ, CD, C, D) || cut(PQ, AD, A, D) || cum(P, Q, A, C)) cout<<"T\n";
			else cout<<"F\n";
		
	}
}
