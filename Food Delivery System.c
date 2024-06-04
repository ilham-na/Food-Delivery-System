/************************************
Project about:	Food delivery system
Done By:	N.M.ILHAM
************************************/

#include <stdio.h>
#include <string.h>

// define global arrays for menu items and prices
char menuitems[100][50];
float menuprices[100];
int menusize = 0;

// define global arrays for order tracking
char customernames[100][50];
char orderitems[100][50];
int orderstatus[100]; // 0: ordered, 1: preparing, 2: delivered
int ordercount = 0;





// function to display the menu
void displaymenu() 
{
    // use loops to print menu items and prices
    printf("---- menu ----\n");
    for (int i = 0; i < menusize; i++) {
        printf("%d. %s - Rs%.2f\n", i + 1, menuitems[i], menuprices[i]);
    }
    printf("--------------\n");
}





// function to place an order
void placeorder() 
{
    	char customername[50];
    	int menuitemindex;
    
   	 printf("Enter your name: ");
    	scanf("%s", customername); 
	printf("---- menu ----\n");
  	for (int i = 0; i < menusize; i++) {
        printf("%d. %s - Rs%.2f\n", i + 1, menuitems[i], menuprices[i]);
    	}
    	printf("--------------\n");



    
    printf("enter the number corresponding to the item you want to order: ");
    scanf("%d", &menuitemindex);
    
    if (menuitemindex >= 1 && menuitemindex <= menusize) {
        strcpy(customernames[ordercount], customername);
        strcpy(orderitems[ordercount], menuitems[menuitemindex]);
        orderstatus[ordercount] = 0; // set status to ordered
        ordercount++;
        printf("Order placed successfully!\n");
    } else {
        printf("Invalid menu item selection.\n");
    }
}




// function to update delivery status
void updatedeliverystatus() {
    int orderindex;
    
    printf("enter the index of the order you want to update: ");
    scanf("%d", &orderindex);
    
    if (orderindex >= 0 && orderindex <= ordercount) {
        printf("update status for order #%d - %s\n", orderindex + 1, customernames[orderindex]);
        printf("1. Preparing\n");
        printf("2. Delivered\n");
        printf("Enter the new status: ");
        scanf("%d", &orderstatus[orderindex]);
        printf("status updated successfully!\n");
    } else {
        printf("invalid order index.\n");
    }
}




int main()

{
// load menu items and prices from a file (file processing)

FILE *file = fopen("./menu.txt","r");
    
    if (file == NULL) {
        printf("error opening menu file.\n");
        return 0;
    }

    while (fscanf(file, "%s %f", menuitems[menusize], &menuprices[menusize]) != EOF) {
        menusize++;
    }
    fclose(file);


 
    int choice;
 
    do {
        // display a menu with options (input/output)
        printf("---- FOOD DELIVERY SYSTEM ----\n");
        printf("1. Display menu\n");
        printf("2. Place an order\n");
        printf("3. Update delivery status\n");
        printf("4. View orders\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        // capture user choice
        scanf("%d", &choice);
        
      	switch (choice) {
            case 1:
                displaymenu();
 
                break;
            case 2:
                placeorder();

                break;
            case 3:
                updatedeliverystatus();
                break;
            case 4:
                // display a list of orders and their statuses
                printf("---- orders ----\n");
                for (int i = 0; i < ordercount; i++) {
                    printf("order #%d - %s: %s\n", i + 1, customernames[i], orderstatus[i] == 0 ? "ordered" : "delivered");
                }
                printf("--------------\n");
                break;
            case 5:
               	printf("exiting...\n");
                break;
            default:
                printf("invalid choice. try again.\n");
       	}
    } while (choice != 5);
    
    return 0;
}

