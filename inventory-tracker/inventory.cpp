//
//  inventory.cpp
//
//  Created by Ethan Houser on 2/21/24.
//

#include "inventory.hpp"


// Getters
optional<Item> Inventory::getItem(string category, int itemID) {
    /*****************************************************
     * Gets an item by ID, returning an empty optional if the ID is not found
     *****************************************************/
    list<Item> categoryList = inventory[category];
    
    // If the item exist, return it, else return empty optional
    for (auto it = categoryList.begin(); it != categoryList.end(); it++) {
        if (itemID == it->getID())
            return *it;
    }
    return nullopt;
};

// Setters
void Inventory::addItem(string category, Item newItem) {
    /************************************************
     * Adds an item to the back of the list of items in a category
     ************************************************/
    if (inventory.find(category) == inventory.end())
        addCategory(category);
    list<Item>& items = inventory[category];
    items.push_back(newItem);
};
void Inventory::addCategory(string category) {
    /************************************************
     * Adds a category with an empty list to the inventory map
     ************************************************/
    // Check if the category already exists
    if (inventory.find(category) == inventory.end()) {
        // If the category doesn't exist, add it with an empty list
        inventory[category] = list<Item>();
    }
};
void Inventory::updateCategory(string category, Item item) {
    /************************************************
     * Adds a category with a list of items to the inventory map
     ************************************************/
    // Selects the category list to update
    list<Item>& list = inventory[category];
    // Inserts the item at the back of the list
    list.push_back(item);
};

// Display Functions
void Inventory::dispInventory() {
    /************************************************
     * Displays the entire inventory
     ************************************************/
    for (auto& pair : inventory) {
        // Assign key and value to variables
        string category = pair.first;
        list<Item> items = pair.second;
        
        // Display the category and items in a friendly way
        cout << endl;
        cout << "Category: " << category << endl;
        cout << "Items: " << endl;
        for_each(items.begin(), items.end(), [](Item& item) {item.dispAll();});
    }
};
void Inventory::dispCategory(string category) {
    list<Item> items = inventory[category];
    
    // Display the category and items in a friendly way
    cout << endl;
    cout << "Category: " << category << endl;
    cout << "Items: " << endl;
    for (auto& item : items)
        item.dispAll();
};
