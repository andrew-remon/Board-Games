#include "NumXO_Player.h"

NumXO_Player::NumXO_Player(string n, int s, PlayerType t, PlayerStatus st) : Player<int>(n, s, t), status(st) {
    if (st == PlayerStatus::Even)
        available_values = {2, 4, 6, 8};
    else
        available_values = {1, 3, 5, 7, 9};
};

void NumXO_Player::set_symbol()
{
    bool is_set_correctly = false;

    while(!is_set_correctly)
    {
        int answer;

        if (type == PlayerType::HUMAN)
        {
            cout << "\nAvailable numbers: ";
            for (int val : available_values) cout << val << " ";

            cout << "\nPlease enter your choice: ";
            cin >> answer;
        }
        else
        {
            if (available_values.empty()) break;
            // answer = rand() % 10;

            auto it = available_values.begin();
            advance(it, rand() % available_values.size());
            answer = *it;
        }

        if (is_input_symbol_validated(answer))
        {
            symbol = answer;
            available_values.erase(answer);
            is_set_correctly = true;
            cout << name << " Choose " << symbol << "\n";
        }
        else if (type == PlayerType::HUMAN)
            cout << "Invalid choice! Try again.\n";
    }
}

bool NumXO_Player::is_input_symbol_validated(int InputSymbol)
{
    // ! first approach
    // if (status == PlayerStatus::Even)
    // {
    //     auto value_found = even_values.find(InputSymbol);
    //     if (value_found != even_values.end()) return true;
    // }

    // else if (status == PlayerStatus::ODD)
    // {
    //     auto value_found = odd_values.find(InputSymbol);
    //     if (value_found != odd_values.end()) return true;
    // }

    // ! second approach
    // auto valueFound = available_values.find(InputSymbol);

    // if (valueFound != available_values.end()) return true;

    // return false;

    // ! third approach
    return available_values.find(InputSymbol) != available_values.end();
}
