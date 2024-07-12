#pragma once

#include "MyMenu.h"
#include <memory>
#include <stdio.h>
#include <iostream>

class MyMenu;
/**
 * @brief Interface for a menu item.
 * 
 * This class defines an interface for menu items with basic properties 
 * like name and an abstract method for opening the item.
 */
class IMenuItem {
	public:

		/**
		 * @brief Retrieves the name of the menu item.
		 * 
		 * @return The name of the menu item.
		 */
		std::string getItemName() {
			return this->itemName;
		}
		
		/**
		 * @brief Sets the name of the menu item.
		 * 
		 * @param itemName The name to set for the menu item.
		 */
		void setItemName(std::string itemName) {
			this->itemName = itemName;
		}

		/**
		 * @brief Opens the menu item (pure virtual).
		 * 
		 * This method is meant to be overridden by derived classes to define 
		 * specific behavior for opening the menu item.
		 * @param myMenu Pointer to manage the previous menu
		 */
		virtual void Open(MyMenu *myMenu) = 0;

	private:
		std::string itemName; ///< Name of the menu item.
};
