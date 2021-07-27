#include<iostream>
#include<vector>
using namespace std;

vector <int>arr[100005];

int main() {

	int v,e,a,b;

	for (int i = 0; i < e;i++) {
	
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}



	return 0;
}