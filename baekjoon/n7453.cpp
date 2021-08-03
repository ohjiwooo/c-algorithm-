#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

ll a[4004];
ll b[4004];
ll c[4004];
ll d[4004];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;//�迭�� ũ��
	
	for (int i = 0; i < n;i++) {
		cin >> a[i];
		cin >> b[i];
		cin >> c[i];
		cin >> d[i];
	}
	//a,b ������ ��� �� ��ó��
	vector<ll>ab;

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			ab.push_back(a[i] + b[j]);
		}
	}

	//c,d ������ ��� �� ��ó��
	vector<ll>cd;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cd.push_back(c[i] + d[j]);
		}
	}
	ll answer = 0;
	sort(cd.begin(), cd.end()); 
	for (int i = 0; i < ab.size();i++) { //ab�� �հ� ���밪�� ���� ��ȣ�� �ݴ��� ���� ������ cd���� Ž��
		
		int upper = upper_bound(cd.begin(), cd.end(), -ab[i]) - cd.begin();
		int lower = lower_bound(cd.begin(),cd.end(), -ab[i]) - cd.begin();
		answer += (upper - lower);

	}

	cout << answer;
	return 0;
}