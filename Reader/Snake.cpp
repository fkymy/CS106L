#include <iostream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

const int kMaxFood = 20;

const char kEmptyTile = ' ';
const char kWallTile  = '#';
const char kFoodTile  = '$';
const char kSnakeTile = '*';

struct pointT {
	int row, col;
};

struct gameT {
	vector<string> world;
	int numRows, numCols;

	deque<pointT> snake;
	int dx, dy;
	int numEaten;
};

string GetLine() {
	string result;
	std::getline(cin, result);
	return result;
}

void OpenUserFile(ifstream& input) {
	while (true) {
		cout << "Enter filename: ";
		string filename = GetLine();

		input.open(filename.c_str());
		if (input.is_open()) break;

		cout << "Sorry, cannot find file " << filename << endl;
		input.clear();
	}
}

pointT MakePoint(int row, int col) {
	pointT result;
	result.row = row;
	result.col = col;
	return result;
}

void LoadWorld(gameT& game, ifstream& input) {
	input >> game.numRows >> game.numCols;
	game.world.resize(game.numRows);

	input >> game.dx >> game.dy;

	string dummy;
	std::getline(input, dummy);

	for (int row = 0; row < game.numRows; ++row) {
		std::getline(input, game.world[row]);
		int col = game.world[row].find(kSnakeTile);
		if (col != string::npos) {
			game.snake.push_back(MakePoint(row, col));
		}
	}
	game.numEaten = 0;
}

void InitializeGame(gameT& game) {
	ifstream input;
	OpenUserFile(input);
	LoadWorld(game, input);
}

void RunSimulation(gameT& game) {
	
}

int main() {
	gameT game;
	InitializeGame(game);
	RunSimulation(game);
	return 0;
}
