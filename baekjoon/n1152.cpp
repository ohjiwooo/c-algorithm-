#include<iostream>
#include<string>

using namespace std;


int ans = 1; // ������  �����ϰ�� �ϳ�����
string a;;
int s = 0;//���۽� 0, �߹ݿ� 1
int main() {
	
	
		getline(cin, a);

		if (a.size() == 0) { //���͸� �Է�
			cout << 0;
			return 0;

		}
		for (int i = 0; i < a.size(); i++) {


			if (a[i] == ' ' && s == 0) {//������ ����
				s = 1;
			}
			else if (a[i] == ' ') {
				ans++;
				s = 1;
			}
			else { s = 1; }

		}

		if (a[a.size() - 1] == ' ') { //���̰���
			ans--;
		}

		cout << ans;

	

	return 0;
}
