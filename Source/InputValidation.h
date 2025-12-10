// InputValidation.h
#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
 * @class InputValidation
 * @brief Provides static methods for validating and reading user input.
 *
 * This class includes methods to read integer inputs and validate
 * whether they fall within specified ranges.
 */
class InputValidation
{
public:

	// Check if a number is within a specified range (inclusive)
    static bool isNumberBetween(int number, int from, int to)
    {
        return (number >= from && number <= to);
    }
	// Read an integer number from user input with validation
    static int readIntNumber(string errorMessage = "Invalid Input, Please enter a Number")
    {
        string input;
        int number;
        bool notValid;
        cout << "Please enter a Number: ";
        do
        {
            cin.clear();
            getline(cin, input);
            notValid = false;

            try
            {
                size_t pos;
                number = stoi(input, &pos);

                if (pos != input.length())
                {
                    throw invalid_argument("Trailing characters");
                }
            }

            catch(...)
            {
                cout << errorMessage << " ";
                notValid = true;
            }

        } while (notValid);

        return number;
    }

	// Read an integer number within a specified range with validation
    static int readIntNumberBetween(int from, int to, string errorMessage)
    {
        while (true)
        {
            int number = readIntNumber();
            if (isNumberBetween(number, from, to)) return number;
            else cout << errorMessage << endl;
        }
    }
};
