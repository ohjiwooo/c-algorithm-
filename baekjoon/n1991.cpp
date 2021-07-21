#include<iostream>

using namespace std;


typedef struct node {

	char v;
	char left;
	char right;

}node;

node tree[28];

void preorder(int s) {


	cout << tree[s].v;

	if (tree[s].left!='.') {
		preorder(tree[s].left-64);
	}
	if (tree[s].right!='.') {
		preorder(tree[s].right-64);
	}


}
void inorder(int s) {

	if (tree[s].left != '.') {
		inorder(tree[s].left-64);
	}cout << tree[s].v;
	if (tree[s].right != '.') {
		inorder(tree[s].right-64);
	}
}
void postorder(int s) {

	if (tree[s].left != '.') {
		postorder(tree[s].left-64);
	}
	if (tree[s].right != '.') {
		postorder(tree[s].right-64);
	}
	cout << tree[s].v;

}
int main() {

	int n;
	cin >> n;
	char a, b, c;


	for (int i = 0; i < n;i++) {
		cin >> a >> b >> c;
		tree[a - 64].v = a;
		tree[a - 64].left = b;
		tree[a - 64].right = c;
	}

	preorder(1);
	cout << "\n";
	inorder(1);
	cout << "\n";
	postorder(1);
	return 0;
}