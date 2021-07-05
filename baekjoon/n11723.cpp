#include<iostream>
#include<string>

using namespace std;


int add(int s,int x) {

	s |= (1 << x);
	return s;

}

int remove(int s,int x) {

	s &= ~(1 << x);
	return s;
}

void check(int s, int x) {

	if (s&(1 << x)) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}
	
}

int toggle(int s, int x) {

	if (s &(1<<x)) {
		s &= ~(1 << x);
	}
	else {
		s |= (1 << x);
	}
	return s;

}

int all(int s) {

	s = (1 << 21) - 1;
	return s;

}
int empty(int s) {

	s = 0;
	return s;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);


	int n = 0;
	int m = 0;
	cin >> n;
	int answer = 0;
	string s;
	while (n--) {
		
		cin >> s;
	

		if (s == "add") {
			cin >> m;
			answer = add(answer, m);
		}
		else if (s == "remove") {
			cin >> m;
			answer = remove(answer, m);
		}
		else if (s =="check") {
			cin >> m;
			check(answer, m);
		}
		else if (s=="toggle") {
			cin >> m;
			answer = toggle(answer, m);
		}
		else if (s == "all") {
			answer = all(answer);
		}
		else if (s == "empty") {
			answer = empty(answer);
		}
	}

	return 0;
}