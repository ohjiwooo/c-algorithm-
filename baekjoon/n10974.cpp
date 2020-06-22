#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


	
	int n;
	cin >> n;
	 vector <char>v(n);
	

	/*for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}*/
	 v[0] = '+';
	 v[1] = '*';
	
	do {

		for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}

		cout << '\n';

	} while (next_permutation(v.begin(), v.end()));

	return 0;

}