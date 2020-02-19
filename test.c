#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.h"

int main(void){
  card data;
  scanf("%d%d",&data.color,&data.num);


  if(data.color == BLACK) printf("Black");
	else printf("White");

	printf(":%2d\n",data.num);
  return 0;
}
