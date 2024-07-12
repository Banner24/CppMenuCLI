#pragma once

#include "IMenuItem.h"
/**
 * @brief A menu item representing an exit option.
 * 
 * This class inherits from IMenuItem and provides functionality 
 * specific to an exit menu item.
 */
class ExitItem : public IMenuItem{
	public:
	    /**
		 * @brief Constructor for ExitItem.
		 * 
		 * @param itemName The name of the exit item.
		 */
		ExitItem(std::string itemName){
			this->setItemName(itemName);	
		}
		/**
		 * @brief Opens the exit item.
		 * 
		 * This function overrides the Open method from the IMenuItem interface.
		 * It prints a message indicating the selected item.
		 * @param myMenu Pointer to manage the previous menu
		 */
		void Open(MyMenu *myMenu) override{
			printf("\nThis is Item: %s\n", this->getItemName().c_str());
		}
};
