//Nathalie Ng
//nng01@uoguelph.com
//March 29th, 2018
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

int isInputValid(int entered, int minimum, int maximum);
int isBoardFull(char currentBoard[N][N]);
void createInitialBoard(char initialBoard[N][N]);
void readUserMove(int * userRow, int * userCol, int * steps);
void printCurrentBoard(char currentBoard[N][N]);
int  getComputerMove(char board[N][N], int * computerRow, int * computerCol, int userRow, int userCol);
int gameWon(char board[N][N], char symbol);
int computerPlaysToWin(char board[N][N], int* cRow, int* cCol);
int computerPlaysToBlock(char board[N][N], int* cRow, int* cCol);
void computerPlaysNotSoRandom(int* cRow, int* cCol, int uRow, int uCol);
void sumAllDimensions(char board[N][N], int sumR[], int sumC[], int* sumLD, int* sumRD);
int isMember(int aNum, int someArray[N]);

int main(){

   int userRow, userCol, computerRow, computerCol;
   int taken;
   int stepsWon = 0;
   char board[N][N];
   char winner = 'N';

   printf("This tic-tac-toe board is of size %d by %d\n", N, N);

   printf("Player symbol: X \n Computer symbol: O\n\n");

   printf("Here is the board - spaces are indicated by a ?\n");

   createInitialBoard(board);

   while ((winner != 'Y') && !(isBoardFull(board))) // while there is no winner and the board is not full
   {
	   taken = 0;

		while (!(taken))                  // loop used to accept valid row and col values from the user
		{
			readUserMove(&userRow, &userCol, &stepsWon);                  //get user's move
			printf("You chose row %d and column %d \n", userRow, userCol);

			while (!isInputValid(userRow, 1, N) || !isInputValid(userCol, 1, N))     // validate user's move
			{
				printf("That's is an invalid row or column number - try again\n");
				readUserMove(&userRow, &userCol, &stepsWon);
				printf("You chose row %d and column %d \n", userRow, userCol);
			}


			if (board[userRow-1][userCol-1] == '?')           // if cell is unoccupied
			{
				board[userRow-1][userCol-1] = 'X';			// store an X there
				taken = 1;
			}
			else
			{
				taken = 0;									// otherwise inform the user to enter values again
				printf("That spot is taken - please try another one\n");
			}

		} //end of while (!taken)

	   if (gameWon(board, 'X'))   // check if the user wins - game will end if the user does win
	   {
		   printf("Congrats - you won against the computer :) in %d steps\n", stepsWon);
		   winner = 'Y';
	   }

	   else  if (!(isBoardFull(board)))            //check if the board is already full
	   {
		   taken = 0;

		   while (!(taken))
		   {
				getComputerMove(board, &computerRow, &computerCol, userRow-1, userCol-1); // get computer's row and col

				if (board[computerRow][computerCol] == '?')         // check if the cell is unoccupied
				{
					board[computerRow][computerCol] = 'O';
					taken = 1;

				}
				else
				{
					taken = 0;		//That spot is taken - computer - try another one
				}
		   }

		   printf("Computer chose row %d and column %d \n", computerRow+1, computerCol+1);

		   if (gameWon(board, 'O'))               // check if the computer wins - game must end if it does
		   {
			   printf("Oh the computer won this time :(( think hard next time\n");
			   winner = 'Y';
		   }
	   }

	printCurrentBoard(board);

	printf("\nPress enter to continue \n");
	getchar();

   } //end of while
   if (winner != 'Y')
			printf("Game was a tie - no winner!\n\n");

   return 0;
}

int  getComputerMove(char board[N][N], int * computerRow, int * computerCol, int userRow, int userCol){
    /*
      This function gathers the computer's move in terms of row (computerRow) and column (computerCol)
      and outputs them to main. The computer first tries to find a winning spot for itself; if it doesn't
      find one, then it calls function computerPlaysNotSoRandom in its attempt to place its symbol in
      the same row or column as the user (userRow, userCol)
    */
   int winningSpot = 0;
   int blocked = 1;

   winningSpot = computerPlaysToWin(board, computerRow, computerCol);

   if (!winningSpot) //if computer does find a winning spot, then it plays to block the user
   {
	   computerPlaysNotSoRandom(computerRow, computerCol, userRow, userCol);

	  blocked = computerPlaysToBlock(board, computerRow, computerCol);
	   if (blocked == 0)
		   computerPlaysNotSoRandom(computerRow, computerCol, userRow, userCol);
   }

   return winningSpot;
}

