#include <iostream>
//#include <cmath>

using namespace std;

typedef long long ll;
ll x, y, m, n, l;
ll xx, yy;

ll extgcd(ll a, ll b) {
	ll d = a;
	ll t;
	if (b != 0) {
		d = extgcd(b, a % b);
		t = xx;
		xx = yy;
		yy = t - (a / b) * yy;
	}
	else {
		xx = 1;
		yy = 0;
	}
	return d;
}

ll mod(ll a, ll b) {
	if (a >= 0)return a % b;
	else return a % b + b;
}


int main() {
	ios::sync_with_stdio(false);
	cin >> x >> y >> m >> n >> l;
	ll d, c;
	if (m > n) {
		d = extgcd(m - n, l);
		c = y - x;
	}
	else {
		d = extgcd(n - m, l);
		c = x - y;
	}
	if (c % d != 0) {

		cout << "Impossible" << endl;
	}
	else {
		l /= d;
		ll times = mod(xx * c / d, l);
		cout << times << endl;
	}
	return 0;
}