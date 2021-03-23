#include <iostream>
#include<vector>
#include <algorithm>
#include "State.h"
#include "jug.h"
#include <time.h>
using namespace std;
bool isSameState(State A, State B)	//this function checks A and B are same or not
{
	return (A.first.GetValue() == B.first.GetValue() && A.second.GetValue() == B.second.GetValue());

}

bool contains(vector<State> nodeslist, State choosenState)	//this function check nodeslist contain choosenState or not
{
	for (auto i : nodeslist)
	{
		if (isSameState(i, choosenState))
		{
			return true;
		}
	}
	return false;
}



int main()
{
	int firsJugCap, SecondjugCap, RestValueRequired;
	int tempfirstjugcap, tempsecondjugcap, tempRestValueRequired;

	cout << "Enter capacity of first jug:\n";
	cin >> firsJugCap;
	cout << "Enter capacity of second jug: \n";
	cin >> SecondjugCap;
	cout << "Enter required water in first jug must remain:\n";
	cin >> RestValueRequired;
	while (!CheckInputs(firsJugCap, SecondjugCap, RestValueRequired))	//check inputs
	{

		cout << "Enter capacity of first jug:\n";
		cin >> firsJugCap;
		cout << "Enter capacity of second jug: \n";
		cin >> SecondjugCap;
		cout << "Enter required water in first jug must remain:\n";
		cin >> RestValueRequired;

	}
	tempfirstjugcap = firsJugCap / gcd(firsJugCap, SecondjugCap);
	tempsecondjugcap = SecondjugCap / gcd(firsJugCap, SecondjugCap);
	tempRestValueRequired = RestValueRequired / gcd(firsJugCap, SecondjugCap);
	//creat Jugs
	jug firstJugState(tempfirstjugcap,0);
	jug secondJugState(tempsecondjugcap, 0);
	State InitioalState(firstJugState, secondJugState);		//creat Initioal State
	vector<State> ExpandableList;
	vector<State> CheckedList; 
	State selectedState = InitioalState;
	ExpandableList.push_back(selectedState);
	clock_t tStart = clock();
	while (selectedState.first.GetValue()!=tempRestValueRequired)
	{
		CheckedList.push_back(selectedState);
		ExpandableList.erase(ExpandableList.begin());
		//Add actions 

		ExpandableList.push_back(selectedState.EmptyFirstJug());


		ExpandableList.push_back(selectedState.EmptySecondJug());


		ExpandableList.push_back(selectedState.FillFirstJug());


		ExpandableList.push_back(selectedState.FillSecondJug());


		ExpandableList.push_back(selectedState.PourToFirstJug());


		ExpandableList.push_back(selectedState.PourToSecondJug());
		
	
		selectedState = ExpandableList.at(0);

	}
	//print all patch
	State printState = selectedState;

	do
	{
		cout << "[" << printState.first.GetValue()*gcd(firsJugCap,SecondjugCap) << "," << printState.second.GetValue()* gcd(SecondjugCap,firsJugCap)<< "]\n";
		printState = *printState.parent;
	}
	while (printState.parent != nullptr);
	cout<< "[" << InitioalState.first.GetValue() << "," << InitioalState.second.GetValue() << "]\n";
	cout << "number of checked states:" << CheckedList.size()+1<<endl;
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	


}


