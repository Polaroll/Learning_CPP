//
//  item.hpp
//
//  Created by Ethan Houser on 2/21/24.
//

#ifndef item_hpp
#define item_hpp

#include <stdio.h>
#include <iostream>
#include "unordered_map"
using namespace std;

class Item {
public:
    // Constructors
    Item() : name(""),
             ID(nextID),
             quantity(0),
             desc("")
             {nextID++;};
    Item(string newName, int newQuantity, string newDesc) : name(newName),
                                                            ID(nextID),
                                                            quantity(newQuantity),
                                                            desc(newDesc)
                                                            {nextID++;};
    
    // Copy assignment operator
    // Leveraged from ChatGPT
    Item& operator=(const Item& other) {
        if (this != &other) {
            // Copy member variables from 'other' to 'this'
            this->name      = other.name;
            this->quantity  = other.quantity;
            this->desc      = other.desc;
            this->specs     = other.specs;
        }
        return *this;
    }
    
    // Getters
    string  getName()                           const {return name;}
    int     getID()                             const {return ID;}
    int     getQuantity()                       const {return quantity;}
    string  getDesc()                           const {return desc;}
    unordered_map<string, string> getSpecs()    const {return specs;}
    string  getSpecValue(string key)                  {return specs[key];}
    
    // Setters
    void    setName(string newName)                 {name = newName;}
//    void    setID(int newID)                        {ID = newID;}
    void    setQuantity(int newQuantity)            {quantity = newQuantity;}
    void    setDesc(string newDesc)                 {desc = newDesc;}
    void    updateSpecs(string key, string value)   {specs[key] = value;}
    
    // Display functions
    void dispAll()          {dispName(); dispID(); dispQuantity(); dispDesc(); dispSpecs();}
    void dispName()         {cout << "Item Name: " << name << endl;}
    void dispID()           {cout << "+ Item ID: " << ID << endl;}
    void dispQuantity()     {cout << "+ Quantity: " << quantity << endl;}
    void dispDesc()         {cout << "+ Description: " << desc << endl;}
    void dispSpecs();           // Displays all specifications
    void dispSpec(string spec); // Displays a single specification
private:
    string      name;
    int const   ID;
    int static  nextID;
    int         quantity;
    string      desc; // Description
    unordered_map<string, string> specs; // Height, width, batteries, etc.
    
};

#endif /* item_hpp */
