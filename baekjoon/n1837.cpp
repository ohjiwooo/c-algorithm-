#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool arr[1000005];
string p; int k;
vector <int>pp;

void prime() {

	for (int i = 2; i <= k;i++) {
		if (arr[i] == true) continue; //이미 소수가 아님
		pp.push_back(i); //소수추가

		for (int j = i * 2; j <= k;j+=i) {
			arr[j] = true;
		}
	
	}

}


bool divi(int m) {//나눌 소수

	int len = p.size(); //나누어지는 수 길이
	int ret = 0;//니머지
	for (int i = 0; i < len;i++) {
		
		ret = ((ret*10)+(p[i] - '0')) % m;
	}if (ret!=0) {
		return true;
	}
	else { cout << "BAD " << m;return false; }

}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> p >> k;

	prime();

	for (int i = 0; i < pp.size();i++) {

		if (divi(pp[i])==false) {
			return 0;
		}
	
	}
	cout << "GOOD";

	return 0;
}