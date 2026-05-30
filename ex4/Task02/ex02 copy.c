#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/**************************************************************************************************/
/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
// #define DEBUGON
/***************************YOU MUST REMARK IT BEFORE SUBMISSION***********************************/
/**************************************************************************************************/

/* Submitters
Name1: Tomer Benveniste     ID: 207961954
Name2: Carmi Finkelstein    ID: 206463846
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* structures */
// Item definition: name, id, linked list of warehouses where the item is stored
typedef struct item {
    char* name;
    int  id;
    struct wlst* warehouses;
} item;

// warehouse definition: location, code, linked list of items in the warehouse
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


/******************************************* function declarations *******************************************************************************/
//create warehouse and add it to the list
warehouse* create_warehouse(char *name, int code, wlst **warehouses);
//create item and add it to the list
item* create_item(char *name, int id, itemlst **items);
//add warehouse to the warehouses list sorted via code
warehouse* add_sorted_whs(wlst **head, warehouse* newWhs);
//add item to the items list sorted via ID
item* add_sorted_itemlst(itemlst **head, item* newItem);
//search warehouse by code
warehouse* search_warehouse_by_code(wlst *head, int code);
//search item by id
item* search_item_by_id(itemlst *head, int id);
// assign item to warehouse
void assign_item_to_warehouse(int item_id, int warehouse_code, wlst **warehouses, itemlst **itemlst);
// unassign item to warehouse (without deleting anything)
void unassign_item_from_warehouse(int item_id, int warehouse_code, wlst **warehouses, itemlst **itemlst);
//print warehouses list
void print_whs_lst(wlst *head);
//print items list
void print_item_lst(itemlst *head);
//print items and warehouses
void print_items(itemlst *items, wlst *warehouses);
//print error messages
void print_error_message(int errid);
// generating and assigning 100 items to 10 warehouses
void generate_and_assign(itemlst **items, wlst **warehouses);
// free all malloced data
void free_all(itemlst **items, wlst **warehouses);
// free malloced item helper function
void free_item(item *itm);
// free malloced warehouse helper function
void free_warehouse(warehouse *whs);

/******************************************* search functions *****************************************************************/
//search item by id
item* search_item_by_id(itemlst *head, int id){
    // if head is NULL, we return NULL
    if (!head) {
        return NULL;
    }
    // if head is not NULL, we check if the current head is the same as the newWhs
    if(head->data->id == id){
        return head->data;
    }
    //if not, we go to the next element in link list
    return search_item_by_id(head->next, id);
}
//search warehouse by code
warehouse* search_warehouse_by_code(wlst *head, int code){
    // if head is NULL, we return NULL
    if (!head) {
        return NULL;
    }
    // if head is not NULL, we check if the current head is the same as the newWhs
    if(head->data->code == code){
        return head->data;
    }
    //if not, we go to the next element in link list
    return search_warehouse_by_code(head->next, code);
}

/**************************************** creating new objects functions *****************************************************/
//create item
item* create_item(char *name, int id, itemlst **items) {
    // if item with same id is already exists, return NULL
    item *existing = search_item_by_id(*items, id);
    if (existing != NULL) {
        return existing;
    }
    item *itm; // if item with same id is not exists, create new item
    itm = malloc(sizeof(item)); // allocating memory for the item
    // if memory allocation failed, print error message
    if (itm == NULL) {
        print_error_message(1);
    }
    itm->name = malloc(strlen(name) + 1); // allocating memory for the string before copying it (+1 is for \0)
    // if memory allocation failed, print error message
    if (itm->name == NULL) {
        print_error_message(1);
    }
    // copying the string
    strcpy(itm->name, name);
    itm->id = id;
    itm->warehouses = NULL;

    add_sorted_itemlst(items, itm); // add new item to the sorted linked list of all items
    return itm; // return new item
}

//create warehouse
warehouse* create_warehouse(char *location, int code, wlst **warehouses) {
    // if warehouse with same code is already exists, return NULL
    warehouse *existing = search_warehouse_by_code(*warehouses, code);
    if (existing != NULL) {
        return existing;
    }
    // if warehouse with same code is not exists, create new warehouse
    warehouse *whs;
    // allocating memory for the warehouse
    whs = malloc(sizeof(warehouse));
    // if memory allocation failed, print error message
    if (whs == NULL) {
        print_error_message(1);
    }
    // allocating memory for the string before copying it
    whs->location = malloc(strlen(location) + 1);
    // if memory allocation failed, print error message
    if (whs->location == NULL) {
        print_error_message(1);
    }
    // copying the string
    strcpy(whs->location, location);
    whs->code = code;
    whs->items = NULL;
    // add new warehouse to the sorted linked list of all warehouses
    add_sorted_whs(warehouses, whs);
    return whs;
}

