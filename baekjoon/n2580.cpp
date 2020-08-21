#include<iostream>
//#include<algorithm>
using namespace std;

int map[15][15];
int num = 0;
//int answer[15][15];
typedef struct s{

	int a=0;//행 or 열
	int b=0;//0의 갯수

}s;

bool com(s s1, s s2) {
	return s1.b < s2.b;
}

void fill_i(int n) {

	int ans[10] = { 0 };
	int a = 0;
	for (int i = 0; i < 9;i++) {
		if (map[n][i] == 0) { a = i; }
		else {
			ans[map[n][i]] = 1;
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (ans[i] == 0) { map[n][a] = i; }
	}
}
void fill_j(int n) {

	int ans[10] = { 0 };
	int a = 0;
	for (int i = 0; i < 9; i++) {
		if (map[i][n] == 0) { a = i; }
		else {
			ans[map[i][n]] = 1;
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (ans[i] == 0) { map[a][n] = i; }
	}
}

void fill_s(int a,int b) {
	int ans[10] = { 0 };
	int tempi, tempj;

	for (int i = a; i < a + 3; i++) {
		for (int j = b; j < b + 3; j++) {
			if (map[i][j] == 0) { tempi = i; tempj = j;; }
			else {
				ans[map[i][j]] = 1;
			}
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (ans[i] == 0) { map[tempi][tempj] = i; }
	}

}
void c() {

	s arr1[9];
	s arr2[9];
	int n;
	for (int i = 0; i < 9; i++) {//행
		n = 0;
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) { n++; }
		}
		if (n==1) {
			fill_i(i);
			num--;
			return;
		}
		//arr1[i].a = i; arr1[i].b = n;
	}//sort(arr1,arr1+9,com);

	for (int j = 0; j < 9; j++) {//열
		n = 0;
		for (int i = 0; i < 9; i++) {
			if (map[i][j] == 0) { n++; }
		}if (n == 1) {
			fill_j(j);
			num--;
			return;
		}
	//	arr2[j].a = j; arr2[j].b = n;
	}//sort(arr2, arr2 + 9, com);


	
	int a = 0; int  b = 0; int c = 0; n = 0;
	while (c < 9) {
		for (int k = 0; k < 3; k++) {
			for (int i = a; i < a + 3; i++) {
				for (int j = b; j < b + 3; j++) {
					if (map[i][j] == 0) { n++; }
				}
			}
			if (n == 1) {
				fill_s(a, b);
				num--;
				return;
			}
			b += 3; n = 0;
		}
		a += 3; b = 0; n = 0;
		c++;
	}
	

}

void p() {
	cout << "==============================\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}cout << "\n";
	}
}

void in() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) { num++; }
		}
	}
}
/*void in2() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> answer[i][j];
		}
	}
}*/

/*bool ans() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (answer[i][j]!= map[i][j]) {
				return false;
			}
		}
	}
	return true;
}*/
int main() {
	
//	in2();
	in();
	
	while (num>0) {
		c();
	}
	p();
//	if (ans() == true) { cout << "\ngood\n"; }
//	else { cout << "\nbad\n"; }

	
	return 0;
}