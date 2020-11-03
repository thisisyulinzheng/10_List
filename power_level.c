#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "power_level.h"

void print_list(struct z_fighter *f) {
  struct z_fighter *z = f;
  printf("\n");
  while (f) {
    print_z(f);
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
    printf("Freeing %s\n", f->name);
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
    //not returning head node here because that's what we're removing
    return fighter;
  }
  while (fighter->next) {
    struct z_fighter *next_fighter = fighter->next;
    if (!strcmp(next_fighter->name, name)) {
      fighter->next = next_fighter->next;
      free(next_fighter);
    }
    //checks if this is the last node
    if (fighter->next) {
      fighter = fighter->next;
    }
  }
  return head;
}


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
  printf("Name: %s, Species: %s, Power Level: %d, Hair Color: %s \n", f->name, f->species, f->power_lvl, f->hair_color);
}

