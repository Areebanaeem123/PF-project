//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&**FINAL PROJECT PROGRAMMING FUNDAMENTALS***&&&&&&&&&&&&&&&&&
//***************************************************
// SUBMITTED BY: AREEBA NAEEM      22I-1502
//             : RUBBAN IFTIKHAR AHMAD   22I-2466
// SUBMITTED TO: MISS HUMA ALTAF
//**************************************************** 
//DECLARING VARIABLES
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
void startgame();//function prototype for starting the game
void kingPosition(char[][8]); //king is symbolized by k
void queenPosition(char[][8]); //queen is symbolized by Q
void bishopPosition(char[][8]); //bishop is symbolized by B
void rockPosition(char[][8]); //rock is symbolized by R
void knightPosition(char[][8]); //knight is symbolized by K
void moveKing(char[][8]); // 'K'
void moveQueen(char[][8]); // 'Q'
void moveBishop(char[][8]); // 'B'
void moveRock(char[][8]); // 'R'
void moveKnight(char[][8]); // 'N'
void gamestarts(char[][8]);//for the initialization of game 
void player1(char[][8]);//for player 1
void player2(char[][8]);//for player 2 
void endthegame(char[][8]);//for ending of the game
void CHECKFORCHECKMATEOFQUEEN(char[][8]);//for checking if the king is killed or not by queen?
void CHECKFORCHECKMATEOFBISHOP(char[][8]);////for checking if the ing is killed by the bishop?
void CHECKFORCHECKMATEOFROCK(char[][8]);////for checking if the ing is killed by the rock?
void CHECKFORCHECKMATEOFKNIGHT(char[][8]);////for checking if the ing is killed by the knight?
void initializeArray(char[][8], char c);
void displayArray(char[][8]);
void VALIDATIONFORRANDOMIZATIONOFKING(char[][8]);
void VALIDATIONFORRANDOMIZATIONOFQUEEN(char[][8]);
void VALIDATIONFORRANDOMIZATIONOFBISHOP(char[][8]);
void VALIDATIONFORRANDOMIZATIONOFROCK(char[][8]);
void VALIDATIONFORRANDOMIZATIONOFKNIGHT(char[][8]);
void VALIDATIONFORKINGOUTOFRANGE(char[][8]);//for keeping the king out of range
//declaring global variables
const int COL = 8;
const int ROW = 8;
int main() {
    startgame();
    return 0;
}
//function definition for start game:
void startgame() {
    int user_selection = 0;
    int user_selection2 = 0;
    cout << setw(80) << "**************************************" << endl;
    cout << setw(80) << "**************************************" << endl;
    cout << setw(80) << "*****WELCOME TO THE 2D CHESS GAME*****" << endl;
    cout << setw(80) << "**************************************" << endl;
    cout << setw(80) << "**************************************" << endl;
    char grid[ROW][COL];
    //initializing the array with character *
    initializeArray(grid, '*');
    displayArray(grid);
    // menu
    do {
        cout << "**WHICH PIECE WOULD YOU LIKE TO PLACE?***" << endl;
        cout << "********************************" << endl;
        cout << "1**************King*************" << endl;
        cout << "2**************QUEEN************" << endl;
        cout << "3**************BISHOP***********" << endl;
        cout << "4**************ROCK*************" << endl;
        cout << "5**************KNIGHT***********" << endl;
        cout << "*********************************" << endl;
        cout << "**ENTER -1 WHEN YOU ARE DONE WITH THE PLACEMENT OF YOUR PIECES!" << endl;
        cin >> user_selection;
        // Using switch statement for multiple selection
        switch (user_selection) {
        case 1:
            // Call the function of king
            kingPosition(grid);
            break;
        case 2:
            // Call the function of queen
            queenPosition(grid);
            break;
        case 3:
            // Call the function of bishop
            bishopPosition(grid);
            break;
        case 4:
            // Call the function of rock
            rockPosition(grid);
            break;
        case 5:
            // Call the function of knight
            knightPosition(grid);
            break;
        }
    } while (user_selection != -1);
    //calling the function for validation while randomizing the pieces..
    VALIDATIONFORRANDOMIZATIONOFKING(grid);
    VALIDATIONFORRANDOMIZATIONOFQUEEN(grid);
    VALIDATIONFORRANDOMIZATIONOFBISHOP(grid);
    VALIDATIONFORRANDOMIZATIONOFROCK(grid);
    VALIDATIONFORRANDOMIZATIONOFKNIGHT(grid);
    //calling the function of validation for keeping the king out of range 
    VALIDATIONFORKINGOUTOFRANGE(grid);
    cout << "***********************************" << endl;
    cout << "**THE PLACEMENT OF PIECES IS DONE!**" << endl;
    cout << "***********************************" << endl;
    do {
        displayArray(grid);
        cout << "**WHICH PIECE WOULD YOU LIKE TO MOVE?***" << endl;
        cout << "********************************" << endl;
        cout << "1**************King*************" << endl;
        cout << "2**************QUEEN************" << endl;
        cout << "3**************BISHOP***********" << endl;
        cout << "4**************ROCK*************" << endl;
        cout << "5**************KNIGHT***********" << endl;
        cout << "*********************************" << endl;
        cout << "**ENTER -1 WHEN YOU ARE DONE WITH THE MOVEMENT OF YOUR PIECES!" << endl;
        cin >> user_selection2;

        switch (user_selection2) {
        case 1:
            moveKing(grid);
            break;
        case 2:
            moveQueen(grid);
            break;
        case 3:
            moveBishop(grid);
            break;
        case 4:
            moveRock(grid);
            break;
        case 5:
            moveKnight(grid);
            break;
        }


    } while (user_selection2 != -1);
    //calling the function of 2playergame()
    gamestarts(grid);

}
//function definition for the initializing of array
void initializeArray(char grid[][8], char c) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = '*';
        }
    }
}//function definition for the displaying of array
void displayArray(char grid[][COL]) {
    cout << endl << "   ";
    for (int j = 0; j < COL; j++) {
        cout << j << "    ";
    }
    cout << endl;
    for (int i = 0; i < ROW; i++) {
        cout << i << "  ";
        for (int j = 0; j < COL; j++) {
            cout << grid[i][j] << "    ";
        }
        cout << endl;
    }
}
//function definition for king position
void kingPosition(char grid[][8]) {
    int kingrow = 0;
    int kingcol = 0;
    srand(int(time(NULL)));
    kingrow = rand() % 8;
    kingcol = rand() % 8;
    grid[kingrow][kingcol] = 'K';
    displayArray(grid);
}//function definition for queen position
void queenPosition(char grid[][8]) {
    int queenrow = 0;
    int queencol = 0;
    srand(int(time(NULL)));
    queenrow = rand() % 8;
    queencol = rand() % 8;
    grid[queenrow][queencol] = 'Q';
    displayArray(grid);
}//function definition for bishop position
void bishopPosition(char grid[][8]) {
    int bishoprow = 0;
    int bishopcol = 0;
    srand(int(time(NULL)));
    bishoprow = rand() % 8;
    bishopcol = rand() % 8;
    grid[bishoprow][bishopcol] = 'B';
    displayArray(grid);
}//function definition for rock position
void rockPosition(char grid[][8]) {
    int rockrow = 0;
    int rockcol = 0;
    srand(int(time(NULL)));
    rockrow = rand() % 8;
    rockcol = rand() % 8;
    grid[rockrow][rockcol] = 'R';
    displayArray(grid);
}//function definition for knight position
void knightPosition(char grid[][8]) {
    int knightrow = 0;
    int knightcol = 0;
    srand(int(time(NULL)));
    knightrow = rand() % 8;
    knightcol = rand() % 8;
    grid[knightrow][knightcol] = 'N';
    displayArray(grid);
}//function definition for validation for king
void VALIDATIONFORRANDOMIZATIONOFKING(char grid[][8]) {
    int kingrow = 0;
    int kingcol = 0;
    int queenrow = 0;
    int queencol = 0;
    int bishoprow = 0;
    int bishopcol = 0;
    int rockrow = 0;
    int rockcol = 0;
    int knightrow = 0;
    int knightcol = 0;
    if (grid[kingrow][kingcol] == grid[queenrow][queencol] ||
        grid[kingrow][kingcol] == grid[bishoprow][bishopcol] ||
        grid[kingrow][kingcol] == grid[rockrow][rockcol] ||
        grid[kingrow][kingcol] == grid[knightrow][knightcol]) {
        kingrow = rand() % 8;
        kingcol = rand() % 8;

    }
}//validating the queen
void VALIDATIONFORRANDOMIZATIONOFQUEEN(char grid[][8]) {
    int kingrow = 0;
    int kingcol = 0;
    int queenrow = 0;
    int queencol = 0;
    int bishoprow = 0;
    int bishopcol = 0;
    int rockrow = 0;
    int rockcol = 0;
    int knightrow = 0;
    int knightcol = 0;
    if (grid[queenrow][queencol] == grid[kingrow][kingcol] ||
        grid[queenrow][queencol] == grid[bishoprow][bishopcol] ||
        grid[queenrow][queencol] == grid[rockrow][rockcol] ||
        grid[queenrow][queencol] == grid[knightrow][knightcol]) {
        queenrow = rand() % 8;
        queencol = rand() % 8;


    }
    else {
        cout << "." << endl;
    }
}//validating the bishop
void VALIDATIONFORRANDOMIZATIONOFBISHOP(char grid[][8]) {
    int kingrow = 0;
    int kingcol = 0;
    int queenrow = 0;
    int queencol = 0;
    int bishoprow = 0;
    int bishopcol = 0;
    int rockrow = 0;
    int rockcol = 0;
    int knightrow = 0;
    int knightcol = 0;
    if (grid[bishoprow][bishopcol] == grid[kingrow][kingcol] ||
        grid[bishoprow][bishopcol] == grid[queenrow][queencol] ||
        grid[bishoprow][bishopcol] == grid[rockrow][rockcol] ||
        grid[bishoprow][bishopcol] == grid[knightrow][knightcol]) {
        bishoprow = rand() % 8;
        bishopcol = rand() % 8;
    }
    else {
        cout << "" << endl;
    }
}//validating for rock
void VALIDATIONFORRANDOMIZATIONOFROCK(char grid[][8]) {
    int kingrow = 0;
    int kingcol = 0;
    int queenrow = 0;
    int queencol = 0;
    int bishoprow = 0;
    int bishopcol = 0;
    int rockrow = 0;
    int rockcol = 0;
    int knightrow = 0;
    int knightcol = 0;
    if (grid[rockrow][rockcol] == grid[kingrow][kingcol] ||
        grid[rockrow][rockcol] == grid[queenrow][queencol] ||
        grid[rockrow][rockcol] == grid[bishoprow][bishopcol] ||
        grid[rockrow][rockcol] == grid[knightrow][knightcol]) {
        rockrow = rand() % 8;
        rockcol = rand() % 8;

    }
    else {
        cout << "" << endl;
    }
}//validating for knight
void VALIDATIONFORRANDOMIZATIONOFKNIGHT(char grid[][8]) {
    int kingrow = 0;
    int kingcol = 0;
    int queenrow = 0;
    int queencol = 0;
    int bishoprow = 0;
    int bishopcol = 0;
    int rockrow = 0;
    int rockcol = 0;
    int knightrow = 0;
    int knightcol = 0;
    if (grid[knightrow][knightcol] == grid[kingrow][kingcol] ||
        grid[knightrow][knightcol] == grid[queenrow][queencol] ||
        grid[knightrow][knightcol] == grid[rockrow][rockcol] ||
        grid[knightrow][knightcol] == grid[bishoprow][bishopcol]) {
        knightrow = rand() % 8;
        knightcol = rand() % 8;


    }
}//function definition:
void VALIDATIONFORKINGOUTOFRANGE(char grid[][8]) {
    int kingrow = 0;
    int kingcol = 0;
    int rockcol = 0;
    int rockrow = 0;
    int bishopRow = 0;
    int bishopCol = 0;
    int queenRow = 0;
    int queenCol = 0;
    int knightRow = 0;
    int knightCol = 0;
    if ((kingcol == rockcol || kingrow == rockrow) || (abs(kingrow - bishopRow) == abs(kingcol - bishopCol)) || (queenRow == kingrow || queenCol == kingcol || abs(queenRow - kingrow) == abs(queenCol - kingcol))|| ((kingrow == knightRow + 1 || kingrow == knightRow - 1) && (kingcol == knightCol + 2 || kingcol == knightCol - 2)) || ((kingrow == knightRow + 2 || kingrow == knightRow - 2) && (kingcol == knightCol + 1 || kingcol == knightCol - 1))){
        kingrow = rand() % 8;
        kingcol = rand() % 8;
    }
}
//for movement of king
void moveKing(char grid[][8]) {
    int kingRow = 0;
    int kingCol = 0;
    int movedRow = 0;
    int movedCol = 0;
    cout << "****************************************" << endl;
    cout << "ENTER THE CURRENT POSITION OF YOUR KING:" << endl;
    cout << "****************************************" << endl;
    do {//using do while loop for validation 
        cout << "**ENTER ROW:**" << endl;
        cin >> kingRow;
        cout << "**ENTER COLOUMN**" << endl;
        cin >> kingCol;
    } while ((kingRow > 7 || kingRow < 0) && (kingCol > 7 || kingCol < 0));
    // checking if the king is there
    if (grid[kingRow][kingCol] != 'K') {
        cout << "OOPS!" << endl;
        cout << "**THERE IS NO KING AT THIS POSITION**" << endl;
        return;
    }//using while loop for the validation:
    int valid_movement = false;
    while (!valid_movement) {
        cout << "********************************************" << endl;
        cout << "**WHERE WOULD YOU LIKE TO MOVE YOUR KING?**" << endl;
        cout << "***********************************************" << endl;
        do {
            cout << "**ENTER THE ROW**" << endl;
            cin >> movedRow;
            cout << "**ENTER THE COLOUMN**" << endl;
            cin >> movedCol;
        } while ((kingRow > 7 || kingRow < 0) && (kingCol > 7 || kingCol < 0));

        if ((movedRow == kingRow + 1 && movedCol == kingCol + 1) || (movedRow == kingRow + 1 && movedCol == kingCol - 1) || (movedRow == kingRow - 1 && movedCol == kingCol + 1) || (movedRow == kingRow - 1 && movedCol == kingCol - 1) || (movedRow == kingRow + 1 && movedCol == kingCol) || (movedRow == kingRow - 1 && movedCol == kingCol) || (movedRow == kingRow && movedCol == kingCol + 1) || (movedRow == kingRow && movedCol == kingCol - 1)) {
            cout << "*********************" << endl;
            cout << "**THE MOVE IS VALID**" << endl;
            cout << "************************" << endl;
            grid[kingRow][kingCol] = '*';
            grid[movedRow][movedCol] = 'K';
            displayArray(grid);
            valid_movement = true;
        }
        else {
            cout << "OOPS" << endl;
            cout << "THE MOVE IS INVALID" << endl;
            valid_movement = false;

        }
    }
}
//for movement of queen
void moveQueen(char grid[][8]) {
    int queenRow = 0;
    int queenCol = 0;
    int movedRow = 0;
    int movedCol = 0;
    cout << "********************************************" << endl;
    cout << "*****WHERE IS YOUR QUEEN CURRENTLY**********" << endl;
    cout << "********************************************" << endl;
    do {
        cout << "ENTER THE ROW: ";
        cin >> queenRow;
        cout << "ENTER THE COLOUMN: ";
        cin >> queenCol;
    } while ((queenRow > 7 || queenRow < 0) && (queenCol > 7 || queenCol < 0));
    // checking if the queen is there
    if (grid[queenRow][queenCol] != 'Q') {
        cout << "THERE IS NO QUEEN AT THIS POSITION:" << endl;
        return;
    }
    //using while loop for validation
    int valid_movement = false;
    while (!valid_movement) {
        cout << "********************************************" << endl;
        cout << "**WHERE WOULD YOU LIKE TO MOVE YOUR QUEEN?****" << endl;
        cout << "********************************************" << endl;
        do {
            cout << "ENTER THE ROW: ";
            cin >> movedRow;
            cout << "ENTER THE COLOUMN:";
            cin >> movedCol;
        } while ((queenRow > 7 || queenRow < 0) && (queenCol > 7 || queenCol < 0));

        // Check if the move is valid for a queen
        if (queenRow == movedRow || queenCol == movedCol ||
            abs(queenRow - movedRow) == abs(queenCol - movedCol)) {
            // The move is valid for a queen
            cout << "THE MOVE IS VALID" << endl;
            grid[queenRow][queenCol] = '*';
            grid[movedRow][movedCol] = 'Q';
            displayArray(grid);
            valid_movement = true;
        }
        else {
            // The move is not valid for a queen
            cout << "OOPS INVALID MOVE:" << endl;
            valid_movement = false;
        }
    }
}
//for movement of bishop
void moveBishop(char grid[][8]) {
    int bishopRow = 0;
    int bishopCol = 0;
    int movedRow = 0;
    int movedCol = 0;
    cout << "********************************************" << endl;
    cout << "******WHERE IS YOUR BISHOP CURRENTLY?*******" << endl;
    cout << "********************************************" << endl;
    do {
        cout << "ENTER THE ROW: ";
        cin >> bishopRow;
        cout << "ENTER THE COLOUMN:";
        cin >> bishopCol;
    } while ((bishopRow > 7 || bishopRow < 0) && (bishopCol > 7 || bishopCol < 0));
    // checking if the bishop is there
    if (grid[bishopRow][bishopCol] != 'B') {
        cout << "THERE IS NO BISHOP AT THIS POSITION:" << endl;
        return;
    }
    int valid_movement = false;
    while (!valid_movement) {
        cout << "********************************************" << endl;
        cout << "***WHERE WOULD YOU LIKE TO MOVE YOUR BISHOP*" << endl;
        cout << "********************************************" << endl;
        do {
            cout << "Enter the row: ";
            cin >> movedRow;
            cout << "Enter the column: ";
            cin >> movedCol;
        } while ((bishopRow > 7 || bishopRow < 0) && (bishopCol > 7 || bishopCol < 0));

        // Check if the move is valid for a bishop
        if (abs(movedRow - bishopRow) == abs(movedCol - bishopCol)) {
            // The move is valid for a bishop
            cout << "THE MOVE IS VALID" << endl;
            grid[bishopRow][bishopCol] = '*';
            grid[movedRow][movedCol] = 'B';
            displayArray(grid);
            valid_movement = true;
        }
        else {
            // The move is not valid for a bishop
            cout << "THE MOVE IS INVALID" << endl;
            valid_movement = false;
        }
    }
}
//function for moverock 
void moveRock(char grid[][8]) {
    int rockRow = 0;
    int rockCol = 0;
    int movedRow = 0;
    int movedCol = 0;
    cout << "********************************************" << endl;
    cout << "****WHERE YOUR ROCK IS CURRECTLY************" << endl;
    cout << "********************************************" << endl;
    do {
        cout << "ENTER THE ROW:" << endl;
        cin >> rockRow;
        cout << "ENTER THE COLOUMN:" << endl;
        cin >> rockCol;
    } while ((rockRow > 7 || rockRow < 0) && (rockCol > 7 || rockCol < 0));
    // checking if the rock is there
    if (grid[rockRow][rockCol] != 'R') {
        cout << "THERE IS NO ROCK AT THIS POSITION:" << endl;
        return;
    }
    int valid_movement = false;
    while (!valid_movement) {
        cout << "********************************************" << endl;
        cout << "**WHERE YOU WOULD LIKE TO MOVE YOUR ROCK?***" << endl;
        cout << "********************************************" << endl;
        do {
            cout << "ENTER THE ROW:" << endl;
            cin >> movedRow;
            cout << "ENTER THE COLOUMN:" << endl;
            cin >> movedCol;
        } while ((rockRow > 7 || rockRow < 0) && (rockCol > 7 || rockCol < 0));

        if ((movedRow == rockRow && movedCol != rockCol) || (movedRow != rockRow && movedCol == rockCol)) {
            cout << "THE MOVE IS VALID" << endl;
            grid[rockRow][rockCol] = '*';
            grid[movedRow][movedCol] = 'R';
            displayArray(grid);
            valid_movement = true;
        }
        else {
            cout << "Invalid move" << endl;
            valid_movement = false;
        }
    }
}
void moveKnight(char grid[][8]) {
    int knightRow = 0;
    int knightCol = 0;
    int movedRow = 0;
    int movedCol = 0;
    cout << "********************************************" << endl;
    cout << "*****WHERE IS YOUR KNIGHT CURRENTLY*********" << endl;
    cout << "********************************************" << endl;
    do {
        cout << "ENTER THE ROW:" << endl;
        cin >> knightRow;
        cout << "ENTER COLOUMN;" << endl;
        cin >> knightCol;
    } while ((knightRow > 7 || knightRow < 0) && (knightCol > 7 || knightCol < 0));
    // checking if the knight is there
    if (grid[knightRow][knightCol] != 'N') {
        cout << "THERE IS NO KNIGHT ON THIS POSITION:" << endl;
        return;
    }
    int valid_movement = false;
    while (!valid_movement) {
        cout << "********************************************" << endl;
        cout << "WHERE WOULD YOU LIKE TO MOVE YOUR KNIGHT??***" << endl;
        cout << "********************************************" << endl;
        do {
            cout << "ENTER THE ROW:" << endl;
            cin >> movedRow;
            cout << "ENTER THE COLOUMN:" << endl;
            cin >> movedCol;
        } while ((knightRow > 7 || knightRow < 0) && (knightCol > 7 || knightCol < 0));

        if (((movedRow == knightRow + 1 || movedRow == knightRow - 1) && (movedCol == knightCol + 2 || movedCol == knightCol - 2)) || ((movedRow == knightRow + 2 || movedRow == knightRow - 2) && (movedCol == knightCol + 1 || movedCol == knightCol - 1))) {
            // knight can move two squares vertically and one square horizontally
            // or two squares horizontally and one square vertically
            cout << "THE MOVE IS VALID" << endl;
            grid[knightRow][knightCol] = '*';
            grid[movedRow][movedCol] = 'N';
            displayArray(grid);
            valid_movement = true;
        }
        else cout << "THE MOVE IS INVALID" << endl;
        valid_movement = false;
    }
}
//make another function for the save the king 
void gamestarts(char grid[][8]) {
    int user;
    cout << setw(80) << "***********************************************" << endl;
    cout << setw(80) << "***********************************************" << endl;
    cout << setw(80) << "********THE GAME IS GONNA  START NOW*********** " << endl;
    cout << setw(80) << "***********************************************" << endl;
    cout << setw(80) << "***********************************************" << endl;
    //calling the function of display grid
    displayArray(grid);
    do {
        cout << "********************************************" << endl;
        cout << "ENTER IF YOU ARE PLAYER 1 OR PLAYER 2?" << endl;
        cout << "********************************************" << endl;
        cout << "ENTER 1 OR 2:" << endl;
        cout << "********************************************" << endl;
        cout << "ENTER 0 IF YOU WANT TO FINISH" << endl;
        cout << "********************************************" << endl;
        cin >> user;
        if (user == 1) {
            player1(grid);
        }
        else if (user == 2) {
            player2(grid);
        }
    } while (user != 0);

    endthegame(grid);
}
void player1(char grid[][8]) {
    int playerselection;
    cout << "********************************************" << endl;
    cout << "NOW YOU ARE THE PLAYER 1 " << endl;
    cout << "YOU HAVE TO SAVE THE KING!" << endl;
    cout << "********************************************" << endl;
    //calling the function of move king
    moveKing(grid);
    cout << "********************************************" << endl;
    cout << "PRESS 2 IF YOU WANT TO SWITCH TO PLAYER 2" << endl;
    cout << "AND PRESSS 0 IF YOU WANT TO BE STILL PLAYER 1 " << endl;
    cout << "********************************************" << endl;
    cin >> playerselection;
    switch (playerselection) {
    case 2:
        player2(grid);
        break;
    case 0:
        player1(grid);
        break;
    }

}
void player2(char grid[][8]) {
    int attackselection;
    cout << "********************************************" << endl;
    cout << "NOW YOU ARE THE PLAYER 2" << endl;
    cout << "YOU HAVE TO ATTACK THE KING !" << endl;
    cout << "********************************************" << endl;
    //calling all other functions:
    do {
        cout << "WHICH PIECE WOULD YOU CHOOSE FOR ATTACKING THE KING?" << endl;
        cout << "1**************QUEEN" << endl;
        cout << "2****************BISHOP" << endl;
        cout << "3*****************ROCK" << endl;
        cout << "4*******************KNIGHT" << endl;
        cout << "IF YOU WANT TO SWITCH TO PLAYER 1 AGAIN PRESS 9" << endl;
        cout << "********************************************" << endl;
        cin >> attackselection;
        switch (attackselection) {
        case 1:
            moveQueen(grid);
            CHECKFORCHECKMATEOFQUEEN(grid);
            break;
        case 2:
            moveBishop(grid);
            CHECKFORCHECKMATEOFBISHOP(grid);
            break;
        case 3:
            moveRock(grid);
            CHECKFORCHECKMATEOFROCK(grid);
            break;
        case 4:
            moveKnight(grid);
            CHECKFORCHECKMATEOFKNIGHT(grid);
            break;
        }
    } while (attackselection != 9);
    //calling the function of player 1 
    player1(grid);

}
void CHECKFORCHECKMATEOFQUEEN(char grid[][8]) {
    int queenRow = 0;
    int queenCol = 0;
    int kingrow = 0;
    int kingcol = 0;
    if ((queenRow == kingrow || queenCol == kingcol ||
        abs(queenRow - kingrow) == abs(queenCol - kingcol))) {
        cout << "********************************************" << endl;
        cout << "YOU KING HAS BEEN TRAPED" << endl;
        cout << "CHECKMATE" << endl;
        cout << "********************************************" << endl;
        endthegame(grid);
    }
    else {
        //calling player 1
        player1(grid);
    }
}
void CHECKFORCHECKMATEOFBISHOP(char grid[][8]) {
    int bishopRow = 0;
    int bishopCol = 0;
    int kingrow = 0;
    int kingcol = 0;
    if (abs(kingrow - bishopRow) == abs(kingcol - bishopCol)) {
        cout << "********************************************" << endl;
        cout << "YOU KING HAS BEEN TRAPED" << endl;
        cout << "CHECKMATE" << endl;
        cout << "********************************************" << endl;
        endthegame(grid);
    }
    else {
        //calling player 1
        player1(grid);
    }
}
void CHECKFORCHECKMATEOFROCK(char grid[][8]) {
    int kingrow = 0;
    int kingcol = 0;
    int rockcol = 0;
    int rockrow = 0;
    if (kingcol == rockcol || kingrow == rockrow) {
        cout << "********************************************" << endl;
        cout << "YOU KING HAS BEEN TRAPED" << endl;
        cout << "CHECKMATE" << endl;
        cout << "********************************************" << endl;
        endthegame(grid);
    }
    else {
        //calling player 1
        player1(grid);
    }
}
void CHECKFORCHECKMATEOFKNIGHT(char grid[][8]) {
    int kingrow = 0;
    int kingcol = 0;
    int knightRow = 0;
    int knightCol = 0;
    if (((kingrow == knightRow + 1 || kingrow == knightRow - 1) && (kingcol == knightCol + 2 || kingcol == knightCol - 2)) || ((kingrow == knightRow + 2 || kingrow == knightRow - 2) && (kingcol == knightCol + 1 || kingcol == knightCol - 1))) {
        cout << "********************************************" << endl;
        cout << "YOU KING HAS BEEN TRAPED" << endl;
        cout << "CHECKMATE" << endl;
        cout << "********************************************" << endl;
        endthegame(grid);
    }
    else {
        //calling player 1
        player1(grid);
    }

}
void endthegame(char grid[][8]) {
    cout << "********************************************" << endl;
    cout << "YOU HAVE SELECTED TO END THE GAME!" << endl;
    cout << "GAME ENDED" << endl;
    cout << "********************************************" << endl;
}