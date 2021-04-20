#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int t = 0; int n = 0; int k = 0; int a = 0; int b = 0; int goal = 0; int temp = 0; int answer = 0;

int f(vector<int>v[1005],int time[1005],int arr[1005],bool vis[1005], vector<int>v2[1005]) {
	queue<int>q;
	int answer[1005] = { 0, };
	int num = 0;
	while (num < n) {
		for (int i = 1; i <= n; i++) {   //진입차수가 0이고 목표건물을 위해 세워야 하는 노드 q에삽입(현재진행 가능한 작업)
			if (arr[i] == 0 && vis[i] != true ) {
				q.push(i); vis[i] = true; num++;
			}
		}
		
		while (q.empty() != true) {
			int node = q.front(); q.pop(); temp = 0;
			for (int j = 0; j < v2[node].size();j++) {
				temp = max(time[v2[node][j]], temp);
			}
			time[node] += temp;
			for (int j = 0; j < v[node].size(); j++) { //다음작업들 수정
				arr[v[node][j]]--;
			}
			
		}
	}
	return time[goal];
}


int main() {

	
	cin >> t;
	
	
	while (t--) {
		cin >> n >> k; //건물 수, 규칙 수
		int time[1005] = {0,};
		int arr[1005] = { 0, };
		bool vis[1005] = {false,};
		vector<int>v[1005];
		vector<int>v2[1005];
		answer = 0;
		temp = 0;

		for (int i = 1; i <= n;i++) {
			cin >> time[i];
		}
		for (int i = 0; i < k;i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v2[b].push_back(a);
			arr[b]++;
		}
		cin >> goal;
			
		cout <<f(v,time,arr,vis,v2) <<"\n";

	}

}


