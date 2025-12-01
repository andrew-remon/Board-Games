//--------------------------------------- IMPLEMENTATION
#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include "Word_XO_Classes.h"
#include <fstream>
using namespace std;

//------------------- X_O_Board Implementation ----------------

word_X_O_Board::word_X_O_Board() : Board(3, 3)
{
    // Initialize all cells with blank_symbol
    for (auto& row : board)
        for (auto& cell : row)
            cell = blank_symbol;
}

bool word_X_O_Board::update_board(Move<char>* move)
{
    int x = move->get_x();
    int y = move->get_y();
    char mark = move->get_symbol();

    // Validate move and apply if valid
    if (!(x < 0 || x >= rows || y < 0 || y >= columns) && (board[x][y] == blank_symbol || mark == 0))
    {
        if (mark == 0)
        { // Undo move
            n_moves--;
            board[x][y] = blank_symbol;
        }
        else
        {
            // Apply move
            n_moves++;
            board[x][y] = toupper(mark);
        }
        return true;
    }


    return false;
}

bool word_X_O_Board::is_win(Player<char>* player)
{
    if (n_moves >= 3)
    {
        // Check rows
        string word;

        for (int i = 0; i < rows; ++i)
        {
            word = "";
            for (int j = 0; j < columns; j++)
            {
                if (board[i][j] != blank_symbol) word += board[i][j];
                else continue;
            }

            if(is_word_found(word, "dic.txt")) return true;
        }

        // Check columns
        for (int i = 0; i < rows; ++i)
        {
            word = "";
            for (int j = 0; j < columns; j++)
            {
                if (board[j][i] != blank_symbol) word += board[j][i];
            }

            if(is_word_found(word, "dic.txt")) return true;
        }

        // Check diagonals
        word = "";
        word += board[0][0];
        word += board[1][1];
        word += board[2][2];
        if(is_word_found(word, "dic.txt")) return true;

        word = "";
        word += board[0][0];
        word += board[1][1];
        word += board[2][2];
        if(is_word_found(word, "dic.txt")) return true;
    }

    return false;
}

bool word_X_O_Board::is_draw(Player<char>* player) {
    return (n_moves == 9 && !is_win(player));
}

bool word_X_O_Board::game_is_over(Player<char>* player) {
    return is_win(player) || is_draw(player);
}

bool word_X_O_Board::is_word_found(string word, const string& file_name)
{
    if (word.length() != 3)
        return false;

    ifstream myFile(file_name);

    if (!myFile.is_open())
        return false;

    string line;
    while(myFile >> line)
    {
        if (line == word)
            return true;
    }

    return false;
    // File closes automatically when myFile goes out of scope
}

//------------------- XO_UI Implementation --------------------

word_XO_UI::word_XO_UI() : UI<char>("Welcome to Our FCAI Word Tic-Tac-Toe Game\n", 3)
{
    cout << "A version where players place letters on the board to form valid three-letter words in a 3x3 grid.\n";
    cout << "[1]Players take turns placing one letter on the board, attempting to form a valid word. Players can build upon letters already on the board.\n";
    cout << "[2]The first player to form a valid three-letter word horizontally, vertically, or diagonally wins.\n";
    cout << "[3]The game is a draw if the board is filled without a valid word being formed.\n\n";
}

Player<char>* word_XO_UI::create_player(string& name, char symbol, PlayerType type)
{
    // Create player based on type
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << symbol << ")\n";

    return new Player<char>(name, symbol, type);
}

Move<char>* word_XO_UI::get_move(Player<char>* player)
{
    int x, y;

    if (player->get_type() == PlayerType::HUMAN)
    {
        cout << "\nPlease enter your move x and y (0 to 2): ";
        cin >> x >> y;
    }

    else if (player->get_type() == PlayerType::COMPUTER)
    {
        x = rand() % player->get_board_ptr()->get_rows();
        y = rand() % player->get_board_ptr()->get_columns();
    }

    player->set_symbol();

    return new Move<char>(x, y, player->get_symbol());
}

Player<char>** word_XO_UI::setup_players()
{
    Player<char>** players = new Player<char>*[2];
    vector<string> type_options = { "Human", "Computer" };

    string name1 = get_player_name("Player 1");
    PlayerType type1 = get_player_type_choice("Player 1", type_options);
    players[0] = new word_XO_Player(name1, 'A', type1);

    string name2 = get_player_name("Player 2");
    PlayerType type2 = get_player_type_choice("Player 2", type_options);
    players[1] = new word_XO_Player(name2, 'B', type2);

    return players;
}

//------------------- XO_Player Implementation --------------------

void word_XO_Player::set_symbol()
{
    bool is_set_correctly = false;

    while(!is_set_correctly)
    {
        char answer;

        if (type == PlayerType::HUMAN)
        {
            cout << "Please Enter Your Letter: ";
            cin >> answer;
        }
        else
        {
            answer = 'A' + (rand() % 26);
        }

        if (is_input_symbol_validated(answer))
        {
            symbol = answer;
            is_set_correctly = true;
            cout << name << " Choose " << symbol << "\n";
        }

        else if (type == PlayerType::HUMAN)
            cout << "Invalid choice! Try again.\n";
    }
}

bool word_XO_Player::is_input_symbol_validated(char symbol)
{
    if (symbol >= 65 && symbol <= 90) return true;
    return false;
}
