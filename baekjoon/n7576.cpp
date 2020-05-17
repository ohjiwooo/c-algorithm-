#include<iostream>
#include<queue>
using namespace std;

int box[1002][1002];
int c[1002][1002] = {0,};
int n;
int m;
int a;//�������� ��
int ans = 0;
int i;
int j;
int b=0;//�����ż�
typedef struct s{

	int i;
	int j;

}s;


int main() {
	
	queue<s> qq;
	int size;
	cin >> m; //����ĭ
	cin >> n;//����ĭ

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0) { a++; }
			else if (box[i][j] == 1) { qq.push({ i,j }); c[i][j] = 1; b++; }
			else if (box[i][j] == -1) { c[i][j] = -1; }
		}
	} //�Է¹���
	
	if (a == 0) { cout << "0"; return 0; } //0���� ��� 0����		
	a = a + b;
	
	while (qq.empty() != true) {
		size = qq.size();
		for (int k= 0; k < size; k++) {
			i = qq.front().i;
			j = qq.front().j;
		
			qq.pop();
			box[i][j] = 1;
			a--;
		
			if (i != 0 && box[i - 1][j] == 0 && c[i - 1][j] != 1) { qq.push({ i - 1,j }); c[i - 1][j] = 1; } //��
			if (j != 0 && box[i][j - 1] == 0 && c[i][j - 1] != 1) { qq.push({ i ,j - 1}); c[i][j - 1] = 1; }//��
			if (j != m - 1 && box[i][j + 1] == 0 && c[i][j + 1] != 1) { qq.push({ i ,j + 1 }); c[i][j + 1] = 1; }//��
			if (i != n - 1 && box[i + 1][j] == 0 && c[i + 1][j] != 1) { qq.push({ i + 1 ,j }); c[i + 1][j] = 1; }//��
		}ans++; 
		
	}

	
	if (a != 0) { cout << "-1"; return 0; }
	else { cout << ans-1; }
		
		
	


		
	return 0;
}