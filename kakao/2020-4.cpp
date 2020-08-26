#include<iostream>
#include<vector>

using namespace std;

typedef struct s {

	s *child[26];
	bool end;
	int arr[100002] = { 0,};
}s;

s *creat() {

	s *node = new s;
	for (int i = 0; i<26;i++) {
		node->child[i] = NULL;
	}
	node->end = false;
	return node;
}


void insert(s *root,string key) {

	s *p = root;
	int n = key.length();
	for (int i = 0; i < n; i++) {
		int index = key[i] - 'a';

		if (p->child[index] == NULL) {
			p ->child[index]= creat();
			p->arr[n - i]++;
		}
		else {
			p->arr[n - i]++;
		}
		p = p->child[index];
	}
	p->end = true;
	
}

void r_insert(s *root, string key) {

	s *p = root;
	int n = key.length();
	for (int i = n-1; i >= 0; i--) {
		int index = key[i] - 'a';

		if (p->child[index] == NULL) {
			p->child[index] = creat();
			p->arr[n - i]++;
		}
		else {
			p->arr[n - i]++;
		}
		p = p->child[index];
	}
	p->end = true;

}
int search(s *root,string key) {
	s*n = root;
	int ans = 0;
	int num = key.length();
	for (int i = 0; i < num;i++) {

		if (key[i] == '?') {
			for (int k = 0; k < 26;k++) {
				ans = n->arr[num - i];
				return ans;
			}
		}
		else {
			int index = key[i] - 'a';
			if (n->child[index]!=NULL) {
				n = n->child[index];
			}
		}
	}
	return ans;
}

int r_search(s *root, string key) {
	s*n = root;
	int ans = 0;
	int num = key.length();
	for (int i = num-1; i >= 0; i--) {

		if (key[i] == '?') {
			for (int k = 0; k < 26; k++) {
				ans = n->arr[num - i];
				return ans;
			}
		}
		else {
			int index = key[i] - 'a';
			if (n->child[index] != NULL) {
				n = n->child[index];
			}
		}
	}
	return ans;
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	
	s *root = creat();
	s *reverse_root = creat();

	for (int i = 0; i <words.size();i++) { //沥规氢 飘府
		insert(root,words[i]);
	}
	for (int i = 0; i < words.size(); i++) { //开规氢 飘府
		r_insert(reverse_root, words[i]);
	}

	for (int i = 0; i < queries.size();i++) {
		if (queries[i][0]=='?') {
			answer.push_back(r_search(reverse_root, queries[i]));
		}
		else {
			answer.push_back(search(root, queries[i]));
		}
	}

	return answer;
}

int main() {

	vector<string> words; 
	vector<string> queries;

	words.push_back("frodo");
	words.push_back("front");
	words.push_back("frost");
	words.push_back("frozen");
	words.push_back("frame");
	words.push_back("kakao");

	queries.push_back("fro??");
	queries.push_back("????o");
	queries.push_back("fr???");
	queries.push_back("fro???");
	queries.push_back("pro?");

	vector<int> answer=solution(words,queries);

	for (int i = 0; i < answer.size();i++) {
		cout << answer[i] << " ";
	}

	return 0;
}