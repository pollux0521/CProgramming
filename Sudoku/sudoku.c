#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct TILE{
	int x;
	int y;
	int data;
	int change;		// 15 == change 	, 11 = not change
	int overlap;   	// 12 == overlap	, 0 = not overlap
}Tile;

typedef struct _auto{
	int rn;			//	row num
	int cn;			// 	column num
	bool num[9];	// 	input check
}auto_Tile;

//global variable
pthread_mutex_t mutex;    
Tile sudoku_arr[9][9];									//sudoku board
Tile sudoku_tile;										//
char key;												//
int current_x;											//
int current_y;											//
int sudoku[9][9];										//
int* r[9][9];   										// row first
int* c[9][9];   										// column first
int* s[9][9];   										// section first
int flag = 1;											// 

// print map
void print_first_screen();
void setColor (int fg, int bg);							//
void map_read();										//
void screen_base();										//
void map_print();										// setColor() , sudoku_arr
void map_refresh();										// sudoku_arr

// make map
void make_map();
void make_screen_base();

// move cursor and set data
void gotoxy (int x, int y);								// 
void change_data(int data);								// setColor() , sudoku_arr, current_x, current_y
void input_key_base();									// change_data() , key , current_x , current_y
void move_cursor();										// gotoxy() , key, current_x, current_y

// check_data thread base
void thread_move_cursor(int x, int y);					// gotoxy()
void column_check_base();								// sudoku_arr
void row_check_base();									// sudoku_arr
void section_check_base(Tile copy_data[]);				// sudoku_arr
int all_check_base();

// check_data thread
void* column_check();									// column_check_base() , key
void* row_check();										// row_check_base() , key
void* section_check(void* section_num);					// section_check_base() , key;
void* all_check();										// sudoku_arr , flag

// auto_mode
int num_size(auto_Tile set);							//
auto_Tile find_num(int rn, int cn);						// r , c , s
auto_Tile find_possible();								// num_size() , find_num() , sudoku
bool solve();											// find_possible() sudoku
int auto_check(int check_num);							// solve() , sudoku , sudoku_arr


