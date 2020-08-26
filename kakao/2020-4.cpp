#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef struct s {

	s *child[26] = {NULL,};
	bool end=false;
	int num = 0;
}s;

s *creat() {

	s *node = new s;
	for (int i = 0; i < 26; i++) {
		node->child[i] = NULL;
	}
	node->end = false;
	return node;
}


void insert(s *root, string key) {

	s *p = root;
	int n = key.length();
	for (int i = 0; i < n; i++) {
		int index = key[i] - 'a';

		if (p->child[index] == NULL) {
			p->child[index] = creat();
			p->num++;
		}
		else { p->num++; }
		p = p->child[index];
	}
	p->end = true;

}

int search(s *root, string key) {

	s *p = root;
	int n = key.length();

	for (int i = 0; i < n;i++) {

		if (key[i]=='?') {
			return p->num;
		}
		else {
			int index = key[i] - 'a';
			if (p->child[index]!=NULL) {
				p = p->child[index];
			}
			else { return 0; }
		}
	}

}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	s *root = new s[10001];
	s *reverse_root = new s[10001];

	for (int i = 0; i < words.size(); i++) {
		int s = words[i].length();
		insert(&root[s], words[i]);
	}
	for (int i = 0; i < words.size(); i++) {
		reverse(words[i].begin(), words[i].end());
		int s = words[i].length();
		insert(&reverse_root[s], words[i]);
	}
	for (int i = 0; i < queries.size(); i++) {
		if (queries[i][0] == '?') {
			int s = queries[i].length();
			reverse(queries[i].begin(), queries[i].end());
			answer.push_back(search(&reverse_root[s], queries[i]));
		}
		else {
			int s = queries[i].length();
			answer.push_back(search(&root[s], queries[i]));
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
	
	queries.push_back("???doo");
//	queries.push_back("?????t");
//	queries.push_back("???t");

	

	vector<int> answer = solution(words, queries);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}