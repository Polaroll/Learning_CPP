//
//  item.cpp
//
//  Created by Ethan Houser on 2/21/24.
//

#include "item.hpp"

int Item:: nextID = 0; // Initialization of static member

void Item::dispSpecs() {
    /******************************
     * Displays all specifications
     ******************************/
    for (auto& pair : specs) {
        cout << "+ " << pair.first << ": " << pair.second << endl;
    }
}

void Item::dispSpec(string spec) {
    /******************************
     * Displays one specification
     ******************************/
    if (specs.find(spec) == specs.end())
        cout << "+ " << spec << ": " << specs[spec] << endl;
    else
        cout << "Spec not found" << endl;
}
