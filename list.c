#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct foo {
	struct foo *next;
	char c[20];
	int i;
	};

void print_list(struct foo *f){
	if (f == NULL){
		printf("nothing in list\n");
	}
	else if (f->next != 0){
		printf("wood:%s\t time in years to grow:%d\n", f->c, f->i);
		print_list(f->next);
	}
  else{
		printf("wood:%s\t time in years to grow:%d\t end of list\n", f->c, f->i);
	}
}

struct foo * make_foo(struct foo *ne, char s[20], int a){
	struct foo *n = malloc(sizeof(struct foo));
  strncpy(n->c, strcat(s,"\0"), strlen(s));
  n->i = a;
  return n;
}

struct foo * insert_front(struct foo *ne, char s[20], int a){
  struct foo *n = make_foo(ne, s, a);
  n->next = ne;
  return n;
}

struct foo * free_list(struct foo *f){
	if (f != NULL){
		if (f->next != 0){
			struct foo *ne = f->next;
			free(f);
			free_list(ne);
		}
		else{
			free(f);
		}
	}
}

struct foo * remove_node(struct foo *front, char data[20]){
	struct foo *temp = front;
	if (!strcmp(front->c, data)){//if first node is == data
		front = front->next;
		free(temp);
		return front;
	}
	while (1){//while nodes != data;
		if (front->next==0){//at last node
			if (!strcmp(front->next->c, data)){//if last node is == data
				free(front->next);
			}
			return temp;
		}
		if (!strcmp(front->next->c, data)){//if node in between == data
			struct foo *temp2 = front->next;
			front->next = front->next->next;
			free(temp2);
			return temp;
		}
		front = front->next;
	}
}
