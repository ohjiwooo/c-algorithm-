#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	int num = 0;//while ��������

	for (int i = 0; i < queries.size(); i++) {
		int size = queries[i].size();
		for (int j = 0; j < size; j++) {
			if ((queries[i][j] == '?') && (queries[i][j + 1] != '?')) { //�ڿ� ����ǥ
				string a = queries[i].substr(j + 1, size - j - 1); //�߶� a�� ����
				while (words[num].empty() != 1) {
					string b = words[num++].substr(j, size - j - 1);
					if (a.compare(b) == 1) {
						answer[i]++;
					}
				}num = 0;
			}
			else if ((queries[i][j] != '?') && (queries[i][j + 1] == '?')) { //�տ�����ǥ

				string a = queries[i].substr(0, j + 1);
				while (words[num].empty() != 1) {
					string b = words[num++].substr(0, j + 1);
					if (a.compare(b) == 1) {
						answer[i]++;
					}
				}num = 0;
			}
		}
	}


	return answer;
}


else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l == 1) && (r - numbers[i] != 1)) {
answer.append("L"); l_flag == 1; l = numbers[i]; //�Ѵ� �ڱ��ڸ����ְ� �����̰����
			}
else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l != 1) && (r - numbers[i] == 1)) {
answer.append("R"); r_flag == 1; r = numbers[i]; //�Ѵ� �ڱ��ڸ����ְ� �������̰����
			}
else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l == 1) && (r - numbers[i] == 1)) {
if (h == 0) { answer.append("R"); r_flag == 1; r = numbers[i]; } //�Ѵ� �ڱ��ڸ�,�ٷο�
else { answer.append("L"); l_flag == 1; l = numbers[i]; } //����������,�޼����� ����        
			}
else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l != 1) && (r - numbers[i] != 1)) {
if (h == 0) { answer.append("R"); r_flag == 1; r = numbers[i]; } //�Ѵ� �ڱ��ڸ�,�ٷο��ƴ�
else { answer.append("L"); l_flag == 1; l = numbers[i]; } //����������,�޼����� ����        
			}