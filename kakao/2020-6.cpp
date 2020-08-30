#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


bool com(int a,int b) {
	return a > b;
}
int f_m(int a, int b) {

	if (a > b) {
		return a - b;
	}
	else {
		return b - a;
	}

}

int answer = 100;
bool distarr[10] = { false, };
bool weakarr[17] = { false, };

void ff(vector<int> weak, vector<int> dist, int i,int n,int m,int ans, int now) {//출발 weak인덱스,둘레 n,weak수 m,간사람수,남은 weak수

	if (now==0) {
		if (ans<answer) {
			answer = ans;
			return;
		}
		else { return; }
	}
	int k = (i+1)%m;
	queue<int>qq;


	for (int j = 0; j < dist.size();j++) {
		if (distarr[j]==false) {
			int t;
			int d = dist[j];
			distarr[j] = true; //j시작

			weakarr[i] = true;
			qq.push(i);
			now--;

			while (1) {

				if (k!=0) {
					t = f_m(weak[k],weak[k-1]);
				}
				else {
					if(k==0) {
						if (weak[k] < weak[m-1]) {
							t = n - weak[m - 1] + weak[k];
						}
						else {
							t = n - weak[k] + weak[m-1];
						}
					}
				}

				if (d>= t) {
					d -= t; qq.push((k + 1) % m); weakarr[(k + 1) % m] = true; now--; k=(k+1)%m;
				}
				else { break; }
			}

			ff(weak, dist, k, n, m, ans + 1, now);
			distarr[j] = false;
			while (qq.empty()!=true) {
				weakarr[qq.front()] = false;
				qq.pop();
				now++;
			}
		}
	}
}


int solution(int n, vector<int> weak, vector<int> dist) {

	int m = weak.size();
	sort(dist.begin(),dist.end(),com);
	
	for (int i = 0; i < weak.size();i++) {//시작인덱스 조절
		ff( weak, dist, i,n,m,0,m); 
		weakarr[i] = false;
	}
	reverse(weak.begin(), weak.end());
	for (int i = 0; i < weak.size(); i++) {
		ff(weak, dist, i, n, m,0,m);
		weakarr[i] = false;
	
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