#include<iostream>

using namespace std;


int w, h,no,hole;
pair<int,int> map[32][32];

int main() {

	cin >> w >> h>>no;

	for (int i = 0; i < no;i++) {
		int a, b;
		cin >> a >> b;
		map[b][a].first = 1;// 1ÀÌ ¹¦Áö
	}
	cin >> hole;

	for (int i = 0; i < hole; i++) {
		int a, b, c, d,e;
		cin >> a >> b >> c >> d, e;

	}
	return 0;
}