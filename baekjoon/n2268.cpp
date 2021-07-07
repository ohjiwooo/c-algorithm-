#include<iostream>
#include<vector>
#include<math.h>

using namespace std;


long long sum(int start,int end,int left,int right, int node, vector <long long> &v) {

	if (left > end || right < start) { //범위에서 벗어남
		return 0;
	}
	if (left <= start &&  end <= right) { //범위에 해당
		return v[node];
	}
	
	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2,v) + sum(mid + 1, end, left, right, node * 2 + 1,v); //노드내려감
	

}
int modify(int start,int end,int node, int index, long long value, vector<long long>&v) {

	if (index < start || index > end) {
		return 0;
	}
	v[node] += value;
	if (start == end) { //리프노드일 경우
		return 0;
	}
	int mid = (start + end) / 2;
	modify(start, mid, node * 2, index, value, v); //내려감
	modify(mid + 1, end, node * 2 + 1, index,value, v); //내려감

	return 0;
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	int m = 0;
	cin >> n >> m;

	int k = (int)ceil(log2(n));
	k = (1 << (k + 1));
	
	vector <long long> v(k,0);
	vector<long long> arr(n + 2,0);

	int a = 0;
	while (m--) {

		cin >> a;

		if (a==0) {
			int b = 0; int c = 0;
			cin >> b >> c;
			if (c < b) {
				int tmp = c;
				c = b; b = tmp;
			}
			cout<<sum(1, n, b, c, 1, v)<<"\n";
		}
		else {
			int b = 0; long long c = 0;
			cin >> b >> c;
			long long change = c-arr[b];
			arr[b] = c;
			modify(1, n, 1, b, change, v);
		
		}

	}
	return 0;
}