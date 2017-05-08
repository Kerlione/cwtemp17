#include <ostream>

using namespace std;

struct Good{
  char goodnum[6]; //TypeXXXX = Ex. D1720 - Divan(Sofa)
  char name[40];
  char size[12];
  char color[15];
  int count;
};

fstream i("Inventory.dat", ios::binary | ios::in);

void goodMenu();
void viewInventory();
void searchGoodMenu();

void searchGood(char *code[6]);
void searchGood(char *name[40]);
void searchGood(char *size[12]);
void searchGood(char *color[15]);
