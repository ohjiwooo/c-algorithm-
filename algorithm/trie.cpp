#include<iostream>

using namespace std;


typedef struct s {

	s *child[26];
	bool end=false;

}s;

s *creat() {

	s *newnode = new s;
	newnode->end = false;
	for (int i = 0; i < 26;i++) {
		newnode->child[i] = NULL;
	}

	return newnode;
}

void insert(s *root,string key) {

	s *p = root;//���� �θ���

	for (int i = 0; i <key.length();i++) {

		int index = key[i] - 'a'; //���ĺ��� ���ڸ� ������

		if (p->child[index]==NULL) {
			p->child[index] = creat();//�θ���� ������
		}
		p = p->child[index];
	}

	p->end = true;

}

bool search(s *root,string key) {
	
	s *p = root;//���� �θ���

	for (int i = 0; i < key.length();i++) {
		int index = key[i] - 'a';

		if (p->child[index] != NULL) {
			p = p->child[index];
		}
		else {
			return false;
		}
	}
	if (p->end == true) {
		return true;
	}

	return false;
}

int main() {

	string keys[] = { "the", "a", "there",
					"answer", "any", "by",
					"bye", "their" };
	int n = sizeof(keys) / sizeof(keys[0]);

	s *root = creat();

	for (int i = 0; i < n;i++) {
		insert(root,keys[i]);
	}

	if (search(root,"the")==true) {
		cout << "ture\n";
	}
	else { cout << "false\n"; }



	return 0;
}