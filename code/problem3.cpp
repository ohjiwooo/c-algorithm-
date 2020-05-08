#include <string>
#include <vector>
#include<iostream>


using namespace std;

int ans[20][20]; //정답리스트
int right[20][20]; //돌림

int key_size;
int lock_size;

int i2 = 0;
int j2 = 0;
int i3 = 0;
int j3 = 0;
void check(vector<vector<int>> key, vector<vector<int>> lock) {
	for (int i = 0; i < lock_size; i++) {
		for (int j = 0; j < lock_size; j++) {
			if (lock[i][j] == 0) {
				if (i2 == 0 && j2 == 0) {
					i2 = i; j2 = j;
					for (int a = 0; a < key_size; a++) {
						for (int b = 0; b < key_size; b++) {
							if (key[a][b] == 1) {
								ans[a][b] = 1;
							}
						}
					}
				}
				else {
					for (int a = 0; a < key_size; a++) {
						for (int b = 0; b < key_size; b++) {
							if ((ans[a][b] == 1) && (key[a + (i2-i)][b + (j2-j)]) == 1) {
								ans[a][b] = 1;
							}
							else if ((ans[a][b] == 1) && (key[a + (i2 - i)][b + (j2 - j)] != 1)) {
								ans[a][b] = 0;
							}
						}
					}
				}
			}
			else {
				i3 = i - i3;
				j3 = j - j3;
				for (int a = 0; a < key_size; a++) {
					for (int b = 0; b < key_size; b++) {
						if ((ans[a][b] == 1) && (key[a + i3][b + j3]) == 1) {
							ans[i][j] = 0;
						}
					}
				}
				i3 = i;
				j3 = j;
			
			}
		}
	}

}

void turn() {


}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	key_size = key.size();
	lock_size = lock.size();
	int all=1;

	for (int i = 0; i < lock_size; i++) {
		for (int j = 0; j < lock_size; j++) {
			if (lock[i][j] == 0) {
				all--;
				break;
				
			}
		}
	}
	if (all == 1) { answer = true; return answer; }


	check(key, lock);

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (ans[i][j] == 0) {
				answer = true;
				return answer;
			}
		}
	}//1

	for (int i = 0; i < key_size; i++) {
		for (int j = 0; j < key_size; j++) {
			key[i][j] = key[key_size - i][j];
		}


		check(key, lock);

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (ans[i][j] == 0) {
					answer = true;
					return answer;
				}
			}
		}//2

		for (int i = 0; i < key_size; i++) {
			for (int j = 0; j < key_size; j++) {
				key[i][j] = key[key_size - i][j];
			}
		}

		check(key, lock);

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (ans[i][j] == 0) {
					answer = true;
					return answer;
				}
			}
		}//3
		for (int i = 0; i < key_size; i++) {
			for (int j = 0; j < key_size; j++) {
				key[i][j] = key[key_size - i][j];
			}
		}

		check(key, lock);

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (ans[i][j] == 0) {
					answer = true;
					return answer;
				}
			} //4


			return answer;
		}
	}
}


int main() {
	
	
	return 0;



}