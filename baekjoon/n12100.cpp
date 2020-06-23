#include<iostream>


using namespace std;


int n;
int map[25][25];
bool c[25][25];
int temp[25][25];


void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = map[i][j];
			c[i][j] = false;
		}
	}


}
void up() {
	int flag = 1;//변하면 1 아니면 0	
	while (flag == 1) {
		flag = 0;
		for (int i = 1; i <n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j]!=0 && map[i][j] == map[i - 1][j] && c[i - 1][j] == false) {
					map[i-1][j] *= 2;
					map[i][j] = 0;
					c[i - 1][j] = true;
					flag = 1;
				}
				else if (map[i-1][j] ==0 && map[i][j]!=0) {
					map[i - 1][j] = map[i][j];
					map[i][j] = 0;
					flag = 1;
				}
			}
		}
	}
}

void right() {
	int flag = 1;//변하면 1 아니면 0	
	while (flag == 1) {
		flag = 0;
		for (int j = n-2; j >=0; j--) {
			for (int i = 0; i < n; i++) {
				if (map[i][j] != 0 && map[i][j] == map[i][j+1] && c[i][j+1] == false) {
					map[i][j+1] *= 2;
					map[i][j] = 0;
					c[i][j+1] = true;
					flag = 1;
				}
				else if (map[i][j+1] == 0 && map[i][j] != 0) {
					map[i][j+1] = map[i][j];
					map[i][j] = 0;
					flag = 1;
				}
			}
		}
	}
}

void down() {
	int flag = 1;//변하면 1 아니면 0	
	while (flag == 1) {
		flag = 0;
		for (int i = n-2; i >=0; i--) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] != 0 && map[i][j] == map[i + 1][j] && c[i + 1][j] == false) {
					map[i + 1][j] *= 2;
					map[i][j] = 0;
					c[i + 1][j] = true;
					flag = 1;
				}
				else if (map[i + 1][j] == 0 && map[i][j] != 0) {
					map[i + 1][j] = map[i][j];
					map[i][j] = 0;
					flag = 1;
				}
			}
		}
	}
}

void left() {
	int flag = 1;//변하면 1 아니면 0	
	while (flag == 1) {
		flag = 0;
		for (int j = 1; j <n; j++) {
			for (int i = 0; i < n; i++) {
				if (map[i][j] != 0 && map[i][j] == map[i][j-1] && c[i][j-1] == false) {
					map[i][j-1] *= 2;
					map[i][j] = 0;
					c[i][j-1] = true;
					flag = 1;
				}
				else if (map[i][j-1] == 0 && map[i][j] != 0) {
					map[i][j-1] = map[i][j];
					map[i][j] = 0;
					flag = 1;
				}
			}
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> map[i][j];
			map[i][j] = temp[i][j];
			c[i][j] = false;
		}
	}

	int temp1[25][25];
	int temp2[25][25];
	int temp3[25][25];
	int temp[25][25];
	//0-up 2-right 3-down 4-left

	for (int i = 0; i < 4;i++) {
		if (i==0) {}
		for (int i2 = 0; i2 < 4;i2++) {
			for (int i3 = 0; i3 < 4;i3++) {
				for (int i4 = 0; i4 < 4;i4++) {
					for (int i5 = 0; i5 < 4;i5++) {

					}
				}
			}
		}	
	}
	


	return 0;
}