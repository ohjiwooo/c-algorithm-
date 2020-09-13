#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#define _CPP 0
#define _JAVA 1
#define _PYTHON 2
#define _BACKEND 0
#define _FRONTEND 1
#define _JUNIOR 0
#define _SENIOR 1
#define _CHICKEN 0
#define _PIZZA 1
#define _DONCARE -1
using namespace std;
unordered_map<string, int> m;
struct INFO {
	int idx[5];
};
int resultTable[3][2][2][2][100001];
vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

void init() {
	m["cpp"] = _CPP;
	m["java"] = _JAVA;
	m["python"] = _PYTHON;
	m["backend"] = _BACKEND;
	m["frontend"] = _FRONTEND;
	m["junior"] = _JUNIOR;
	m["senior"] = _SENIOR;
	m["chicken"] = _CHICKEN;
	m["pizza"] = _PIZZA;
	m["-"] = _DONCARE;
}
INFO getInfoFromInput(string & testInfo) {
	INFO info;
	vector<string> ss;
	ss = split(testInfo, ' ');
	//분할
	for (int i = 0; i < 4; i++) {
		info.idx[i] = m[ss[i]];
	}
	info.idx[4] = stoi(ss[4]);
	return info;
}
INFO getInfoFromQuery(string & query) {
	INFO returnV;
	vector<string> ss = split(query, ' ');
	for (int i = 0; i <= 3; i++) {
		returnV.idx[i] = m[ss[i * 2]];
	}
	returnV.idx[4] = stoi(ss[7]);
	return returnV;
}
//부분합 전처리
void preProcess() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					for (int n = 1; n < 100001; n++) {
						resultTable[i][j][k][l][n] += resultTable[i][j][k][l][n - 1];
					}
				}
			}
		}
	}
}
int getQueryCnt(INFO query) {
	int start[4], end[4];
	int result = 0;

	if (query.idx[0] == -1) {
		start[0] = 0;
		end[0] = 2;
	}
	else {
		start[0] = end[0] = query.idx[0];
	}
	for (int i = 1; i < 4; i++) {
		if (query.idx[i] == -1) {
			start[i] = 0;
			end[i] = 1;
		}
		else {
			start[i] = end[i] = query.idx[i];
		}
	}
	//점수 구하기
	for (int i = start[0]; i <= end[0]; i++) {
		for (int j = start[1]; j <= end[1]; j++) {
			for (int k = start[2]; k <= end[2]; k++) {
				for (int l = start[3]; l <= end[3]; l++) {
					if (!query.idx[4]) result += resultTable[i][j][k][l][100000];
					else result += resultTable[i][j][k][l][100000] - resultTable[i][j][k][l][query.idx[4] - 1];
				}
			}
		}
	}
	return result;
}
vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	init();
	//전처리
	for (int i = 0; i < info.size(); i++) {
		INFO eachInfo = getInfoFromInput(info[i]);
		resultTable[eachInfo.idx[0]][eachInfo.idx[1]][eachInfo.idx[2]][eachInfo.idx[3]][eachInfo.idx[4]]++;
	}
	//부분합 전처리
	preProcess();
	//쿼리 처리
	for (int i = 0; i < query.size(); i++) {
		INFO queryInfo = getInfoFromQuery(query[i]);
		answer.push_back(getQueryCnt(queryInfo));
	}
	return answer;
}