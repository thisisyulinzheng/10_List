#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "power_level.h"
struct z_fighter * create_z(char *n, char *s, int p_lvl, char *h) {

  struct z_fighter *fighter;
  fighter = malloc(sizeof(struct z_fighter));
  strncpy(fighter->name, n, sizeof(fighter->name)-1);
  strncpy(fighter->species, s, sizeof(fighter->species)-1);
  strncpy(fighter->hair_color, h, sizeof(fighter->hair_color)-1);
  fighter->power_lvl = p_lvl;

  return fighter;
}

void print_z (struct z_fighter *f) {
	printf("Name: %s\nSpecies: %s\nPower Level: %d\nHair Color: %s\n", f->name, f->species, f->power_lvl, f->hair_color);
}

void change_z (struct z_fighter *z_f, int p_lvl, char *h) {
  z_f->power_lvl = p_lvl;
  strncpy(z_f->hair_color, h, sizeof(z_f->hair_color)-1);
}

void print_list(struct z_fighter *f) {
  struct z_fighter *z = f;
  printf("\n");
  while (f) {
    print_z(f);
    printf("\n");
    f = f->next;
  }
}

struct z_fighter * insert_front(struct z_fighter *head, char *name, char *species, int p_lvl, char *h) {
  struct z_fighter *fighter;
  fighter = create_z(name, species, p_lvl, h);
  fighter->next = head;
  return fighter;
}

struct z_fighter * free_list(struct z_fighter *head) {
  struct z_fighter *f = head;
  struct z_fighter *t;
  while (f) {
    t = f->next;
    //ensures that the next node is pointing to null
    //t should still point to the next null
    f->next = NULL;
    free(f);
    f = t;
  }
  //since the pointer to the head node was never explicitly set to null, I do it here
  head = NULL;
  return head;
}

struct z_fighter * remove_node(struct z_fighter *head, char *name) {
  struct z_fighter *fighter = head;
  if (!strcmp(fighter->name, name)) {
    fighter = head->next;
    free(head);
    return fighter;
  }
  while (fighter) {
    struct z_fighter *next_fighter = fighter->next;
    if (!strcmp(fighter->next->name, name)) {
      next_fighter = fighter->next;
      fighter->next = fighter->next->next;
      free(next_fighter);
    }
    if (fighter->next) {
      printf("s1s\n");
      fighter = fighter->next;
      printf("s2\n");
    }
    
    printf("s3s\n");
  }
  printf("sdas\n");
  return fighter;
}
