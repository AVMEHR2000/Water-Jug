#pragma once
class jug
{
	int capacity;
	int Value;
public:
	jug();
	jug(int Cap);	//constructor for a jug with capacity Cap
	jug(int Cap,int val);	//constructor for a jug with capacity Cap and value
					
	// check jug is full?
	int IsFull();
	// check jug is empty?
	int IsEmpty();
	// get capacity of the jug
	int GetCap();
	// get value of the jug
	int GetValue();
	//pour water to another jug
	void PourTo(jug );
};
int CheckInputs(int, int, int);	//this function checks the input is valid
int gcd(int, int);	//this function computes greatest common divisor of two integer



