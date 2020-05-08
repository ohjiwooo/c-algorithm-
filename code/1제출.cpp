#include <string>
#include <vector>
#include<iostream>
using namespace std;


int solution(string s) {
	int temp = 0;
	int answer = 0;
	int n = s.length();
	if (n == 1) { return 1; }
	for (int i = 1; i <= (n / 2); i++) {
		int start = 0;
		int flag = 1;
		while ((start + (2 * i) - 1) <= n) {
			string cut = s.substr(start, i);
			start = start + i;
			string cut_2 = s.substr(start, i);
			if (cut.compare(cut_2) == 0) {
				flag ++;
			}
			else {
				if (flag >1) {
					if ((flag > 0) && (flag < 10)) {
						temp = temp + 1 + i;
						flag = 1;
					}else if ((flag >= 10) && (flag < 100)) {
						temp = temp + 2 + i;
						flag = 1;
					}else if((flag >= 100) && (flag < 1000)) {
						temp = temp + 3 + i;
						flag = 1;
					}
					else if (flag ==1000) {
						temp = temp + 4 + i;
						flag = 1;
					}
				}
				else {
					temp = temp + i;
					flag = 1;
				}

			}
		}
		if (flag >1) {

			if ((flag > 1) && (flag < 10)) {
				temp = temp + 1 + i;
				temp = temp + (n - (start + i));
			}
			else if ((flag >= 10) && (flag < 100)) {
				temp = temp + 2 + i;
				temp = temp + (n - (start + i));
			}
			else if ((flag >= 100) && (flag < 1000)) {
				temp = temp + 3 + i;
				temp = temp + (n - (start + i));
			}
			else if (flag == 1000) {
				temp = temp + 4 + i;
				temp = temp + (n - (start + i));
			}

		}
		else { temp = temp + (n - start); }

		if (answer == 0) {
			answer = temp; temp = 0;
		}
		else {
			if (temp <= answer) {
				answer = temp; temp = 0;
			}
			temp = 0;
		}
	}
	return answer;
}

int main() {

	string s;
	cin >> s;
	cout << solution(s);


}