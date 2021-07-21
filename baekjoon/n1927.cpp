#include<iostream>
#include<queue>
using namespace std;



int main() {

	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	int a;
	priority_queue <int>q;
	while(n--) {
		cin >> a;
		if (a==0) {//Ãâ·Â
			if (q.empty()==true) {
				cout << "0\n";
			}
			else {
				cout <<q.top()<<"\n";
				q.pop();
			}
		}
		else {
			q.push(a);
		}
	
	}

}