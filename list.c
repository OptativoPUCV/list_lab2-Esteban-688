#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List * lista = (List *)malloc(sizeof(List));
     return lista;
}

void * firstList(List * list) {
    if (list->head == NULL){
      return NULL;
    }
    list->current = list->head;
    
    return (void*)list->current->data;
}

void * nextList(List * list) {
	if(list->current == NULL || list->current->next == NULL){ return NULL;}
	
	list->current = list->current->next;

	return (void *) list->current->data;
}

void * lastList(List * list) {
  if(list->current == NULL){

    return NULL;
  }
    list->current = list->tail;
    return (void*)list->current->data;
}

void * prevList(List * list) {
  if(list->current == NULL || list->current->prev == NULL) {
    return NULL;
  }
   list->current = list->current->prev; 
    return (void*)list->current->data;
}

void pushFront(List * list, const void * data) {

	Node * nodo = createNode(data);
	
	if(list->tail == NULL) {
		list->tail = nodo;
		list->head = nodo;
	}
	else
	{
		nodo->next = list->head;
		nodo->prev = NULL;
		list->head->prev = nodo;
		list->head = nodo;
	}
}

void pushBack(List * list, const void * data) {

  Node * nodo = createNode(data);

  if(list->head == NULL){

    list->head = nodo;
    list->tail = nodo;
   }
  else{
   nodo->next = NULL;
    nodo->prev = list->tail;
    list->tail = nodo;
    }
}

void pushCurrent(List * list, const void * data) {

  Node * nodo = createNode(data);

  if (list->current == list->head){

    nodo->prev = list->head;
    list->current->prev =  NULL;
    list->current->next = nodo;
    
  }
  else{
  if(list->current == list->tail){
    list->tail = nodo;
    nodo->next = NULL;
    nodo->prev = list->current->prev;

  }
    else{
      nodo->next = list->current;
      list->current->prev = nodo;
      nodo->prev = list->current->prev->next;
      

    }
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}