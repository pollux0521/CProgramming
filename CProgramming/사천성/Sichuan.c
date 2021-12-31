#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_X 78      // maximum row value
#define MAX_Y 20      // maximum column value
#define MIN_X 0       // maximum row value
#define MIN_Y 0       // maximum column value

#define M_MAX_Y 3 
static int score = 0;
static int _x;
static int _y;
typedef struct _tile_t{
   int _card;   //카드 모양
   int _x;
   int _y; 
}TILE_T;
void setColor (int fg, int bg)   {
    int	color = bg * 16 + fg;  // bg: 배경색, fg: 글자색
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void print_pan(int x, int y,TILE_T pan[20][30]){
	int i, j;
	for(i=0;i<y+1;i++){
		for(j=0;j<x+1;j++){
			switch(pan[i][j]._card){
				case 0:
					printf(" ");
					break;
				case 1:
					setColor (9,0);
					printf("1");
					break;
				case 2:
					setColor (4,0);
					printf("2");
					break;
				case 3:
					setColor (3,0);
					printf("3");
					break;
				case 4:
					setColor (2,0);
					printf("4");
					break;
				case 5:
					setColor (9,0);
					printf("5");
					break;
				case 6:	
					setColor (4,0);
					printf("6");
					break;
				case 7:
					setColor (3,0);
					printf("A");
					break;
				case 8:
					setColor (2,0);
					printf("B");
					break;
				case 9:
					setColor (9,0);
					printf("C");
					break;
				case 10:
					setColor (4,0);
					printf("D");
					break;
				case 11:
					setColor (3,0);
					printf("E");
					break;
				case 12:
					setColor (2,0);
					printf("F");
					break;
				case 13:
					setColor (9,0);
					printf("G");
					break;
				case 14:
					setColor (4,0);
					printf("H");
					break;
				case 15:
					setColor (3,0);
					printf("I");
					break;
				case 16:
					setColor (2,0);
					printf("J");
					break;
				case 17:
					setColor (9,0);
					printf("K");
					break;
				case 18:
					setColor (4,0);
					printf("L");
					break;
				case 19:
					setColor (3,0);
					printf("M");
					break;
				case 20:
					setColor (2,0);
					printf("N");
					break;					
				case 21:
					setColor (9,0);
					printf("O");
					break;
				case 22:
					setColor (4,0);
					printf("P");
					break;
				case 23:
					setColor (3,0);
					printf("Q");
					break;
				case 24:
					setColor (2,0);
					printf("R");
					break;
				case 25:
					setColor (9,0);
					printf("S");
					break;
				case 26:
					setColor (4,0);
					printf("T");
					break;
				case 27:
					setColor (3,0);
					printf("U");
					break;
				case 28:
					setColor (2,0);
					printf("V");
					break;
				case 29:
					setColor (9,0);
					printf("W");
					break;
				case 30:
					setColor (4,0);
					printf("X");
					break;
				case 31:
					setColor (3,0);
					printf("Y");
					break;
				case 32:
					setColor (2,0);
					printf("Z");
					break;
			}	
		}
		printf("\n");	
	}
	printf("\n\n");
	
	printf("	hint : o      save : s");
}
void set_random_card(int x, int y, TILE_T pan[20][30]){
	int length;
	srand(time(NULL));
	int random_y, random_x, random_card;
	
	for(length=0;length<x*y/2;length++){
		random_card = rand()%32 + 1;
		do {	
			random_y = rand()%y+1;
			random_x = rand()%x+1;
		} while(pan[random_y][random_x]._card != 0);
		pan[random_y][random_x]._card = random_card;
		do {	
			random_y = rand()%y+1;
			random_x = rand()%x+1;
		} while(pan[random_y][random_x]._card != 0);
		pan[random_y][random_x]._card = random_card;
	}	
}
void gotoxy (int x, int y)   {
    COORD   Pos = {x, y};
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), Pos);
}
void delete_two_card(TILE_T pan[20][30], TILE_T* select_card2, TILE_T* select_card1){
	gotoxy(select_card1->_x, select_card1->_y);	
	printf(" ");
	gotoxy(select_card2->_x, select_card2->_y);
	printf(" ");
	pan[select_card1->_y][select_card1->_x]._card = 0;
	pan[select_card2->_y][select_card2->_x]._card = 0;
	score += 10;
}
void movePosition (char key, int *x, int *y, TILE_T pan[][30], TILE_T *select_card1, TILE_T *select_card2){
    switch(key) {
        case 72: // up
           *y -= 1;
            if (*y < MIN_Y) *y = MIN_Y;
            break;
        case 80: // down
           *y += 1;
            if (*y > MAX_Y) *y = MAX_Y;
            break;
        case 75: // left
            *x -= 1;
            if (*x < MIN_X) *x = MIN_X;
            break;
		case 77: // right
            *x += 1;
            if (*x > MAX_X) *x = MAX_X;
            break;
		case 32:   // space bar
    		if(select_card1->_card == 0){
    			select_card1->_card = pan[*y][*x]._card;
    			select_card1->_x = *x;
    			select_card1->_y = *y;
    			break;
			}
			else{
				select_card2->_card = pan[*y][*x]._card;
				select_card2->_x = *x;
				select_card2->_y = *y;
				if(Check_Sellect_Card(select_card1, select_card2, pan) == 1){
					
							delete_two_card(pan, select_card1, select_card2);
							select_card1->_card = 0;
							select_card2->_card = 0;
							
							gotoxy(*x, *y);
							break;				
						}
					
					else{
						select_card1->_card = 0;
						select_card2->_card = 0;
						break;
					}			
				}
			
	    default:
            break;
    }
}

