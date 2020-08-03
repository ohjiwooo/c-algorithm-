#include<iostream>
#include<algorithm>
using namespace std;

int t=0;
int r, c, k;
int arr[105][105] = { 0 };
int x = 3;
int y = 3;

void func_r() {
	int new_y=y;

	for (int i = 1; i <= x;i++) {

		int temp[105] = { 0 };
		int temp2 = 1;

		for (int j = 1; j <=y;j++) {
			temp[arr[i][j]]++;
		}
		for (int z = 1; z < 101;z++) {
			if (temp[z]!=0 && temp2<=101) {
				arr[i][temp2++] = z;
				if (temp2<=101) {
					arr[i][temp2++] = temp[z];
				}
				else {
					break;
				}
			}
			else if (temp2 > 101) { break; }
			
		}if (--temp2<new_y && i!=1) {
			for (int z = temp2+1; z <= new_y;z++) {
				arr[i][z] = 0;
			}
		}
		else if (i == 1) { new_y = temp2; }
		else if(temp2>new_y){ new_y = temp2; }
	}
	y = new_y;
}
void func_c(){

	int new_x = x;

	for (int j = 1; j <= y; j++) {

		int temp[101] = { 0 };
		int temp2 = 1;

		for (int i = 1; i <= x; i++) {
			temp[arr[i][j]]++;
		}
		for (int z = 1; z < 101; z++) {
			if (temp[z] != 0 && temp2<=101) {
				arr[temp2++][j] = z;
				if (temp2<=101) {
					arr[temp2++][j] = temp[z];
				}
				else { break; }
			}
			else if (temp2 > 101) { break; }

		}if (--temp2 < new_x && j!=1) {
			for (int z = temp2+1; z <= new_x; z++) {
				arr[z][j] = 0;
			}
		}
		else if (j == 1) { new_x = temp2; }
		else if (temp2 > new_x) { new_x = temp2; }
	}
	x = new_x;

}

void p() {

	cout << "======================== t: " << t << "=======================\n";
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			cout << arr[i][j] << " ";
		}cout << "\n";
	}
}
bool ans() {
	if (arr[r][c]==k) {
		return true;
	}
	return false;
}
int main() {

	cin >> r >> c >> k;
	for (int i = 1; i< 4;i++) {
		for (int j = 1; j < 4;j++) {
			cin >> arr[i][j];
		}
	}

/*	func_r();
	func_c();
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			cout << arr[i][j]<<" ";
		}cout << "\n";
	}*/
	while (t<=100) {
		p();
		if (ans() == true) {
			cout << t;
			return 0;
		}
		if (x>=y) {
			func_r();
		}
		else {
			func_c();
		}
		t++;
	}
	cout << -1;
	return 0;
}