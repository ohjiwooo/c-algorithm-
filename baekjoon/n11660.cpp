#include<iostream>


using namespace std;

long long map[1030][1030];

int sum(int i1,int j1, int i2, int j2) {

	int answer = 0;
	if (i1 > i2)swap(i1, i2); //i2가 더 크게
	if (j1 > j2)swap(j1, j2);//j2가 더 크게
	answer = map[i2][j2] - map[i1][j2] - map[i2][j1] + map[i1][j1];
	return answer;
}

int main() {



	int n, m;
	cin >> n >> m;
	int a;
	for (int i = 1; i < n;i++) {
		for (int j = 1; j <= n;j++) {
			cin >> a;

		}
	}


}