#include<iostream>
#include<vector>
using namespace std;




int n,p;
long long temp;
bool vis[22];

long long f(int a) { //팩토리얼 리턴
	long long answer=1;
	while (a>0) {
		answer *= a--;
	}
	return answer;
}

int get_num(int m,long long num) {
	int tmp = 0;
	long long a = f(m);
	
	for (int i = 1; i <= n;i++) {
		if (num <= a*i) {
			tmp = i; 
			temp = num-(a * (i-1));
			break;
		}
	}
	
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] != true)answer++;
		if (answer == tmp){answer = i; break;}
	}
	vis[answer] = true;
	return answer;
}

int order(int m) { //m이 vis==true 인 수를 제외하고 몇번째인지

	int answer = 0;
	for (int i = 1; i <= m; i++) {
		if (vis[i] != true)answer++;
	}
	vis[m] = true;
	return answer;
}
int main() {



	cin >> n>>p;

	if (p == 1) {
		long long num;
		vector<int>answer;
		cin >> num; //num번째 순열 구하기
		int tmp = n-1;
		temp = num;
		while (tmp>=0) {
			answer.push_back(get_num(tmp, temp));
			tmp=tmp - 1;
		}
		for (int i = 0; i < answer.size();i++) {
			cout << answer[i]<<" ";
		} cout << "\n";
	}
	else {
	
		vector<int>v;
		long long answer = 0;
		int a;
		for (int i = 0; i < n;i++) {  //v가 몇번째 순열인지 구하기
			cin >> a;
			v.push_back(a);
		}

		int tmp = n-1;
		for (int i = 0; i < v.size();i++) {

			int now = v[i];

			answer += f(tmp--)* (order(now)-1);


		}
		cout << answer+1;
	}

}