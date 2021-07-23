#include<iostream>

using namespace std;


int main() {



	int n, k;
	cin >> n >> k;

	int a = 1; int b = 1;

	for (int i = 0; i < k;i++) {
		a *= n - i;
		b *= k - i;
	}

	cout << a / b;




}