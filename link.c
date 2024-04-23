#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "link.h"


Item* createItem(const char* name, int quantity) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    if (newItem == NULL) {
        printf("Memory allocation failed for item '%s'\n", name);
        exit(EXIT_FAILURE);
    }
    strcpy_s(newItem->name, sizeof(newItem->name), name);
    newItem->quantity = quantity;
    return newItem;
}

// Function to create a new warehouse
Warehouse* createWarehouse(const char* name) {
    Warehouse* newWarehouse = (Warehouse*)malloc(sizeof(Warehouse));
    if (newWarehouse == NULL) {
        printf("Memory allocation failed for warehouse '%s'\n", name);
        exit(EXIT_FAILURE);
    }
    strcpy_s(newWarehouse->name, sizeof(newWarehouse->name), name);
    newWarehouse->inventory = NULL;
    newWarehouse->next = NULL;
    return newWarehouse;
}

// Function to add an item to a warehouse's inventory
void addItemToWarehouse(Warehouse* warehouse, Item* item) {
    if (warehouse == NULL || item == NULL) {
        printf("Invalid input for adding item to warehouse\n");
        return;
    }
    item->next = warehouse->inventory;
    warehouse->inventory = item;
}

// Function to remove an item from a warehouse's inventory
void removeItemFromWarehouse(Warehouse* warehouse, const char* itemName) {
    if (warehouse == NULL || itemName == NULL) {
        printf("Invalid input for removing item from warehouse\n");
        return;
    }
    Item* curr = warehouse->inventory;
    Item* prev = NULL;

    while (curr != NULL) {
        if (strcmp(curr->name, itemName) == 0) {
            if (prev == NULL) {
                warehouse->inventory = curr->next;
            }
            else {
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Item '%s' not found in warehouse '%s'.\n", itemName, warehouse->name);
}

// Function to search for an item in a warehouse's inventory
Item* searchItemInWarehouse(Warehouse* warehouse, const char* itemName) {
    if (warehouse == NULL || itemName == NULL) {
        printf("Invalid input for searching item in warehouse\n");
        return NULL;
    }
    Item* curr = warehouse->inventory;

    while (curr != NULL) {
        if (strcmp(curr->name, itemName) == 0) {
            return curr;
        }
        curr = curr->next;
    }

    return NULL;
}

// Function to print the inventory of a warehouse
void printWarehouseInventory(Warehouse* warehouse) {
    if (warehouse == NULL) {
        printf("Invalid input for printing warehouse inventory\n");
        return;
    }
    printf("Inventory of warehouse '%s':\n", warehouse->name);
    Item* curr = warehouse->inventory;
    while (curr != NULL) {
        printf("  %s - Quantity: %d\n", curr->name, curr->quantity);
        curr = curr->next;
    }
}
// Function to add a warehouse to the list of warehouses
void addWarehouse(Warehouse** warehouses, Warehouse* newWarehouse) {
    if (warehouses == NULL || newWarehouse == NULL) {
        printf("Invalid input for adding warehouse\n");
        return;
    }
    newWarehouse->next = *warehouses;
    *warehouses = newWarehouse;
}

// Function to find a warehouse by name
Warehouse* findWarehouse(Warehouse* warehouses, const char* name) {
    Warehouse* curr = warehouses;
    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL; // Warehouse not found
}

// Function to delete all warehouses
void deleteAllWarehouses(Warehouse** warehouses) {
    Warehouse* curr = *warehouses;
    while (curr != NULL) {
        Warehouse* temp = curr;
        curr = curr->next;
        free(temp); // Free memory for warehouse
    }
    *warehouses = NULL; // Set warehouses pointer to NULL
}

// Function to print all warehouses
void printAllWarehouses(Warehouse* warehouses) {
    printf("Warehouses:\n");
    Warehouse* curr = warehouses;
    while (curr != NULL) {
        printf("- %s\n", curr->name);
        curr = curr->next;
    }
}
