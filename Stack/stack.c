#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "stack.h"

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node Node;

Node *top = NULL;
int stack_size = 0;

void initialize_stack_size(int size) {
  if (size <= 0) {
    stack_size = 0;
  }

  stack_size = size;
}

bool isEmpty() {
  if (top == NULL) {
    return true;
  }

  return false;
}

bool isFull() {
  int count = 0;

  Node *temp = top;
  while(temp != NULL) {
    temp = temp->next;
    count++;
  }

  if (count >= stack_size) {
    return true;
  }

  return false;
}

void push(int data) {
  if (stack_size == 0) {
    printf("Stack not initialized\n");
    return;
  }
  if (isFull() == true) {
    printf("Stack is Full\n");
    return;
  }

  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;

  if (isEmpty() == true) {
    new_node->next = NULL;
    top = new_node;
    return;
  }

  new_node->next = top;
  top = new_node;
}

int peek() {
  return top->data;
}

int pop() {
  assert(isEmpty() == false);

  Node *temp = top;
  int data;

  top = top->next;
  data = temp->data;

  free(temp);

  return data;
}

void display() {
  if (isEmpty() == true) {
    return;
  }

  Node *temp = top;

  while(temp->next != NULL) {
    printf("%d\n|\n", temp->data);
    temp = temp->next;
  }
  printf("%d", temp->data);
}
