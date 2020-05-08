#include <string>
#include <vector>

using namespace std;

int ans[20][20];

void make(vector<vector<int>> key, vector<vector<int>> lock,int i,int j) {


}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	int keysize = key.size();
	int locksize = lock.size();
	int lockn = 0; //홈부분 세기
	int board[60][60];

	for (int i = 0; i < locksize;i++) {
		for (int j = 0; j < locksize;j++) {
			if (lock[i][j] == 0) { lockn++; } //홈부분 셈
		}
	}

	if (lockn == 0) { return answer; } //잠긴거 없음

	for (int i = 20; i < 20+locksize; i++) {
		for (int j = 20; j < 20+locksize; j++) {
			board[i][j] = lock[i - 20][j - 20];
		}
	}//자물쇠 가운데 입력


	for (int i = 20-keysize; i < 20; i++) {
		for (int j = 20-keysize; j < 20 ; j++) {
			board[i][j] = key[i-(20 - keysize)][j- (20 - keysize)];
		}
	}//왼쪽상단에 key 입력

	for (int i = 0; i < (keysize+locksize-1);i++) {
		for (int j = 0; j < (keysize + locksize - 1);j++) {



		}
	}



	return answer;
}