#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node *first = NULL;
Node *last = NULL;

int queue_size = 0;

void initialize_queue_size(int size) {
  if (size <= 0) {
    queue_size = 0;
    return;
  }

  queue_size = size;
}

bool isEmpty() {

  if (first == NULL && last == NULL) {
    return true;
  }

  return false;
}

bool isFull() {
  Node *temp = first;

  int count = 0;

  while(temp != NULL) {
    count++;
    temp = temp->next;
  }

  if (count >= queue_size) {
    return true;
  }

  return false;
}

void enqueue(int data) {

  if (isFull() == true) {
    return;
  }

  Node *newnode = (Node*)malloc(sizeof(Node));

  if (!newnode) {
    printf("Memory allocation failed\n");
    return;
  }

  newnode->data = data;

  if (first == NULL) {
    first = newnode;
    last = newnode;
    newnode->next = NULL;
    return;
  }

  last->next = newnode;
  last = newnode;
}

void display() {
  Node *temp = first;

  if (isEmpty() == false) {
    while(temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int peek() {
  if (isEmpty() == true) {
    printf("Queue is Empty\n");
    return -1;
  }

  return first->data;
}

void dequeue() {
  Node *temp = first;
  first = first->next;

  free(temp);
}
