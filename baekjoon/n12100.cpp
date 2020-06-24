#include<iostream>

using namespace std;

int n;
int map[25][25];
bool c[25][25];

int temp1[25][25];
int temp2[25][25];
int temp3[25][25];
int temp4[25][25];
int temp5[25][25];

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp1[i][j] = map[i][j];
		}
	}
}

void init_c() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = false;
		}
	}
}

void co(int arr1[25][25],int arr2[25][25]) {
	int a;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

void up(int arr[25][25]) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				int k = i;
				while (k - 1 > 0 && arr[k - 1][j] == 0) {
					k--;
				}
				if (arr[i][j] == arr[k-1][j] && c[k-1][j] == false) {
					arr[k-1][j] *= 2;
					arr[i][j] = 0;
					c[k-1][j] = true;
				}
				else if (arr[k - 1][j] == 0) {
					arr[k - 1][j] = arr[i][j];
					arr[i][j] = 0;
				}
				else if (arr[k-1][j]!=0 && k!=i) {
					arr[k][j] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
	}
}


void right(int arr[25][25]) {
	for (int j = n - 2; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] != 0) {
				int k = j;
				while (arr[i][k + 1] == 0 && k + 1 < n-1) {
					k++;
				}
				if (arr[i][j] == arr[i][k + 1] && c[i][k + 1] == false) {
					arr[i][k + 1] *= 2;
					arr[i][j] = 0;
					c[i][k + 1] = true;
				}
				else if (arr[i][k + 1] == 0) {
					arr[i][k + 1] = arr[i][j];
					arr[i][j] = 0;

				}
				else if (arr[i][k + 1] != 0 && k!=j) {
					arr[i][k] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
	}
}

void down(int arr[25][25]) {
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]!=0) {
				int k = i;
				while (arr[k + 1][j] == 0 && k + 1 < n-1) {
					k++;
				}
				if (arr[i][j] == arr[k+1][j] && c[k+1][j] == false) {
					arr[k+1][j] *= 2;
					arr[i][j] = 0;
					c[k+1][j] = true;

				}
				else if (arr[k+1][j] == 0 ) {
					arr[k+1][j] = arr[i][j];
					arr[i][j] = 0;

				}
				else if (arr[k+1][j] !=0 && k!=i) {
					arr[k][j] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
	}
}

void left(int arr[25][25]) {
	for (int j = 1; j <n; j++) {
		for (int i = 0; i < n; i++) {
			if (arr[i][j] !=0) {
				int k = j;
				while (arr[i][k - 1] == 0 && k - 1 > 0) {
					k--;
				}
				if (arr[i][j] == arr[i][k - 1] && c[i][k - 1] == false) {
					arr[i][k - 1] *= 2;
					arr[i][j] = 0;
					c[i][k - 1] = true;
				}
				else if (arr[i][k - 1] == 0 ) {
					arr[i][k - 1] = arr[i][j];
					arr[i][j] = 0;
				}
				else if (arr[i][k-1] !=0 && k!=j) {
					arr[i][k] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}
	}
}

int max(int arr[25][25]) {
	int ans=0;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			if (arr[i][j] > ans) { ans = arr[i][j]; }
		}
	}
	return ans;
}

int main() {
	
	int ans = 0;

	cin >> n;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> map[i][j];
			c[i][j] = false;
	
		}
	}

	//0-up 2-right 3-down 4-left

	for (int i = 0; i < 4;i++) {
		init_c();
		init();
		if (i==0) {up(temp1);}
		else if (i == 1) { right(temp1); }
		else if (i == 2) { down(temp1); }
		else  {left(temp1); }

		
		for (int i2 = 0; i2 < 4;i2++) {
			init_c();
			co(temp2, temp1);
			if (i2 == 0) { up(temp2); }
			else if (i2 == 1) { right(temp2); }
			else if (i2 == 2) { down(temp2); }
			else { left(temp2); }
		
			for (int i3 = 0; i3 < 4;i3++) {
				init_c();
				co(temp3, temp2);
				if (i3 == 0) { up(temp3); }
				else if (i3 == 1) { right(temp3); }
				else if (i3 == 2) { down(temp3); }
				else { left(temp3); }
				
				for (int i4 = 0; i4 < 4;i4++) {
					init_c();
					co(temp4, temp3);
					if (i4 == 0) { up(temp4); }
					else if (i4 == 1) { right(temp4); }
					else if (i4 == 2) { down(temp4); }
					else { left(temp4); }

					for (int i5 = 0; i5 < 4;i5++) {
						init_c();
						co(temp5, temp4);

						if (i5 == 0) { up(temp5); }
						else if (i5 == 1) { right(temp5); }
						else if (i5 == 2) { down(temp5); }
						else {left(temp5); }	

						if (max(temp5) > ans) { ans = max(temp5); }
					}
				}
			}
		}	
	}
	
	cout << ans;

	return 0;
}