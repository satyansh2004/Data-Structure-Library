#include <stdio.h>
#include "queue.h"

int main(void) {
  initialize_queue_size(4);
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);

  display();

  dequeue();
  dequeue();
  dequeue();
  dequeue();

  display();
  return 0;
}
