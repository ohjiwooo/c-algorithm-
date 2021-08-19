#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

typedef long long ll;
int n, q;// ����, ���� 100000
int a, b, c, d;


void update(int s,int e, int node, int aim, ll diff, vector<ll>&v) {

	if (s > aim || e < aim)return ;

	v[node] += diff;

	if (s == e)return ;

	int mid = (s + e) / 2;

	update(s, mid, node * 2, aim, diff, v);
	update(mid+1,e, node * 2+1, aim, diff, v);

}

ll sum(int s, int e, int node, int aim_s, int aim_e,vector<ll>&v) {

	if (s > aim_e || e < aim_s)return 0; //�������� ���
	if (s >= aim_s && e <= aim_e) return v[node];//������
	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, aim_s, aim_e, v) + sum(mid+1,e,node*2+1,aim_s,aim_e,v);

}
int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;

	int k = (int)ceil(log2(n));
	k = (1 << (k + 1));

	vector<ll> v(k, 0);
	vector<ll>arr(k + 2, 0);

	for (int i = 1; i <= n;i++) {
		cin >> arr[i];
		update(1, n, 1, i, arr[i], v);
	}

	while (q--) {

		cin >> a >> b >> c >> d;

		if (a > b)swap(a, b);
		cout << sum(1,n,1, a, b,v) << "\n";
		//a���� b������ �ձ��ϱ�

		ll diff = d - arr[c];
		arr[c] = d;
		update(1, n, 1, c, diff, v);
		//c��° ���� d�� �ٲ��

	}


	return 0;
}