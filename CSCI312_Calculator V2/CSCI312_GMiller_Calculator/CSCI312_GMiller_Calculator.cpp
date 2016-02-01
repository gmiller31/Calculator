// CSCI312_GMiller_Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include "Memento.h"
#include "Calculator.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])    //Lots of things are commented out, switched from calculator in main to calculator class, didn't want to lose anything if it didn't work
{

	Calculator calc;


	cout << "                          --==CALCULATOR==--" << endl;
	cout << "Available Commands: UNDO CLEAR EXIT HELP" << endl;

	while (calc.Quit() != true)
	{
		calc.run();

		
	}


}

