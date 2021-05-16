#include<iostream>
#include<thread>

#define FunctionPointer 0
#define LambdaFunction 0
#define Functor 0
#define NonStaticMemberFunction 0
#define StaticMemberFunction 1

#if FunctionPointer
/*
Function Pointer
*/

void fun(int x)
{
	while (x-- > 0)
	{
		std::cout << x << std::endl;
	}
}

int main()
{
	std::thread t(fun, 10);
	t.join();

	std::cin.get();
	return 0;
}


#endif



#if LambdaFunction
/*
Lambda Function
*/

int main()
{
	auto fun = [](int x) {
							while (x-- > 0)
							{
								std::cout << x << std::endl;
							}
						};

	std::thread t(fun, 10);
	t.join();

	std::cin.get();
	return 0;
}


#endif


#if Functor

/*
Functor ( Function objects)*/

class Base
{
public:
	void operator ()(int x) 
	{
		while (x-- > 0)
		{
			std::cout << x << std::endl;
		}
	}
};

int main()
{
	std::thread t((Base()),10);
	t.join();


	std::cin.get();
	return 0;

}


#endif


#if NonStaticMemberFunction

/* Non-Static Memeber Function */

class Base
{
public:
	void run(int x)
	{
		while (x-- > 0)
		{
			std::cout << x << std::endl;
		}
	}
};


int main()
{
	Base b;
	std::thread t(&Base::run,&b,10);
	t.join();


	std::cin.get();
	return 0;

}

#endif




#if StaticMemberFunction

/* Static Memeber Function */

class Base
{
public:
	static void run(int x)
	{
		while (x-- > 0)
		{
			std::cout << x << std::endl;
		}
	}
};


int main()
{
	Base b;
	std::thread t(&Base::run, 10);
	t.join();


	std::cin.get();
	return 0;

}

#endif