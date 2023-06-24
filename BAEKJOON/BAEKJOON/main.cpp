#pragma once

#include "main.h"
#include "SortFunctions.h"

#include <algorithm>
#include <vector>
#include <set>


vector<string> strings = { "sun", "bed", "car" };

struct Compare {
    int inPos;

    Compare(int variable) : inPos(0 < variable ? variable : 0) {}

    bool operator()(const string& ls, const string& rs) const {
        int min = ls.length() > rs.length() ? ls.length() : rs.length();
        int newIndex = ((int)ls[inPos] == (int)rs[inPos] || inPos == min - 1) ? 0 : inPos;

        for (int curPos = newIndex; curPos < min; ++curPos) {
            if ((int)ls[curPos] != (int)rs[curPos]) {
                return (int)ls[curPos] < (int)rs[curPos];
            }
        }
    }
};

int simpleN = 1;
bool simpleCompare(string& ls, string& rs) {
    return ls == rs ? ls < rs : ls[simpleN] < rs[simpleN];
}

int main() {
    int n = 1;

    /*
    [���α׷��ӽ� �������� - "���ڿ� �� ������� �����ϱ�"]
    
    ù ��° ������ ����: �� ������ ����Ϸ��� �Ͽ�����, key �ߺ��� �Ǿ����� ���, ������ ������ ������
    �ذ���: �ߺ��� ���Ǵ� �����̳�(multi set, multi set)�� ����ؼ� ���� �õ�

    �� ��° ������ ����: ���� ���ϴ� �� ����� �����ϱ� ���� ����� ����
    �ذ���: �־��� ��ġ�� ����(��)�� ���� ��� ������ ���ұ��� ���ϰ� ���ڰ� �ٸ� ��ġ�� ã�� ��ȯ.

    �� ��° ������ ����: ������ �߸� �����Ͽ�, �־��� ��ġ�� ���� ���� ��� �ڿ������� �����ϴ� ������ ����
    �ذ���: �־��� ��ġ�� ����(��)�� ���� ��� ���ڿ� �񱳸� ����� ���� ��ȯ.
    */

    /*
    multiset<string, Compare> words(strings.begin(), strings.end(), Compare(n));
    for (string s : words)
        cout << s << endl;    
    */

    sort(strings.begin(), strings.end(), simpleCompare);
    for (string s : strings)
        cout << s << endl;
}