#include<iostream>

using namespace std;


int n, m;//n 100000
int a, b, c;
int main() {

	cin >> n;

	for (int i = 0; i < n;i++) {
		cin >> a >> b >> c; // a와 b사이에 길이가 c인 도로
	
	}

	cin >> m;

	while (m--) {
	
		cin >> a >> b; //a와 b사이의 가장 짧은 도로, 긴 도로 출력
		
	}
	return 0;
}