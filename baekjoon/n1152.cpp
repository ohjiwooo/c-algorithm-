#include<iostream>
#include<string>

using namespace std;


int ans = 1; // 마지막  공백일경우 하나빼줌
string a;;
int s = 0;//시작시 0, 중반엔 1
int main() {
	
	while (1) {
		getline(cin, a);

		if (a.size() == 0) { //엔터만 입력
			cout << 0;
			return 0;

		}
		for (int i = 0; i < a.size(); i++) {


			if (a[i] == ' ' && s == 0) {//시작이 공백
				s = 1;
			}
			else if (a[i] == ' ') {
				ans++;
				s = 1;
			}
			else { s = 1; }

		}

		if (a[a.size() - 1] == ' ') { //끝이공백
			ans--;
		}

		cout << ans;

	}

	return 0;
}
