#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n, k;//n장 중 k장 선택

vector<string>v;
int num = 0;
bool vis[100];
vector<string>answer;


bool find(string a) {

	for (int i = 0; i < answer.size();i++) {
		if (answer[i] == a)return false;
	}
	return true;
}
bool dfs(int nn,string now) {

	if (nn == 0) { //다만듬
		if (find(now)==true) { //만들지않은 수라면
			num++;
			answer.push_back(now);
		}
		return true;
	}

	for (int i=0; i <n ;i++) {
		if (vis[i]!=true) {
			vis[i] = true;
			dfs(nn - 1,now+v[i]);
			vis[i] = false;
		}

	}
	return true;
}

int main() {
	
	cin >> n >> k;

	for (int i = 0; i < n;i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}

	dfs(k,"");
	cout << num;

	return 0;
}