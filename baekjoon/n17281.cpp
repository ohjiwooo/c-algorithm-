#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int arr[55][15];
int start = 1;
int out = 0;
vector <int>v(8);
vector <int>v2(10);

int ff(int a,int arr2[10]) {
	int score = 0;

	if (a==1 ||a==2 || a==3) {
		for (int i = 3; i >=0 ;i--) {
			arr2[i + a] +=arr2[i];//다음위치로 전부이동
			arr2[i] = 0;//현재위치에서 나감
		}
	}
	else if (a==4) {
		for (int i = 0; i < 4; i++) {
			arr2[4] += arr2[i];//전부 홈으로 이동
			arr2[i] = 0;
		}
	}
	else if (a==0) {
		out++;
		arr2[0] = 0;
	}
	//이동

	for (int i = 4; i< 10;i++) {
	
		score += arr2[i];
		arr2[i] = 0;
	}
	return score;
}

int round() {
	int s = 0;

	for (int i = 1; i <= n;i++) {
		int arr2[10] = { 0 };//위치
		out = 0;
		while (out < 3) {

			if (start == 10) {
				start = 1;
			}
			arr2[0]++;
			s += ff(arr[i][v2[start++]],arr2);

		}
	}
	return s;
}


int main() {

	cin >> n;
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9;j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < 8; i++) {
		v[i] = i + 2;
	}
	
	do {
		int k = 1;

		for (int i = 0; i < 8; i++) {
			if (i == 3) { v2[k++] = 1; }
			v2[k++] = v[i];
		}
		start = 1;
		int temp = round();
		if (temp > answer) { answer = temp; }
	
	} while (next_permutation(v.begin(),v.end()));

	cout << answer;

	return 0;
}