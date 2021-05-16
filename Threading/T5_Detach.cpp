/*
TOPIC:  use of join() , detach() and joinable() in thread c++(C++11)

JOIN Notes:
1.Once a thread is started we wait for this thread to finish by calling join()
function on thread object.
2.Double join will result into program termination
3.If needed we should check thread is joinable before joining ( using joinable() function).


DETACH Notes:
1.This is used to detach newly created thread from the paret thread
2.Always check before detaching a thread that it is joinable otherwise we may end up
diuble detaching and double detach() will result into program termination.
3.If we have detached thread and main function is returning then the detached thread
execution is suspended.

Notes:
Either join() or detach() should be called on thread object, otherwise during thread
object's destructor it will terminate the program.Because inside destructor it checks
if thread is still joinable ? If yes then it terminates the program.


*/

#include<iostream>
#include<thread>
#include<chrono>

void fun(int x)
{
	while (x-- > 0)
	{
		std::cout <<"\ninside fun() thread" << std::endl;
	}

	//std::this_thread::sleep_for(std::chrono::seconds(5));

	std::cout << "\nThread Finished.." << std::endl;
}

int main()
{
	std::thread t(fun, 10);
	std::cout << "\ninside main() thread" << std::endl;

	t.detach();

	if (t.joinable())  //To avoid double detach
		t.detach();

	std::cout << "\nmain() after";

	//std::this_thread::sleep_for(std::chrono::seconds(5));


	//std::cin.get();
	return 0;
}