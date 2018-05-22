// cpp17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include <numeric>
#include <iostream>
#include <execution>
#include <chrono>

using namespace std;

void test_reduce_parallel()
{
	array<int, 10> data = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };

	auto start = chrono::steady_clock::now();
	auto total = reduce(execution::par_unseq, begin(data), end(data), 0);
	auto end = chrono::steady_clock::now();
	auto elapsed = end - start;

	cout << "sum parallel: " << total << "(" << chrono::duration<double, milli>(elapsed).count() << " ms)" << endl;
}

void test_reduce_sequential()
{
	array<int, 10> data = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };

	auto start = chrono::steady_clock::now();
	auto total = reduce(begin(data), end(data), 0);
	auto end = chrono::steady_clock::now();
	auto elapsed = end - start;

	cout << "sum sequential: " << total << "(" << chrono::duration<double, milli>(elapsed).count() << " ms)" << endl;
}

int main()
{
	test_reduce_sequential();
	test_reduce_parallel();

    return 0;
}



