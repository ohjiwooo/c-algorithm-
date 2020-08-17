#include<iostream>
#include<vector>
using namespace std;

typedef struct s {

	char c;
	int d;//0-¿À¸¥ÂÊ,1-¿ÞÂÊ
}s;

int n1, n2,t;

int main() {

	cin >> n1 >> n2;
	vector<s>v(n1 + n2);
	for (int i = n1 - 1; i >= 0;i--) {
		cin >> v[i].c;
		v[i].d = 0;
	}
	for (int i = n1; i < n1+n2; i++) {
		cin >> v[i].c;
		v[i].d = 1;
	}
	cin >> t;
	int  n= 0;

	while (n<t) {
		
		vector <bool> vis(n1 + n2);
		for (int i = 0; i < n1 + n2-1;i++) {
			if (v[i].d ==0 && v[i+1].d==1 && vis[i]!=true && vis[i+1]!=true) {
				s temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				vis[i] = true;
				vis[i + 1] = true;
			}
		}	
		n++;
	}

	for (int i = 0; i < n1 + n2;i++) {
		cout << v[i].c;
	}
	return 0;
}