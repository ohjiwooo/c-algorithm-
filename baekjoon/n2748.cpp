#include<iostream>



using namespace std;



int main() {

	long long n = 0;
	long long arr[92];
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n;i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n];
	return 0;

}