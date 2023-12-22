#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ONEHOT_MODE  (1)
#define GRAY_MODE    (2)

unsigned int binary2gray(unsigned int  n ){
	return n ^ ( n >> 1 );
}

unsigned int getbitnum(unsigned int number){
	unsigned int num = 0;
	while(number){
		number = number >> 1;
		num ++;
	}
	return num;
}


void show_onehot(int index, int total_num){
	for( int i=0;i<total_num-1-index;i++){
		printf("0");
	}
	printf("1");
	for(int i = 0 ;i<index;i++){
		printf("0");
	}
	printf("\r\n");
}

void show_gray(int num,unsigned int total_num){
	unsigned int num_bit = getbitnum((unsigned int) num);
	for( unsigned int i=0;i<total_num-num_bit;i++){
		printf("0");
	}
	int rl = num_bit -1;
	for(int i=0;i<num_bit;i++){
		printf("%d",(num>>rl ) & 0x01);
		rl--;
	}
	
	printf("\r\n");
}


void help_info(){
	printf("\r\nCreate OneHot && Gray Code !\r\n");
	printf("usage:\r\n");
	printf("  ogcode [-g] num \r\n");
	printf("  <-- both start_range and end_range should >= 0 -->\r\n");
	printf("--> -g : gray mode, default onehot mode\r\n");
	printf("--> -h/--help : help info\r\n");
}

int main(int argc ,char * argv[]){
	int  number_num;
	char work_mode ;
	
	if( argc < 2 ){
		help_info();
		return -1;
	} else if( !strcmp(argv[1],"-h") || !strcmp(argv[1],"--help") ){
		help_info();
		return -1;
	}else if( argc == 2 ){
		number_num = atoi(argv[1]);

		work_mode = ONEHOT_MODE;
	}else if( argc == 3){
		if( strcmp(argv[1],"-g") ){
			help_info();
			return -1;
		}
		number_num =atoi(argv[2]);
		work_mode = GRAY_MODE;
	}else{
		help_info();
		return -1;
	}
	if( number_num <= 0 ){
		help_info();
		return -1;
	}
	
	/************************ main function ******************************/
	if( work_mode == ONEHOT_MODE){
		printf("The num bit is %u\r\n",number_num);
		for( int i=0;i<number_num;i++){
			show_onehot(i,number_num);
		}
	}else if( work_mode == GRAY_MODE ){
		unsigned int num_bit = getbitnum((unsigned int)(number_num));
		printf("The num bit is %u\r\n",num_bit);
		for( int i=0;i<number_num;i++){
			show_gray(binary2gray((unsigned int)i),num_bit);
		}
	}else {
		printf("unknown error \r\n");
	}
	return 0;
} 



