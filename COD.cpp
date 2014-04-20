#include "LIST.h"
#include <iostream>

void main() {
	int N, k, ak;
	std::cin >> N;
	list A = list();
	for (int i = 0; i < N; i++)
	{
		std::cin >> k >> ak;
		A.add(k, ak);
	}
	std::cin >> k;
	A.del(k);
	A.print();
}