/**************************************** sorted inserting object functions *****************************************************/

// item was created, now need to insert via ID sort
item* add_sorted_itemlst(itemlst **head, item* newItem){
    /* if current (recursive call) head is NULL or with bigger ID than newItem,
     * we add the newItem to the sorted Linked List */
    if (!*head || newItem->id < (*head)->data->id) {
        itemlst *node = malloc(sizeof(itemlst));
        if (!node) print_error_message(2);
        node->data = newItem;
        node->next = *head;
        *head = node;
        // return new item
        return newItem;
    }
    /* if current head is not NULL and with smaller ID than newItem,
     * we call recursion again with (*head)->next */
    return add_sorted_itemlst(&((*head)->next), newItem);
}

// item was created, now need to insert via code sort
warehouse* add_sorted_whs(wlst **head, warehouse* newWhs){
    /* if current (recursive call) head is NULL or with bigger code than newWhs,
     * we add the newWhs to the sorted Linked List */
    if ( !(*head) || newWhs->code < (*head)->data->code) {
        wlst *node = malloc(sizeof(wlst));
        if (!node) print_error_message(2);
        node->data = newWhs;
        node->next = *head;
        *head = node;
        // return new warehouse
        return newWhs;
    }
    /* if current head is not NULL and with smaller ID than newItem,
     * we call recursion again with (*head)->next */
    return add_sorted_whs(&((*head)->next), newWhs);
}

/*************************************** assign/unassign item to a Warehouse ************************************************/

// assign item to warehouse
void assign_item_to_warehouse(int item_id, int warehouse_code, wlst **warehouses, itemlst **items){
    // search for warehouse by code
    warehouse *whs = search_warehouse_by_code(*warehouses, warehouse_code);
    if(!whs) 
    {
        print_error_message(4); // if warehouse not found, print error message
        return;

    }

    // search for item by id
    item *itm = search_item_by_id(*items, item_id);
    if(!itm)
    {
        print_error_message(5); // if item not found, print error message
        return;
    } 
        
    if(search_item_by_id(whs->items, item_id)) 
    {
        return;
    }
    // add item to warehouse's items list
    add_sorted_itemlst(&(whs->items), itm);
    // add warehouse to item's warehouses list
    add_sorted_whs(&(itm->warehouses), whs);
}

// unassign item to warehouse
void unassign_item_from_warehouse(int item_id, int warehouse_code, wlst **warehouses, itemlst **items){
    // search for warehouse by code
    warehouse *whs = search_warehouse_by_code(*warehouses, warehouse_code);
    if(!whs) print_error_message(4); // if warehouse not found, print error message

    // search for item by id
    item *itm = search_item_by_id(*items, item_id);
    if(!itm) print_error_message(5); // if item not found, print error message

    // remove item from warehouse's items list
    itemlst **itm_ptr = &(whs->items); // a pointer to the pointer of the items list of the warehouse
    // as long as the item pointer is not NULL and is not pointing on the requested item, continue to search
    while (*itm_ptr && (*itm_ptr)->data != itm) itm_ptr = &((*itm_ptr)->next);
    // the pointer is not NULL but points to the requested item
    if (*itm_ptr) {
        /* creating a tmp pointer to save the item address of the item we want to remove,
         * that way we can free the allocated memory later */
        itemlst *tmp = *itm_ptr;
        // rewire the pointer to the next one
        *itm_ptr = (*itm_ptr)->next;
        // free the item from the list of that warehouse (the struct in the global struct list stays)
        free(tmp);
    }

    // remove warehouse from item's warehouses list - same structure as before
    wlst **whs_ptr = &(itm->warehouses);
    while (*whs_ptr && (*whs_ptr)->data != whs) whs_ptr = &((*whs_ptr)->next);
    if (*whs_ptr) {
        wlst *tmp = *whs_ptr;
        *whs_ptr = (*whs_ptr)->next;
        free(tmp);
    }
}

/********************************************** printout functions **********************************************************************/

