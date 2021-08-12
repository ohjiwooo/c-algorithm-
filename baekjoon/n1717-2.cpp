#include<iostream>

using namespace std;


int n, m,a,b,c;
int arr[1000005];

void init() {

	for (int i = 0; i <= n;i++) {
		arr[i] = i;
	}

}

int find(int a) {

	if (arr[a] == a)return a;

	return arr[a] = find(arr[a]);

}
void uni(int a,int b) {

	int p_a = find(a);
	int p_b = find(b);

	arr[p_b] = p_a;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	init();
	while (m--) {
	
		cin >> a>> b>> c;

		if (a==0) { //b,c 합침
			uni(b, c);

		}
		else {//b,c 같은집합?
			if (find(b) == find(c))cout << "YES\n";
			else { cout << "NO\n"; }
		
		}
	
	}


}