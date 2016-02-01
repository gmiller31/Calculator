#pragma once
#include <string>
#include <stack>
#include "Memento.h"

using namespace std;

class Calculator
{
public:
	Calculator();
	~Calculator();
	void Calculator::run();
	Memento<double> Calculator::CreateMemento();
	void Calculator::setMemento(Memento<double> m);
	bool Calculator::Quit();

	bool quit = false;
	string input = "";
	double input1 = 0, input2 = 0;
	string string1, string2, inputNew = "", stringChar;
	double output;
	stack<Memento<double>> s;
	int pos;
	bool valid;

private:
	double runningTotal = 0;


};


