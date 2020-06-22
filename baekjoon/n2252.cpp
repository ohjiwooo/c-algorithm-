#include<iostream>
#include<queue>

using namespace std;

int n, m;
vector <int>stud[32005];
int a,b;
int arr[32005];
vector <int>ans(32005);

int main() {

	queue<int>qq;

	cin >> n >> m;

	for (int i = 0; i < m;i++) {
		cin >> a;
		cin >> b;

		stud[a].push_back(b);
		arr[b]++;
	}

	
	for (int i = 1; i <=n; i++) {
		if (arr[i] == 0) {
			qq.push(i);
		}
	}
	
	
	int k = 0;
	while (qq.empty()!=true) {
		int now = qq.front();
	
		qq.pop();
		ans[k++]=now;
		

		for (int i = 0; i < stud[now].size();i++) {
			arr[stud[now][i]]--;
			if (arr[stud[now][i]] == 0) { qq.push(stud[now][i]); }
		}

		
	}
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
		}
	
	return 0;

}