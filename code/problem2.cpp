#include <string>
#include <vector>
#include<iostream>

using namespace std;


string solution(string p) {
	string answer = "";
	int n = p.length();
	int check = 0;
	int temp; //자른기점
	string u;
	string v;
		if (p.empty() == 1) {
			return p;
		} //올바른 문자열 -종료
	
		for (int i = 0; i < n; i++) {
			if (p[i] == '(') { check++; }
			else { check--; }
			if (check < 0) { break; } //올바른 문자열아님
			else if ((check == 0) && (i == (n - 1))) { return p; } //올바른 문자열 -종료

		}
		check = 0;
	
		for (int i = 0; i < n; i++) {
			if (p[i] == '(') { check++; }
			else { check--; }
			if (check == 0) {
				u = p.substr(0, i + 1);
				if (i == (n - 1)) { v = ""; }
				else { v = p.substr(i+1, n - i - 1); }
				temp = i + 1;
				break;
			}
		} //나누기
		check = 0;
	//	cout << "u:" << u << "  v:" << v << "\n";

		for (int j = 0; j < temp; j++) { //u가 올바른 문자열이라면 v를 처음부터 재귀 +v에붙여 반환
			if (u[j] == '(') { check++; }
			else { check--; }
			if (check < 0) { break; } //올바른문자열 아님
			else if (check == 0) { return( u.append(solution(v))); } //올바른 문자열 맞음
			}
		answer.append("(");
		answer.append(solution(v));
		answer.append(")");
		int asize = answer.length();
		int usize = u.length();
		if (usize > 2) {
			for (int j = 1; j < (usize-1); j++) {
				if (u[j] == '(') {
					answer.append(")");
				}
				else { answer.append("("); }
			}
			return answer;
		}
		else { return answer; }
		

	
}

int main() {

	string p;
	cin >> p;
	cout << solution(p);

	return 0;
}