#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"

int main(){
	srand(time(NULL));
  char a[20] = "oak";
  struct foo *wood = insert_front(0, a, 30);
  strcpy(a, "random");
  wood = insert_front(wood, a, rand());
  strcpy(a, "beech");
  wood = insert_front(wood, a, 50);
  strcpy(a, "holly");
  wood = insert_front(wood, a, 30);
  print_list(wood);
  strcpy(a, "random");
  print_list(remove_node(wood, a));
  wood = free_list(wood);
  print_list(wood);
  return 0;
}
