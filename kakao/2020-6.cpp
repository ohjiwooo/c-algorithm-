#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


bool com(int a,int b) {
	return a > b;
}
int answer = 100;
bool distarr[10] = { false, };
bool weakarr[17] = { false, };

void ff(vector<int> weak, vector<int> dist,int i,int n,int m,int ans,int now) {//출발 weak인덱스,,weak 원소갯수,간 사람수,남은 weak

	queue <int> qq;
	if (ans >= dist.size() || now==-1) {
		for (int i2 = 0; i2 < m; i2++) {
			if (weak[i2] == false) {
				return;
			}
		}

		if (ans!=0 &&ans<answer) {
			answer = ans;
			return;

		}
	}
	
	for (int j = 0; j < dist.size(); j++) {//가는사람 조절- 가는사람 i
		int f = 0; 
		if (distarr[j]==false) {
			int k=(i+1)%m;
			int a = 0;
			int d = dist[j];
			int t;
			while (1) {
				k = k % m;
				if (weakarr[k] ==true) {
					break;
				}
				if (k != 0) {
					t = weak[k] - weak[k - 1];
				}
				else {
					t = (n - weak[m - 1]) + weak[k];
				}
				if (t <= d) {
					weakarr[k] = true; d -= t; a++; f = 1; qq.push(k); k++; now--;
				}
				else { break; }
			}
			if (f==1) {
				distarr[j] = true;
				ff(weak, dist, k, n, m, ans + 1, now-1);
				now++;
				distarr[j] = false;
				while (qq.empty()!=true) {
					int tt = qq.front();
					weakarr[tt] = false;
					now++;
					qq.pop();
				}
			}
		}
	}
}


void r_ff(vector<int> weak, vector<int> dist, int i, int n, int m, int ans, int now) {//출발 weak인덱스,,weak 원소갯수,간 사람수,남은 weak

	queue <int> qq;
	if (ans >= dist.size() || now == -1) {
		for (int i2 = 0; i2 < m; i2++) {
			if (weak[i2] == false) {
				return;
			}
		}

		if (ans != 0 && ans < answer) {
			answer = ans;
			return;

		}
	}
	///////반대로가는거 고치기
	for (int j = 0; j < dist.size(); j++) {//가는사람 조절- 가는사람 i
		int f = 0;
		if (distarr[j] == false) {
			int k = (i + 1) % m;
			int a = 0;
			int d = dist[j];
			int t;
			while (1) {
				k = k % m;
				if (weakarr[k] == true) {
					break;
				}
				if (k != 0) {
					t = weak[k] - weak[k - 1];
				}
				else {
					t = (n - weak[m - 1]) + weak[k];
				}
				if (t <= d) {
					weakarr[k] = true; d -= t; a++; f = 1; qq.push(k); k++; now--;
				}
				else { break; }
			}
			if (f == 1) {
				distarr[j] = true;
				ff(weak, dist, k, n, m, ans + 1, now - 1);
				now++;
				distarr[j] = false;
				while (qq.empty() != true) {
					int tt = qq.front();
					weakarr[tt] = false;
					now++;
					qq.pop();
				}
			}
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {

	int m = weak.size();
	sort(dist.begin(),dist.end(),com);
	
	for (int i = 0; i < weak.size();i++) {
	//시작점 하나씩 조절
		weakarr[i] = true;
		ff( weak, dist, i, n,m,0,m-1);
		weakarr[i] = false;
	}
	reverse(weak.begin(), weak.end());
	for (int i = 0; i < weak.size(); i++) {
		//시작점 하나씩 조절
		weakarr[i] = true;
		ff(weak, dist, i, n, m, 0, m - 1);
		weakarr[i] = false;
		cout << answer << "\n";
	}

	return answer;
}


int main() {

	vector<int> weak;
	vector<int> dist;

	weak.push_back(1);
	weak.push_back(5);
	weak.push_back(6);
	weak.push_back(10);

	dist.push_back(1);
	dist.push_back(2);
	dist.push_back(3);
	dist.push_back(4);
	
	solution(12,weak, dist);
	cout << answer;
	return 0;
}