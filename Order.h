#import "Order.cpp"

struct Order{
  char number[10];
  char csurname[30];
  char goodnum[6];
  int goodcount;
  char date[11];
  char status;
};

void orderMenu();
void orderPlace(int selected);
void purchaseGood(int selected);
void customOrder(int selected);