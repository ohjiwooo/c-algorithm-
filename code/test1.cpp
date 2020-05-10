#include<iostream>
#include<vector>
#include<string>
using namespace std;


int ff(int a) {
	if (a < 0) { return -a; }
	else { return a; }
}

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int r = 0; //현재어디에
	int l = 0; //현재어디에
	int l_flag = 0; //왼손이 중앙
	int r_flag = 0; //오른손이 중앙    
	int h = 0;
	int lzero = 0;
	int rzero = 0;
	if (hand[0] == 'r') {
		h = 0; //오른손잡이
	}
	else { h = 1; }//왼손잡이 

	for (int i = 0; i < numbers.size(); i++) {

		if ((numbers[i] == 3) || (numbers[i] == 6) || (numbers[i] == 9)) {
			answer.append("R"); r = numbers[i]; r_flag = 0; rzero = 0; //
		}
		else if ((numbers[i] == 1) || (numbers[i] == 4) || (numbers[i] == 7)) {
			answer.append("L"); l = numbers[i]; l_flag = 0; lzero = 0;
		}
		else if (l == numbers[i]) { answer.append("L"); l_flag = 1; l = numbers[i]; if (numbers[i] != 0) { lzero = 0; } }
		else if (r == numbers[i]) { answer.append("R"); r_flag = 1; r = numbers[i]; if (numbers[i] != 0) { rzero = 0; } }//중간라인 및 같은거 누르기
		else { //중간라인일 경우
			if (i == 0) { //초기는 뺄셈불가
				if (h == 0) { answer.append("R"); r_flag == 1; r = numbers[i]; }
				else { answer.append("L"); l_flag = 1; l = numbers[i]; }
			}
			else if (numbers[i] == 0) {
				if (r_flag == 1 && r_flag == 1) {
					if (r > l) { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 1; }
					else { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 1; }
				}
				else if (r_flag == 1 && l_flag != 1) {
					if (r == 8) { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 1; }
					else if (r == 5) {
						if (l == 7) {
							if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 1; }
							else { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 1; }
						}
						else { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 1; }
					}
					else if (r == 2) {
						if (l = 7) { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 1; }
						if (l == 4) {
							if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 1; }
							else { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 1; }
						}
						else { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 1; }
					}
				}
				else if (r_flag != 1 && l_flag == 1) {
					if (l == 8) { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 1; }
					else if (l == 5) {
						if (r == 7) {
							if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 1; }
							else { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 1; }
						}
						else { answer.append("L"); l_flag = 1; l = numbers[i]; }
					}
					else if (l == 2) {
						if (r = 9) { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 1; }
						if (r == 6) {
							if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 1; }
							else { answer.append("L"); l_flag = 1; l = numbers[i]; } lzero = 1;
						}
						else { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 1; }
					}
				}
			}
			//if(rzero ==0 &&lzero==0){
			else if ((r_flag == 0) && (l_flag == 0)) { //둘다자기자리
				if ((numbers[i] - l == 1) && (r - numbers[i] != 1)) {
					answer.append("L"); l_flag = 1; l = numbers[i]; //완쪽이가까움

				}
				else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l != 1) && (r - numbers[i] == 1)) {
					answer.append("R"); r_flag = 1; r = numbers[i]; //오른쪽이가까움
				}
				else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l == 1) && (r - numbers[i] == 1)) {
					if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; } //바로옆
					else { answer.append("L"); l_flag = 1; l = numbers[i]; } //오른손잡이,왼손잡이 구분        
				}
				else if ((r_flag == 0) && (l_flag == 0) && (numbers[i] - l != 1) && (r - numbers[i] != 1)) {
					if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; } //둘다 자기자리,바로옆아님
					else { answer.append("L"); l_flag = 1; l = numbers[i]; } //오른손잡이,왼손잡이 구분        
				}
			}
			else if ((r_flag == 1) && (l_flag != 1)) { //오른손이 가운데 왼손은 자기자리
				if (rzero == 0) {
					if ((r - numbers[i] == 3) || (r - numbers[i] == -3) && (numbers[i] - l == 1)) {//둘다한칸차
						if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; } //손선택
						else { answer.append("L"); l_flag = 1; l = numbers[i]; }
					}
					else if (((r - numbers[i] == 3) || (r - numbers[i] == -3)) && (numbers[i] - l != 1)) {
						answer.append("R"); r_flag = 1; r = numbers[i]; //오른이 한칸차,오른이가운데,왼자기자리
					}
					else if ((r - numbers[i] != 3) && (r - numbers[i] == -3) && (numbers[i] - l == 1)) {
						answer.append("L"); r_flag = 1; r = numbers[i]; //왼손이 한칸차
					}
					else if ((r - numbers[i] != 3) && (r - numbers[i] == -3) && (numbers[i] - l != 1)) {
						if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; }//둘다 한칸차 아님
						else { answer.append("L"); l_flag = 1; l = numbers[i]; }
					}
				}
				else {
					if (numbers[i] == 8) {
						if (l == 7) {
							if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 0; }
							else { answer.append("L"); l_flag = 1; l = numbers[i]; }
						}

						else { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 0; }
					}
			else if (numbers[i] == 5) {
				if (l == 7 || l == 1) {
					if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 0; }
					else { answer.append("L"); l_flag = 1; l = numbers[i]; }
				}
				if (l == 4) { answer.append("L"); l_flag = 1; l = numbers[i]; }
			}
			else if (numbers[i] == 2) {
				if (l == 1 || l == 4) { answer.append("L"); l_flag = 1; l = numbers[i]; }
				else {
					if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 0; }
					else { answer.append("L"); l_flag = 1; l = numbers[i]; }
				}
			}

				}

			}

			else if ((r_flag != 1) && (l_flag == 1)) {//왼손은 가운데 오른손은 자기자리
				if (lzero == 0) {
					if ((r - numbers[i] == 1) && ((numbers[i] - l == 3) || (numbers[i] - l == -3))) {
						if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; } //둘다 한칸차,
						else { answer.append("L"); l_flag = 1; l = numbers[i]; }// 손선택
					}
					else if ((r - numbers[i] == 1) && (numbers[i] - l != 3) && (numbers[i] - l != -3)) {
						answer.append("R"); r_flag = 1; r = numbers[i]; //오른이 한칸차
					}
					else if ((r - numbers[i] != 1) && (ff(numbers[i] - l) == 3)) {
						answer.append("L"); l_flag = 1; l = numbers[i]; //왼손이 한칸차
					}
					else if ((r - numbers[i] != 1) && (numbers[i] - l != 3) && (numbers[i] - l != -3)) {
						if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; }//둘다 한칸차 아님
						else { answer.append("L"); l_flag = 1; l = numbers[i]; }
					}
				}
				else {
					if (numbers[i] == 8) {
						if (r == 9) {
							if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; }
							else { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 0; }
						}

						else { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 0; }
					}
				
			else if (numbers[i] == 5) {
				if (r == 9 || l == 3) {
					if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; }
					else { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 0; }
				}
				if (r == 6) { answer.append("R"); r_flag = 1; r = numbers[i]; lzero = 0; }
			}
			else if (numbers[i] == 2) {
				if (r == 3 || l == 6) { answer.append("R"); r_flag = 1; r = numbers[i]; }
				else {
					if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; }
					else { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 0; }
				}
			}

				}
			}
			else if ((r_flag == 1) && (l_flag == 1)) { //둘다가운데
				if (ff(r) > ff(l)) {
					answer.append("L"); l_flag = 1; l = numbers[i];
				}
				else if (ff(r) < ff(l)) {
					answer.append("R"); r_flag = 1; r = numbers[i];
				}
				else if (ff(r) == ff(l)) {
					if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; } //둘이 같음
					else { answer.append("L"); l_flag = 1; l = numbers[i]; }// 손선택
				}
			}
			//}
		}
	}


	return answer;
}







