#include <iostream>

int main() 
{
	int Min = 0, Max = 0;
	std::cin >> Min >> Max;
	bool* PrimeArray = new bool[Max];

	for (int i = 2; i <= Max; i++)
		PrimeArray[i] = true;

	for (int i = 2; i <= Max; i++)
	{
		if (PrimeArray[i])
		{
			for (int j = i + i; j <= Max; j += i)
				PrimeArray[j] = false;
		}
	}

	// cout << endl�� ����� ��� buffer�� ���� �� �ð��� �ҿ�Ǿ� Ÿ�ӿ���
	for (int i = Min; i <= Max; ++i)
		if (PrimeArray[i] && i >= 2) printf("%d\n", i);
}
