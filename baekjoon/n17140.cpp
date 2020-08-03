#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t=0;
int r, c, k;
int arr[105][105] = { 0 };
int x = 3;
int y = 3;
typedef struct s {
	int sum;
	int n;

}s;
bool comp(s a,s b) {

	return a.sum < b.sum || ((a.sum == b.sum) && a.n < b.n);

}
void func_r() {
	int new_y=y;

	for (int i = 1; i <= x; i++) {
		vector <s> v;
		int temp[105] = { 0 };
		int temp2 = 1;

		for (int j = 1; j <= y; j++) {
			temp[arr[i][j]]++;
		}
		for (int j = 1; j <= 100; j++) {
			if (temp[j] != 0) { v.push_back({ temp[j],j }); }
		}

		sort(v.begin(), v.end(), comp);
		
		 for (int j = 0; j < v.size(); j++) {
			 if (temp2 <= 100) {
				 arr[i][temp2++] = v[j].n;
			 }
			 else { break; }
			 if (temp2 <= 100) {
				 arr[i][temp2++] = v[j].sum;
			 }
			 else { break; }
		}
		--temp2;
		if (i == 1) { new_y = temp2; }
		if (temp2 < y) {
			for (int z = temp2 + 1; z <= y; z++) {
				arr[i][z] = 0;
			}
			if (new_y < temp2) { new_y = temp2; }
		}
		else {
			if (new_y < temp2) { new_y= temp2; }
		}
	
	}
	y = new_y;
		
}
void func_c(){
	int new_x = x;

	for (int j = 1; j <= y; j++) {
		vector <s> v;
		int temp[105] = { 0 };
		int temp2 = 1;

		for (int i = 1; i <= x; i++) {
			temp[arr[i][j]]++;
		}
		for (int i = 1; i <= 100; i++) {
			if (temp[i] != 0) { v.push_back({ temp[i],i }); }
		}

		sort(v.begin(), v.end(), comp);

		for (int i = 0; i < v.size(); i++) {
			if (temp2 <= 100) {
				arr[temp2++][j] = v[i].n;
			}
			else { break; }
			if (temp2<=100) {
				arr[temp2++][j] = v[i].sum;
			}
			else { break; }
		}
		--temp2;
		if (j == 1) { new_x = temp2; }
		if (temp2<x) {
			for (int z = temp2 + 1; z <= x; z++) {
				arr[z][j] = 0;
			}
			if (new_x < temp2) { new_x = temp2; }
		}
		else {
			if (new_x < temp2) { new_x = temp2; }
		}
	}
	x = new_x;
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

	while (t<=100) {
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