#include "Piezas.h"
#include <vector>

/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/

/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas() {
	reset();
	turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset() {
	board.resize(3);
	for (int i = 0; i < 3; i++) {
		board[i].resize(4);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = Blank;
		}
	}
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column) {
	// Check out of bounds
	if (column < 0 || column > 3) {
		if (turn == X) {
			turn = O;
		} else {
			turn = X;
		}
		return Invalid;
	}
	bool piecePlaced = false;
	// Check if spot available
	for (int i = 0; i < 3; i++) {
		if (board[i][column] == Blank && piecePlaced == false) {
			board[i][column] = turn;
			piecePlaced = true;
		}
	}
	// Return move status
	if (piecePlaced == false) {
		if (turn == X) {
			turn = O;
		} else {
			turn = X;
		}
		return Blank;
	} else {
		if (turn == X) {
			turn = O;
			return X;
		} else {
			turn = X;
			return O;
		}
	}
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column) {
	if (row < 0 || row > 2 || column < 0 || column > 3) {
		return Invalid;
	} else {
		return board[row][column];
	}
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState() {
	Piece winner = Invalid;
	int longestX = 0, longestO = 0;
	bool full = true, tie = false;
	// Check rows
	for (int i = 0; i < 3; i++) {
		if (((board[i][0] == board[i][1]) && board[i][0] == X) ||
		    ((board[i][1] == board[i][2]) && board[i][1] == X) ||
		    ((board[i][2] == board[i][3]) && board[i][2] == X)) {
			if (longestX < 2) {
				longestX = 2;
			}
		}
		if (((board[i][0] == board[i][1]) && board[i][0] == O) ||
		    ((board[i][1] == board[i][2]) && board[i][1] == O) ||
		    ((board[i][2] == board[i][3]) && board[i][2] == O)) {
			if (longestO < 2) {
				longestO = 2;
			}
		}
		if (((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) &&
		    (board[i][0] == X)) ||
		    ((board[i][1] == board[i][2]) && (board[i][2] == board[i][3]) &&
		    (board[i][1] == X))) {
			if (longestX < 3) {
				longestX = 3;
			}
		}
		if (((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) &&
		    (board[i][0] == O)) ||
		    ((board[i][1] == board[i][2]) && (board[i][2] == board[i][3]) &&
		    (board[i][1] == O))) {
			if (longestO < 3) {
				longestO = 3;
			}
		}
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) &&
		    (board[i][2] == board[i][3]) && (board[i][0] == X)) {
			if (longestX < 4) {
				longestX = 4;
			}
		}
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) &&
		    (board[i][2] == board[i][3]) && (board[i][0] == O)) {
			if (longestO < 4) {
				longestO = 4;
			}
		}
	}
	// Check columns
	for (int i = 0; i < 4; i++) {
		if (((board[0][i] == board[1][i]) && (board[0][i] == X)) ||
		    ((board[1][i] == board[2][i]) && (board[1][i] == X))) {
			if (longestX < 2) {
				longestX = 2;
			}
		}
		if (((board[0][i] == board[1][i]) && (board[0][i] == O)) ||
		    ((board[1][i] == board[2][i]) && (board[1][i] == O))) {
			if (longestO < 2) {
				longestO = 2;
			}
		}
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) &&
		    (board[0][i] == X)) {
			if (longestX < 3) {
				longestX = 3;
			}
		}
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) &&
		    (board[0][i] == O)) {
			if (longestO < 3) {
				longestO = 3;
			}
		}
	}
	// Check full
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == Blank) {
				full = false;
			}
		}
	}
	if (longestX == longestO) {
		tie = true;
	} else if (longestX > longestO) {
		winner = X;
	} else if (longestO > longestX) {
		winner = O;
	}
	// Check final status (full, not over, tie, winner)
	if (full == true) {
		if (tie == true) {
			return Blank;
		}
		else {
			return winner;
		}
	} else {
		return Invalid;
	}
}
