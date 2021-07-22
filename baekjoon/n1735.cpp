#include<iostream>

using namespace std;

typedef long long ll;
ll gcd(ll a,ll b) {

	ll answer = a % b;
	if (answer!=0) {

		return gcd(b, answer);
	}
	else {
		return b;
	}

}


int main() {

	ll c1, m1, c2, m2;
	cin >> c1 >> m1 >> c2 >> m2;


	ll tmp = m1;

	c1 *= m2; int answer_m=m1 * m2;
	c2 *= tmp;;  //ХыКа

	ll answer_c = c1 + c2;
	ll a=0;
	if (answer_m >= answer_c) {
		a = gcd(answer_m, answer_c);
	}
	else{
		a = gcd(answer_c, answer_m);
	}
	answer_m /= a; answer_c /= a;

	cout << answer_c << " " << answer_m;

}