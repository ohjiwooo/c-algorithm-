#include<iostream>
#include<vector>
#include<math.h>
using namespace std;



long long update(int s, int e, int node, int aim, long long value, vector <long long> &v) {

	if (aim < s || aim > e) { // �������� ���
		return 0;
	}
	v[node] += value; // �����ȿ� �����Ƿ� ������Ʈ����
	if (s == e) { //���� node�� ��������̹Ƿ� ����
		return 0;
	}
	int mid = (s + e) / 2;
	update(s, mid, node * 2, aim, value, v); //�����ڽ����� �̵�
	update(mid + 1, e, node * 2 + 1, aim, value, v); //������ �ڽ����� �̵�
	return 0;
}

long long sum(int s, int e, int node, int aim_s, int aim_e, vector <long long> &v) {

	if (e < aim_s || s >  aim_e) { //�������� ������
		return 0;
	}if (s >= aim_s && e <= aim_e) {//������ �ش�
		return v[node];
	}

	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, aim_s, aim_e, v) + sum(mid + 1, e, node * 2 + 1, aim_s, aim_e, v); //�������� ������


}
int main() {

	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;// ���ǰ���, ���ǰ���
	cin >> n >> q;
	int k = (int)ceil(log2(n));
	k = (1 << (k + 1));

	vector<long long> arr(n + 2, 0);
	vector <long long>v(k,0);

	for (int i = 1; i <= n;i++) {
		long long a;
		cin >> a;
		update(1,n,1,i,a,v);
		arr[i] = a;
	}
	while (q--) {
	
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a>b) {
			int tmp = b;
			b = a; a = tmp;
		}
		cout<<sum(1, n, 1, a, b, v)<<"\n";


		long long change = d - arr[c];
		arr[c] = d;
		update(1,n,1,c,change,v);
	}


	return 0;
}