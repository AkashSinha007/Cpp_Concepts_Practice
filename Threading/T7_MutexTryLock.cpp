
#include<iostream>
#include<thread>
#include<mutex>

int myAmount = 0;
std::mutex m;

void increaseCounterFor100000Time()
{
	for (size_t i = 0; i < 100000; i++)
	{
		if(m.try_lock()) //This will not block the other threads, hence different answer
		++myAmount;
		m.unlock();
	}
	
}


int main()
{
	std::thread t1(increaseCounterFor100000Time);
	std::thread t2(increaseCounterFor100000Time);

	t1.join();
	t2.join();

	std::cout << "\nValue of myAmount= " << myAmount;

	return 0;
}