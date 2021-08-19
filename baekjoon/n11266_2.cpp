#include<iostream>
#include<vector>
using namespace std;


int v, e,a,b;//노드, 간선 10000,100000
vector <int>arr[10005];

int main() {

	cin >> v >> e;
	for (int i = 0; i < e;i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	
	}



	//단절점의 개수, 번호 출력-오름차순

	return 0;
}