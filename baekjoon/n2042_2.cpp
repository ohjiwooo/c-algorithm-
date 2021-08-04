#include<algorithm>
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;

int update(int s,int e,int node,int aim,ll diff,vector<ll>&v) { //aim�� diff�� ����

	if (s > aim || e < aim)return 0; //�������� ���
	v[node] += diff;
	if (s == e)return 0; //�����尡 �������

	int mid = (s + e) / 2;
	update(s, mid, node * 2, aim, diff, v);
	update(mid + 1, e, node * 2 + 1, aim, diff, v);
	return 0;

}

ll sum(int s, int e, int node, int aim_s, int aim_e, vector<ll>&v) {

	if (e < aim_s || s > aim_e)return 0; //�������� ���
	if (aim_s <= s && aim_e >= e) {//��������
		return v[node];
	}
	int mid = (s + e) / 2;
	return sum(s,mid,node*2,aim_s,aim_e,v) + sum(mid+1, e,node*2+1,aim_s,aim_e, v);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;//���ǰ��� ����Ƚ�� ������ Ƚ��
	cin >> n >> m >> k;
	ll a, b, c;
	int nn = (int)ceil(log2(n));
	nn = (1 << (1 + nn));

	vector<ll>v(nn,0);
	vector<ll>v2(n + 2, 0);
	
	for (int i = 1; i <= n;i++) {
		
		cin >> a;
		update(1, n, 1, i, a, v);
		v2[i] = a;
	}


	for (int i = 0; i < m + k;i++) {
		cin >> a >> b >> c;
		if (a == 1) { //b�� c�� �ٲ�
			ll diff = c-v2[b];
			update(1, n, 1, b, diff,v);
			v2[b] = c;
		}
		else {
			if (c < b)swap(b, c);
			cout << sum(1,n,1,b,c,v)<<"\n";
		}
	
	}


}