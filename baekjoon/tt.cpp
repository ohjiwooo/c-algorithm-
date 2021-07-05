#include <string>
#include <vector>
#include<list>
#include<stack>
#include<iostream>
using namespace std;


string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	stack<pair<int, int>> s;
	list<int> ll;
	for (int i = 0; i < n; i++) {
		ll.push_back(1);
	}

	list<int>::iterator it;
	list<int>::iterator temp;
	it = ll.begin();
	for (int i = 0; i < k; i++) {
		it++;
	}

	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i][0] == 'U') {
			int n = cmd[i][2] - '0';
			for (int i = 0; i < n; i++) {
				it--;
			}

		}
		else if (cmd[i][0] == 'D') {
			int n = cmd[i][2] - '0';
			for (int i = 0; i < n; i++) {
				it++;
			}

		}
		else if (cmd[i][0] == 'C') {
			/*if (++it == ll.end()) {
				it--; it--;
			}*/
			s.push(make_pair(*(--it), *(++it)));
			it=ll.erase(it);
			
		}
		else if (cmd[i][0] == 'Z') {
			int a = s.top().first;
			int b = s.top().second;
			temp = ll.begin();
			while (1) {
				if (*temp == a) {
					break;
				}
				else { temp++; }
			}
			temp=ll.insert(++temp, b);
			s.pop();
		}
		
	}
	   vector<int> temp_arr(n,1);

	   temp=ll.begin();
	   while(temp!=ll.end()){
		   temp_arr[*temp]=0;
	   }
	   for (int i=0;i<n;i++){
		   if (temp_arr[i]==0){
			   answer+='O';}
		   else{answer+='X';}
	   }
	return answer;
}

int main() {

	int n = 8;
	int k = 2;
	vector<string> cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z" };
	solution(n, k, cmd);
	return 0;
}