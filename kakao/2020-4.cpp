#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct s {

	s *child[26];
	bool end;

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
	
	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';

		if (p->child[index] == NULL) {
			p ->child[index]= creat();
		}
		p = p->child[index];
	}
	p->end = true;
}

int search(s *root,string key) {

	
	queue <s*> qq;
	qq.push(root);
	for (int i = 0; i < key.length();i++) {

		int size = qq.size();
		for (int j = 0; j < size;j++) {
			s*n = qq.front();
			qq.pop();

			if (key[i] == '?') {
				for (int k = 0; k < 26;k++) {
					if (n->child[k]!=NULL) {
						qq.push(n->child[k]);
					}
				}
			}
			else {
				int index = key[i] - 'a';
				if (n->child[index]!=NULL) {
					qq.push(n->child[index]);
				}
			}
		}
	}
	int ans = 0;
	while (qq.empty()!=true) {
		s*n = qq.front();
		qq.pop();

		if (n->end==true) {
			ans++;
		}
	}

	return ans;
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	
	s *root = creat();

	for (int i = 0; i <words.size();i++) {
		insert(root,words[i]);
	}

	for (int i = 0; i < queries.size();i++) {
		answer.push_back(search(root,queries[i]));
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