void readUserMove(int * userRow, int * userCol, int * steps){
    /*
      This function prompts the user to input values to place symbol X on the board
      It also calculates the number of times the user enters such values
    */
   printf("Your move - enter numbers between 1 and %d \n\n", N);

   printf("Enter row number: ");
   scanf("%d", userRow);

   printf("Enter column number: ");
   scanf("%d", userCol);

   *steps = *steps  + 1;
}

void createInitialBoard(char initialBoard[N][N]){
    //function to create initial board
    initialBoard[0][0] = '?';
    initialBoard[1][0] = '?';
    initialBoard[2][0] = '?';
    initialBoard[0][1] = '?';
    initialBoard[1][1] = '?';
    initialBoard[2][1] = '?';
    initialBoard[0][2] = '?';
    initialBoard[1][2] = '?';
    initialBoard[2][2] = '?';
    printf("%c | %c | %c\n", initialBoard[0][0], initialBoard[0][1],initialBoard[0][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", initialBoard[1][0], initialBoard[1][1],initialBoard[1][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", initialBoard[2][0], initialBoard[2][1],initialBoard[2][2]);
}

void printCurrentBoard(char currentBoard[N][N]){
    //function displays current board after changes have been made
    printf("%c | %c | %c\n", currentBoard[0][0], currentBoard[0][1], currentBoard[0][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", currentBoard[1][0], currentBoard[1][1],currentBoard[1][2]);
    printf("----------\n");
    printf("%c | %c | %c\n", currentBoard[2][0], currentBoard[2][1],currentBoard[2][2]);
}

int isBoardFull(char currentBoard[N][N]){
    //function determines if the game is done by checking if the board is full
    int fullReturn=0;
    int full=0;
    /*
    the entire board has 9 spots, this loop will add to variable full if the cell
    is occupied by O or X to determine how many spots are taken.
    if full=9, then the board is full
    */
    for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(currentBoard[i][j]=='O' || currentBoard[i][j]=='X'){
                    full=full+1;
                }
            }
    }
    if(full==9){
        fullReturn = 1;
    }
    else{
        fullReturn = 0;
    }
    return fullReturn;
}

int isInputValid(int entered, int minimum, int maximum){
    //function will determine if user's input is a valid cell on board
    int returnValue=0;
    minimum = 1;
    maximum = 3;
    //board is 3 by 3 so entered value must be between 1 and 3
    if(entered >=1 && entered <=3){
        returnValue = 1;
    }
    return returnValue;
}

int gameWon(char board[N][N], char symbol){
    //function will determine if there is a winner
    int sumRow1 = 0;
    int sumRow2 = 0;
    int sumRow3 = 0;
    int sumCol1 = 0;
    int sumCol2 = 0;
    int sumCol3 = 0;
    int sumDiag1 = 0;
    int sumDiag2 = 0;
    int returnVal = 0;
    //If the symbol is X, then it will add how many X's there are.
    if(symbol == 'X'){
        for(int i=0; i<3; i++){
            if(board[0][i] == 'X'){
                sumRow1 = sumRow1 + 1;
            }
            if(board[1][i] == 'X'){
                sumRow2 = sumRow2 + 1;
            }
            if(board[2][i] == 'X'){
                sumRow3 = sumRow3 + 1;
            }
        }
        for(int j=0; j<3; j++){
            if(board[j][0] == 'X'){
                sumCol1 = sumCol1 + 1;
            }
            if(board[j][1] == 'X'){
                sumCol2 = sumCol2 + 1;
            }
            if(board[j][2] == 'X'){
                sumCol3 = sumCol3 + 1;
            }
        }
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
            sumDiag1 = 3;
        }
        if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
            sumDiag2 = 3;
        }
        if(sumRow1 == 3 || sumRow2 == 3 || sumRow3 == 3 || sumCol1 == 3 || sumCol2 == 3 || sumCol3 == 3 || sumDiag2 ==3 || sumDiag1 ==3){
            returnVal= 1;
        }
    }
    //If symbol is O, then it will determine the sum of O's here.
    if(symbol == 'O'){
        for(int a=0; a<3; a++){
            //determine sum of rows
            if(board[0][a] == 'O'){
                sumRow1 = sumRow1 + 4;
            }
            if(board[1][a] == 'O'){
                sumRow2 = sumRow2 + 4;
            }
            if(board[2][a] == 'O'){
                sumRow3 = sumRow3 + 4;
            }
        }
        for(int b=0; b<3; b++){
            //determine sum of columns
            if(board[b][0] == 'O'){
                sumCol1 = sumCol1 + 4;
            }
            if(board[b][1] == 'O'){
                sumCol2 = sumCol2 + 4;
            }
            if(board[b][2] == 'O'){
                sumCol3 = sumCol3 + 4;
            }
        }
        //next 2 if statements will determine sum of left diagonal and right diagonal.
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
            sumDiag1 = 12;
        }
        if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
            sumDiag2 = 12;
        }
        if(sumRow1 == 12 || sumRow2 == 12 || sumRow3 == 12 || sumCol1 == 12 || sumCol2 == 12 || sumCol3 == 12 || sumDiag2 == 12 || sumDiag1 == 12){
            returnVal = 1;
        }
    }
    return returnVal;
}

