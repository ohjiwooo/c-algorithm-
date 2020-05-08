#include <string>
#include <vector>
#include<iostream>


using namespace std;



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	int a[60][60];
	int b[60][60];
	int right1[20][20];
	int key_size = key.size();
	int lock_size = lock.size();

	for (int i = 20; i < lock_size; i++) {
		for (int j = 20; j < lock_size; j++) {
			a[i][j] = lock[i-20][j-20];
		}
	}

	//right1[i][j] = key[key_size - i][j];

	for (int i = 20-key_size; i < 20 ;i++) {
		for (int j = 20-key_size; j < 20;j++) {	
			b[i][j] = key[i - 20][j - 20];
		}
	}

	for (int i =1; i < lock_size*2; i++) {
		for (int j=1; j <lock_size; j++) {
			b[(20-key_size)+i][(20 - key_size)+j] 
		}
	}




	return answer;
}


int main() {
	

	return 0;



}