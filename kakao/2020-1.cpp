#include <string>
#include <vector>

using namespace std;
string solution(string p) {
	string answer = "";
	int n = p.length();
	int check = 0;
	int temp; //�ڸ�����
	string u;
	string v;
	if (p.empty() == 1) {
		return p;
	} //�ùٸ� ���ڿ� -����

	for (int i = 0; i < n; i++) {
		if (p[i] == '(') { check++; }
		else { check--; }
		if (check < 0) { break; } //�ùٸ� ���ڿ��ƴ�
		else if ((check == 0) && (i == (n - 1))) { return p; } //�ùٸ� ���ڿ� -����

	}
	check = 0;

	for (int i = 0; i < n; i++) {
		if (p[i] == '(') { check++; }
		else { check--; }
		if (check == 0) {
			u = p.substr(0, i + 1);
			if (i == (n - 1)) { v = ""; }
			else { v = p.substr(i + 1, n - i - 1); }
			temp = i + 1;
			break;
		}
	} //������
	check = 0;
	//	cout << "u:" << u << "  v:" << v << "\n";

	for (int j = 0; j < temp; j++) { //u�� �ùٸ� ���ڿ��̶�� v�� ó������ ��� +v���ٿ� ��ȯ
		if (u[j] == '(') { check++; }
		else { check--; }
		if (check < 0) { break; } //�ùٸ����ڿ� �ƴ�
		else if (check == 0) { return(u.append(solution(v))); } //�ùٸ� ���ڿ� ����
	}
	answer.append("(");
	answer.append(solution(v));
	answer.append(")");
	int asize = answer.length();
	int usize = u.length();
	if (usize > 2) {
		for (int j = 1; j < (usize - 1); j++) {
			if (u[j] == '(') {
				answer.append(")");
			}
			else { answer.append("("); }
		}
		return answer;
	}
	else { return answer; }


}