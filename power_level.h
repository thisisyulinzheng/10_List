#ifndef POWER_LEVEL_H
#define POWER_LEVEL_H

struct z_fighter {
	char name[256]; 
	char species[256]; 
	int power_lvl;
	char hair_color[256];

	struct z_fighter *next;
};

struct z_fighter * create_z(char *name, char *species, int p_lvl, char *h);
void print_z(struct z_fighter *);
void change_z(struct z_fighter *z_f, int p_lvl, char *h);
void print_list(struct z_fighter *z);
struct z_fighter * insert_front(struct z_fighter *head, char *name, char *species, int p_lvl, char *h);
struct z_fighter * free_list(struct z_fighter *head);
struct z_fighter * remove_node(struct z_fighter *head, char *name);
#endif