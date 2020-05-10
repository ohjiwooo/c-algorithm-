#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	int num = 0;//while 문에쓰임

	for (int i = 0; i < queries.size(); i++) {
		int size = queries[i].size();
		for (int j = 0; j < size; j++) {
			if ((queries[i][j] == '?') && (queries[i][j + 1] != '?')) { //뒤에 물음표
				string a = queries[i].substr(j + 1, size - j - 1); //잘라서 a에 저장
				while (words[num].empty() != 1) {
					string b = words[num++].substr(j, size - j - 1);
					if (a.compare(b) == 1) {
						answer[i]++;
					}
				}num = 0;
			}
			else if ((queries[i][j] != '?') && (queries[i][j + 1] == '?')) { //앞에물음표

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
answer.append("L"); l_flag == 1; l = numbers[i]; //둘다 자기자리에있고 완쪽이가까움
			}
else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l != 1) && (r - numbers[i] == 1)) {
answer.append("R"); r_flag == 1; r = numbers[i]; //둘다 자기자리에있고 오른쪽이가까움
			}
else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l == 1) && (r - numbers[i] == 1)) {
if (h == 0) { answer.append("R"); r_flag == 1; r = numbers[i]; } //둘다 자기자리,바로옆
else { answer.append("L"); l_flag == 1; l = numbers[i]; } //오른손잡이,왼손잡이 구분        
			}
else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l != 1) && (r - numbers[i] != 1)) {
if (h == 0) { answer.append("R"); r_flag == 1; r = numbers[i]; } //둘다 자기자리,바로옆아님
else { answer.append("L"); l_flag == 1; l = numbers[i]; } //오른손잡이,왼손잡이 구분        
			}