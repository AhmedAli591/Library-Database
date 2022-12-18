#ifndef USERTYPE_H
#define USERTYPE_H


typedef struct NODE {
	u8 BookName[30];
	u8 BookAuthor[30] ;
	u32 Price;
	struct NODE *Next;
	struct NODE *Prevouse;
} NODE_t;

typedef struct {
	NODE_t *Head;
	NODE_t *Tail;
	u32 Size;
} List_t;


#endif