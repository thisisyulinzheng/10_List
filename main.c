#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "power_level.h"

int main() {	
	struct z_fighter *Goku = create_z("Goku", "Saiyan", 9000, "Yellow");
	struct z_fighter *Krillin = create_z("Krillin", "Human", 10, "Black");
	struct z_fighter *Piccolo = create_z("Piccolo", "Namekian", 5000, "Bald");
	struct z_fighter *Cell = create_z("Cell", "Bio-Android", 200000, "Green");
	Goku->next = Krillin;
	Krillin->next = Piccolo;
	Piccolo->next = Cell;
	struct z_fighter *Gohan = insert_front(Goku, "Gohan", "Half-Saiyan", 10000, "Black");
	remove_node(Gohan, "Goku");
	print_list(Gohan);

	return 0;
}