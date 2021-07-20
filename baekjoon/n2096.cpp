#include<iostream>
#include<algorithm>

using namespace std;

int arr[100004][3];
int minn[2][3];
int maxx[2][3];

int max_3(int a,int b,int c) {

	int answer = a;
	if (answer<b) {
		answer = b;
	}if(answer < c) {
		answer = c;
	}
	return answer;
}

int min_3(int a,int b,int c) {

	int answer = a;
	if (answer >b) {
		answer = b;
	}if (answer > c) {
		answer = c;
	}
	return answer;

}
int main() {

	int n = 0;
	int a, b, c;

	cin >> n;

	for (int i = 0; i < n;i++) {
	
		cin >> a >> b >> c;
		arr[i][0] = a;
		arr[i][1] = b;
		arr[i][2] = c;

	}

	for (int i = 0; i < 3;i++) {
		minn[0][i] = arr[0][i];
		maxx[0][i] = arr[0][i];
	}
	for (int i = 1; i < n;i++) {
		
		
		maxx[1][0] = max(maxx[0][0] + arr[i][0], maxx[0][1] + arr[i][0]);
		maxx[1][1] = max_3(maxx[0][0] + arr[i][1], maxx[0][1] + arr[i][1],maxx[0][2] + arr[i][1]);
		maxx[1][2] = max(maxx[0][1] + arr[i][2], maxx[0][2] + arr[i][2]);

		maxx[0][0] = maxx[1][0]; maxx[0][1] = maxx[1][1]; maxx[0][2] = maxx[1][2];

		minn[1][0] = min(minn[0][0] + arr[i][0], minn[0][1] + arr[i][0]);
		minn[1][1] = min_3(minn[0][0] + arr[i][1], minn[0][1] + arr[i][1], minn[0][2] + arr[i][1]);
		minn[1][2] = min(minn[0][1] + arr[i][2], minn[0][2] + arr[i][2]);
		minn[0][0] = minn[1][0]; minn[0][1] = minn[1][1]; minn[0][2] = minn[1][2];
	}

	int max_answer = max_3(maxx[0][0], maxx[0][1], maxx[0][2]);
	int min_answer = min_3(minn[0][0], minn[0][1], minn[0][2]);

	cout << max_answer << " " << min_answer;

	return 0;
}