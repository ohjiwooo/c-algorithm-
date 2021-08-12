#include<iostream>
#include<queue>
using namespace std;

int n, m; //컴퓨터의 수, 줄의 수
int a, b, c;
int arr[1004];

void init() {
	for (int i = 1; i <= n;i++) {
		arr[i] = i;
	}

}
int find(int a) {

	if (arr[a] == a)return a;
	
	return arr[a] = find(arr[a]);

}

void uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	arr[pa] = pb;

}
int main() {

	cin >> n >> m;

	priority_queue<pair<int, pair<int, int>>>q;

	for (int i = 0; i < m;i++) {
		cin >> a >> b >> c;
		q.push(make_pair(-c, make_pair(a, b)));
	
	}
	int answer = 0;
	init();
	for (int i = 0; i < m;i++) {
		
		if (find(q.top().second.first) != find(q.top().second.second)) { 
			answer += -(q.top().first);
			uni(q.top().second.first, q.top().second.second);
		}
		q.pop();
	}

	cout << answer;
	return 0;
}