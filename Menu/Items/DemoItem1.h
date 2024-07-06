#pragma once

#include "../IMenuItem.h"
#include "../MyMenu.h"
/**
 * @brief DemoItem1 class representing a specific menu item example.
 * 
 * This class demonstrates a specific implementation of an IMenuItem,
 * providing functionality for setting its name and opening it,
 * as well as interacting with a MyMenu instance.
 */
class DemoItem1 : public IMenuItem {
public:
    /**
     * @brief Constructor for DemoItem1.
     * 
     * @param itemName The name of the menu item.
     */
    DemoItem1(std::string itemName) {
        this->setItemName(itemName);
    }

    /**
     * @brief Opens the menu item.
     * 
     * Overrides the Open method from IMenuItem.
     * Prints a message indicating the selected item and starts a new MyMenu instance.
     */
    void Open() override {
        printf("\nThis is Item: %s\n", this->getItemName().c_str());

        // Example: Create a new MyMenu instance and start it
        MyMenu *m = new MyMenu("Test Menu");
        m->Start();
    }
};
