#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n; //숫자의 개수
int num[15]; //숫자리스트

int temp_ans = 0;
int min_ans = 1000000005;
int max_ans = -1000000005;
char now;
int j=0;
int m;
int a;

int main() {

	cin >> n;
	

	vector <int>v(n-1); //기호 리스트

	for (int i = 0; i < n;i++) {
		
		cin >> num[i];

	}

	for (int i = 0; i < 4; i++) {
		cin >> a;

		while (a>0) {

			v[j] = i;
			a--;
			j++;
			
		}

	}

		do {
			
			temp_ans = num[0];
			for (int i = 0; i < n-1; i++) {
				
				now = v[i];

				if (now == 0) {
					temp_ans += num[i + 1];
				}
				else if (now == 1) {
					temp_ans -= num[i + 1];
				}
				else if (now == 2) {
					temp_ans *= num[i + 1];
				}
				else {
					temp_ans /= num[i + 1];
				}

			}

			if (temp_ans > max_ans) {
				max_ans = temp_ans;
			}
			if (temp_ans < min_ans) {
				min_ans = temp_ans;
			}


		} while (next_permutation(v.begin(), v.end()));

	
	cout << max_ans << "\n";
	cout << min_ans;

	return 0;


}
