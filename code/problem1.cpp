#include<iostream>
#include<string>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


string str;

int fun_1(int n) {
	int temp = 0;
	int ans = 0;
	int flag = 0;
	for (int i = 1; i <= (n/2); i++) {
		int start = 0;
		while ((start + (2 * i) - 1) <= n) {
			string cut = str.substr(start, i);
			start = start + i;
			string cut_2 = str.substr(start, i);
			if (cut.compare(cut_2) == 0) {
				flag = 1;
			}
			else {
				if (flag == 1) {
					temp = temp + 1 + i;
					flag = 0;
				}
				else {
					temp = temp + i;
					flag = 0;
				}

			}
		}
		if (flag == 1) {
			temp = temp + 1 + i;
			temp = temp + (n - (start + i));
		}
		else { temp = temp + (n - start); }

		if (ans == 0) {
			ans = temp; temp = 0; }
		else {
			if (temp <= ans) { 
				ans = temp; temp = 0; }
			temp = 0;
		}
	}
	return ans;
}



int main() {

	cin >> str;
	int n = str.length();
	cout << fun_1(n);
	return 0;
}