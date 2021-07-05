#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> ans; int pi_arr[1000005] = { 0, };

int pi(string word) {

	int j = 0;
	for (int i = 1; i < word.size();i++) {
		while (j>0 && word[j]!=word[i]) {
			j = pi_arr[j - 1];
		}
		if (word[i]==word[j]) {
			pi_arr[i] = j + 1; j++;
		}
	}
	return 0;
}

int kmp(string str, string word) {

	int answer = 0;
	int j = 0;
	int len = word.size();
	for (int i = 0; i < str.size();i++) {
		while (str[i]!=word[j] && j>0) {
			j = pi_arr[j - 1];
		}
		if (str[i]==word[j]) {
			if (j==len-1) {
				ans.push_back(i-len+2);
				answer++; 
				j = pi_arr[j];

			}
			else { j++; }
		}

	}
	return answer;

}

int main() {

	string str; string word; 
	getline(cin,str);
	getline(cin, word);
	

	pi(word);
	cout << kmp(str, word)<<"\n";
	for (int i = 0; i < ans.size();i++) {
		cout << ans[i] << " ";
	}
}