// cpp17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include <numeric>
#include <iostream>

using namespace std;

int main()
{
	array<int, 10> data = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };
	auto total = std::reduce(begin(data), end(data));
	cout << "sum: " << total << endl;
    return 0;
}

