#include "State.h"

State::State(jug a, jug b)
{
	first = a;
	second = b;
	parent = nullptr;
	cost = 0;
}

State::State(jug a, jug b, State* p)
{
	first = a;
	second = b;
	parent = p;
	cost = 0;
}

State::State(jug a, jug b, State* p, int c)
{
	first = a;
	second = b;
	parent = p;
	cost = c;
}

State State::EmptyFirstJug()
{
	jug newfirstJug(first.GetCap(), 0);
	State* currentState = new State(first, second, parent, cost);
	return State(newfirstJug,second,currentState,cost+1);
}


State State::EmptySecondJug()
{
	jug newSecJug(second.GetCap(), 0);
	State* currentState = new State(first, second, parent, cost);
	return State(first, newSecJug, currentState,cost+1);
}

State State::FillFirstJug()
{
	jug newfirstJug(first.GetCap(), first.GetCap());
	State* currentState = new State(first, second, parent, cost);
	return State(newfirstJug, second, currentState,cost+1);
}

State State::FillSecondJug()
{
	jug newSecJug(second.GetCap(), second.GetCap());
	State* currentState = new State(first, second, parent, cost);
	return State(first, newSecJug, currentState,cost+1);
}

State State::PourToSecondJug()
{
	int newfirstjugValue;
	int newsecondjugValue;
	if (first.GetValue() + second.GetValue() > second.GetCap())
	{
		newsecondjugValue = second.GetCap();
		
		
	}
	else
	{
		newsecondjugValue = first.GetValue() + second.GetValue();
	}
	if (first.GetValue() - (second.GetCap() - second.GetValue()) < 0)
	{
		newfirstjugValue = 0;
	}
	else
	{
		newfirstjugValue = first.GetValue() - (second.GetCap() - second.GetValue());
	}
	jug newfirstJug(first.GetCap(), newfirstjugValue);
	jug newSecJug(second.GetCap(), newsecondjugValue);
	State* currentState = new State(first, second, parent, cost);
	return State(newfirstJug, newSecJug,currentState,cost+1);
}

State State::PourToFirstJug()
{
	int newfirstjugValue;
	int newsecondjugValue;
	if (first.GetValue() + second.GetValue() > first.GetCap())
	{
		newfirstjugValue =  first.GetCap();
		
	}
	else
	{
		newfirstjugValue = (first.GetValue() + second.GetValue());
	}
	if (second.GetValue() - (first.GetCap() - first.GetValue()) < 0)
	{
		newsecondjugValue = 0;
	}
	else
	{
		newsecondjugValue = second.GetValue() - (first.GetCap() - first.GetValue());
	}
	jug newfirstJug(first.GetCap(), newfirstjugValue);
	jug newSecJug(second.GetCap(), newsecondjugValue);
	State* currentState = new State(first, second, parent, cost);
	return State(newfirstJug, newSecJug, currentState,cost+1);
}

State State::GetParent()
{
	return *parent;
}

int heuristicCost(State s, int goal)
{
	int heuristic;
	heuristic = abs(s.first.GetValue() - goal);
	return heuristic;
}