void computerPlaysNotSoRandom(int* cRow, int* cCol, int uRow, int uCol){
    //function will determine computer move based on previous user move
    int userInput=1;
    int randRow=0;
    int randCol=0;
    int randDiag=0;
    int decide=0;
    //randomly generate numbers for row, column, diagonal, and decision of whether to place in same row, col or diagonal.
    randRow = rand()%2;
    randCol = rand()%2;
    randDiag = rand()%2;
    decide = rand()%2;
    //if decide is 0, it will use row, if decide is 1, it will use col and if decide is 3 it will use diagonal
    if(decide ==0){
        *cRow = uRow;
        *cCol = randCol;
        userInput=0;
    }
    if(decide ==1){
        *cCol = uCol;
        *cRow = randRow;
        userInput=0;
    }
    if(decide==2){
        *cCol = randDiag;
        *cRow = randDiag;
        userInput=0;
    }
}

int isMember(int aNum, int someArray[]){
    //this function will determine if a value is present in the array
    int inArray = 0;

    for(int i=0; i<N; i++){
        if(aNum == someArray[i]){
            inArray = 1;
        }
    }
    return inArray;
}

void sumAllDimensions(char board[N][N], int sumR[], int sumC[], int* sumLD, int* sumRD){
    //this function determines the sum of every row, column and diagonal, given X=1 and O=4
    //loop to add for each row
    for(int i=0; i<3; i++){
        if(board[0][i] == 'X'){
            sumR[0] = sumR[0] + 1;
        }
        if(board[1][i] == 'X'){
            sumR[1] = sumR[1] + 1;
        }
        if(board[2][i] == 'X'){
            sumR[2] = sumR[2] + 1;
        }
        if(board[0][i] == 'O'){
            sumR[0] = sumR[0] + 4;
        }
        if(board[1][i] == 'O'){
            sumR[1] = sumR[1] + 4;
        }
        if(board[2][i] == 'O'){
            sumR[2] = sumR[2] + 4;
        }
    }
    //loop to add each column sum
    for(int j=0; j<3; j++){
        if(board[j][0] == 'X'){
            sumC[0] = sumC[0] + 1;
        }
        if(board[j][1] == 'X'){
            sumC[1] = sumC[1] + 1;
        }
        if(board[j][2] == 'X'){
            sumC[2] = sumC[2] + 1;
        }
        if(board[j][0] == 'O'){
            sumC[0] = sumC[0] + 4;
        }
        if(board[j][1] == 'O'){
            sumC[1] = sumC[1] + 4;
        }
        if(board[j][2] == 'O'){
            sumC[2] = sumC[2] + 4;
        }
    }
    //next 2 if statements will determine sum of right diagonal
    if(board[0][0] == 'X' || board[1][1] == 'X' || board[2][2] == 'X'){
        *sumRD = *sumRD + 1;
    }
    if(board[0][0] == 'O' || board[1][1] == 'O' || board[2][2] == 'O'){
        *sumRD = *sumRD + 4;
    }
    //next 2 if statements will determine sum of left diagonal
    if(board[2][0] == 'O' || board[1][1] == 'O' || board[0][2] == 'O'){
        *sumLD = *sumLD + 4;
    }
    if(board[2][0] == 'X' || board[1][1] == 'X' || board[0][2] == 'X'){
        *sumLD = *sumLD + 1;
    }

}
int computerPlaysToWin(char board[N][N], int* cRow, int* cCol){
    //this function determines if the computer is able to win in the next move, and will place next move in the cell that will win
    int sumRow=0;
    int sumRow2=0;
    int sumRow3=0;
    int sumCol=0;
    int sumCol2=0;
    int sumCol3=0;
    int leftDiag=0;
    int rightDiag=0;
    int returnVal=0;
    int userInput=1;

    //check row 1
    while(userInput==1){
        //this for loop determines the sum of row
        for(int a=0; a<3; a++){
            if(board[0][a]=='O'){
                sumRow = sumRow + 4;
            }
        }
        if(sumRow == 8){
            //if the sum equals to 8, this will run and replace an empty cell in the same row to win
            for(int b=0; b<3; b++){
                if(board[0][b]=='?'){
                    *cRow = 0;
                    *cCol = b;
                    returnVal=1;
                    userInput=0; //will stop loop, and will not start any other while loop
                }
            }
        }
        else{
            userInput=2; //will allow next while loop to begin
        }
    }
    //check row 2
    while(userInput==2){
        for(int c=0; c<3; c++){
            if(board[1][c]=='O'){
                sumRow2 = sumRow2 + 4;
            }
        }
        if(sumRow2 == 8){
            for(int d=0; d<3; d++){
                if(board[1][d]=='?'){
                    *cRow = 1;
                    *cCol = d;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=3;
        }
    }
    //check row 3
    while(userInput==3){
        for(int e=0; e<3; e++){
            if(board[2][e]=='O'){
                sumRow3 = sumRow3 + 4;
            }
        }
        if(sumRow3 == 8){
            for(int f=0; f<3; f++){
                if(board[2][f]=='?'){
                    *cRow = 2;
                    *cCol = f;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=4;
        }
    }
    //check col1
    while(userInput==4){
        for(int g=0; g<3; g++){
            if(board[g][0]=='O'){
                sumCol = sumCol + 4;
            }
        }
        if(sumCol == 8){
            for(int h=0; h<3; h++){
                if(board[h][0]=='?'){
                    *cRow = h;
                    *cCol = 0;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=5;
        }
    }
    //check col2
    while(userInput==5){
        for(int i=0; i<3; i++){
            if(board[i][1]=='O'){
                sumCol2 = sumCol2 + 4;
            }
        }
        if(sumCol2 == 8){
            for(int j=0; j<3; j++){
                if(board[j][1]=='?'){
                    *cRow = j;
                    *cCol = 1;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=6;
        }
    }
    //check col3
    while(userInput==6){
        for(int k=0; k<3; k++){
            if(board[k][2]=='O'){
                sumCol3 = sumCol3 + 4;
            }
        }
        if(sumCol3 == 8){
            for(int l=0; l<3; l++){
                if(board[l][2]=='?'){
                    *cRow = l;
                    *cCol = 2;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=7;
        }
    }
    //check rightdiagonal
    while(userInput==7){
        for(int m=0; m<3; m++){
            if(board[m][m]=='O'){
                rightDiag = rightDiag + 4;
            }
        }
        if(rightDiag == 8){
            for(int n=0; n<3; n++){
                if(board[n][n]=='?'){
                    *cRow = n;
                    *cCol = n;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=8;
        }
    }
    //check leftdiagonal
    while(userInput==8){
            if(board[2][0]=='O'){
                leftDiag = leftDiag + 4;
            }
            if(board[1][1]=='O'){
                leftDiag = leftDiag + 4;
            }
            if(board[0][2]=='O'){
                leftDiag = leftDiag + 4;
            }
        if(leftDiag == 8){
            if(board[2][0]=='?'){
                *cRow = 2;
                *cCol = 0;
                returnVal=1;
                userInput=0;
            }
            if(board[1][1]=='?'){
                *cRow = 1;
                *cCol = 1;
                returnVal=1;
                userInput=0;
            }
            if(board[0][2]=='?'){
                *cRow = 0;
                *cCol = 2;
                returnVal=1;
                userInput=0;
            }
        }
        else{
            userInput=9;
        }
    }
    return returnVal;
}
int computerPlaysToBlock(char board[N][N], int* cRow, int* cCol){
    //this determines the computer's next move to block the user from winning, if the computer is unable to win in this move
    int sumRow=0;
    int sumRow2=0;
    int sumRow3=0;
    int sumCol=0;
    int sumCol2=0;
    int sumCol3=0;
    int leftDiag=0;
    int rightDiag=0;
    int returnVal=0;
    int userInput=1;
    //check row 1
    while(userInput==1){
        //loop to determine the sum of the row for X's
        for(int a=0; a<3; a++){
            if(board[0][a]=='X'){
                sumRow = sumRow + 1;
            }
        }
        if(sumRow == 2){
            //if the sum is 2, then it will find an empty cell to replace
            for(int b=0; b<3; b++){
                if(board[0][b]=='?'){
                    *cRow = 0;
                    *cCol = b;
                    returnVal=1;
                    userInput=0; //stop the loop, and will not start any other while loop
                }
            }
        }
        else{
            userInput=2; //will propmt next while loop to begin if no spot is available.
        }
    }
    //check row 2
    while(userInput==2){
        for(int c=0; c<3; c++){
            if(board[1][c]=='X'){
                sumRow2 = sumRow2 + 1;
            }
        }
        if(sumRow2 == 2){
            for(int d=0; d<3; d++){
                if(board[1][d]=='?'){
                    *cRow = 1;
                    *cCol = d;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=3;
        }
    }
    //check row 3
    while(userInput==3){
        for(int e=0; e<3; e++){
            if(board[2][e]=='X'){
                sumRow3 = sumRow3 + 1;
            }
        }
        if(sumRow3 == 2){
            for(int f=0; f<3; f++){
                if(board[2][f]=='?'){
                    *cRow = 2;
                    *cCol = f;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=4;
        }
    }
    //check column 1
    while(userInput==4){
        for(int g=0; g<3; g++){
            if(board[g][0]=='X'){
                sumCol = sumCol + 1;
            }
        }
        if(sumCol == 2){
            for(int h=0; h<3; h++){
                if(board[h][0]=='?'){
                    *cRow = h;
                    *cCol = 0;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=5;
        }
    }
    //check column 2
    while(userInput==5){
        for(int i=0; i<3; i++){
            if(board[i][1]=='X'){
                sumCol2 = sumCol2 + 1;
            }
        }
        if(sumCol2 == 2){
            for(int j=0; j<3; j++){
                if(board[j][1]=='?'){
                    *cRow = j;
                    *cCol = 1;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=6;
        }
    }
    //check column 3
    while(userInput==6){
        for(int k=0; k<3; k++){
            if(board[k][2]=='X'){
                sumCol3 = sumCol3 + 1;
            }
        }
        if(sumCol3 == 2){
            for(int l=0; l<3; l++){
                if(board[l][2]=='?'){
                    *cRow = l;
                    *cCol = 2;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=7;
        }
    }
    //check rightdiagonal
    while(userInput==7){
        for(int m=0; m<3; m++){
            if(board[m][m]=='X'){
                rightDiag = rightDiag + 1;
            }
        }
        if(rightDiag == 2){
            for(int n=0; n<3; n++){
                if(board[n][n]=='?'){
                    *cRow = n;
                    *cCol = n;
                    returnVal=1;
                    userInput=0;
                }
            }
        }
        else{
            userInput=8;
        }
    }
    //check leftdiagonal
    while(userInput==8){
            if(board[2][0]=='X'){
                leftDiag = leftDiag + 1;
            }
            if(board[1][1]=='X'){
                leftDiag = leftDiag + 1;
            }
            if(board[0][2]=='X'){
                leftDiag = leftDiag + 1;
            }
        if(leftDiag == 2){
            if(board[2][0]=='?'){
                *cRow = 2;
                *cCol = 0;
                returnVal=1;
                userInput=0;
            }
            if(board[1][1]=='?'){
                *cRow = 1;
                *cCol = 1;
                returnVal=1;
                userInput=0;
            }
            if(board[0][2]=='?'){
                *cRow = 0;
                *cCol = 2;
                returnVal=1;
                userInput=0;
            }
        }
        else{
            userInput=9;
        }
    }
    return returnVal;

}
