#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n = 0;//�ĺ� ��
int m = 0;//��õ�� Ƚ��
int a = 0;
int num = 0;//����ɸ� ���� ��
vector <pair<pair<int, int>,int>>v; //��ǥ��, ���¼���, �л���ȣ
vector<int> input;
int stu[102]; //�Խõ� �ε���

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

int update() { //����

	sort(v.begin(), v.end(),comp);

	for (int i = 0; i <v.size();i++) {
		int a = v[i].first.first; //��ǥ��
		int b = v[i].first.second; // ����
		int c = v[i].second;//�л���ȣ

		stu[c] = i;//��ġ�ٲ���
	}
	return 0;
}


int func(int a,int i) { // a:�л���ȣ i:����

	if (num==n && stu[a]==-1) { //�Խ� ������ ���� ���
		update();
		stu[v[n - 1].second] = -1;
		v[n-1].first.first = 1;
		v[n-1].first.second = i;
		v[n-1].second = a;
		stu[a] = n - 1;
	}
	else {
		if (stu[a]==-1) { //���� �Խ�x
			stu[a] = num;
			v.push_back(make_pair(make_pair(1, i), a));
			num++;
		}
		else {//�ԽõǾ� ����
			v[stu[a]].first.first++; //��ǥ���ø���
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

	
	sort(v.begin(), v.end(), comp2);//�л���ȣ��� ����
	for (int i = 0; i < num;i++) {
		cout << v[i].second << " ";
	}


}