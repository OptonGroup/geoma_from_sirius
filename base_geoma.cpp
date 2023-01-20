// @active_botane every day
#include <bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ld eps = 0.0000001;
const ld PI = 3.1415926535897932384;
 
struct vect{
	ld x, y;
	vect(){};
	vect(ld x, ld y) : x(x), y(y) {};
 
	ld len2(){
		return (ld)x*x + (ld)y*y;
	}
 
	ld len(){
		return sqrt(len2());
	}
 
	ld distTo(vect point){
		return vect(point.x-x, point.y-y).len();
	}	
};
 
vect operator*(vect a, ld n){
	a.x *= n;
	a.y *= n;
	return a;
}
 
vect setLen(vect &a, ld new_len){
	return a * (new_len / a.len());
}
 
ld operator*(vect a, vect b){
	return (ld)a.x*b.x + (ld)a.y*b.y;
}
 
ld operator%(vect a, vect b){
	return (ld)a.x*b.y - (ld)a.y*b.x;
}
 
vect operator+(vect a, vect b){
	a.x += b.x;
	a.y += b.y;
	return a;
}
 
vect operator-(vect a, vect b){
	a.x -= b.x;
	a.y -= b.y;
	return a;
}
 
ostream& operator<<(ostream& os, vect a){
	os << fixed << setprecision(12) << a.x << " " << a.y;
	return os;
}
 
istream& operator>>(istream& is, vect &a){
	is >> a.x >> a.y;
	return is;
}
 
struct line{
	vect start, dir;
	ld a, b, c;
 
	line(){};
 
	line(vect p1, vect p2) : start(p1), dir(p2-p1), 
		a(p2.y - p1.y), b(p1.x - p2.x), c(-(a*p1.x + b*p1.y)) {};
 
	line(ld a, ld b, ld c) : a(a), b(b), c(c) {};
 
	bool contains(vect v){
		return (v - start) % dir < eps;
	}
 
	ld distTo(vect p){
		return (start%p)/(dir.len());
	}
 
	vect findCross(line & line2){
		ld x = (b*line2.c - line2.b*c) / (a*line2.b - b*line2.a);
		ld y = (a*line2.c - c*line2.a) / (b*line2.a - a*line2.b);
		return {x, y};
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
	
 
	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}