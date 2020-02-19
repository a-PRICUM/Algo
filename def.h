#ifndef _INCLUDE_CARD_
#define _INCLUDE_CARD_
typedef struct{
	int statue;	//0->close 1->open
 	int color;	//0->Black 1->white
	int num;
}card;
#endif

#ifndef _INCLUDE_ENUM_
#define _INCLUDE_ENUM_
enum{
	BLACK = 0,
	WHITE = 1,
	OPEN,
	CLOSE,
};
#endif
