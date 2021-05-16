
#include<iostream>
#include<thread>
#include<mutex>

int myAmount = 0;
std::mutex m;

void addMoney()
{
	m.lock();
	++myAmount;
	m.unlock();
}


int main()
{
	std::thread t1(addMoney);
	std::thread t2(addMoney);

	t1.join();
	t2.join();

	std::cout << "\nValue of myAmount= " << myAmount;

	return 0;
}