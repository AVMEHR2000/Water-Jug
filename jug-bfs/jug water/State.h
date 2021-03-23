#pragma once
#include "jug.h"
#include <cstdlib> 
#include<vector>
#include <iostream>
class State
{

	
public:
	jug first, second;
	int cost;
	State* parent;
	State(jug, jug);
	State(jug, jug, State*);
	State(jug, jug, State*, int);
	//Actions to creat childs node
	State EmptyFirstJug();
	State EmptySecondJug();
	State FillFirstJug();
	State FillSecondJug();
	State PourToSecondJug();
	State PourToFirstJug();
	//Method to access parent node
	State GetParent();

};
int heuristicCost(State, int);




