#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int money[10005];
int arr[10005];
vector <pair<int, int>> v[10005];
priority_queue <pair<int, pair<int, int>>>pq;



int uni(int a, int b, int arr[10005]) {

	if (arr[a]<arr[b]) {
		arr[arr[b]] = arr[a];
	}
	else {
		arr[arr[a]] = arr[b];
	}
	return 0;
}

int find(int a,int arr[10005]) {

	if (arr[a]==a) {
		return a;
	}
	else {
		arr[a] = find(arr[a], arr); return arr[a];
	}

}

int main() {


	int n = 0; int p = 0;
	cin >> n >> p;
	int a = 0; int b = 0; int c = 0;

	int temp = 999999;
	for (int i = 1; i <= n;i++) {
		cin >> money[i];
		if (money[i] < temp) {
			temp = money[i];
		}
	}
	for (int i = 0; i < p;i++) {
		cin >> a >> b >> c;
		int w = money[a] + money[b] + c * 2;
		pq.push(make_pair(-w, make_pair(a, b)));
	}

	for (int i = 0; i <= n;i++) {
		arr[i] = i;
	}
	int num = 0;
	long long answer = 0;
	answer += temp;
	while (num<n-1) {

		int w = -pq.top().first; int i = pq.top().second.first; int j = pq.top().second.second; pq.pop();
		if (find(i,arr)!=find(j,arr)) {
			answer += w; uni(i, j, arr); num++;
		}
	}
	cout << answer;

	return 0;
}