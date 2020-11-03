#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "power_level.h"

int main() {	
	struct z_fighter *Z_Fighters = NULL;
	Z_Fighters = insert_front(Z_Fighters, "Goku", "Saiyan", 9000, "Yellow");
	Z_Fighters = insert_front(Z_Fighters, "Vegeta", "Saiyan", 200000, "Green");
	Z_Fighters = insert_front(Z_Fighters, "Krillin", "Human", 10, "Black");
	Z_Fighters = insert_front(Z_Fighters, "Piccolo", "Namekian", 5000, "Bald");
	Z_Fighters = insert_front(Z_Fighters, "Cell", "Bio-Android", 200000, "Green");
	Z_Fighters = insert_front(Z_Fighters, "Gohan", "Half-Saiyan", 10000, "Black");
	printf("\nBehold, the Z-Fighters!");
	print_list(Z_Fighters);
	printf("\n");

	printf("Removing Krillin:");
	Z_Fighters = remove_node(Z_Fighters, "Krillin");
	print_list(Z_Fighters);
	printf("\n");

	printf("Removing Gohan:");
	Z_Fighters = remove_node(Z_Fighters, "Gohan");
	print_list(Z_Fighters);
	printf("\n");

	printf("Removing Goku:");
	Z_Fighters = remove_node(Z_Fighters, "Goku");
	print_list(Z_Fighters);
	printf("\n");

	printf("Removing Android 17 (Not on the list, so nothing should change):");
	Z_Fighters = remove_node(Z_Fighters, "Android 17");
	print_list(Z_Fighters);
	printf("\n");

	printf("Freeing Everyone Else:\n");
	free_list(Z_Fighters);

	return 0;
}