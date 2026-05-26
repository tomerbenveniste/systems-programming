#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/**************************************************************************************************/
/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
#define DEBUGON
/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
/**************************************************************************************************/

/* Submitters
Name1: Privetname Familyname     ID: xxxxxxxx
Name2: Privetname Familyname     ID: xxxxxxxx
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* structures */
// Item defenition: name, id, link list of warehouses where the item is stored
typedef struct item {
    char* name;
    int  id;
    struct wlst* warehouses;
} item;

// warehouse defenition: location, code, link list of items in the warehouse
typedef struct warehouse {
    char* location;
    int  code;
    struct itemlst* items;
} warehouse;

//Linked list of all items exists in the world
typedef struct itemlst {
    item* data;
    struct itemlst* next;
} itemlst;

//Linked list of warehouses around the globe
typedef struct wlst {
    warehouse* data;
    struct wlst* next;
} wlst;


/******************************************* your's prototypes *******************************************************************************/

item* create_item(char *name, int id, itemlst **items);
warehouse* create_warehouse(char *name, int code, wlst **warehouses);

warehouse* add_last_whs(wlst **head, warehouse* newWhs);
item* add_last_itemlst(itemlst **head, item* newItem);

void print_items(itemlst *items, wlst *warehouses);
void print_whs_lst(wlst *head);
void print_item_lst(itemlst *head);

item* search_item_by_id(itemlst *head, int id);
warehouse* search_warehouse_by_code(wlst *head, int code);

void print_error_message(int errid);


/******************************************* your's functions ********************************************************************************/
item* search_item_by_id(itemlst *head, int id){
    if (!head) {
        return NULL;
    }
    if(head->data->id == id){
        return head->data;
    }
    return search_item_by_id(head->next, id);
}
warehouse* search_warehouse_by_code(wlst *head, int code){
    if (!head) {
        return NULL;
    }
    if(head->data->code == code){
        return head->data;
    }
    return search_warehouse_by_code(head->next, code);
}


/*****************************************new objects and insert object functions******************************************************/

item* create_item(char *name, int id, itemlst **items) {
    if(search_item_by_id(*items, id) != NULL){
        return NULL;
    }
    item *itm;
    itm = malloc(sizeof(item));
    if (itm == NULL) {
        print_error_message(1);
    }
    // allocating memory for the string before copying it
    itm->name = malloc(strlen(name) + 1);
    if (itm->name == NULL) {
        print_error_message(1);
    }
    strcpy(itm->name, name);
    itm->id = id;
    itm->warehouses = NULL;
    add_last_itemlst(items, itm);
    return itm;
}


warehouse* create_warehouse(char *location, int code, wlst **warehouses) {
    if(search_warehouse_by_code(*warehouses, code) != NULL){
        return NULL;
    }
    warehouse *whs;
    whs = malloc(sizeof(warehouse));
    if (whs == NULL) {
        print_error_message(1);
    }
    // allocating memory for the string before copying it
    whs->location = malloc(strlen(location) + 1);
    if (whs->location == NULL) {
        print_error_message(1);
    }
    strcpy(whs->location, location);
    whs->code = code;
    whs->items = NULL;
    add_last_whs(warehouses, whs);
    return whs;
}


item* add_last_itemlst(itemlst **head, item* newItem){
    // if current (recursive call) head is NULL, we add the newWhs to the current head
    if (!*head) {
        *head = malloc(sizeof(itemlst));
        if (*head == NULL) {
            print_error_message(2);
        }   
        (*head)->data = newItem;
        (*head)->next = NULL;
        return newItem;
    }
    // if current head is not NULL, we check if the current head is the same as the newWhs
    if (newItem->id == (*head)->data->id)
    {
        return (*head)->data;
    }
    // if current head is not NULL, we go to the next head
    add_last_itemlst(&((*head)->next), newItem);
}

warehouse* add_last_whs(wlst **head, warehouse* newWhs){
    // if current (recursive call) head is NULL, we add the newWhs to the current head
    if (!*head) {
        *head = malloc(sizeof(wlst));
        if (*head == NULL) {
            print_error_message(2);
        }   
        (*head)->data = newWhs;
        (*head)->next = NULL;
        return newWhs;
    }
    // if current head is not NULL, we check if the current head is the same as the newWhs
    if (newWhs->code == (*head)->data->code)
    {
        return (*head)->data;
    }   
    // if current head is not NULL, we go to the next head
    return add_last_whs(&((*head)->next), newWhs);
}





