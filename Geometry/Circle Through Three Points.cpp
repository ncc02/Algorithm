#include<bits/stdc++.h>
using namespace std;

string s; 

double sqr(double x){
	return x*x;
}

struct equation{
	double x, y, z;
};

struct point{
	double x, y;
};

void f(point A, point B, point C){
	equation e1;
	e1.z = sqr(A.x) + sqr(A.y);
	e1.x = A.x;
	e1.y= A.y;
	
	equation e2;
	e2.z = sqr(B.x) + sqr(B.y);
	e2.x = B.x;
	e2.y= B.y;
	
	equation e3;
	e3.z = sqr(C.x) + sqr(C.y);
	e3.x = C.x;
	e3.y= C.y;
	 
	equation e12;
	e12.x = e1.x - e2.x;
	e12.y = e1.y - e2.y;
	e12.z = e1.z - e2.z;
	
	equation e13;
	e13.x = e1.x - e3.x;
	e13.y = e1.y - e3.y;
	e13.z = e1.z - e3.z;
	
	double t1, t2, t3, t4, c, d, e;
	t1 = e12.z / e12.x;
	t2 = - (e12.y / e12.x);
	t3 = e13.x * t1;
	t4 = e13.x * t2 + e13.y;
	d = (e13.z - t3) / t4;
	c = (e13.z - e13.y*d) / e13.x;
	d = -d;
	c = -c;
	e = sqr(A.x) + sqr(A.y)	+ c*A.x + d*A.y;
	e = -e;
	
	double h, k, r;
	h = c/2;
	k = d/2;
	r = sqrt(sqr(A.x + h) + sqr(A.y + k));
	
	 if (isnan(h) || isnan(k) || isnan(c) || isnan(d) || isnan(e)) {
        throw std::runtime_error("One or more variables are NaN.");
    }
	
	cout << fixed << setprecision(3);
    cout << "(x " << (h < 0 ? "-" : "+") << " " << abs(h) << ")^2 + ";
    cout << "(y " << (k < 0 ? "-" : "+") << " " << abs(k) << ")^2 = ";
    cout << r << "^2" << endl;

    cout << "x^2 + y^2 ";
    cout << (c < 0 ? "-" : "+") << " " << abs(c) << "x ";
    cout << (d < 0 ? "-" : "+") << " " << abs(d) << "y ";
    cout << (e < 0 ? "-" : "+") << " " << abs(e) << " = 0" << endl << endl;
}

int main(){
	while(getline(cin, s)){
		stringstream ss(s);
		
		point A, B, C;
		ss >> A.x; ss >> A.y;
		ss >> B.x; ss >> B.y;
		ss >> C.x; ss >> C.y;
		
		try{f(A, B, C);}catch(...){
			try{f(A, C, B);}catch(...){
				try{f(B, A, C);}catch(...){
					try{f(B, C, A);}catch(...){
						try{f(C, A, B);}catch(...){
							try{f(C, B, A);}catch(...){
	
			}
				
			}	
				
			}	
				
			}	
				
			}
			
		}
	}
}
