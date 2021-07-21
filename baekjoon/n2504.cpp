#include<iostream>
#include<string>
#include<stack>

using namespace std;


int main() {

	string  s = "";
	cin >> s;
	int answer = 0;
	int flag = 0;
	int i = 0;
	stack <char>st;
	stack <int>ans;
	char now;
	while (1) {

		int tmp = 0;
		while (s[i]=='(' || s[i]=='[') {
			st.push(s[i++]);
		}
		while (s[i] == ')' || s[i] == ']') {
			st.top() = now; st.pop();
			if ((now == '(' && s[i] == ']') || (now == '[' && s[i] == ')')) { //Æ²¸²
				cout << "0"; return 0;
			}

		}
	
	}


	return 0;

}