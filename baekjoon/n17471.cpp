#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;
int arr[15];//牢备 荐
vector <int> v[15];
vector <int> v2(n);//1 or 0
vector <int> v3(n + 1);//锅龋客 备开

bool find(int start, int end) {

	int vis[15] = { false };
	queue<int>qq;

	qq.push(start);
	vis[start] = true;

	while (qq.empty() !=true) {
		int now = qq.front();
		qq.pop();

		for (int i = 0; i < v[now].size; i++) {
			
			if (v[start][i] == end) {
				return true;
			}
			else if (vis[v[start][i]] != true && v3[v[start][i]]==v3[now]) {
				qq.push(v[start][i]);
				vis[v[start][i]] = true;
			}
		}
	}
	return false;
}

int main() {

	cin >> n;
	for (int i = 1; i <= n;i++) {
		cin >> arr[i];
	}

	int a, b;
	for (int i = 1; i <= n;i++) {
		cin >> a;
		for (int j = 0; j < a;j++) {
			cin >> b;
			v[i].push_back(b);
		}
	}

	for (int i = 0; i < n;i++) {
		v2[i] = 0;
		v3[i+1] = i + 1;
	}
	
	for (int k = 1; k < n;k++) {
	
		for (int i = 0; i <= k;i++) {
			v2[i] = 1;
		}

		do {
		
			for (int i = 0; i < n;i++) {
				if (v2[i]==1) {
					v3[i+1]= 1;
				}
			}
			//备泅



		} while (next_permutation(v2.begin(), v2.end()));
	
	}


	return 0;
}