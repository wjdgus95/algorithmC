#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a ? true : false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> tmp;

	for (int i = 0; i < numbers.size(); i++) {
		tmp.push_back(to_string(numbers[i]));
	}

	sort(tmp.begin(), tmp.end(), cmp); //cmp �Լ� �������� ���� ����

	for (int i = 0; i < tmp.size(); i++) {
		answer = answer + tmp[i];
	}

	if (answer[0] == '0') return "0"; //answer[0]�� 0�̸� ���� ū ���� 0�̶�� ���̹Ƿ� 0����

	return answer;
}