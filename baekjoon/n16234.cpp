#include<iostream>
#include<algorithm>
using namespace std;

int ground[52][52] = { 0, }; //�α��� �ֱ�
int n; //��ũ��
int l; //�α��� �̻�
int m; //�α��� ����
int v[52][52] = { 0, };
int g;
int mm = 0;//��
int nn = 0;//����
int vn = 1;

int p(int a) {
	if (a >= 0) { return a; }
	else { return - a; }
}

void cc(int i, int j) {

	v[i][j] = vn;
	mm = mm + ground[i][j];
	nn++;

	if (j != n - 1&&(p(ground[i][j + 1] - ground[i][j]) >= l) && (p(ground[i][j + 1] - ground[i][j]) <= m)&&v[i][j+1]==0) {
		cc(i, j + 1);
	}//��
	if (j!=0&&(p(ground[i][j - 1] - ground[i][j]) >= l) && (p(ground[i][j - 1] - ground[i][j]) <= m) && v[i][j - 1] ==0) {
		cc(i, j - 1);
	}//��
	if (i != 0&& (p(ground[i - 1][j] - ground[i][j]) >= l) && (p(ground[i - 1][j] - ground[i][j]) <= m) && v[i - 1][j] ==0) {
		cc(i-1,j);
	}//��
	if (i!=n-1&&(p(ground[i + 1][j] - ground[i][j]) >= l) && (p(ground[i + 1][j] - ground[i][j]) <= m) && v[i+1][j] ==0) {
		cc(i + 1, j);
	}//�Ʒ�

}

void cc2(int mm,int nn) {
	int ans = mm / nn;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if  (v[i][j] == vn) {ground[i][j]=ans;}
		}
	}
	

}

int main() {


	cin >> n;
	cin >> l;
	cin >> m;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ground[i][j];
		}
	}
	
	for (g = 0; g < 2001; g++) {
		vn = 1;
		fill(&v[0][0], &v[49][49], 0);
		for (int i = 0; i <n ; i++) {
			for (int j = 0; j < n; j++) {
				nn = 0; mm = 0;
				if (v[i][j] == 0) {
					cc(i, j); 
					if (nn > 1) { cc2(mm, nn); }
					vn++;
				}
			}
		}
		cout <<"g:"<<g<< "-----------------------\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << ground[i][j]<<" ";
			}cout << "\n";
		}
		if (vn == (n*n+1)) {break;}
		vn = 1;
	}
		cout << g;
	return 0;
}