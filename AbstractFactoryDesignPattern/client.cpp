/*
Abstract Factory Design Pattern
================================
Defines an abstract class for creating families of related 
objects but without specifying their concrete sub-class
*/
#include <iostream>
using namespace std;

#include "CarFactory.cpp"

#define SIMPLE_CAR 1
//#define LUXURY_CAR 1

int main() {

	#ifdef SIMPLE_CAR
		CarFactory* factory = new SimpleCarFactory;

	#elif LUXURY_CAR
		CarFactory* factory = new LuxuryCarFactory;
		
	#endif

	Car *car = factory->buildWholeCar();
	car->printDetails();

	return 0;
}