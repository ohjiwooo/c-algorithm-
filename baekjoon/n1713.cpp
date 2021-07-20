#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n = 0;//후보 수
int m = 0;//추천한 횟수
int a = 0;
int num = 0;//현재걸린 사진 수
vector <pair<pair<int, int>,int>>v; //득표수, 들어온순서, 학생번호
vector<int> input;
int stu[102]; //게시된 인덱스

bool comp(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b) {

	if (a.first.first==b.first.first) {
		return a.first.second  > b.first.second;
	}
	else {
		return a.first.first > b.first.first;
	}


}

bool comp2(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b) {

	return a.second < b.second;



}

int update() { //정렬

	sort(v.begin(), v.end(),comp);

	for (int i = 0; i <v.size();i++) {
		int a = v[i].first.first; //득표수
		int b = v[i].first.second; // 순서
		int c = v[i].second;//학생번호

		stu[c] = i;//위치바꿔줌
	}
	return 0;
}


int func(int a,int i) { // a:학생번호 i:순서

	if (num==n && stu[a]==-1) { //게시 공간이 없을 경우
		update();
		stu[v[n - 1].second] = -1;
		v[n-1].first.first = 1;
		v[n-1].first.second = i;
		v[n-1].second = a;
		stu[a] = n - 1;
	}
	else {
		if (stu[a]==-1) { //지금 게시x
			stu[a] = num;
			v.push_back(make_pair(make_pair(1, i), a));
			num++;
		}
		else {//게시되어 있음
			v[stu[a]].first.first++; //득표수올리고
		}
		
	}
	return 0;

}
int main() {

	

	cin >> n >> m;

	for (int i = 0; i < 102;i++) {
		stu[i] = -1;
	}
	for (int i = 0; i < m;i++) {
		cin >> a;
		func(a,i);
	}

	
	sort(v.begin(), v.end(), comp2);//학생번호대로 정렬
	for (int i = 0; i < num;i++) {
		cout << v[i].second << " ";
	}


}