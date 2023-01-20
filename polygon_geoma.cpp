// @active_botane every day
#include <bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef long double ld;
using namespace std;

struct vect{
	ll x, y;
	vect(){};
	vect(ll x, ll y) : x(x), y(y) {};
};
 
vect operator*(vect a, ll n){
	a.x *= n;
	a.y *= n;
	return a;
}
 
ll operator*(vect a, vect b){
	return (ll)a.x*b.x + (ll)a.y*b.y;
}
 
ll operator%(vect a, vect b){
	return (ll)a.x*b.y - (ll)a.y*b.x;
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
	os << a.x << " " << a.y;
	return os;
}
 
istream& operator>>(istream& is, vect &a){
	is >> a.x >> a.y;
	return is;
}

ll get_sign(ll a){
	if (a < 0) return -1;
	if (a > 0) return 1;
	return 0;
}

bool point_on_segment(vect seg_start, vect seg_end, vect p){
	if ( (seg_end - seg_start) % (p - seg_start) == 0 && 
		 (seg_end - seg_start) * (p - seg_start) >= 0 &&
		 (seg_start - seg_end) * (p - seg_end) >= 0) return true;
	return false;
}

bool point_in_angle(vect right, vect start, vect left, vect point){
	if( (right-start) % (left-start) >= 0){
		if ( (left-start) % (point-start) <= 0 && (right-start) % (point-start) >= 0 ) 
			return true;
		else
			return false;
	}else{
		if ( (left-start) % (point-start) >= 0 && (right-start) % (point-start) <= 0 ) 
			return true;
		else
			return false;
	}
}

vector <vect> vv;
bool point_in_polygon(vect p){

	// point in polygon
	if ( !point_in_angle(vv[vv.size()-2], vv[0], vv[1], p) ) return false;
	ll left = 0, right = vv.size()-2;
	while (right - left > 1){
		ll m = left + (right - left) / 2;

		if ( (vv[m]-vv[0]) % (p-vv[0]) >= 0 ) left = m;
		else right = m;
	}

	if ( point_in_angle(vv[right], vv[left], vv[0], p) ) return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    

	cerr << "Time: " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}