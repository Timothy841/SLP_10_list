#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct foo {
	char c[20];
	int i;
	struct foo *next;
	};

void print_stat(struct foo *f);
struct foo * make_foo(char s[20], int a, struct foo *ne);

int main(){
  struct foo *wood = make_foo("oak", 30, wood);
  srand(time(NULL));
  struct foo *random = make_foo("random", rand(), wood);
  print_stat(wood);
  print_stat(random);
  free(wood->c);
  free(wood);
  free(wood->c);
  free(random);
}

void print_stat(struct foo *f){
  printf("wood:%s\t time in years to grow:%d\n", f->c, f->i);
}

struct foo * make_foo(char s[20], int a, struct foo *ne){
  struct foo *n = malloc(sizeof(struct foo));
  strncpy(n->c, s, sizeof((n->c)-1));
  printf("%s\n", n->c);
  strlen(n->c) = "\0";
  n->i = a;
  n->next = ne;
  return n;
}
