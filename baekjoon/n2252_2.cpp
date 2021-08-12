#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int n, m;//n명의 학생-32000, m번의 비교
int a, b;

vector<int>v[32002]; //내뒤에 누구?
int arr[32002]; //내앞에 몇명?

queue<int>q;
int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	while (m--) {
	
		cin >> a >> b; //a가 b 앞에서야함
		arr[b]++;
		v[a].push_back(b);

	}
	for (int i = 1; i <= n;i++) {
		if (arr[i] == 0)q.push(i);
	}
	
	while (q.empty()!=true) {
		
		int now = q.front(); q.pop();
		cout << now << " ";
		for (int i = 0; i < v[now].size();i++) {
			arr[v[now][i]]--;
			if (arr[v[now][i]] == 0)q.push(v[now][i]);
		}
	}


	return 0;
}