/****************************************find Matchings and register item to Warehouse*************************************************/



/********************************************uregisters objects*************************************************************************/



/***********************************************printout functions***********************************************************************/
void print_item_lst(itemlst *head){
 printf("item LIST:\n");
 itemlst *ptr = head;
 if (!head){
    printf("item LIST is empty\n");
    return;
 }
 while(ptr){
    printf("%d:%s\n", ptr->data->id, ptr->data->name);
    ptr = ptr->next;
 }
}

void print_items(itemlst *items, wlst *warehouses){
    print_item_lst(items);
    print_whs_lst(warehouses);
}

void print_whs_lst(wlst *head){
    printf("warehouse LIST:\n");
    wlst *ptr = head;
    if (!head){
        printf("warehouse LIST is empty\n");
        return;
    }
    while(ptr){
        printf("Warehouse code %d, Warehouse name: %s\n", ptr->data->code, ptr->data->location);
        print_item_lst(ptr->data->items);
        ptr = ptr->next;
    }
}

/***************************************************free**********************************************************************************/


/*******************************************Generate And Assign Items And Warehouses******************************************************/
warehouse* assign_item_to_warehouse(int item_id, int warehouse_num, wlst *warehouses, itemlst *itemlst){
    warehouse *warehouse = search_warehouse_by_code(warehouses, warehouse_num);
    if(!warehouse){
        print_error_message(4);
        return warehouse;
    }
    item *item = search_item_by_id(itemlst,item_id);
    if(!item){
        print_error_message(5);
        return warehouse;
    }
    
    add_last_itemlst(&(warehouse->items), item);
    return warehouse;
}


    


/*DO NOT TOUCH THIS FUNCTION */
void getstring(char* buf, int length) {
    int len;
    //buf = fgets(buf, length, stdin);
	scanf("%s", buf);
    len = (int)strlen(buf);
    if (buf[len - 1] == '\n')
        buf[len - 1] = '\0';
}


/*DO NOT TOUCH THIS FUNCTION */

void print_error_message(int errid) {
	#ifdef DEBUGON
	fprintf(stderr, "BGU ERROR %d\n", errid);
	#else
	fprintf(stderr, "BGU ERROR\n");	
	#endif
	exit(-1);
}

/*DO NOT TOUCH THIS MAIN TEMPLATE - ONLY ADD YOUR FUNCTIONS CALLS */
int main() {
    itemlst* items = 0;
    wlst* warehouses = 0;
    char  c;
    char  buf[100];
    int   id, num;
	


    do {
        printf("Choose:\n"
            "    i - new item\n"
            "    w - new warehouse\n"
            "    a - assign an item to a warehouse\n"
            "    u - unassign an item from a warehouse(not delete!)\n"
            "    p - print status\n"
			"    g - generating and assigning 100 items to 10 warehouses\n"
            "    q - quit\n");

        while ((c = (char)getchar()) == '\n');
        getchar();

        switch (c) {
        case 'i':
            printf("Adding new item.\n");

            printf("item name: ");
            getstring(buf, 100);
			

            printf("item ID: ");
            scanf("%d", &id);
			
			printf("\n Add new item: name %s item id: %d",buf, id);
            
			create_item(buf, id, &items);
        
            break;

        case 'w':
            printf("Adding new warehouse.\n");

            printf("\n warehouse name: ");
            getstring(buf, 100);

            printf("\n warehouse code: ");
            scanf("%d", &num);
			
			printf("\n Add new warehouse: name %s warehouse code: %d",buf, num);
            
			create_warehouse(buf, num, &warehouses);

            break;

        case 'a':
            printf("Assign an item to a warehouse.\n");

            printf("item ID: ");
            scanf("%d", &id);

            printf("warehouse code: ");
            scanf("%d", &num);

            //your function
            assign_item_to_warehouse(id, num, warehouses, items);
            break;

        case 'u':
            printf("Remove an item from a warehouse.\n");

            printf("item ID: ");
            scanf("%d", &id);

            printf("warehouse code: ");
            scanf("%d", &num);

           //your function

            break;

        case 'p':
            printf("Printing status.\n");

            print_items(items, warehouses);
            //your function

            break;
			
		case 'g':  // generating and assigning items and warehouses
			printf("Generating and assigning items to warehouses\n");
		
			//your function
			
			break;

        case 'q':
            printf("Quitting...\n");
            break;
        }

        if (c != 'q')
            printf("\n");
    } while (c != 'q');

    //your free functions
	return 0;
    
}




