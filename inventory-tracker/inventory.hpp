//
//  inventory.hpp
//
//  Created by Ethan Houser on 2/21/24.
//

#ifndef inventory_hpp
#define inventory_hpp

#include <stdio.h>
#include <list>
#include "item.hpp"

class Inventory {
public:
    // Constructors
    Inventory() : inventory(){};
    Inventory(string category, list<Item> items) {inventory[category] = items;}
    Inventory(unordered_map<string, list<Item>> newInventory) : inventory(newInventory) {};
    
    // Getters
    unordered_map<string, list<Item>>   getInventory()                          {return inventory;}
    list<Item>                          getCategory(string category)            {return inventory[category];}
    optional<Item>                      getItem(string category, int itemID);
    
    // Setters
    void updateInventory(string category, list<Item> list) {inventory[category] = list;}
    void addItem(string category, Item newItem);
    void addCategory(string category);
    void updateCategory(string category, Item item);
    
    // Display functions
    void dispInventory();
    void dispCategory(string category);
    
private:
    unordered_map<string, list<Item>> inventory; // Will hold different categories of items: electronics, kitchen, grocery, etc.
};

#endif /* inventory_hpp */
