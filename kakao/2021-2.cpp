#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;



int search(vector<string> orders, vector<char> temp) {//temp�� ������ ����ִ� ���� ,�ش������� ��� ������ ���� �Լ�

	vector<string> ans;
	int n = 0;
	int count = 0;
	int temp_s = temp.size();
	bool a = false;

	for (int i = 0; i < orders.size(); i++) {

		count = 0;
		a = false;

		for (int k = 0; k < temp_s; k++) {
			char c = temp[k];
			a = false;
			for (int j = 0; j < orders[i].size(); j++) {
				a = false;
				if (orders[i][j] == c)
				{
					count++;
					a = true;
					break;
				}
			}
			if (a == false) { break; }

		}
		if (count == temp_s) { //������ �� ����
			n++;//������ ���� ���� ����
		}
	}

	return n;
}




vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;
	vector<char> list;
	bool a[30];

	for (int i = 0; i < orders.size(); i++) { //���� ���ĺ� üũ
		for (int j = 0; j < orders[i].size(); j++) {
			if (a[orders[i][j] - 'A'] != true) {
				list.push_back(orders[i][j]);
				a[orders[i][j] - 'A'] = true;
			}
		}
	}

	sort(list.begin(), list.end());
	int list_n = list.size();

	vector<int> v(list_n);


	for (int k = 0; k < course.size(); k++) {//course�� �ִ� ���ڵ鸸 ������ ����

		int n = course[k];
		int ans_n = 1;
		vector<string> now_answer; //����course[k]�� ���� �� ����Ʈ
		now_answer.clear();

		for (int i = 0; i < list_n; i++) {
			v[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			v[i] = 1;
		}
		sort(v.begin(), v.end());

		do {
			vector<char> temp; //���չ���

			for (int i = 0; i < list_n; i++) {

				if (v[i] == 1) {
					temp.push_back(list[i]);
				}
			}

			int temp_n = search(orders, temp);

			if (ans_n < temp_n && temp_n>1) { //�ٲ� - ������� �߰�

				ans_n = temp_n;
				now_answer.clear();

				string str = "";
				for (int ii = 0; ii < n; ii++) {
					str += temp[ii];
				}
				now_answer.push_back(str);

			}
			else if (ans_n == temp_n && temp_n > 1) {// �߰�
				string str = "";
				for (int ii = 0; ii < n; ii++) {
					str += temp[ii];
				}
				now_answer.push_back(str);

			}

		} while (next_permutation(v.begin(), v.end()));

		//��ü�信 ����� ��ħ

		for (int i = 0; i < now_answer.size(); i++) {

			answer.push_back(now_answer[i]);
		}

	}

	sort(answer.begin(), answer.end());

	return answer;
}



int main() {
	
	vector<string> orders;
	vector<int> course;
	vector<string> answer;

	

	orders.push_back("ZXCVB");
	orders.push_back("ZXCVB");
	orders.push_back("ZXCVB");
	orders.push_back("ZXCVB");


	course.push_back(2);
	course.push_back(3);
	course.push_back(4);

	answer=solution(orders,course);

	for (int i = 0; i < answer.size();i++) {
		cout << answer[i] <<"\n";
	}
	return 0;
}


