#include<iostream>
#include<string>
using namespace std;

int pi_arr[1000005];
char word[1000005];
string text;

int pi(int n) {

	int j = 0;
	for (int i= 1; i < n;i++) {
		
		while (j>0 && word[i]!=word[j]) {
			j = pi_arr[j - 1];
		}if (word[i]==word[j]) {
			pi_arr[i] = ++j;
		}
	}
	return 0;
}

int kmp(int n,int m) {
	int answer = 0;
	int j = 0;
	for (int i = 0; i < m;i++ ) {
		while (j>0 && text[i]!= word[j]) {
			j = pi_arr[j - 1];
		}
		if (text[i]==word[j]) {
			if (j==n-1) {
				answer++; j = pi_arr[j];
			}
			else {
				j++;
			}
		}
	
	}
	return answer;

}

int main() {

	int n = 0; int m = 0;
	cin >> n;
	cin >> m;
	n = n * 2 + 1;
	for (int i= 0; i < n;i++) {
		if (i%2==0) {
			word[i] = 'I';
		}
		else {
			word[i] = 'O';
		}
	}
	getline(cin, text);
	pi(n);
	cout << kmp(n, m);
}