int main() {
	string hand = "light";

	int h = 0;

	if (hand[0] == 'r') {
		h = 0; //오른손잡이
	}
	else { h = 1; }//왼손잡이 
	int a = '*';
	cout << a;

	return 0;
}

if (rzero == 0) { r = 10; }
else if (lzero == 0) { l = 10; }
if (ff(r - numbers[i]) > ff(l - numbers[i])) {
	answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 0;
	if (rzero == 0) { r = 0; }
}
else if (ff(r - numbers[i]) < ff(l - numbers[i])) {
	answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 0;
	if (lzero == 0) { l = 0; }
}
else if (ff(r - numbers[i]) == ff(l - numbers[i])) {
	if (h == 0) {
		answer.append("R"); r_flag = 1; r = numbers[i]; rzero = 0;
		if (lzero == 0) { l = 0; }
	} //둘이 같음
	else {
		answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 0;
		if (rzero == 0) { r = 0; }
	}// 손선택
}
//둘다가운데
			   /*  if(ff(r - numbers[i]) < ff(l - numbers[i])){
					  answer.append("R"); r_flag = 1; r = numbers[i]; }
				else if(ff(r - numbers[i]) <ff(l - numbers[i])){
					  answer.append("L"); l_flag = 1; l = numbers[i]; }
				 else if(ff(r - numbers[i]) ==ff(l - numbers[i])){
					  if (h == 0) { answer.append("R"); r_flag = 1; r = numbers[i]; }
					else { answer.append("L"); l_flag = 1; l = numbers[i]; lzero = 0; } }*/
