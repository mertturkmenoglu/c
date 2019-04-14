/*Random knight moves*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

/*Function prototype*/
void draw(int [][SIZE]);

/*Main function starts*/
int main(){
	
	/*Random function seeds*/
	srand( time(NULL) );
	
	/*Variable declarations*/
	static int board[SIZE][SIZE];
	int moves[8][2]=
	{
		{-2,-1},
		{-2,1},
		{2,-1},
		{2,1},
		{-1,-2},
		{-1,2},
		{1,-2},
		{1,2}
	};
	int i, j, xpos, ypos, n, a, xtemp, ytemp, control;
	
	/*Read starting coordinates*/
	do{
		printf("Please enter x position: ");
		scanf("%d", &xpos);
	}while((xpos > SIZE)||(xpos < 0));
	
	do{
		printf("Please enter y position: ");
		scanf("%d", &ypos);
	}while((ypos > SIZE)||(ypos < 0));
	
	
	/*Read n*/
	do{
		printf("Please enter n value: ");
		scanf("%d", &n);
	}while(n <= 0);
	
	/*Shows board*/
	draw(board);
	
	for(i=1; i <= n; i++){
	
		control = 0;
	
		do{
			
			/*Randomly chooses a move*/
			a = rand() % 8;
			xtemp = moves[a][0];
			ytemp = moves[a][1];
			
			/*
			 *Check if movement is valid
			 *If it is a valid move, change coordinates
			 *and show board
			 *else choose another move
			 */
			 
			if((xpos+xtemp >= 0)&&(xpos+xtemp < SIZE)&&(ypos+ytemp >= 0)&&(ypos+ytemp < SIZE)){
				
				/*Change position*/
				xpos += xtemp;
				ypos += ytemp;
				
				/*Show board*/
				board[xpos][ypos] = 1;
				draw(board);
				board[xpos][ypos] = 0;
				
				/*Knight changed position*/
				control = 1;
			}
		}while(control == 0);
	}
	
	/*Indicates successful termination*/
	return 0;
}/*Main function ends*/

/*draw function*/
void draw(int board[][SIZE]){
	
	int i, j;
	
	/*Clear screen*/
	system("clear");
	
	/*Print board*/
	for(i=0; i < SIZE; i++){
		for(j=0; j < SIZE; j++)
			printf("%2d", board[i][j]);
		printf("\n");
	}
	
	
}/*draw function ends*/
