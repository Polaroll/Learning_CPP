//
//  main.cpp
//  inventory-tracker
//
//  Created by Ethan Houser on 2/21/24.
//


#include <iostream>
#include "inventory.hpp"
#include "item.hpp"
using namespace std;


int main(void) {
    
    // Initialize inventory and create some test items
    Inventory inventory = Inventory();
    string          category = "Electronics";
    list<Item>      items;
    list<string>    itemNames = {"iPhone", "iPad", "Chromebook", "GPS", "Universal Charger"};
    list<int>       itemQty = {4, 2, 5, 8, 1};
    list<string>    itemDesc = {"The most overpriced mobile phone on the market.", "Just a bigger iPhone.", "The worst laptop a student can buy.", "For the directionally challenged.", "Will literally fit into and charge anything."};
    
    // Creates iterators to iterate through the list
    auto nameIt = itemNames.begin();
    auto qtyIt  = itemQty.begin();
    auto descIt = itemDesc.begin();

    // Create item objects and push to the items list
    for (int i = 0; i < 5; i++) {
        Item item;
        item.setName(*nameIt++);
        item.setQuantity(*qtyIt++);
        item.setDesc(*descIt++);
        items.push_back(item);
    }
    
    // Add the category and newly created items to inventory
    inventory.updateInventory(category, items);
    
    // Redefinition of test cases to create another set of test cases
    category = "Clothing";
    items.clear();
    itemNames.clear();
    itemNames = {"T-shirt", "Jacket", "Jeans", "Socks", "Shoes"};
    itemQty.clear();
    itemQty = {15, 20, 16, 24, 12};
    itemDesc.clear();
    itemDesc = {"Just a shirt.", "A leather jacket.", "Denim.", "They go on your feet!", "They go over your socks."};
    
    // Creates iterators to iterate through the list
    nameIt = itemNames.begin();
    qtyIt  = itemQty.begin();
    descIt = itemDesc.begin();

    // Create item objects and push to the items list
    for (int i = 0; i < 5; i++) {
        Item item;
        item.setName(*nameIt++);
        item.setQuantity(*qtyIt++);
        item.setDesc(*descIt++);
        items.push_back(item);
    }
    
    // Add the category and newly created items to inventory
    inventory.updateInventory(category, items);

    // Menu
    bool menu = true;
    while (menu) {
        cout << endl << endl;  // Spacing for looks
        cout << "Acount menu:\n";
        cout << "0. Quit Program\n";
        cout << "1. Display all items\n";
        cout << "2. Display items within a category\n";
        cout << "3. Add an item\n";
        cout << "\n";
        
        
        // Users menu choice
        int choice;
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
            case 0:
                // Exits the while loop
                menu = false;
                break;
            case 1:{
                // Display all items
                inventory.dispInventory();
                break;}
            case 2:{
                // Display items from within a category
                string category;
                cout << "Name of category: ";
                cin >> category;
                inventory.dispCategory(category);
                break;}
            case 3:{
                // Add an item
                // Declare variables
                string itemCategory;
                string itemName;
                int itemQty;
                string itemDesc;
                
                // Recieve user input and set variables
                cout << "Category of item: ";
                cin >> itemCategory;
                cout << "Item name: ";
                cin.ignore();
                getline(cin, itemName);
                cout << "Item quantity: ";
                cin >> itemQty;
                cout << "Item description: ";
                cin.ignore();
                getline(cin, itemDesc);
                
                // Create Item
                Item item = Item(itemName, itemQty, itemDesc);
                
                // Add item to inventory
                inventory.addItem(itemCategory, item);
                break;}
//            case 4:{
//
//                break;}
//            case 5: {
//
//                break;}
//            case 6:{
//
//                break;}
//            case 7:{
//
//                break;}
//            case 8:{
//
//                break;}
//            case 9: {
//
//                break;}
        } // End of switch
    } // End of menu
    
    return 0;
} // End of main
