#include <string>
#include <vector>

using namespace std;



vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	string a;//물음표 자름
	string b;//단어 자름
	int num=0;//while 문에쓰임

	for (int i = 0; i < queries.size(); i++) {
		int size = queries[i].size();
		for (int j = 0; j < size; j++) {	
			if ((queries[i][j] == '?') && (queries[i][j + 1] !='?')) { //뒤에 물음표
				a = queries[i].substr(j, size - i - 1); //잘라서 a에 저장
				while (words.empty() != 1) {
					b = words[num++].substr(j, size - i - 1);
					if (a.compare(b) == 1) {
						answer[i]++;
					}
				}num = 0;
			}
			else if ((queries[i][j] != '?') && (queries[i][j + 1] == '?')) { //앞에물음표

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