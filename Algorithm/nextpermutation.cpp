#pragma warning(disable: 4996)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) { //���� ū �� - fail
	vector<string> tmp;

	sort(numbers.begin(), numbers.end());

	do {
		string s = "";
		for (int i = 0; i < numbers.size(); i++) {
			s += to_string(numbers[i]);
		}
		tmp.push_back(s);

	} while (next_permutation(numbers.begin(), numbers.end()));

	sort(tmp.begin(), tmp.end());

	return tmp[tmp.size() - 1];
}