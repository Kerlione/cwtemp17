struct Client{
  char surname[30]; //Surname
  char name[30]; //Name
  char phone[9]; //Phone number 8 digits + 0
  int orders;   //Order count
  char lorder[10];   //Last order number
};

void clientMenu();
