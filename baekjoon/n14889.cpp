#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int arr[25][25];
int temp_ans1 = 0;
int temp_ans2 = 0;
int ans = 50000;

int m(int a,int b) {
	if (a - b > 0) { return a - b; }
	else { return b - a; }

}


int main() {

	cin >> n;

	int k = n / 2;

	vector <int>v(n);
	vector<int> ind(n);
	vector <int>temp1(n);
	vector <int>temp2(n);
	
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			cin >> arr[i][j];
		}
	}



	for (int i = 0; i < n;i++) {
		v[i] = i + 1;
	} //º¤ÅÍÃÊ±âÈ­

	for (int i = 0; i < k; i++) {
		ind[i] = 1;
	}

	for (int i = k; i < n; i++) {
		ind[i] = 0;
	}

	sort(ind.begin(),ind.end());

	do {
		temp_ans1 = 0;
		temp_ans2 = 0;

		for (int i = 0; i < n; i++) {
			if (ind[i] == 1) {

				temp1.push_back(v[i]);
			}
			else { temp2.push_back(v[i]); }
		}

		for (int i = 0; i < n;i++) {

		}

		if (m(temp_ans1,temp_ans2) < ans) { 
			ans = m(temp_ans1,temp_ans2); }

	} while (next_permutation(ind.begin(), ind.end()));


	cout << ans;
	
	return 0;
}