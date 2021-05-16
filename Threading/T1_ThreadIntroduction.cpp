/*
Ways to create threads in C++ 11

1.Function Pointers
2.Lambda Functions
3.Functors
4.Member functions
5.Static Member Functions
*/

/*
In this we will only consider using function pointers

//Requirement:
Find the addition of all odd number from 1 to 1900000000 and all even 
number from 1 to 1900000000
*/


#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findEven(ull start,ull end)
{
	for (ull i = start; i <= end; ++i)
	{
		if ((i & 1) == 0)
		{
			evenSum += i;
		}
	}
}

void findOdd(ull start, ull end)
{
	for (ull i = start; i <= end; ++i)
	{
		if ((i & 1) == 1)
		{
			oddSum += i;
		}
	}
}


int main()
{
	ull start = 0, end = 1900000000;

	auto startTime = std::chrono::high_resolution_clock::now();

	findOdd(start, end);
	findEven(start, end);

	auto stopTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

	std::cout << "\nOdd Sum: " << oddSum;
	std::cout << "\nEven Sum: " << evenSum;

	std::cout << "\nTime Taken in seconds: " << duration.count() / 1000000 << std::endl;

	std::cin.get();
	return 0;
}