// print linked list of items
void print_item_lst(itemlst *head){
 printf("item LIST:\n");
 itemlst *ptr = head;
 // if head is NULL, just return
 if (!head){
    return;
 }

 // print all items with their warehouses lists
 while(ptr){
    printf("%d:%s\n", ptr->data->id, ptr->data->name);
    // check if the item has a warehouses list for printing
    if (ptr->data->warehouses) {
        printf("Item Warehouses: ");
        wlst *wp = ptr->data->warehouses;
        // goes over all warehouses in the list and printing them
        while (wp) {
            printf("%d-%s", wp->data->code, wp->data->location);
            if (wp->next) printf(", ");
            wp = wp->next;
        }
         printf("\n");
    }
    // moving over to the next item if exists
    ptr = ptr->next;
 }
}

// print all items and warehouses
void print_items(itemlst *items, wlst *warehouses){
    print_item_lst(items);
    print_whs_lst(warehouses);
}

// print linked list of warehouses
void print_whs_lst(wlst *head){
    printf("warehouse LIST:\n");
    wlst *ptr = head;
    // if head is NULL, just return
    if (!head){
        return;
    }
    // print all warehouses and the items assigned to them if they have
    while(ptr){
        printf("Warehouse code %d, Warehouse name: %s\n", ptr->data->code, ptr->data->location);

        if (ptr->data->items) {
            printf("items: ");
            itemlst *ip = ptr->data->items;
            // goes over all items in the list and printing them
            while (ip) {
                printf("ID %d Name %s", ip->data->id, ip->data->name);
                if (ip->next) printf(" | ");
                ip = ip->next;
            }
            printf(" |\n");
        }
        // moving over to the next warehouse if exists
        ptr = ptr->next;
    }
}
/******************************************* generate function *************************************************************************/
// generate and assign 100 items to 10 warehouses
void generate_and_assign(itemlst **items, wlst **warehouses) {
    int i;
    char name[20];

    // creating 10 warehouses needed for storing 100 items later
    for (i = 0; i < 10; i++) {
        sprintf(name, "Warehouse%d", i); // takes the string and puts it in 'name'
        create_warehouse(name, i, warehouses); // creates the warehouse
    }

    srand(1948); //

    // creating 100 items and assigning them to warehouses randomly
    for (i = 0; i < 100; i++) {
        int randomCode = rand() % 10;
        sprintf(name, "Item%d", i);
        create_item(name, i, items);
        assign_item_to_warehouse(i, randomCode, warehouses, items);
    }
}

/************************************************** free *********************************************************************************/

// free all malloced data
void free_all(itemlst **items, wlst **warehouses) {
    // freeing all items using the helper
    itemlst *ip = *items;
    while (ip) {
        itemlst *tmp = ip->next;
        free_item(ip->data);
        free(ip);
        ip = tmp;
    }

    // freeing all warehouses using the helper
    wlst *wp = *warehouses;
    while (wp) {
        wlst *tmp = wp->next;
        free_warehouse(wp->data);
        free(wp);
        wp = tmp;
    }
}

// free malloced item helper function
void free_item(item *itm) {
    // first freeing the cross-reference nodes
    wlst *wp = itm->warehouses;
    while (wp) {
        wlst *tmp = wp->next; // capture the next address so we don't lose it
        free(wp);
        wp = tmp;
    }

    // secondly freeing the name string
    char *np = itm->name;
    free(np);

    // third and last - freeing the struct itself
    free(itm);
}

// free malloced warehouse helper function
void free_warehouse(warehouse *whs) {
    // first freeing the cross-reference nodes
    itemlst *ip = whs->items;
    while (ip) {
        itemlst *tmp = ip->next; // capture the next address so we don't lose it
        free(ip);
        ip = tmp;
    }

    // secondly freeing the location string
    char *lp = whs->location;
    free(lp);

    // third and last - freeing the struct itself
    free(whs);
}


/*DO NOT TOUCH THIS FUNCTION */
void getstring(char* buf, int length) {
    int len;
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

            assign_item_to_warehouse(id, num, &warehouses, &items);
            break;

        case 'u':
            printf("Remove an item from a warehouse.\n");

            printf("item ID: ");
            scanf("%d", &id);

            printf("warehouse code: ");
            scanf("%d", &num);

            unassign_item_from_warehouse(id, num, &warehouses, &items);

            break;

        case 'p':
            printf("Printing status.\n");

            print_items(items, warehouses);

            break;

		case 'g':  // generating and assigning items and warehouses
			printf("Generating and assigning items to warehouses\n");

            generate_and_assign(&items, &warehouses);

			break;

        case 'q':
            printf("Quitting...\n");

            break;

        default:
            //print_error_message(3);
            break;
        }

        if (c != 'q')
            printf("\n");
    } while (c != 'q');

    //your free functions
    free_all(&items, &warehouses);

	return 0;

}
