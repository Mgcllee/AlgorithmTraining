#pragma once

#include "main.h"
#include "SortFunctions.h"

#include <vector>
#include <algorithm>
#include <set>

int eratos(set<int>& num) {
	vector<int> nums;

	// ���� result�� �Ѱ� num ������ ���޹޴� �����̳ʰ� ���������� ���޵��� ����.

	for (int i = 2; i <= *num.crbegin(); ++i) 
		nums.push_back(i);

	for (int i = 2; i <= *num.crbegin(); ++i) {
		if (nums[i - 2] == 0) 
			continue;
		for (int j = i + i; j <= *num.crbegin(); j += i)
			nums[j - 2] = 0;
	}

	int cnt = 0;
	for (int n : nums) {
		if (n == 0) continue;
		if (num.find(n) != num.end() && n != 0)
			cnt += 1;
	}
	return cnt;
}
void failCase01() {
	vector<int> nums = { 1,2,7,6,4 };

	/*

	[���� �ܰ�]
	1. nums�� ���ڵ��� Ȧ��, ¦���� �����Ͽ� ���ο� vector<int>�� �����Ѵ�.
	2. Ȧ�� == Ȧ�� x 3 == Ȧ�� x 1 + ¦�� x 2 ���� �̿��Ͽ� set<int>�� �ߺ��� �����ϸ鼭 �����Ѵ�.
	3. "�����佺�׳׽��� ü"�� �̿��Ͽ� set<int>�� ����Ǿ� �ִ� ���� �� ���� ū ������ �Ҽ����� �����ϴ� �����̳ʸ� �����Ѵ�.
	4. �Ҽ��� ����Ǿ� �ִ� �����̳ʿ� set<int> �����̳ʸ� ���Ͽ� �Ҽ��� �ɷ�����.

	[���� �ܰ�]
	1. Ȧ���� ¦���� �����Ͽ� ������ ���, �׽�Ʈ ���̽��� �����ִ� ���� ����ǳ�, �� �������� �������� ����.

	[���� ����]
	1. 3������ ������ ���̶�� �Ϳ� ���� � ������� �ذ��ؾ� ���� ������ �� ����.
	2. �ݺ����� �ʹ� ���� ��ȿ������.

	*/


	int answer = 0;
	set<int> result;
	vector<int> odds, evens;
	for (int n : nums) (n % 2 == 0) ? evens.push_back(n) : odds.push_back(n);

	sort(odds.begin(), odds.end());
	sort(evens.begin(), evens.end());

	for (int odd : odds) {
		for (int i = 0; i < evens.size() - 1; ++i) {
			result.insert(odd + evens[i] + evens[i + 1]);
			cout << odd << " + " << evens[i] << " + " << evens[i + 1] << endl;
		}
	}
	for (int i = 0; i < odds.size() - 2; ++i) {
		result.insert(odds[i] + odds[i + 1] + odds[i + 2]);
		cout << odds[i] << " + " << odds[i + 1] << " + " << odds[i + 2] << endl;
	}

	cout << eratos(result);
}

void Combination(vector<int> vec, vector<int> comb, int r, int index, int depth, set<int>& result) {
	if (r == 0) {
		int sum = 0;
		for (int n : comb) {
			cout << n << " + ";
			// sum += n;
		}
		cout << endl;
		// result.insert(sum);
	}
	else if (depth == vec.size()) {
		return;
	}
	else {
		comb[index] = vec[depth];
		Combination(vec, comb, r - 1, index + 1, depth + 1, result);

		Combination(vec, comb, r, index, depth + 1, result);
	}
}

int main() {
	vector<int> nums = { 1, 5, 6 };
	set<int> result;
	//=> 3���� ���ڸ� ��� ���ϴ� ���̹Ƿ� '����' ������ ���ؼ� ��� ����� ����� ���Ѵ�.	
	
	int selector = 3;
	vector<int> comb(selector);
	Combination(nums, comb, selector, 0, 0, result);

	for (int n : result)
		cout << n << endl;
	cout << "===============\n";

	cout << eratos(result);
}
