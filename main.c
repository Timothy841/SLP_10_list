#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"

int main(){
	srand(time(NULL));
  struct foo *wood = insert_front(0, "oak", 30);
  wood = insert_front(wood, "random", rand());
  wood = insert_front(wood, "beech", 50);
  wood = insert_front(wood, "holly", 30);
  print_list(wood);
  print_list(remove_node(wood, "random"));
  wood = free_list(wood);
  print_list(wood);
  return 0;
}


