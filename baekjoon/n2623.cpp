#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int n, m;//가수 수, 순서 수
vector<int> v[1005]; //내뒤에애들
int arr[1005]; //내앞에 몇명
queue <int>q;
int inp[105][1005];
int a;
int pre = 0;
int now;
vector<int>answer;

void func() {

	for (int i = 1; i <= n;i++) {
		if (arr[i] == 0)q.push(i);
	}

	while (q.empty()!=true) {
		int now = q.front(); q.pop();
		answer.push_back(now);
		for (int i = 0; i < v[now].size();i++) {
			if (--arr[v[now][i]]==0) {
				q.push(v[now][i]);
			}	
		}
	}

}

void input() {
	
	for (int i = 0; i < m;i++) {
		cin >> a;
		for (int j = 0; j < a;j++) {
			cin >> inp[i][j];
		}

		for (int j = 1; j < a; j++) {
			v[inp[i][j - 1]].push_back(inp[i][j]);
			arr[inp[i][j]]++;
		}
	}
	
}
int main() {

	cin >> n >> m;

	
	input();
	func();
	if (answer.size()!=n) {
		cout << 0;
	}
	else {
		for (int i = 0; i < n;i++) {
			cout << answer[i] << "\n";
		}
	}
	return 0;
}