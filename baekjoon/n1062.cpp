#include<iostream>
#include<string>

using namespace std;

bool check[26];
int n, k;
string arr[52];
bool word[52][26];
int answer = 0;

int ans() {
	int ans = 0;
	for (int i = 0; i < n;i++) { //i번째 문장
		bool flag = true;
		for (int j = 0; j < 26;j++) {
			if (word[i][j]==true && check[j]==false) {
				flag = false; break;
			}
		}
		if (flag==true) {
			ans++;
		}
	}

	return ans;
}
int dfs(int idx,int c) {//시작 알파벳, 현재까지 개수

	if(c==k) {
	
		int tmp = ans();
		if (tmp > answer)answer = tmp;
		return 0;
	} //되는단어 찾기

	for (int i = idx; i < 26;i++) {

		if (check[i])continue;
	
		check[i] = true;
		dfs(i + 1, c + 1);
		check[i] = false;

	}
	return 0;
}

int main() {

	
	cin >> n >> k;


	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}
	if (k<5) { //a,c,n,t,i
		cout << 0;
		return 0;
	}

	k -= 5;
	check['a' - 'a']=true;
	check['c' - 'a']=true;
	check['n' - 'a']=true;
	check['t' - 'a']=true;
	check['i' - 'a']=true;
	for (int i = 0; i < n;i++) {
		word[i]['a' - 'a']=true;
		word[i]['c' - 'a']=true;
		word[i]['n' - 'a']= true;
		word[i]['t' - 'a']=true;
		word[i]['i' - 'a']=true;
		for (int j = 0; j < arr[i].size();j++) {
			word[i][arr[i][j]-'a'] = true;
		}
	}

	dfs(1,0);
	cout << answer;
}