int Check_Sellect_Card(TILE_T *select_card1, TILE_T *select_card2,TILE_T pan[20][30]){      //   선택된 2개의 카드가 없어질수 있는지 확인 
   COORD temp_before, temp_after;
   temp_before.X = select_card1->_x;
   temp_before.Y = select_card1->_y;
   temp_after.X = select_card2->_x;
   temp_after.Y = select_card2->_y;
   if(temp_before.X == temp_after.X && temp_before.Y == temp_after.Y){
      return 0;
   }
   
   if(pan[temp_before.Y][temp_before.X]._card == pan[temp_after.Y][temp_after.X]._card){
       if(No_Corner(temp_before, temp_after,pan) == 1){
          return 1;
       }
       if(One_Corner(temp_before, temp_after,pan) == 1){      //   temp_before < temp_after
          return 1;
       }       
       if(One_Corner(temp_after, temp_before,pan) == 1){      //   temp_before > temp_after
          return 1;
       }if(Two_Corner(temp_before, temp_after,pan) == 1){
          return 1;
       }
   }
   return 0;
}
int Two_Corner(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){
   
   if(Two_Corner_Right(temp_before, temp_after,pan) == 1){
      return 1;
   }
   if(Two_Corner_Left(temp_before, temp_after,pan) == 1){
      return 1;
   }
   if(Two_Corner_Up(temp_before, temp_after,pan) == 1){
      return 1;
   }
   if(Two_Corner_Down(temp_before, temp_after,pan) == 1){
      return 1;
   }
   if(temp_before.X != temp_after.X && temp_before.Y != temp_after.Y){
      if(Two_Corner_Width(temp_before, temp_after,pan) == 1){
         return 1;
      }
      if(Two_Corner_Length(temp_before, temp_after,pan) == 1){
         return 1;
      }
   }
   
   return 0;
}
int Two_Corner_Length(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){
   COORD temp_1, temp_2;
   int i;
   
   if(temp_before.Y <= temp_after.Y){
      for(i=1; ; i++){
         temp_1.X = temp_before.X;
         temp_1.Y = temp_before.Y+i;
         
         temp_2.X = temp_after.X;
         temp_2.Y = temp_before.Y+i;
         
         if(temp_1.Y > temp_after.Y){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card== 0){
            if(No_Corner(temp_before, temp_1,pan) == 1 && No_Corner(temp_after, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }else{      //   temp_before.X > temp_after.X
      for(i=1; ; i++){
         temp_1.X = temp_after.X;
         temp_1.Y = temp_after.Y+i;
         
         temp_2.X = temp_before.X;
         temp_2.Y = temp_after.Y+i;
         
         if(temp_1.Y > temp_before.Y){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card== 0){
            if(No_Corner(temp_after, temp_1,pan) == 1 && No_Corner(temp_before, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }
   return 0;
}
int Two_Corner_Width(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){
   COORD temp_1, temp_2;
   int i;
   
   if(temp_before.X <= temp_after.X){
      for(i=1; ; i++){
         temp_1.X = temp_before.X+i;
         temp_1.Y = temp_before.Y;
         
         temp_2.X = temp_before.X+i;
         temp_2.Y = temp_after.Y;
         
         if(temp_1.X > temp_after.X){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_before, temp_1,pan) == 1 && No_Corner(temp_after, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }else{      //   temp_before.X > temp_after.X
      for(i=1; ; i += 1){
         temp_1.X = temp_after.X+i;
         temp_1.Y = temp_after.Y;
         
         temp_2.X = temp_after.X+i;
         temp_2.Y = temp_before.Y;
         
         if(temp_1.X > temp_before.X){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_after, temp_1,pan) == 1 && No_Corner(temp_before, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }
   return 0;
}
int Two_Corner_Up(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){
   COORD temp_1, temp_2;
   int i;
   
   if(temp_before.Y >= temp_after.Y){
      for(i=1; ; i++){
         temp_1.X = temp_before.X;
         temp_1.Y = temp_after.Y-i;
         
         temp_2.X = temp_after.X;
         temp_2.Y = temp_after.Y-i;
         
         if(temp_1.Y < 0){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_before, temp_1,pan) == 1 && No_Corner(temp_after, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }else{      //   (temp_before.Y < temp_after.Y)
      for(i=1; ; i++){
         temp_1.X = temp_after.X;
         temp_1.Y = temp_before.Y-i;
         
         temp_2.X = temp_before.X;
         temp_2.Y = temp_before.Y-i;
         
         if(temp_1.Y < 0){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_after, temp_1,pan) == 1 && No_Corner(temp_before, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }
   
   return 0;
}
int Two_Corner_Down(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){
   COORD temp_1, temp_2;
   int i;
   
   if(temp_before.Y <= temp_after.Y){
      for(i=1; ; i++){
         temp_1.X = temp_before.X;
         temp_1.Y = temp_after.Y+i;
         
         temp_2.X = temp_after.X;
         temp_2.Y = temp_after.Y+i;
         
         if(temp_1.Y > 29){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_before, temp_1,pan) == 1 && No_Corner(temp_after, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }else{      //   (temp_before.Y > temp_after.Y)
      for(i=1; ; i++){
         temp_1.X = temp_after.X;
         temp_1.Y = temp_before.Y+i;
         
         temp_2.X = temp_before.X;
         temp_2.Y = temp_before.Y+i;
         
         if(temp_1.Y > 29){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_after, temp_1,pan) == 1 && No_Corner(temp_before, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }
   
   return 0;
}
int Two_Corner_Left(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){
   COORD temp_1, temp_2;
   int i;
   
   if(temp_before.X >= temp_after.X){
      for(i=1; ; i += 1){
         temp_1.X = temp_after.X-i;
         temp_1.Y = temp_after.Y;
         
         temp_2.X = temp_after.X-i;
         temp_2.Y = temp_before.Y;
         
         if(temp_1.X < 0){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_after, temp_1,pan) == 1 && No_Corner(temp_before, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }else{      //   (temp_before.X < temp_after.X)
      for(i=1; ; i += 1){
         temp_1.X = temp_before.X-i;
         temp_1.Y = temp_before.Y;
         
         temp_2.X = temp_before.X-i;
         temp_2.Y = temp_after.Y;
         
         if(temp_1.X < 0){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_before, temp_1,pan) == 1 && No_Corner(temp_after, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }
   
   return 0;
}
int Two_Corner_Right(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){
   COORD temp_1, temp_2;
   int i;
   
   if(temp_before.X <= temp_after.X){
      for(i=2; ; i += 2){
         temp_1.X = temp_after.X+i;
         temp_1.Y = temp_after.Y;
         
         temp_2.X = temp_after.X+i;
         temp_2.Y = temp_before.Y;
         
         if(temp_1.X > 28){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_after, temp_1,pan) == 1 && No_Corner(temp_before, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }else{      //   (temp_before.X > temp_after.X)
      for(i=2; ; i += 2){
         temp_1.X = temp_before.X+i;
         temp_1.Y = temp_before.Y;
         
         temp_2.X = temp_before.X+i;
         temp_2.Y = temp_after.Y;
         
         if(temp_1.X > 28){
            return 0;
         }
         
         if(pan[temp_1.Y][temp_1.X]._card == 0 && pan[temp_2.Y][temp_2.X]._card == 0){
            if(No_Corner(temp_before, temp_1,pan) == 1 && No_Corner(temp_after, temp_2,pan) == 1 && No_Corner(temp_1, temp_2,pan) == 1){
               return 1;
            }
         }
      }
   }
   
   return 0;
}
int One_Corner(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){
   COORD temp;

   if(pan[temp_after.Y][temp_before.X]._card != 0){
      return 0;
   }
      temp.X = temp_before.X;
      temp.Y = temp_after.Y;
      if(No_Corner(temp_before, temp,pan) == 1 && No_Corner(temp_after, temp,pan) == 1){
         return 1;
      }

   if(pan[temp_before.Y][temp_after.X]._card != 0){
      return 0;
   }
      temp.X = temp_after.X;
      temp.Y = temp_before.Y;
      if(No_Corner(temp_before, temp,pan) == 1 && No_Corner(temp_after, temp,pan) == 1){
         return 1;
      }
   return 0;
}
int No_Corner(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){      //   사라지면 1반환 
   if(!(temp_before.X == temp_after.X || temp_before.Y == temp_after.Y)){
      return 0;
   }

   if(temp_before.X == temp_after.X){
      if(temp_before.Y < temp_after.Y){
         return No_Corner_Y(temp_before, temp_after,pan);
      }else{
         return No_Corner_Y(temp_after, temp_before,pan);
      }
   }else if(temp_before.Y == temp_after.Y){
      if(temp_before.X < temp_after.X){
         return No_Corner_X(temp_before, temp_after,pan);
      }else{
         return No_Corner_X(temp_after, temp_before,pan);
      }
   }
}
int No_Corner_X(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){   //   before.X < after.X
   int i, _x;

   _x = temp_after.X - 2;
   
   if(temp_after.X - temp_before.X == 2 && temp_after.Y == temp_before.Y){
      return 1;
   }else{
      for(i=1; i < (temp_after.X-temp_before.X)/2; i++, _x -= 2){
         if(pan[temp_after.Y][_x]._card != 0){
            return 0;
         }
      }
      return 1;
   }
}
int No_Corner_Y(COORD temp_before, COORD temp_after,TILE_T pan[20][30]){   //   before.Y < after.Y
   int i, _y;
   
   _y = temp_after.Y;
   
   if(temp_after.Y - temp_before.Y == 1 && temp_after.X == temp_before.X){
      return 1;
   }else{
      for(i=1; i < temp_after.Y-temp_before.Y; i++){
         if(pan[--_y][temp_after.X]._card != 0){
            return 0;
         }
      }
      return 1;
   }
}
void hint(int *x, int *y, TILE_T pan[][30], TILE_T *select_card1, TILE_T *select_card2){
	TILE_T hi1,hi2;
	int i, j,k,l;
	for(i=0;i<*y;i++){
		for(j=0;j<*x;j++){
			hi1._card = pan[i][j]._card;
			hi1._x = j;
			hi1._y = i;	
			for(k=0;k<*y;k++){
				for(l=0;l<*x;l++){
					hi2._card = pan[k][l]._card;
					hi2._x = l;
					hi2._y = k;	
					
					if(Check_Sellect_Card(&hi1,&hi2,pan)==0){
					delete_two_card(pan,&hi1,&hi2);
					select_card1->_card = 0;
					select_card2->_card = 0;
					gotoxy(*x, *y);
					return ;
					}
				}
			}	
		}
	}
}
void move_main_position(char key, int *y){
	int min_y = 4;
	int max_y = 7;
	switch(key) {
		 case 72: // up
           *y -= 1;
            if (*y < 4) *y = min_y;
            break;
        case 80: // down
           *y += 1;
            if (*y > 8) *y = max_y;
            break;
    	default:
    		break;
    	}
}
void move_option_position(char key, int *y, int *op_x, int *op_y){
		switch(key) {
		 case 72: // up
           *y -= 1;
            if (*y < MIN_Y) *y = MIN_Y;
            break;
        case 80: // down
           *y += 1;
            if (*y > MAX_Y) *y = MAX_Y;
            break;
        case 75: // left
        	if(*y==1){
        		if(*op_x <= 2) break;
           		*op_x -= 2;
           		}
           	else if(*y==2){
           		if(*op_y <= 2) break;
           		*op_y -= 2;
			   }
            break;
		case 77: // right
            if(*y==1){
        		if(*op_x >= 20) break;
           		*op_x += 2;
           		}
           	else if(*y==2){
           		if(*op_y >= 30) break;
           		*op_y += 2;
			   }
            break;  
		default:
			break;
		}
            
}
void print_game_menu(){
	setColor(11,0); 
		printf("==================================================================\n");
		printf("\n");
		printf("\n");
		printf(" 			for sky castle\n");
		setColor(15,0);
		printf("     new game\n");			//0,4
		printf("     load game\n");			//0,5
		printf("     options\n");			//0,6
		printf("     manual\n");			//0,7
		printf("     exit\n");				//0,8
		printf("\n");
		printf("\n");
		setColor(11,0); 
		printf("==================================================================\n");
}
void print_option(int *op_x,int *op_y){
	
	int _y = 0;
	char key;
	while(1){
		setColor(11,0);
		move_option_position(key, &_y, op_x, op_y);
		printf("		options\n");
		printf("	select size of pan(width) : %d\n" , *op_x);
		printf("	select size of pan(height) : %d\n" , *op_y);
		printf("\n\n\n\n back : q");
		gotoxy(0,_y);
		key = getch();
		if(key == 'q') break;
		gotoxy(0,0);
		
	}
	system("cls");
	print_game_menu();
}
void select_tile(TILE_T pan[20][30], int x, int y){			//원래값 복원  
	switch(pan[y][x]._card){
		case 1: case 5: case 9: case 13: case 17: case 21: case 25: case 29: 
			setColor(9,15);
			break;
		case 2: case 6: case 10: case 14: case 18: case 22: case 26: case 30:
			setColor(4,15);
			break;
		case 3: case 7: case 11: case 15: case 19: case 23: case 27: case 31:
			setColor(3,15);
			break;
		case 4: case 8: case 12: case 16: case 20: case 24: case 28: case 32:
			setColor(2,15);
			break;		
	}
}
void print_manual(){
	printf("=========================================================================================================");
	printf("\n");
	printf("사천성은 불규칙으로 나열된 패 에서 종류가 같은 패를 찾아 없애가는 방식이다.\n");
	printf("없어지는 경우는 다음과 같다.\n");
	printf("1. 동일한 모양의 패 2개가 인접해 있을 때\n");
	printf("2. 동일한 모양의 패 2개 사이에 다른 패가 있을 경우, 수평 또는 수직의 직선으로 연결하여\n");
	printf("   그 선이 구부러지는 횟수가 2회 이내 일 때(즉, 3개 이내의 수직선 또는 수평선의 조합으로 2개의 패를 이을 때\n");
	printf("\n");
	printf("back : q"); 
	printf("\n");
	printf("==========================================================================================================");
	char key;
	while(1){
		key = getch();
		if(key == 'q') break;
	}
	system("cls");
	print_game_menu();
	return ;
}
int check_pan(TILE_T pan[20][30]){
	int i,j;
	for(i=0;i<20;i++){
		for(j=0;j<30;j++){
			if(pan[i][j]._card != 0) return 1;
			
		}
	}	
	return 0;
}
void start_game(int *x, int *y, TILE_T pan[20][30], TILE_T *select_card1, TILE_T *select_card2){
	char key;
	int check, j;
	FILE *fp = fopen("save.dat", "wb");
	FILE *tp = fopen("time.dat", "wb");
	FILE *sp = fopen("score.dat", "wb");
	FILE *xp = fopen("x.dat", "wb");
	FILE *yp = fopen("y.dat", "wb");
	_x = *x;
	_y = *y;
	print_pan(*x,*y,pan);
	time_t start, end, save_time;
	time(&start);
	while(1){		
  		key = getch();
  		if(key == 115) {
  			time(&end);
  			 
  			fwrite(&score,4,1,sp);
  			fwrite(pan,12,600,fp);
  			fwrite(&end,sizeof(time_t),1,tp);
  			fwrite(&_x, 4, 1, xp);
  			fwrite(&_y, 4, 1, yp);
  			fclose(xp);
  			fclose(yp);
			fclose(sp);
  			fclose(fp);
  			fclose(tp);
  			gotoxy(22 , 0);
			printf("세이브되었습니다.");
			return ;
		  }
  		if(key == 111){
  			hint(x,y,pan,select_card1,select_card2);
		  }
		movePosition (key, x, y, pan, select_card1, select_card2);
		gotoxy(*x, *y);
		check = check_pan(pan);
		if(check == 0) break;
	}
	time(&end);
	
	fclose(xp);
  	fclose(yp);		
	fclose(sp);
	fclose(fp);
	fclose(tp);
	j = difftime(end,start);
	system("cls");
	gotoxy(0,0);
	setColor(11,0);
	printf("==============================================\n");
	printf("\n경과시간  : %f\n", difftime(end, start));
	printf("최종점수  : %d\n", score-j);
	printf("\n==============================================");
}
void load_game(int *x, int *y, TILE_T pan[20][30], TILE_T *select_card1, TILE_T *select_card2){
	char key;
	int check, j;
	FILE *fp = fopen("save.dat", "rb");
	FILE *tp = fopen("time.dat", "rb");
	FILE *sp = fopen("score.dat", "rb");
	FILE *xp = fopen("x.dat", "rb");
	FILE *yp = fopen("y.dat", "rb");
	
	time_t start, end, save_time;
	fread(&_x,4,1,xp);
	fread(&_y,4,1,yp);
	fread(&score , 4, 1 ,sp);
	fread(&save_time,sizeof(time_t),1,tp);
	fread(pan,12,600,fp);
	*x = _x;
	*y = _y;
	print_pan(*x,*y,pan);
	time(&start);
	while(1){		
  		key = getch();
  		if(key == 27) break;
  		if(key == 115) {
  			time(&end);
  			
  			fclose(fp);
  			fclose(tp);
  			fclose(sp);
  			fclose(xp);
  			fclose(yp);
  			
  			sp = fopen("score.dat","wb");
  			fp = fopen("save.dat", "wb");
			tp = fopen("time.dat", "wb");
			xp = fopen("x.dat", "wb");
			yp = fopen("y.dat", "wb");
			end += save_time;
			fwrite(&score,4,1,fp);
  			fwrite(pan,12,600,fp);
  			fwrite(&end,sizeof(time_t),1,tp);
  			fwrite(&_x, 4, 1, xp);
  			fwrite(&_y, 4, 1, yp);
  			
			
  			save_time = difftime(end, start);
  			fwrite(&save_time,sizeof(time_t),1,tp);
  			fclose(sp);
  			fclose(xp);
  			fclose(yp);
  			fclose(fp);
  			fclose(tp);
  			gotoxy(22,0);
  			
			printf("세이브되었습니다.");
  			return ;
		  }
  		if(key == 111){
  			hint(x,y,pan,select_card1,select_card2);
		  }
		movePosition (key, x, y, pan, select_card1, select_card2);
		gotoxy(*x, *y);
		check = check_pan(pan);
		if(check == 0) break;
	}
	time(&end);
	fclose(yp);
	fclose(xp);
	fclose(sp);
	fclose(fp);
	fclose(tp);
	j = difftime(end,start);
	system("cls");
	gotoxy(0,0);
	setColor(11,0);
	printf("==============================================\n");
	printf("\n경과시간  : %f\n", difftime(end, start));
	printf("최종점수  : %d\n", score-j);
	printf("\n==============================================");
}
void print_game_main(int *op_x, int *op_y, TILE_T pan[20][30], TILE_T *select_card1, TILE_T *select_card2){
	int y=2, x=0;
	int past_y;
	char key;
		time_t start, end;
	print_game_menu();
	while(1){
		past_y = y;
		key = getch();
		if(key == 32){
			 //start game
        	if(y==4) {
        		
        		system("cls");
        		set_random_card(*op_x,*op_y, pan);
				start_game(op_x,op_y,pan,select_card1,select_card2);
				return ;
			}
        	//load game
			else if(y==5){
				system("cls");
				load_game(op_x,op_y,pan,select_card1,select_card2);
				break;
			}
			//option
        	else if(y==6) {
        		system("cls");
				print_option(op_x,op_y);
			}
        	else if(y==7) {
        		system("cls");
        		print_manual();
	
			}        	//exit
        	else if(y==8) {
        		gotoxy(0,12);
				return ;
			}
		}
		move_main_position(key, &y);
		
		gotoxy(x, past_y);
		printf("    ");
		gotoxy(x, y);
		printf("  ->"); 
		
	}
}
int main(void){
	
	int x=2, y=2, i, j;
	char key;
	
	//FILE *fp = fopen("pan4.dat", "rb");
	TILE_T pan[20][30];
  	TILE_T *select_card1;
  	TILE_T *select_card2;
  	
	select_card1 = (TILE_T*)malloc(sizeof(TILE_T));
  	select_card1->_card = 0;
  	
  	select_card2 = (TILE_T*)malloc(sizeof(TILE_T));
  	select_card2->_card = 0;
	//초기화  
	for(i=0;i<20;i++){
		for(j=0;j<30;j++)
			pan[i][j]._card = 0;
	}	
	//게임 메인 출력  
	
	print_game_main(&x,&y,pan,select_card1,select_card2);


	setColor(15, 0);
   return 0;
}
