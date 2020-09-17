#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;


void step3(string & str) {
	string before = "..";
	string after = ".";
	int loc;
	while (1) {
		loc = str.find(before);
		if (loc == string::npos) break;
		str.replace(loc, 2, after);
	}
}
void step2(string & str) {
	//소문자, 숫자, 빼기, 밑줄, 마침표
	while (1) {
		bool eraseState = false;
		for (int i = 0; i < str.size(); i++) {
			if ((str[i] >= 'a' && str[i] <= 'z') ||
				(str[i] == '-') ||
				(str[i] == '_') ||
				(str[i] == '.') ||
				(str[i] >= '0' && str[i] <= '9')) continue;
			str.erase(i, 1);
			eraseState = true;
		}
		if (!eraseState)break;
	}
}
void step1(string & str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
}
string solution(string new_id) {
	string answer = "";

	//1단계
	step1(new_id);
	//2단계
	step2(new_id);
	//3단계
	step3(new_id);
	//4단계
	if (new_id.size() && new_id[new_id.size() - 1] == '.') new_id.pop_back();
	if (new_id.size() && new_id[0] == '.') new_id.erase(0, 1);
	//5단계
	if (!new_id.size()) new_id = "a";
	//6단계
	if (new_id.size() >= 16) {
		new_id = new_id.substr(0, 15);
		if (new_id.size() && new_id[new_id.size() - 1] == '.') new_id.pop_back();
	}
	//7단계
	char last = new_id.back();
	while (new_id.size() < 3) {
		new_id.push_back(last);
	}
	return new_id;
}