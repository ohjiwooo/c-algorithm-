#include<iostream>
#include<vector>
#include<math.h>
using namespace std;



long long update(int s, int e, int node, int aim, long long value, vector <long long> &v) {

	if (aim < s || aim > e) { // 범위에서 벗어남
		return 0;
	}
	v[node] += value; // 범위안에 있으므로 업데이트해줌
	if (s == e) { //현재 node가 리프노드이므로 종료
		return 0;
	}
	int mid = (s + e) / 2;
	update(s, mid, node * 2, aim, value, v); //왼쪽자식으로 이동
	update(mid + 1, e, node * 2 + 1, aim, value, v); //오른쪽 자식으로 이동
	return 0;
}

long long sum(int s, int e, int node, int aim_s, int aim_e, vector <long long> &v) {

	if (e < aim_s || s >  aim_e) { //범위에서 벗어날경우
		return 0;
	}if (s >= aim_s && e <= aim_e) {//범위에 해당
		return v[node];
	}

	int mid = (s + e) / 2;

	return sum(s, mid, node * 2, aim_s, aim_e, v) + sum(mid + 1, e, node * 2 + 1, aim_s, aim_e, v); //양쪽으로 내려감


}
int main() {

	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;// 수의개수, 턴의개수
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