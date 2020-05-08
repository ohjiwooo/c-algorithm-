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