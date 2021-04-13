#include<iostream>
#include<queue>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	cin >> n;

	priority_queue<int> max;
	priority_queue<int> min;

	int i = 0;
	
	while (i<n) {

		int a = 0;
		cin >> a;

		if (i % 2 == 0) { //max에 넣기
			max.push(a);
		}
		else { //min에 넣기
			min.push(-a);
		}

		if ( min.size()>0 && max.top() > -min.top()) {
			int temp = max.top();
			int temp2 = -min.top();
			max.pop();
			min.pop();
			max.push(temp2);
			min.push(-temp);
		}
		cout <<max.top()<<"\n";

		i++;
	
	}
	
	return 0;
}