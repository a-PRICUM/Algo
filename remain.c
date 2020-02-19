#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int statue;	//0->close 1->open
 	int color;	//0->Black 1->white
	int num;
}card;

enum{
	BLACK=0,
	WHITE=1,
	OPEN,
	CLOSE,
	EMPTY,
};

//int型の一次元配列の要素(正の数のみ)を小さい順に並びかえる
/*  引数  (配列名, 要素数)  */
void minToMax(int list[],int n);

void gets_card(int statue, card *data);
void print_card(card *data);
void Gprint_card(card list[],int n);
int check_card(card data, card list[],int n);


int main(void){
	int i,j,k,stu,count=0;
	card list[9],used[17],data;
	
	for(i=0;i<17;i++){
		used[i].statue = EMPTY;
	}
	
	printf("一人目:\n%2d:",1);
	for(i=0;i<16;i++){
		if(i == 8) printf("\b\b\b二人目:\n%2d:",1);
		
		gets_card(OPEN,&used[i]);
		if(check_card(used[i],used,i) == 1){
			printf("\tError そのカードはすでに使われています\n   ");
			i--;
		}else{
			printf("\n%2d:",i+2);
		}
	}
	printf("\b\b\b");
	
	data.statue = CLOSE;
	for(i=0;i<12;i++){
		data.num = i;
		for(j=0;j<2;j++){
			data.color = j;
			if (check_card(data,used,16)==0){
				list[count] = data;
				count++;
			}
		}
	}
	
	Gprint_card(list,8);
	
	
	return 0;
}












void minToMax(int list[], int n){
  int i,j,num,min,*ans_list;
  ans_list = malloc(sizeof(int)*n);

  for(i=0;i<n;i++){

    for(j=0;;j++){
      if(list[j] != -1){
        min = list[j];
        break;
      }
    }

    for(j=0;j<n;j++){
      if((list[j]<=min) && (0<=list[j])){
        min = list[j];
        num = j;
      }
    }
    ans_list[i] = list[num];
    list[num] = -1;
  }

  for(i=0;i<n;i++){
    list[i] = ans_list[i];
  }

  free(ans_list);
  return;
}

void gets_card(int statue,card *data){
	int mode=0,statu=1;
	data->statue = statue;
	
	do{
		switch(mode){
			case 0:	printf("色を入力(黒->0, 白->1)	>>");
						scanf("%d",&data->color);
						if(data->color<0 || 1<data->color){
							printf("\tError 0,1のどちらかを入力\n   ");
							break;
						}
			case 1:	printf("   数字を入力(-1で色選択に戻る)	>>");
						scanf("%d",&data->num);
						if (data->num == -1){
							mode = 0;
							printf("   ");
							break;
						}else if (data->num<0 || data->num>11){
							printf("\tError 0~11の間で入力\n");
							mode = 1;
						}else{
							statu = 0;
						}
		}
	}while(statu);
	return;
}

void print_card(card *data){
	if(data->color == BLACK) printf("Black ");
	else printf("White ");
	
	printf("%d\n",data->num);
	return;
}

void Gprint_card(card data[],int n){
	int i;
	for(i=0;i<n;i++){
		if(data[i].color == BLACK) printf("Black ");
		else printf("White ");
	
		if (data[i].statue == OPEN) printf("%d",data[i].num);
		printf("\n");
	}
	return;
}

int check_card(card data, card list[],int n){
	int i,stu=0;
	for(i=0;i<n;i++){
		if (data.color==list[i].color && data.num==list[i].num) stu = 1;
	}
	return stu;
}
	

