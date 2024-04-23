#pragma once
// Structure to represent an item
typedef struct Item {
    char name[50];
    int quantity;
    struct Item* next;
} Item;

// Structure to represent a warehouse
typedef struct Warehouse {
    char name[50];
    struct Item* inventory;
    struct Warehouse* next;
} Warehouse;
Item* createItem(const char* name, int quantity);
Warehouse* createWarehouse(const char* name);
void addItemToWarehouse(Warehouse* warehouse, Item* item);
void removeItemFromWarehouse(Warehouse* warehouse, const char* itemName);
Item* searchItemInWarehouse(Warehouse* warehouse, const char* itemName);
void printWarehouseInventory(Warehouse* warehouse);
void addWarehouse(Warehouse** warehouses, Warehouse* newWarehouse);
Warehouse* findWarehouse(Warehouse* warehouses, const char* name);
void deleteAllWarehouses(Warehouse** warehouses);
void printAllWarehouses(Warehouse* warehouses);








