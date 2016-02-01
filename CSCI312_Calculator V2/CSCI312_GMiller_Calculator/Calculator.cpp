#include "stdafx.h"
#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

Calculator::Calculator()
{

	s.push(CreateMemento());
}


Calculator::~Calculator()
{
}

void Calculator::run()
{
	input1 = 0;
	input2 = 0;
	output = 0;
	inputNew = "";
	string1 = "";
	string2 = "";
	valid = true;

	getline(cin, input);

	if (input == "UNDO" || input == "undo")
	{
		s.pop();
		if (s.empty())
		{
			cout << "ERROR: UNDO IS NOT AVAILABLE" << endl;
			s.push(CreateMemento());
		}
		cout << "Running Total: " << s.top().getData() << endl;
	}
	else if (input == "CLEAR" || input == "clear")
	{
		while (!s.empty())
		{
			s.pop();
		}
		s.push(0);
		cout << "CLEARED" << endl;
	}
	else if (input == "EXIT" || input == "exit")
	{
		cout << "Exiting Program..." << endl;
		quit = true;

	}
	else if (input == "HELP" || input == "help")
	{
		cout << "Available Commands: UNDO CLEAR EXIT HELP" << endl;
		cout << "UNDO: Returns the Running Total to the previous value" << endl;
		cout << "CLEAR: Resets the program to startup" << endl;
		cout << "EXIT: Quits the program" << endl;
		cout << "HELP: Displays this screen" << endl;
		cout << "Available Operations: + - * /" << endl;
		cout << "Input only one operation at a time in a '1+2' format" << endl;
		cout << "Spaces are ignored." << endl;

	}
	else
	{

		if (input.find('+') != string::npos)
		{

			for (unsigned int c = 0; c < input.size(); c++) //for each character, check if it's a space
			{
				if (input[c] != ' ')  //if it's not, put it into a new string without the spaces
				{
					stringChar = input[c];
					inputNew.append(stringChar);
				}
			}//removes the spaces from the input

			input = inputNew;
			pos = input.find('+');

			if (input[0] == '+' || input[input.size() - 1] == '+') //checks to see if the input can be put into STRING+STRING
			{
				//cout << "The Input Starts With +" << endl; for testing
				cout << "ERROR: INVALID INPUT" << endl;
			}
			else
			{
				//puts 
				string1 = input.substr(0, pos);
				//istringstream(input.substr(0, pos)) >> string1;
				input.erase(0, pos + 1);
				string2 = input;
				//istringstream(input) >> string2;


				//checks if both strings are numbers



				for (int c = 0; c < string1.size(); c++)
				{
					if (!isdigit(string1[c]) && string1[c] != '.') //if the character isn't a digit or a period
					{
						valid = false;
					}

				}

				for (int c = 0; c < string2.size(); c++)
				{
					if (!isdigit(string2[c]) && string2[c] != '.') //if the character isn't a digit
					{

						valid = false;  //the input isn't valid

					}

				}




				if (valid)
				{

					istringstream(string1) >> input1;
					istringstream(string2) >> input2;



					cout << "input1: " << input1 << "   input2: " << input2 << endl;

					output = input1 + input2;

					s.push(output + s.top().getData());

					cout << "Sum: " << output << "   Running Total: " << s.top().getData() << endl;
				}
				else
				{
					cout << "ERROR: INVALID INPUT" << endl;
				}

			}

		}
		else if (input.find('-') != string::npos)
		{
			for (int c = 0; c < input.size(); c++) //for each character, check if it's a space
			{
				if (input[c] != ' ')  //if it's not, put it into a new string without the spaces
				{
					stringChar = input[c];
					inputNew.append(stringChar);
				}
			}//removes the spaces from the input

			input = inputNew;
			pos = input.find('-');

			if (input[0] == '-' || input[input.size() - 1] == '-') //checks to see if the input can be put into STRING+STRING
			{
				//cout << "The Input Starts With +" << endl;
				cout << "ERROR: INVALID INPUT" << endl;
			}
			else
			{
				//puts 
				string1 = input.substr(0, pos);
				//istringstream(input.substr(0, pos)) >> string1;
				input.erase(0, pos + 1);
				string2 = input;
				//istringstream(input) >> string2;


				//checks if both strings are numbers



				for (int c = 0; c < string1.size(); c++)
				{
					if (!isdigit(string1[c]) && string1[c] != '.') //if the character isn't a digit or a period
					{
						valid = false;
					}

				}

				for (int c = 0; c < string2.size(); c++)
				{
					if (!isdigit(string2[c]) && string2[c] != '.') //if the character isn't a digit
					{

						valid = false;  //the input isn't valid

					}

				}




				if (valid)
				{

					istringstream(string1) >> input1;
					istringstream(string2) >> input2;



					cout << "input1: " << input1 << "   input2: " << input2 << endl;

					output = input1 - input2;

					runningTotal = output + s.top().getData();

					s.push(CreateMemento());

					cout << "Difference: " << output << "   Running Total: " << s.top().getData() << endl;
				}
				else
				{
					cout << "ERROR: INVALID INPUT" << endl;
				}

			}

		}
		else if (input.find('*') != string::npos)
		{
			for (int c = 0; c < input.size(); c++) //for each character, check if it's a space
			{
				if (input[c] != ' ')  //if it's not, put it into a new string without the spaces
				{
					stringChar = input[c];
					inputNew.append(stringChar);
				}
			}//removes the spaces from the input

			input = inputNew;
			pos = input.find('*');

			if (input[0] == '*' || input[input.size() - 1] == '*') //checks to see if the input can be put into STRING+STRING
			{
				//cout << "The Input Starts With +" << endl;
				cout << "ERROR: INVALID INPUT" << endl;
			}
			else
			{
				//puts 
				string1 = input.substr(0, pos);
				//istringstream(input.substr(0, pos)) >> string1;
				input.erase(0, pos + 1);
				string2 = input;
				//istringstream(input) >> string2;


				//checks if both strings are numbers



				for (int c = 0; c < string1.size(); c++)
				{
					if (!isdigit(string1[c]) && string1[c] != '.') //if the character isn't a digit or a period
					{
						valid = false;
					}

				}

				for (int c = 0; c < string2.size(); c++)
				{
					if (!isdigit(string2[c]) && string2[c] != '.') //if the character isn't a digit
					{

						valid = false;  //the input isn't valid

					}

				}




				if (valid)
				{

					istringstream(string1) >> input1;
					istringstream(string2) >> input2;



					cout << "input1: " << input1 << "   input2: " << input2 << endl;

					output = input1 * input2;

					s.push(output + s.top().getData());

					cout << "Product: " << output << "   Running Total: " << s.top().getData() << endl;
				}
				else
				{
					cout << "ERROR: INVALID INPUT" << endl;
				}

			}

		}
		else if (input.find('/') != string::npos)
		{
			for (int c = 0; c < input.size(); c++) //for each character, check if it's a space
			{
				if (input[c] != ' ')  //if it's not, put it into a new string without the spaces
				{
					stringChar = input[c];
					inputNew.append(stringChar);
				}
			}//removes the spaces from the input

			input = inputNew;
			pos = input.find('/');

			if (input[0] == '/' || input[input.size() - 1] == '/') //checks to see if the input can be put into STRING+STRING
			{
				//cout << "The Input Starts With +" << endl;
				cout << "ERROR: INVALID INPUT" << endl;
			}
			else
			{
				//puts 
				string1 = input.substr(0, pos);
				//istringstream(input.substr(0, pos)) >> string1;
				input.erase(0, pos + 1);
				string2 = input;
				//istringstream(input) >> string2;


				//checks if both strings are numbers



				for (int c = 0; c < string1.size(); c++)
				{
					if (!isdigit(string1[c]) && string1[c] != '.') //if the character isn't a digit or a period
					{
						valid = false;
					}

				}

				for (int c = 0; c < string2.size(); c++)
				{
					if (!isdigit(string2[c]) && string2[c] != '.') //if the character isn't a digit
					{

						valid = false;  //the input isn't valid

					}

				}




				if (valid)
				{

					istringstream(string1) >> input1;
					istringstream(string2) >> input2;



					cout << "input1: " << input1 << "   input2: " << input2 << endl;

					if (input2 == 0)
					{
						cout << "ERROR: CAN'T DIVIDE BY ZERO" << endl;

					}
					else
					{
						output = input1 / input2;
						s.push(output + s.top().getData());
						cout << "Quotient: " << output << "   Running Total: " << s.top().getData() << endl;
					}

				}
				else
				{
					cout << "ERROR: INVALID INPUT" << endl;
				}

			}



		}
		else
		{
			cout << "ERROR: INVALID INPUT" << endl;

		}






	}


}

bool Calculator::Quit()
{
	if (quit == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Memento<double> Calculator::CreateMemento()
{
	Memento<double> m(runningTotal);

	return m;
}

void Calculator::setMemento(Memento<double> m)
{
	runningTotal = m.getData();
}

