#include <string>
#include <vector>

using namespace std;



vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	string a;//����ǥ �ڸ�
	string b;//�ܾ� �ڸ�
	int num=0;//while ��������

	for (int i = 0; i < queries.size(); i++) {
		int size = queries[i].size();
		for (int j = 0; j < size; j++) {	
			if ((queries[i][j] == '?') && (queries[i][j + 1] !='?')) { //�ڿ� ����ǥ
				a = queries[i].substr(j, size - i - 1); //�߶� a�� ����
				while (words.empty() != 1) {
					b = words[num++].substr(j, size - i - 1);
					if (a.compare(b) == 1) {
						answer[i]++;
					}
				}num = 0;
			}
			else if ((queries[i][j] != '?') && (queries[i][j + 1] == '?')) { //�տ�����ǥ

				a = queries[i].substr(0, i+1); 
				while (words.empty() != 1) {
					b = words[num++].substr(0,i+1);
					if (a.compare(b) == 1) {
						answer[i]++;
					}
				}num = 0;
			}
		}
	}


	return answer;
}