#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;


string str;

int main() {

	cin >> str;
	int n = str.length; //문자열길이
	int num; //동일문자열개수
	int start=0; //시작문자열
	string ans; 

	for (int i = 1; 1 < n;i++) {

		string cut=str.substr(start,(start+i));
		start = start + i;
		string cut_2 = str.substr(start, (start + i));
		if (cut.compare(cut_2) == 0) {
			
		}

	}

	return 0;
}