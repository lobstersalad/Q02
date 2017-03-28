/*
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, checkNewBoardEmpty) {
	Piezas game;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			ASSERT_EQ(game.pieceAt(i, j), Blank);
		}
	}
}

TEST(PiezasTest, checkResetEmptyBoardEmpty) {
	Piezas game;
	game.reset();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			ASSERT_EQ(game.pieceAt(i, j), Blank);
		}
	}
}

TEST(PiezasTest, checkResetFullBoardEmpty) {
	// finish this later
}

TEST(PiezasTest, checkDropPieceX) {
	Piezas game;
	ASSERT_EQ(game.dropPiece(0), X);
}

TEST(PiezasTest, checkDropPieceO) {
	Piezas game;
	game.dropPiece(0);
	ASSERT_EQ(game.dropPiece(1), O);
}

TEST(PiezasTest, checkDropPieceX00) {
	Piezas game;
	game.dropPiece(0);
	ASSERT_EQ(game.pieceAt(0, 0), X);
}

TEST(PiezasTest, checkDropPieceX01) {
	Piezas game;
	game.dropPiece(1);
	ASSERT_EQ(game.pieceAt(0, 1), X);
}

TEST(PiezasTest, checkDropPieceX02) {
	Piezas game;
	game.dropPiece(2);
	ASSERT_EQ(game.pieceAt(0, 2), X);
}

TEST(PiezasTest, checkDropPieceX03) {
	Piezas game;
	game.dropPiece(3);
	ASSERT_EQ(game.pieceAt(0, 3), X);
}

TEST(PiezasTest, checkDropPieceX10) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	ASSERT_EQ(game.pieceAt(1, 0), X);
}

TEST(PiezasTest, checkDropPieceX11) {
	Piezas game;
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);
	ASSERT_EQ(game.pieceAt(1, 1), X);
}

TEST(PiezasTest, checkDropPieceX12) {
	Piezas game;
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(2);
	ASSERT_EQ(game.pieceAt(1, 2), X);
}

TEST(PiezasTest, checkDropPieceX13) {
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(3);
	ASSERT_EQ(game.pieceAt(1, 3), X);
}

TEST(PiezasTest, checkDropPieceX20) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	ASSERT_EQ(game.pieceAt(2, 0), X);
}

TEST(PiezasTest, checkDropPieceX21) {
	Piezas game;
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(1);
	ASSERT_EQ(game.pieceAt(2, 1), X);
}

TEST(PiezasTest, checkDropPieceX22) {
	Piezas game;
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(2);
	ASSERT_EQ(game.pieceAt(2, 2), X);
}

TEST(PiezasTest, checkDropPieceX23) {
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);
	ASSERT_EQ(game.pieceAt(2, 3), X);
}

TEST(PiezasTest, checkDropPieceO00) {
	Piezas game;
	game.dropPiece(1);
	game.dropPiece(0);
	ASSERT_EQ(game.pieceAt(0, 0), O);
}

TEST(PiezasTest, checkDropPIeceO01) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(1);
	ASSERT_EQ(game.pieceAt(0, 1), O);
}

TEST(PiezasTest, checkDropPieceO02) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(2);
	ASSERT_EQ(game.pieceAt(0, 2), O);
}

TEST(PiezasTest, checkDropPieceO03) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(3);
	ASSERT_EQ(game.pieceAt(0, 3), O);
}

TEST(PiezasTest, checkDropPieceO10) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	ASSERT_EQ(game.pieceAt(1, 0), O);
}

TEST(PiezasTest, checkDropPieceO11) {
	Piezas game;
	game.dropPiece(1);
	game.dropPiece(1);
	ASSERT_EQ(game.pieceAt(1, 1), O);
}

TEST(PiezasTest, checkDropPieceO12) {
	Piezas game;
	game.dropPiece(2);
	game.dropPiece(2);
	ASSERT_EQ(game.pieceAt(1, 2), O);
}

TEST(PiezasTest, checkDropPieceO13) {
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	ASSERT_EQ(game.pieceAt(1, 3), O);
}

TEST(PiezasTest, checkDropPieceO20) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	ASSERT_EQ(game.pieceAt(2, 0), O);
}

TEST(PiezasTest, checkDropPieceO21) {
	Piezas game;
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(1);
	ASSERT_EQ(game.pieceAt(2, 1), O);
}

TEST(PiezasTest, checkDropPieceO22) {
	Piezas game;
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(2);
	ASSERT_EQ(game.pieceAt(2, 2), O);
}

TEST(PiezasTest, checkDropPieceO23) {
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(3);
	ASSERT_EQ(game.pieceAt(2, 3), O);
}

TEST(PiezasTest, checkDropPieceXUnderCol) {
	Piezas game;
	ASSERT_EQ(game.dropPiece(-1), Invalid);
}

TEST(PiezasTest, checkDropPieceOUnderCol) {
	Piezas game;
	game.dropPiece(0);
	ASSERT_EQ(game.dropPiece(-1), Invalid);
}

TEST(PiezasTest, checkDropPieceXOverCol) {
	Piezas game;
	ASSERT_EQ(game.dropPiece(4), Invalid);
}

TEST(PiezasTest, checkDropPieceOOverCol) {
	Piezas game;
	game.dropPiece(0);
	ASSERT_EQ(game.dropPiece(4), Invalid);
}

TEST(PiezasTest, checkDropPieceXOverRow) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	ASSERT_EQ(game.dropPiece(0), Blank);
}

TEST(PiezasTest, checkDropPieceOOverRow) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	ASSERT_EQ(game.dropPiece(0), Blank);
}

TEST(PiezasTest, checkStateNotOver) {
	Piezas game;
	game.dropPiece(0);
	ASSERT_EQ(game.gameState(), Invalid);
}

TEST(PiezasTest, checkStateFullTie) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);
	ASSERT_EQ(game.gameState(), Blank);	
}

TEST(PiezasTest, checkStateXWinnerVertical3) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	ASSERT_EQ(game.gameState(), X);
}

TEST(PiezasTest, checkStateOWinnerVertical3) {
	Piezas game;
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(1);
	ASSERT_EQ(game.gameState(), O);
}

TEST(PiezasTest, checkStateOWinnerHorizontal3) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	ASSERT_EQ(game.gameState(), O);
}

TEST(PiezasTest, checkStateXWinnerHorizontal3) {
	Piezas game;
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(0);
	ASSERT_EQ(game.gameState(), X);
}

TEST(PiezasTest, checkStateXWinnerHorizontal4) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	ASSERT_EQ(game.gameState(), X);
}

TEST(PiezasTest, checkStateOWinnerHorizontal4) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(3);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(3);
	ASSERT_EQ(game.gameState(), O);
}

TEST(PiezasTest, checkStateTie2) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(3);
	game.dropPiece(1);
	ASSERT_EQ(game.gameState(), Blank);
}

TEST(PiezasTest, checkStateTie3) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(0);
	game.dropPiece(2);
	game.dropPiece(1);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(3);
	ASSERT_EQ(game.gameState(), Blank);
}

TEST(PiezasTest, checkStateTie4) {
	Piezas game;
	game.dropPiece(0);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(2);
	game.dropPiece(3);
	game.dropPiece(3);
	game.dropPiece(0);
	game.dropPiece(1);
	game.dropPiece(2);
	game.dropPiece(3);
	ASSERT_EQ(game.gameState(), Blank);
}
