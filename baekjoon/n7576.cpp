#include<iostream>

using namespace std;

int box[1002][1002];
int c[1002][1002] = {0,};
int n;
int m;
int ans=0;
int a;//�������� ��
int k;
int cc = 2;
void change(int i, int j) {
	if (j != m - 1 && box[i][j + 1] != 0&& box[i][j + 1] != cc&& box[i][j + 1]!=-1) { box[i][j] = cc; a--; }//������
	else if (j != 0 && box[i][j - 1] != 0 && box[i][j - 1] != cc&& box[i][j - 1] != -1) { box[i][j] = cc; a--; }//����
	else if (i != 0 && box[i - 1][j] !=0 && box[i-1][j] != cc && box[i - 1][j] != -1) { box[i][j] = cc; a--; }//��
	else if (i != n - 1 && box[i + 1][j] !=0 &&box[i + 1][j] !=cc && box[i + 1][j] != -1) { box[i][j] = cc; a--; }//�Ʒ�
}

/*void change2() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == 1) { box[i][j] = 1; }
		}

	}

}*/
int main() {

	cin >> m; //����ĭ
	cin >> n;//����ĭ

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0) { a++; }
		}
	} //�Է¹���

	if (a == 0) { cout << "0"; return 0; }


	for ( k = 0; k < 3000; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j] == 0) {
					change(i, j);
				}
			}	
		}cc++;//change2();
		if (a == 0) { break; }
	}

	
	if (a != 0) { cout << "-1"; return 0; }


	cout << k+1;
	return 0;
}