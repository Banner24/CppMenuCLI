#pragma once

#include "../IMenuItem.h"
#include "../MyMenu.h"

/**
 * @brief DemoItem2 class representing another specific menu item example.
 * 
 * This class demonstrates another implementation of an IMenuItem,
 * providing functionality for setting its name and opening it.
 */
class DemoItem2 : public IMenuItem {
	public:
		/**
		 * @brief Constructor for DemoItem2.
		 * 
		 * @param itemName The name of the menu item.
		 */
		DemoItem2(std::string itemName) {
			this->setItemName(itemName);
		}

		/**
		 * @brief Opens the menu item.
		 * 
		 * Overrides the Open method from IMenuItem.
		 * Prints a message indicating the selected item and waits for user input.
		 * Here would be the point to add your code
		 * @param myMenu Pointer to manage the previous menu 
		 */
		void Open(MyMenu *myMenu) override {
			printf("\nThis is Item: %s\n", this->getItemName().c_str());
			myMenu->RemoveItem(this);	
			// Continue here!

			// Example: Wait for user input, then get back to the previous menu 
			getch();
		}
};
