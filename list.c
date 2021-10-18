#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct foo {
	struct foo *next;
	char c[20];
	int i;
	};

void print_list(struct foo *f);
struct foo * insert_front(struct foo *ne, char s[20], int a);
struct foo * free_list(struct foo *f);

int main(){
	srand(time(NULL));
  struct foo *wood = insert_front(0, "oak", 30);
  wood = insert_front(wood, "random", rand());
  wood = insert_front(wood, "beech", 50);
  wood = insert_front(wood, "holly", 30);
  print_list(wood);
  free_list(wood);
	return 0;
}

void print_list(struct foo *f){
	if (f->next != 0){
		printf("wood:%s\t time in years to grow:%d\n", f->c, f->i);
		print_list(f->next);
	}
  else{
		printf("wood:%s\t time in years to grow:%d\t end of list\n", f->c, f->i);
	}
}

struct foo * insert_front(struct foo *ne, char s[20], int a){
  struct foo *n = malloc(sizeof(struct foo));
  n->next = ne;
  strncpy(n->c, strcat(s,"\0"), strlen(s));
  n->i = a;
  return n;
}

struct foo * free_list(struct foo *f){
	if (f->next != 0){
		struct foo *ne = f->next;
		free(f);
		free_list(ne);
	}
	else{
		free(f);
	}
}
