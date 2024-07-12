#pragma once

#include <ncurses.h>
#include <string>
#include <vector>
#include <memory>
#include "IMenuItem.h"

class IMenuItem;
/**
 * @brief A class representing a menu using ncurses.
 * 
 * This class manages a menu interface using ncurses library.
 */
class MyMenu {
	public:
		/**
		 * @brief Constructor for MyMenu.
		 * 
		 * @param menuTitle The title of the menu.
		 */
		MyMenu(std::string menuTitle);

		/**
		* @brief Starts the menu interaction.
		*/
		void Start();

		/**
		 * @brief Appends an item to the menu.
		 * 
		 * @param item Pointer to the menu item to append.
		 */
		void AppendItem(std::unique_ptr<IMenuItem> item);

		/**
		 * @brief Appends an item to the menu.
		 * 
		 * @param item Pointer to the menu item to remove.
		 */
		void RemoveItem(IMenuItem *item);
	private:
		std::vector<std::unique_ptr<IMenuItem>> menuItems; ///< List for menu options 
		std::string menuTitle; ///< Title of the menu.
							   ///
		/**
		 * @brief Displays the menu with highlighting.
		 * 
		 * @param highlight The index of the currently highlighted menu item.
		 */
		void displayMenu(int highlight);

		/**
		 * @brief Manages user choice selection.
		 * 
		 * @param choice The user's selected menu option index.
		 * @param highlight The index of the currently highlighted menu item.
		 */
		void manageChoice(int choice, int highlight);
		
		/**
		* @brief Initializes ncurses for menu display.
		*/
		void initNcurses();
};
