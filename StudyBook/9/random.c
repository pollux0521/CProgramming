//난수 발생 함수
#define SEED 17
#define MULT 25173
#define INC 13849
#define MOD 65536

unsigned int call_count = 0;
static unsigned seed = SEED;

// 정수 난수 생성 함수
unsigned random_i(void)
{
	seed = (MULT*seed + INC) % MOD;
	call_count++;
	
	return seed;
 } 
 //실수 난수 생성 함수        난수란???
 double random_f(void)
 {
 	seed = (MULT*seed + INC) % MOD;
 	call_count++;
 		
 	return seed / (double) MOD;
  } 
