#include <iostream>
#include "BoardGame_Classes.h"
#include "MisereXO_Board.h"
#include "MisereXO_UI.h"
#include "NumXO_Board.h"
#include "NumXO_UI.h"
#include "SuS_TTT_Board.h"
#include "SuS_TTT_UI.h"
#include "4X4board.h"
#include "4X4UI.h"
#include "5x5XO_Classes.h"
#include "Infinity_XO_Classes.h"
#include "Word_XO_Classes.h"
#include "Connect_4.h"
#include "Ultimate_X_O.h"
#include "InputValidation.h"
#include "DiamondXO_Board.h"
#include "DiamondXO_UI.h"

// ======= Game Type Enum =======

enum MenuOptions {
    MISERE_XO = 1,
    NUM_XO = 2,
    SUS_XO = 3,
    FOUR_X_FOUR_XO = 4,
    FIVE_X_FIVE_XO = 5,
    INFINITY_XO = 6,
    WORD_XO = 7,
    CONNECT_4 = 8,
    ULTIMATE_XO = 9,
    Diamond_XO = 10,
    EXIT = 11
};

// ======= Games Class =======

class Games {
public:
    static void RunUltimateXO()
    {
        UI<char>* game_ui = new Ultimate_X_O_UI();
        Board<char>* xo_board = new Ultimate_X_O_Board();
        Player<char>** players = game_ui->setup_players();
        GameManager<char> x_o_game(xo_board, players, game_ui);
        x_o_game.run();
        // --- Cleanup ---
        delete xo_board;
        delete game_ui;
        delete players[0];
        delete players[1];
        delete[] players;
    }
    static void RunConnect4()
    {
        UI<char>* game_ui = new connect_4_UI();
        Board<char>* xo_board = new connect_4_Board();
        Player<char>** players = game_ui->setup_players();
        GameManager<char> x_o_game(xo_board, players, game_ui);
        x_o_game.run();
        // --- Cleanup ---
        delete xo_board;
        delete game_ui;
        delete players[0];
        delete players[1];
        delete[] players;
    }

    static void RunWordXO()
    {
        UI<char>* game_ui = new word_XO_UI();

        Board<char>* xo_board = new word_X_O_Board();

        Player<char>** players = game_ui->setup_players();

        GameManager<char> x_o_game(xo_board, players, game_ui);

        x_o_game.run();

        // --- Cleanup ---
        delete xo_board;

        delete game_ui;

        delete players[0];
        delete players[1];

        delete[] players;
    }

    static void RunInfinityXO()
    {
        UI<char>* game_ui = new inf_XO_UI();

        Board<char>* xo_board = new inf_X_O_Board();

        Player<char>** players = game_ui->setup_players();

        GameManager<char> x_o_game(xo_board, players, game_ui);

        x_o_game.run();

        // --- Cleanup ---
        delete xo_board;

        delete game_ui;

        delete players[0];
        delete players[1];

        delete[] players;

    }

    static void Run5x5XO()
    {
        UI<char>* game_ui = new _5X5_XO_UI();

        Board<char>* xo_board = new _5X5_X_O_Board();

        Player<char>** players = game_ui->setup_players();

        GameManager<char> x_o_game(xo_board, players, game_ui);

        x_o_game.run();

        // --- Cleanup ---
        delete xo_board;

        delete game_ui;

        delete players[0];
        delete players[1];

        delete[] players;
    }

    static void RunMisereXO() {
        Board<char>* board = new MisereXO_Board();
        UI<char>* ui = new MisereXO_UI();
        Player<char>** players = ui->setup_players();
        GameManager<char> manager(board, players, ui);
        manager.run();

        // Clean up
        delete board;
        delete ui;
        delete players[0];
        delete players[1];
        delete[] players;
    }

    static void RunNumXO() {
        Board<int>* board = new NumXO_Board();
        UI<int>* ui = new NumXO_UI();
        Player<int>** players = ui->setup_players();
        GameManager<int> manager(board, players, ui);
        manager.run();

        // Clean up
        delete board;
        delete ui;
        delete players[0];
        delete players[1];
        delete[] players;
    }

