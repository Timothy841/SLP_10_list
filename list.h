struct foo {
	struct foo *next;
	char c[20];
	int i;
	};

void print_list(struct foo *f);
struct foo * make_foo(struct foo *ne, char s[20], int a);
struct foo * insert_front(struct foo *ne, char s[20], int a);
struct foo * free_list(struct foo *f);
struct foo * remove_node(struct foo *front, char data[20]);
