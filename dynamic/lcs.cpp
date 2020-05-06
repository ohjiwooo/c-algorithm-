#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

char a[1001];
char b[1001];
int ans[1001][1001];
int an;
int bn;


int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}
int main() {

	scanf("%s", &a);
	scanf("%s", &b);

	an = strlen(a);
	bn = strlen(b);

	for (int i = 0; i < 1000; i++) {
		ans[i][0] = 0;
	}
	for (int i = 0; i < 1000; i++) {
		ans[0][i] = 0;
	}

	for (int i = 1; i <= an; i++) {
		for (int j = 1; j <= bn; j++) {

			if (a[i - 1] == b[j - 1]) {
				ans[i][j] = (ans[i - 1][j - 1] + 1);
			}
			else {
				ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
			}

		}
	}

	printf("%d", ans[an][bn]);

	return 0;
}