int main(){
	pthread_t row, column;
	pthread_t section[9];
	pthread_t all;
	current_x = 0;
	current_y = 0;
	int section_num;
	char check_key;
	// map print
	int x, y;
	// move , change num
	print_first_screen();
	while(1){
		check_key = getch();
		if(check_key == '1' || check_key == '2')	break;
	} 

	if(check_key == '1'){
		system("cls");
		screen_base();
		map_read();
		map_print();
		while(1){
			map_refresh();
			key = getch();
			input_key_base();
			//use detach -> program down, so use join
			pthread_create(&row, NULL, row_check, NULL);
			pthread_join(row, NULL);
			pthread_create(&column, NULL, column_check, NULL);
			pthread_join(column, NULL);
			for(section_num=0;section_num<9;section_num++){
				pthread_create(&section[section_num], NULL, section_check, (void*)&section_num);
				pthread_join(section[section_num], NULL);
			}
			map_print();
			move_cursor();
			pthread_create(&all, NULL , all_check , NULL);
			pthread_join(all, NULL);
			if(flag == 0) break;
		}
		thread_move_cursor(0, 10);
		printf(" clear! ( press any key... ))");
		check_key = getch();
		return 0;
	}
	if(check_key == '2'){
		system("cls");
		make_screen_base();
		map_print();
		for(y=0; y<9; y++){
			for(x=0; x<9; x++){
				sudoku_arr[y][x].x = x;
				sudoku_arr[y][x].y = y;
				sudoku_arr[y][x].change = 15;
			}
		}
		while(1){
			key = getch();
			if(key == 'f'){
				make_map();	
				gotoxy(10,20);
				return 0;
			}
			input_key_base();
			map_print();
			move_cursor();
		}
	}
}
void print_first_screen(){
	int i; 
	gotoxy(30,5); //45 75 50
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	for(i=6;i<16; i++){
		gotoxy(30,i);
		printf("早                                             早  \n");
	}
	gotoxy(30,16);
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭 \n");
	gotoxy(49,8);
	printf("蝶紫瓔 啪歜");
	gotoxy(39,12);
	printf("1. 啪歜Ы溯檜      2.裘虜菟晦"); 
}
void screen_base(){
	
	printf("旨收收收收忖收收收收忖收收收收有收收收收忖收收收收忖收收收收有收收收收忖收收收收忖收收收收旬 	旨收收收收收收收收收收收收收收收收收旬\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                 早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此	早  up    = ∟     早  \n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                 早\n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此	早  down  = ⊿     早\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                 早 \n");
	printf("曳收收收收托收收收收托收收收收朱收收收收托收收收收托收收收收朱收收收收托收收收收托收收收收朽	早  left  = ⊥     早\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                 早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此	早  right = ∠     早\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                 早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此 	早  auto  = o      早\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                 早 \n");
	printf("曳收收收收托收收收收托收收收收朱收收收收托收收收收托收收收收朱收收收收托收收收收托收收收收朽	曲收收收收收收收收收收收收收收收收收旭 \n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此 \n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此 \n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早 \n");
	printf("曲收收收收戎收收收收戎收收收收朴收收收收戎收收收收戎收收收收朴收收收收戎收收收收戎收收收收旭 \n");
}
void make_screen_base(){
	
	printf("旨收收收收忖收收收收忖收收收收有收收收收忖收收收收忖收收收收有收收收收忖收收收收忖收收收收旬 	旨收收收收收收收收收收收收收收收收收收旬\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                  早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此	早  up     = ∟     早  \n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                  早\n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此	早  down   = ⊿     早\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                  早 \n");
	printf("曳收收收收托收收收收托收收收收朱收收收收托收收收收托收收收收朱收收收收托收收收收托收收收收朽	早  left   = ⊥     早\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                  早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此	早  right  = ∠     早\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                  早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此 	早  fisish = f      早\n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早	早                  早 \n");
	printf("曳收收收收托收收收收托收收收收朱收收收收托收收收收托收收收收朱收收收收托收收收收托收收收收朽	曲收收收收收收收收收收收收收收收收收收旭 \n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此 \n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早 \n");
	printf("朵式式式式托式式式式托式式式式池式式式式托式式式式托式式式式池式式式式托式式式式托式式式式此 \n");
	printf("早    弛    弛    早    弛    弛    早    弛    弛    早 \n");
	printf("曲收收收收戎收收收收戎收收收收朴收收收收戎收收收收戎收收收收朴收收收收戎收收收收戎收收收收旭 \n");
}
void setColor (int fg, int bg)   {
    int	color = bg * 16 + fg;  // bg: 寡唳儀, fg: 旋濠儀
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void map_read(){
	FILE* fd = fopen("sudoku.map", "rb");
	fread(sudoku_arr, sizeof(Tile), 81, fd);
	fclose(fd);
}
void map_refresh(){
	int x, y;
	pthread_mutex_lock(&mutex);
	for(y=0;y<9;y++){
		for(x=0;x<9;x++){
			sudoku_arr[y][x].overlap = 0;
		}
	}
	pthread_mutex_unlock(&mutex);

}
void map_print(){
	int x, y;
	int data = 1;
	int arr_x = 3;
	int arr_y = 1;
	pthread_mutex_lock(&mutex);
	for(y=0; y<9; y++){
		for(x=0; x<9; x++){
				arr_x = 5*(sudoku_arr[y][x].x + 1) - 2;
				arr_y = 2*(sudoku_arr[y][x].y + 1) - 1;
				gotoxy(arr_x, arr_y);
				setColor(sudoku_arr[y][x].change, sudoku_arr[y][x].overlap);
				
				if(sudoku_arr[y][x].data == 0) printf(" ");	
				else printf("%d", sudoku_arr[y][x].data);		
				
		}
	}
	pthread_mutex_unlock(&mutex);
}
void make_map(){
	int x, y;
	int data = 1;
	int arr_x = 3;
	int arr_y = 1;
	
	for(y=0; y<9; y++){
		for(x=0; x<9; x++){
			if(sudoku_arr[y][x].data > 0)sudoku_arr[y][x].change = 11;
		}
	}
	FILE* fd = fopen("sudoku.map", "wb");
	fwrite(sudoku_arr, sizeof(Tile), 81, fd);
	fclose(fd);
}
void change_data(int data){
	pthread_mutex_lock(&mutex);
	if(sudoku_arr[current_y][current_x].change == 11)	return ;
	else{
		sudoku_arr[current_y][current_x].data = data;
		sudoku_arr[current_y][current_x].overlap = 0;
	}
	pthread_mutex_unlock(&mutex);
}
void gotoxy (int x, int y)   {
    COORD   Pos = {x, y};
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), Pos);
}
void input_key_base(){
	int MIN_X = 0;	int MIN_Y = 0;	int MAX_X = 8;	int MAX_Y = 8;
	pthread_mutex_lock(&mutex);
	int x = current_x; int y = current_y;
	switch(key) {
        case 72: // up
           current_y -= 1;
            if (current_y < MIN_Y) current_y = MIN_Y;
            break;
        case 80: // down
           current_y += 1;
            if (current_y > MAX_Y) current_y = MAX_Y;
            break;
        case 75: // left
            current_x -= 1;
            if (current_x < MIN_X) current_x = MIN_X;
            break;
		case 77: // right
            current_x += 1;
            if (current_x > MAX_X) current_x = MAX_X;
            break;
    	case 'o':
    		auto_check(0);
    		break;
    	default :
    		if (48 <= key && key <= 57){
    			change_data(key-48);	
    			break;
			}
    		break;
	}
	pthread_mutex_unlock(&mutex);
}
void move_cursor(){
	int move_x, move_y;	

	move_x = 5*(current_x + 1) - 2;
	move_y = 2*(current_y + 1) - 1;
	gotoxy(move_x, move_y);
	
}
void thread_move_cursor(int x, int y){
	int move_x, move_y;	
	
	move_x = 5*(x + 1) - 2;
	move_y = 2*(y + 1) - 1;
	gotoxy(move_x, move_y);	
}
void column_check_base(){
	int i, j;
	int check_y;
	pthread_mutex_lock(&mutex);
	for(check_y=0;check_y<9;check_y++){
		for(i=0;i<9;i++){
			if(sudoku_arr[check_y][i].data == 0) continue;
			for(j=0;j<9;j++){
				if(sudoku_arr[check_y][j].data == 0) continue;
				else if(i == j) continue;
				else if(sudoku_arr[check_y][i].data == sudoku_arr[check_y][j].data){
					sudoku_arr[check_y][i].overlap = 12;	
					sudoku_arr[check_y][j].overlap = 12;
					break;
				}	
			}
		}
	}
	pthread_mutex_unlock(&mutex);
}
void row_check_base(){
	int i, j;
	int check_x;
	pthread_mutex_lock(&mutex);

	for(check_x=0;check_x<9;check_x++){
		for(i=0;i<9;i++){
			if(sudoku_arr[i][check_x].data == 0) continue;
			for(j=0;j<9;j++){
				if(sudoku_arr[i][check_x].data == 0) continue;
				else if(i == j) continue;
				else if(sudoku_arr[i][check_x].data == sudoku_arr[j][check_x].data){
					sudoku_arr[i][check_x].overlap = 12;	
					sudoku_arr[j][check_x].overlap = 12;	
					break;
				}	
			}
		}
	}
	pthread_mutex_unlock(&mutex);
}
int num_size(auto_Tile AT){ 
	int rtn=0;
	int i;
	bool *count=AT.num;
	for(i=0;i<9;i++){
		rtn += count[i];
	}
	return rtn;
}
auto_Tile find_num(int rn, int cn){ 
   auto_Tile nums = {rn, cn}; 
   int i;
	for(i=0;i<9;i++){
   		nums.num[i] = true;
	}
	int sn = rn / 3 * 3 + cn / 3;    
	for(i=0;i<9;i++) {  
		if(*r[rn][i] > 0) nums.num[*r[rn][i] - 1] = false;    
		if(*c[cn][i] > 0) nums.num[*c[cn][i] - 1] = false;
		if(*s[sn][i] > 0) nums.num[*s[sn][i] - 1] = false;
	}
	return nums;
}
auto_Tile find_possible(){ 
	int size = 10;
	auto_Tile min_AT = {-1, -1};
	auto_Tile rtn;
	int i, j;
	int n_size;
	auto_Tile temp;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(sudoku[i][j] > 0) continue;   
			temp = find_num(i, j);
			n_size = num_size(temp);
			if(!n_size){
				rtn.rn = 10;
				rtn.cn = 10;
				return rtn;  
			}   
			else if(n_size == 1)  return temp;
			else if(n_size < size){
			    size = n_size;
				min_AT = temp;
			}
		}
	}
	return min_AT;
}
bool solve() {
	int i;
	auto_Tile AT = find_possible();
	if (AT.rn > 9) return false;
	if (AT.rn < 0) return true;
	for (i = 1; i <= 9; i++){
		if (!AT.num[i - 1]) continue;   
		sudoku[AT.rn][AT.cn] = i; 
		if (solve()) return true; 
	}
	sudoku[AT.rn][AT.cn] = 0;  
	return false; 
}
int auto_check(int check_key){
	int i, j;
	int sect_x, sect_y, sect_num, num;	
	int rn, cn;
	bool solve_rtn;	
	int g = 1;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			r[i][j] = &sudoku[i][j];
			c[j][i] = &sudoku[i][j];
		}
	}
	for(sect_num=0;sect_num<9;sect_num++){
		sect_y = 3*(sect_num/3);
		sect_x = 3*(sect_num%3);
		num = 0;
		for(i=sect_y;i<sect_y+3;i++){
			for(j=sect_x;j<sect_x+3;j++){
				s[sect_num][num] = &sudoku[i][j];
				num++;
			}
		}
	}
	for(i=0;i<9;i++){
		for (j=0;j<9;j++){
			if(sudoku_arr[i][j].change == 11) sudoku[i][j] = sudoku_arr[i][j].data;
			else sudoku[i][j] = 0;
		}
	}
	
	if(solve() == false){
		system("cls");
		printf("薑港檜 橈朝 だ橾殮棲棻.");
		return 1;
	}
	else{
		if(check_key == 0){
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					sudoku_arr[i][j].data = sudoku[i][j];
					map_print();
				}
			}
		}
	}
	return 0;
}
void section_check_base(Tile copy_data[]){
	int i=0,j;
	int num = 0;
	Tile check_data[9];
	memcpy(check_data, copy_data, 9*sizeof(Tile));
	for(i=0;i<9;i++){
		if(check_data[i].data == 0) continue;
		for(j=0;j<9;j++){
			if(check_data[j].data == 0) continue;
			else if(i == j) continue;
			else if(check_data[i].data == check_data[j].data){
				pthread_mutex_lock(&mutex);
				sudoku_arr[check_data[i].y][check_data[i].x].overlap = 12;
		    	sudoku_arr[check_data[j].y][check_data[j].x].overlap = 12;	
				pthread_mutex_unlock(&mutex);
				break;		
			}
		}
	}
}
void* column_check(){
	column_check_base();
}
void* row_check(){
	row_check_base();
}
void* section_check(void* section_num){
	int i=0,j;
	int num = 0;
	int sect_x, sect_y;
	int sect_num = *((int*)section_num);
	Tile check_data[9];
	sect_y = 3*(sect_num/3 + 1);
	sect_x = 3*(sect_num%3 + 1);
	for(i=sect_y-3;i<sect_y;i++){
		for(j=sect_x-3;j<sect_x;j++){
			memcpy(&check_data[num],&sudoku_arr[i][j],sizeof(Tile));
			num++;
		}
	}
	section_check_base(check_data);
}

void* all_check(){
	int i, j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(sudoku_arr[i][j].data == 0) return ;
			if(sudoku_arr[i][j].overlap == 12) return ;
		}
	}
	flag = 0;
}
