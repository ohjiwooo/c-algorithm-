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
		arr[arr[a]] = arr[b];
	}
	else {
		arr[arr[b]] = arr[a];

	}
	return 0;
}

int find(int arr[105],int k) {

	if (arr[k]==k) {
		return k;
	}
	else {
		arr[k] = find(arr, arr[k]); return arr[k];
	}
}

int main() {

	priority_queue < pair<float, pair<int, int>>> pq;
	float star[105][2] = { 0, };
	int n = 0;
	int arr[105] = {0,};

	
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
	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
	int m = 1;
	float answer = -pq.top().first;
	arr[pq.top().second.second] = pq.top().second.first;
	pq.pop();
	while (m<n-1) {
		int w = -pq.top().first; int i = pq.top().second.first; int j = pq.top().second.second; pq.pop();
		if (find(arr,i)!=find(arr,j)) {
			answer += w;
			uni(arr, n, i, j);
			m++;
		}
	}
	cout << answer;


	return 0;
}