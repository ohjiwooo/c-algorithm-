#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;


typedef struct ss {

	string s = "";
	int n = 0;
};

stack <long long>st;
ss arr[100002];
queue<int>q2;
int k = 0;
bool num(int n) {

	st.push(n);
	return true;
}

bool pop() {

	if (st.empty()==true) {
		return false;
	}
	st.pop();
	return true;
}

bool inv() {

	if (st.empty() == true) {
		return false;
	}
	int a = st.top();
	st.pop();
	a *= -1;
	st.push(a);
	return true;

}

bool dup() {

	if (st.empty() == true ) {
		return false;
	}

	int a = st.top();
	st.push(a);
	return true;

}

bool swp() {

	if (st.size() <2) {
		return false;
	}

	int first = st.top();
	st.pop();
	int second = st.top();
	st.pop();
	st.push(first);
	st.push(second);
	return true;
}

bool add() {

	if (st.size() <2 ) {
		return false;
	}

	int first = st.top();
	st.pop();
	int second = st.top();
	st.pop();
	int answer = first + second;
	if (answer > 1000000000 || answer < -1000000000) {
		return false;
	}
	st.push(answer);
	return true;

}

bool sub() {

	if (st.size() < 2) {
		return false;
	}

	int first = st.top();
	st.pop();
	int second = st.top();
	st.pop();

	int answer = second-first;
	if (answer > 1000000000 || answer < -1000000000) {
		return false;
	}
	st.push(answer);
	return true;

}
bool mul() {

	if (st.size() < 2) {
		return false;
	}

	int first = st.top();
	st.pop();
	int second = st.top();
	st.pop();

	int answer = second * first;
	if (answer > 1000000000 || answer < -1000000000) {
		return false;
	}
	st.push(answer);

	return true;

}

bool div() {

	if (st.size() < 2) {
		return false;
	}
	int num = 0;
	int first = st.top();
	st.pop();
	int second = st.top();
	st.pop();

	if (second==0 || first==0) {
		return false;
	}
	if (first < 0) { 
		first *= -1; num++;
	}
	if (second<0) {
		second *= -1; num++;
	}
	int answer = second / first;
	if (num == 1) {
		answer *= -1;
	}

	if (answer > 1000000000 || answer < -1000000000) {
		return false;
	}
	st.push(answer);

	return true;

}

bool mod() {

	if (st.size() < 2) {
		return false;
	}

	int first = st.top();
	st.pop();
	int second = st.top();
	st.pop();


	if (second == 0 || first ==0) {
		return false;
	}
	int num = 0;
	if (first < 0) {
		first *= -1; 
	}
	if (second < 0) {
		second *= -1; num++;
	}
	int answer = second % first;
	if (num==1) {
		answer *= -1;
	}


	if (answer > 1000000000 || answer < -1000000000) {
		return false;
	}

	st.push(answer);
	return true;

}

int func() {

	for (int i = 0; i < k;i++) {
		
		string s = arr[i].s;

		if (s == "NUM") {

			if (num(arr[i].n)==false) {
				cout << "ERROR\n";
				return 0;
			}
		}
		else if (s == "POP") {
			if (pop() == false) {
				cout << "ERROR\n";
				return 0;
			}
		}
		else if (s == "INV") {
			if (inv() == false) {
				cout << "ERROR\n";
				return 0;
			}

		}
		else if (s == "DUP") {
			if (dup() == false) {
				cout << "ERROR\n";
				return 0;
			}

		}
		else if (s == "SWP") {
			if (swp() == false) {
				cout << "ERROR\n";
				return 0;
			}

		}
		else if (s == "ADD") {
			if (add() == false) {
				cout << "ERROR\n";
				return 0;
			}

		}
		else if (s == "SUB") {
			if (sub() == false) {
				cout << "ERROR\n";
				return 0;
			}

		}
		else if (s == "MUL") {
			if (mul() == false) {
				cout << "ERROR\n";
				return 0;
			}

		}
		else if (s == "DIV") {
			if (div() == false) {
				cout << "ERROR\n";
				return 0;
			}

		}
		else {
			if (mod() == false) {
				cout << "ERROR\n";
				return 0;
			}

		}
	}
	if (st.size()!=1) {
		cout << "ERROR\n";
		return 0;
	}
	else {
		cout << st.top()<<"\n";
		return 0;
	}

	return 0;
}

int main() {

	
	while (1) {
		k = 0;
		cin >> arr[k].s;
		if (arr[k].s== "QUIT") {
			break;
		}
		if (arr[k].s == "NUM") {
			cin >> arr[k].n;
		}
		k++;
		while (arr[k - 1].s != "END") {

			cin >> arr[k].s;
			if (arr[k].s == "NUM") {
				cin >> arr[k].n;
			}
			k++;
		}
		arr[k - 1].s = ""; k--;
		int t = 0; int m = 0;
		cin >> t;
		while (t--) {
			cin >> m;
			q2.push(m);
		}

		while (q2.empty() != true) {
			int a = q2.front();
			q2.pop();
			while (st.empty() != true) {
				st.pop();
			}
			st.push(a);
			func();
		}
		cout << "\n";
	}


	return 0;
}