#include<iostream>

using namespace std;


int main() {


	long long mid,z,tmp,answer,x,y; //°ÔÀÓÈ½¼ö, ÀÌ±ä°ÔÀÓ, ½Â·ü
	
	cin >> x >> y; 
	z = 100*y/x;
	answer = 9999999999;
	long long s = 0; long long e = x;

	if (z>=99) {
		cout << -1; return 0;
	}
	while (s<=e ) {

		mid = (s + e) / 2;
		tmp = 100*(y + mid) / (x + mid);

		if (tmp > z ) {
			if (answer > mid) {
				answer = mid;
			}
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}	
	}
	if (answer==9999999999) {
		answer = -1;
	}
	cout << answer;

	return 0;
}