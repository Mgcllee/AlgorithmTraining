#pragma once

#include <iostream>
#include <string>

using namespace std;

#include "linkedList.h"

// "�����佺�׳׽��� ä"�� ���ϴ� �Լ�.
//int eratos(vector<int>& num) {
//	vector<int> primeNums;
//	for (int i = 2; i <= *num.crbegin(); ++i)
//		primeNums.push_back(i);
//	for (int i = 2; i <= *num.crbegin(); ++i) {
//		if (primeNums[i - 2] == 0)
//			continue;
//		for (int j = i + i; j <= *num.crbegin(); j += i)
//			primeNums[j - 2] = 0;
//	}
//	int cnt = 0;
//	for (int n : primeNums) {
//		if (n != 0)
//			cnt += 1;
//	}
//	return cnt;
//}