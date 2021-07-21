#include<iostream>
#include<vector>
#include<math.h>

using namespace std;



long long update(int s, int e, int node, int aim, long long value, vector <long long> &v) {

	if (aim < s || aim > e) { // �������� ���
		return 0;
	}
	v[node]  += value; // �����ȿ� �����Ƿ� ������Ʈ����
	if (s == e) { //���� node�� ��������̹Ƿ� ����
		return 0;
	}
	int mid = (s + e) / 2;
	update(s, mid, node*2, aim, value,v); //�����ڽ����� �̵�
	update(mid + 1, e, node*2+1, aim, value,v); //������ �ڽ����� �̵�
	return 0;
}

long long sum(int s,int e,int node, int aim_s,int aim_e, vector <long long> &v) {

	if (e < aim_s || s >  aim_e) { //�������� ������
		return 0;
	}if (s >= aim_s && e <= aim_e)  {//������ �ش�
		return v[node]; 
	}

	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, aim_s, aim_e,v) + sum(mid + 1, e, node * 2 + 1, aim_s, aim_e,v); //�������� ������


}
int main() {

	int n, m, k; //���ǰ���, ���� �� , ������ ���ϴ� ��
	cin >> n >> m >> k;

	int ss = (int)ceil(log2(n));
	ss = (1 << (ss + 1));
	vector <long long> v(ss, 0);
	vector<long long> arr(n + 2, 0);

	for (int i = 1; i <= n;i++) {
		long long c;
		cin >> c;
		update(1, n, 1, i, c,v);
		arr[i] = c;
	}
	int count = m + k;
	while (count--) {
	
		long long a, b, c;
		cin >> a >> b >> c;

		if (a==1) { //b�� c��
			long long value = c - arr[b];
			arr[b] = c;
			update(1, n, 1, b, value,v);
		}
		else { //b���� c ���� ������
			cout << sum(1, n, 1, b, c,v)<<"\n";
		}
	}

}