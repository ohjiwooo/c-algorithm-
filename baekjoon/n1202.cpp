#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int main() {

	long long n, k;
	cin >> n >> k;

	priority_queue <pair<long long, long long>> j;
	priority_queue <long long> bag;

	for (int i = 0; i < n;i++) {
		int a, b;
		cin >> a >> b;
		j.push(make_pair(-a, b)); 

	}
	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;
		bag.push(-a);

	}
	long long answer = 0;

	priority_queue <pair<long long, long long>> pq;

	while (bag.empty()!=true) {

		
		int bag_g = -bag.top(); bag.pop();

		while(j.empty()!=true && -j.top().first <= bag_g){
			int j_g = -j.top().first; int j_v = j.top().second; j.pop();
			pq.push(make_pair(j_v,j_g));
		}
		if (pq.empty()!=true) {
			answer += pq.top().first; pq.pop();
		}
	
	}

	cout << answer;
}