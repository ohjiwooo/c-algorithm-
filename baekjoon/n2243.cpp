#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
typedef long long ll;


int a, b, c,n;
vector<ll>arr(1000004, 0);

int update(int s,int e,int node, int aim,int value,vector <ll>&v) {

	if (aim < s || aim > e) { // �������� ���
		return 0;
	}
	v[node] += value;
	if (s==e) { //��������� ���
		return 0;
	}

	int mid = (s + e) / 2;

	update(s,mid,node*2,aim,value,v);
	update(mid+1,e,node*2+1,aim,value,v);
	return 0;
}

int find(int s, int e, int node, int value, vector<ll>&v) {

	
	if (s==e) { //���������
		return s;
	}

	int mid = (s + e) / 2;
	if (v[node*2] >= value) { // ���ʿ� ������� -> �������� ������ (���������� ������)
	
		return find(s,mid,node*2,value,v);
	}
	else { // �����ʿ� ����
		return find(mid+1,e , node * 2+1, value-v[node*2], v);
	}

	return 0;

}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int k = (int)ceil(log2(1000000));
	k = (1 << (k + 1));

	vector<ll>v(k, 0);
	
	cin >> n;
	while (n--) {
	
		cin >> a;
		if (a==1) { //������
			cin >> b;
			int ans = find(1, 1000000, 1, b, v);
			cout << ans << "\n";
			update(1, 1000000, 1, ans, -1, v);
			arr[ans] -= 1;
		}
		else { //�ְų� ��
			cin >> b >> c;
			update(1, 1000000, 1,b,c,v);
		}
	
	}

	return 0;
}

