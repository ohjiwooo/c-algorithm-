#include<iostream>
#include<stdio.h>

using namespace std;

typedef struct tree_node {

	int data;
	tree_node *left;
	tree_node *right;

}tree_node;

tree_node *new_node() {

	tree_node *new_node = (tree_node*)malloc(sizeof(tree_node));
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}

void set_data(tree_node *p, int data) {
	p->data = data;
}


void insert_node(tree_node *root, int data) {
	if (root->data > data) {
		if (root->left == NULL) {
			root->left = new_node();
			root->left->data = data;
		}
		else {
			insert_node(root->left, data);
		}
	}
	else {
		if (root->right == NULL) {
			root->right = new_node();
			root->right->data = data;
		}
		else {
			insert_node(root->right, data);
		}
	}

}

void search_node(tree_node *root, int data) {
	if (root->data == data) {
		printf("%d\n", data);
		return;
	}
	else if (root->data > data) {
		if (root->left != NULL) {
			search_node(root->left, data);
		}
		else { return; }
	}
	else if (root->data < data) {
		if (root->right != NULL) {
			search_node(root->right, data);
		}
		else { return; }
	}
}


void print_node(tree_node *p) {
	if (p == NULL) {
		return;
	}
	printf("%d\n", p->data);
	print_node(p->left);
	print_node(p->right);
}

tree_node *find_small(tree_node *root) {


	if ((root->left != NULL) && (root->left->left == NULL)) {
		return root;
	}
	else if ((root->left != NULL) && (root->left->left != NULL)) {
		find_small(root->left);
	}
}

void del(tree_node *root, int data) {
	if (root->data == data) {

		if (root->right->left != NULL) {
			tree_node *psmall = find_small(root->right);
			tree_node *small = psmall->left;

			if (small->right == NULL) {
				root->data = small->data;
				free(small);
			}
			else {
				root->data = small->data;
				psmall->left = small->right;
				free(small);
			}
		}
		else {
			root->data = root->right->data;
			free(root->right);

		}


	}
	else if (root->left->data == data) {
		tree_node *find = root->left;
		if ((find->left == NULL) && (find->right = NULL)) {
			free(find);
		}
		else if ((find->left != NULL) && (find->right == NULL)) {
			root->left = find->left;
			free(find);
		}
		else if ((find->left == NULL) && (find->right != NULL)) {
			root->left = find->right;
			free(find);
		}
		else if ((find->left != NULL) && (find->right != NULL)) {
			if (find->right->left != NULL) {
				tree_node *psmall = find_small(find->right);
				tree_node *small = psmall->left;

				if (small->right == NULL) {
					find->data = small->data;
				}
				else {
					find->data = small->data;
					psmall->left = small->right;
					free(small);
				}
			}
			else {
				find->data = find->right->data;
				free(find->right);
			}
		}

	}
	else if (root->right->data == data) {
		tree_node *find = root->right;
		if ((find->left == NULL) && (find->right = NULL)) {
			free(find);
		}
		else if ((find->left != NULL) && (find->right == NULL)) {
			root->left = find->left;
			free(find);
		}
		else if ((find->left == NULL) && (find->right != NULL)) {
			root->left = find->right;
			free(find);
		}
		else if ((find->left != NULL) && (find->right != NULL)) {
			if (find->right->left != NULL) {
				tree_node *psmall = find_small(find->right);
				tree_node *small = psmall->left;

				if (small->right == NULL) {
					find->data = small->data;
				}
				else {
					find->data = small->data;
					psmall->left = small->right;
					free(small);
				}
			}
			else {
				find->data = find->right->data;
				free(find->right);
			}
		}
	}
	else {
		del(root->left, data);
		del(root->right, data);
	}

}


int main() {

	int n = 0;
	int input;
	tree_node *root = new_node();

	while (1) {
		printf("1.insert node 2.delete node 3.search node 4.node print\n");
		cin >> input;

		if (input == 1) {
			printf("data:");
			cin >> input;
			if (n == 0) {
				set_data(root, input);
				n++;
			}
			else {
				insert_node(root, input);
				n++;
			}
		}
		else if (input == 2) {
			printf("삭제할 데이터 입력 : ");
			cin >> input;
			del(root, input);

		}

		else if (input == 3) {
			printf("찾을 값 입력 :");
			cin >> input;
			search_node(root, input);
		}

		else if (input == 4) {
			printf("---print---\n");
			print_node(root);
		}
	}
	return 0;
}





