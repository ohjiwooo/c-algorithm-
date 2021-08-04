#include<iostream>
#include<deque>
using namespace std;


int arr[5000005];

int s, e;
int main() {


	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	deque <pair<int, int>>q;
	cin >> n >> l;

	for (int i = 1; i <= n;i++) {
		cin >> arr[i];
	}

	

	for (int i = 1; i <= n;i++) {
		
		while (q.empty() != true && q.front().second < i - l+1) {
			q.pop_front();
		}
		while(q.empty()!=true && q.back().first > arr[i]){
			q.pop_back();
		}
		q.push_back(make_pair(arr[i], i));
		cout << q.front().first << " ";
	
	}
	return 0;
}