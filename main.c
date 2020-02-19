#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"

//card型リストの全要素をnumが小さい順に並びかえる、同値ならBlack<White
/*  引数  (配列名, 要素数)  */
void minToMax(card list[],int n);

//statueを指定して、numとcolorをキーボード操作から取得
/*	引数	(statue, 代入先のアドレス)	*/
void gets_card(int statue, card *data);

//card型のcolorとnumを出力
/*	引数	(アドレス)	*/
void print_card(card *data);

//card型のリストの全要素のcolorとnumを出力
/*	引数	(リスト名, 要素数)	*/
void print_cards(card data[],int n);

//card型のリストうちOpenな要素のcolorとnumを出力
/*	引数	(リスト名, 要素数)	*/
void Gprint_cards(card list[],int n);

//あるデータと一致するものがリスト内にないかを確認して(被りナシ->0, 被りアリ->1)を返す
/*	引数	(データのアドレス, リスト名)	*/
int check_card(card *data, card list[]);

//card型をコピー
/*  引数  (コピー元のアドレス, コピー先のアドレス)  */
void cpycard(card *before,card *after);

//指定したリスト内のカードにアタックを受け付ける。アタック成功で０、失敗で１を返す
/*	引数	(リスト名)	*/
int attacked(card list[]);





int main(void){
	int i,j,k,stu,count=0;
	card list[24],used[16],data;

	printf("一人目：\n");
	for(i=0;i<16;i++){
		if(i == 8) printf("二人目:\n");
		gets_card(CLOSE,&data);
		if(check_card(&data,used) == 0){
			cpycard(&data, &used[i]);
		}else{
			while(check_card(&data,used) == 1){
				printf("Error:すでに入力済のカードです\n");
				gets_card(CLOSE,&data);
			}
			cpycard(&data, &used[i]);
		}
	}

	data.statue = CLOSE;
	for(i=0;i<12;i++){
		data.num = i;
		for(j=0;j<2;j++){
			data.color = j;
			if (check_card(&data,used)==0){
				list[count] = data;
				count++;
			}
		}
	}

	Gprint_cards(list,count);
	printf("\n");


	if(attacked(list) == 1){
		gets_card(OPEN,&data);
		while(check_card(&data,	list) == 1){
			printf("Error:すでに入力済のカードです\n");
			gets_card(OPEN,&data);
		}
		cpycard(&data, &list[count]);
		count++;
		minToMax(list, count);
	}

	Gprint_cards(list, count);
	printf("\n");

	print_cards(list,count);
	return 0;
}












void minToMax(card list[], int n){
  int i,j,num,min,*num_list;
	card *cpy_list;
  num_list = malloc(sizeof(int)*n);
	cpy_list = malloc(sizeof(card)*n);

	for(i=0;i<n;i++){
		cpycard(&list[i], &cpy_list[i]);
	}

  for(i=0;i<n;i++){
    for(j=0;;j++){
      if(list[j].num != -1){
        min = list[j].num;
        break;
      }
    }

    for(j=0;j<n;j++){
      if((list[j].num <= min) && (0 <= list[j].num)){
        min = list[j].num;
        num = j;
      }
    }
    num_list[i] = num;
    list[num].num = -1;
  }

  for(i=0;i<n;i++){
		min = num_list[i];
    cpycard(&cpy_list[min], &list[i]);
  }

  free(num_list);
	free(cpy_list);
  return;
}

void gets_card(int statue,card *data){
	data->statue = statue;
	printf("色(黒->0, 白->1)	>>");
	scanf("%d",&data->color);
	while (data->color < 0 || data->color > 1){
		printf("Error 0~1の間で入力してください	>>");
		scanf("%d",&data->color);
	}
	printf("数字を入力	>>");
	scanf("%d",&data->num);
	while (data->num<0 || data->num>11){
		printf("Error 0~11の間で入力してください	>>");
		scanf("%d",&data->num);
	}
	return;
}

void print_card(card *data){
	if(data->color == BLACK) printf("Black");
	else printf("White");

	printf(":%2d\n",data->num);
	return;
}

void Gprint_cards(card data[],int n){
	int i;
	printf("\n");
	for(i=0;i<n;i++){
		printf("%2d:",i+1);
		if(data[i].color == BLACK) printf("Black");
		else printf("White");

		if (data[i].statue == OPEN) printf(" %2d",data[i].num);
		printf("\n");
	}
	return;
}

void print_cards(card data[],int n){
	int i;
	printf("\n");
	for(i=0;i<n;i++){
		printf("%2d:",i+1);
		if(data[i].color == BLACK) printf("Black");
		else printf("White");
		printf(" %2d",data[i].num);
		printf("\n");
	}
	return;
}

int check_card(card *data, card list[]){
	int i,stu=0;
	for(i=0;i<24;i++){
		if (data->color==list[i].color && data->num==list[i].num) stu = 1;
	}
	return stu;
}

void cpycard(card *before,card *after){
	after->statue = before->statue;
	after->color = before->color;
	after->num = before->num;
	return;
}

int attacked(card list[]){
	int cardnum,num;

	printf("何番のカードにアタックをしかけますか	>>");
	scanf("%d",&cardnum);

	printf("このカードの数字は？	>>");
	scanf("%d",&num);

	if(list[cardnum-1].num == num){
		list[cardnum-1].statue = OPEN;
		printf("アタック成功！\n");
		return 0;
	}else{
		printf("アタック失敗...\n");
		return 1;
	}
}
