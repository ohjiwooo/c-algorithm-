#include<iostream>
#include<queue>
using namespace std;

int box[1002][1002];
int c[1002][1002] = {0,};
int n;
int m;
int a;//안익은거 수
int ans = 0;
int i;
int j;
int b=0;//익은거수
typedef struct s{

	int i;
	int j;

}s;


int main() {
	
	queue<s> qq;
	int size;
	cin >> m; //가로칸
	cin >> n;//세로칸

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			if (box[i][j] == 0) { a++; }
			else if (box[i][j] == 1) { qq.push({ i,j }); c[i][j] = 1; b++; }
			else if (box[i][j] == -1) { c[i][j] = -1; }
		}
	} //입력받음
	
	if (a == 0) { cout << "0"; return 0; } //0개일 경우 0리턴		
	a = a + b;
	
	while (qq.empty() != true) {
		size = qq.size();
		for (int k= 0; k < size; k++) {
			i = qq.front().i;
			j = qq.front().j;
		
			qq.pop();
			box[i][j] = 1;
			a--;
		
			if (i != 0 && box[i - 1][j] == 0 && c[i - 1][j] != 1) { qq.push({ i - 1,j }); c[i - 1][j] = 1; } //위
			if (j != 0 && box[i][j - 1] == 0 && c[i][j - 1] != 1) { qq.push({ i ,j - 1}); c[i][j - 1] = 1; }//왼
			if (j != m - 1 && box[i][j + 1] == 0 && c[i][j + 1] != 1) { qq.push({ i ,j + 1 }); c[i][j + 1] = 1; }//오
			if (i != n - 1 && box[i + 1][j] == 0 && c[i + 1][j] != 1) { qq.push({ i + 1 ,j }); c[i + 1][j] = 1; }//아
		}ans++; 
		
	}

	
	if (a != 0) { cout << "-1"; return 0; }
	else { cout << ans-1; }
		
		
	


		
	return 0;
}