    static void RunSuSXO() {
        UI<char>* ui = new SuS_TTT_UI();
        Board<char>* board = new SuS_TTT_Board();
        Player<char>** players = ui->setup_players();
        GameManager<char> susGame(board, players, ui);
        susGame.run();

        // Clean up
        delete board;
        delete ui;
        delete players[0];
        delete players[1];
        delete[] players;
    }

    static void Run4X4Game() {
        Board<char>* board = new Board4X4();
        UI<char>* ui = new UI4X4();
        Player<char>** players = ui->setup_players();
        GameManager<char> manager(board, players, ui);
        manager.run();

        //Clean up
        delete board;
        delete ui;
        delete players[0];
        delete players[1];
        delete[] players;
    }

    static void RunDiamondXOGame() {
        Board<char>* board = new DiamondXO_Board();
        UI<char>* ui = new DiamondXO_UI();
        Player<char>** players = ui->setup_players();
        GameManager<char> manager(board, players, ui);
        manager.run();

        //Clean up
        delete board;
        delete ui;
        delete players[0];
        delete players[1];
        delete[] players;
    }
};

// ======= Main Menu =======
    // forward declaration
void anotherGame();


void gameHandler(MenuOptions choice) {

    srand(static_cast<unsigned int>(time(NULL)));

    switch (choice) {
    case MenuOptions::MISERE_XO:
        Games::RunMisereXO();
        break;

    case MenuOptions::NUM_XO:
        Games::RunNumXO();
        break;

    case MenuOptions::SUS_XO:
        Games::RunSuSXO();
        break;

    case MenuOptions::FOUR_X_FOUR_XO:
        Games::Run4X4Game();
        break;

    case MenuOptions::FIVE_X_FIVE_XO:
        Games::Run5x5XO();
        break;

    case MenuOptions::INFINITY_XO:
        Games::RunInfinityXO();
        break;

    case MenuOptions::WORD_XO:
        Games::RunWordXO();
        break;

    case MenuOptions::CONNECT_4:
        Games::RunConnect4();
        break;

    case MenuOptions::ULTIMATE_XO:
        Games::RunUltimateXO();
        break;

    case MenuOptions::Diamond_XO:
        Games::RunDiamondXOGame();
        break;

    case MenuOptions::EXIT:
        return;

    default:
        cout << "==========================================\n";
        cout << "Invalid choice. Please try again.\n";
        cout << "==========================================\n";
        break;
    }
}
void Menu() {
    cout << "Welcome to the Ultimate XO Game Collection!\n";
    cout << "Choose a game to play from the menu below:\n";
    cout << "==========================================\n";
    cout << "[1]  MisereXO\n";
    cout << "[2]  NumXO\n";
    cout << "[3]  SusXO\n";
    cout << "[4]  4x4 XO\n";
    cout << "[5]  5x5 XO\n";
    cout << "[6]  Infinity XO\n";
    cout << "[7]  Word XO\n";
    cout << "[8]  Connect 4\n";
	cout << "[9]  Ultimate XO (demo)\n";
	cout << "[10] Diamond XO \n";
	cout << "[11] exit\n";
    cout << "==========================================\n";
    

    MenuOptions choice = static_cast<MenuOptions>(InputValidation::readIntNumberBetween(1, 11, "Invalid Input, Please Enter a number from 1 to 11"));

    if (choice != MenuOptions::EXIT) {
        gameHandler(choice);
		anotherGame();
    }
    else {
        cout << "==========================================\n";
		cout << "Thanks For Playing!!!\n";
		cout << "Exiting the game.\nGoodbye <3\n";
        cout << "==========================================\n";
		return;
    }
}
void anotherGame() {
    cout << "==========================================\n";
    cout << "Do you want to play another game? (y/n): ";
    cout << "\n==========================================\n";

    string choice;
    cin.ignore();
    getline(cin,choice);
    
    if (choice == "y" || choice == "Y") {
        cout << "\n==========================================\n";
        Menu();
    }
    else if (choice == "n" || choice == "N") {

        cout << "==========================================\n";
        cout << "\nThanks For Playing!!!\n";
        cout << "Exiting the game.\nGoodbye <3\n";
        cout << "==========================================\n";
    }
    else {
        cout << "Invalid choice.\n";
        anotherGame();
    }
}

// ======= Main Function =======
int main()
{
	Menu();
}
