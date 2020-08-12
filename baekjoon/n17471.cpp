#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n;
int arr[15];//인구 수
vector <int> v[15];
int flag = 0;//나누어지면 1
int answer = 987654321;

int ans(vector <int> v2) {

	int a = 0;//-0
	int b = 0;//-1

	for (int i = 0; i < n;i++) {
		if (v2[i]==0) {
			a += arr[i+1];
		}
		else {
			b += arr[i+1];
		}
	}
	if (a > b) { return a - b; }
	else { return b - a; }
}


bool find(int start, int end, vector <int> v2) {

	int vis[15] = { false };
	queue<int>qq;

	qq.push(start);
	vis[start] = true;

	while (qq.empty() !=true) {
		int now = qq.front();
		qq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			
			if (v[now][i] == end) {
				return true;
			}
			else if (vis[v[now][i]] != true && v2[start-1]==v2[v[now][i]-1]) {
				qq.push(v[now][i]);
				vis[v[now][i]] = true;
			}
		}
	}
	return false;
}

bool f(vector <int> arr,int aa, vector <int> v2) {
	
	for (int i = 0; i < aa;i++) {
		for (int j = i+1; j < aa; j++) {//arr1
			if (find(arr[i],arr[j],v2) == false) {
				return false;
			}
		}
	}

	return true;
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

	vector <int> v2(n);//1 or 0

	for (int k = 0; k < n-1;k++) {
	
		for (int i = 0; i < n; i++) {
			v2[i] = 0;
		}

		for (int i = 0; i <= k;i++) {
			v2[i] = 1;
		}
		sort(v2.begin(), v2.end());

		do {
			vector <int> arr1(15);//0
			vector <int> arr2(15);//1
			int aa = 0;
			int bb = 0;

			for (int i = 0; i < n;i++) {
	
				if (v2[i]==1) {
					arr2[bb++] = i + 1;
				}
				else {
					arr1[aa++] = i + 1;
				}
			}
			//구현
			if (f(arr1,aa,v2)==true && f(arr2,bb,v2)==true) {
				flag = 1;//나누어짐
				int temp = ans(v2);
				if (answer > temp) { answer = temp; }
			}
		} while (next_permutation(v2.begin(), v2.end()));
	}

	if (flag == 0) { cout << -1; return 0; }
	else { cout << answer; }
	return 0;
}