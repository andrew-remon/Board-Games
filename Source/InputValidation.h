#pragma once
#include <iostream>
#include <string>
using namespace std;

class InputValidation
{
public:

    static bool isNumberBetween(int number, int from, int to)
    {
        return (number >= from && number <= to);
    }

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
