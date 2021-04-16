#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

float dis(int x,int y,int x2, int y2) {

	float a = sqrt(((x - x2)*(x - x2)) + ((y - y2)*(y - y2)));
	return a;

}


int uni(int arr[105],int n,int a,int b) {

	if (arr[a]> arr[b]) {
		arr[a] = arr[b];
	}
	else {
		arr[b] = arr[a];

	}

}

int main() {

	priority_queue < pair<int, pair<int, int>>> pq;
	float star[105][2] = { 0, };
	int n = 0;
	cin >> n;

	for (int i = 0; i < n;i++) {
		cin >> star[i][0]>>star[i][1];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n;j++) {
			float a=dis(star[i][0],star[i][1],star[j][0],star[j][1]);
			pq.push(make_pair(-a,make_pair(i, j)));
		}
	}


	return 0;
}