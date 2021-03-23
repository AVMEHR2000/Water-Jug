#include "jug.h"
#include <iostream>
using namespace std;

jug::jug()
{
	capacity = 0;
	Value = 0;
}

jug::jug(int Cap)
{
	capacity = Cap;
	Value = 0;
}

jug::jug(int Cap, int val)
{
	capacity = Cap;
	Value = val;
}

// check jug is full?
int jug::IsFull()
{
	// TODO: Add your implementation code here.
	return (Value == capacity);
}


// check jug is empty?
int jug::IsEmpty()
{
	return (Value == 0);
}

int jug::GetCap()
{
	return capacity;
}


// get value of the jug
int jug::GetValue()
{
	
	return Value;
}
void jug::PourTo(jug Target)
{
	if (Value >= Target.capacity)
	{
		Target.Value = this->Value;
	}
	else
	{
		Target.Value = Target.capacity;
	}
}
int gcd(int first, int second)
{
	if (second <= first && first % second == 0)
		return second;
	if (first < second)
		return gcd(second, first);
	else
		return gcd(second, first % second);
}
int CheckInputs(int firstCap, int secondCap, int Rest)
{
	if (firstCap < Rest)
	{
		cout << "first jug can't hold more water than it's capacity!\n";
	}
	if (firstCap <= secondCap && Rest != firstCap)
	{
		cout << "first jug capacity is lower than second jug\n";
		return 0;
	}
	if (Rest % gcd(firstCap, secondCap) != 0)
	{
		cout << "can't reach this state with the given jugs\n";
		return 0;
	}
	return 1;




}