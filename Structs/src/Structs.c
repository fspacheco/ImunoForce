/*
 ============================================================================
 Name        : Structs.c
 Author      : Felipe Sens Bonetto
 Created	 : 17/03/2014
 Version     : 1.0
 Copyright   : Exemplo de lista duplamente encadeada
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tag;
    char String[20];

    struct elemento *next;
    struct elemento *prev; /*prev sera utilizado no list_del*/
}elemento;

elemento list_head = {0,"Header",NULL,NULL};

elemento *list_add(elemento *, int);
elemento *list_search(int);
void list_del(int);

int main()
{
	elemento *oi;
	elemento *player;
	int x;
	for(x = 1; x < 5; x++){
		oi = list_add(oi, x);
	}
	for(x = 7; x < 9; x++){
		oi = list_add(oi, x);
	}

	oi = list_search(0);
	for(x = 0; (oi == NULL) || (oi->next != NULL); x++){
		oi = list_search(x);
		if(oi != NULL){
		printf("A tag deste elemento ser: %d\n",oi->tag);
		}
	}

	player = list_search(1);
	strcpy(player->String, "Este é o player");
	printf("	Objeto tag: %d \n	Intentificação: %s\n",player->tag,player->String);

}

elemento *list_add(elemento *p, int tag)
{
    elemento *a;
    p = (elemento *)malloc(sizeof(elemento)); /*Aloca p na memoria*/
    p->tag = tag;
    p->next = NULL;
    if(list_head.next == NULL){
        list_head.next = p;
        p->prev = &list_head;
    }
    else{
        for(a = &list_head; a->next != NULL; a = a->next){} /* a vira ponteiro do ultimo elemento da lista*/
        a->next = p;
        p->prev = a;
    }
    return p;
}

elemento *list_search(int tag){
    elemento *a;
    for(a = &list_head; a->tag != tag; a = a->next){
        if(a->next == NULL)
            return NULL;
    }
    return a;
}

void list_del(int tag){
    elemento *a;
    elemento *prev;
    elemento *next;

    a = list_search(tag);
    prev = a->prev;
    next = a->next;
    next->prev = prev->prev;
    prev->next = next->next;

    free(a);
}

