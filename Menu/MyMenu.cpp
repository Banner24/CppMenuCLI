#include "MyMenu.h"
#include "ExitItem.h"

MyMenu::MyMenu(std::string menuTitle){
	this->menuTitle = menuTitle;
	
	// adds an ExitItem.
	ExitItem *exit = new ExitItem("Exit");
	this->options.push_back(exit);
}
MyMenu::~MyMenu() {
    // Delete dynamically allocated memory in options vector
    for (IMenuItem* item : options) {
        delete item;
    }
    options.clear(); // Clear the vector after deleting items
}
void MyMenu::AppendItem(IMenuItem *item){
	this->options.insert(options.end()-1, item);
}

void MyMenu::initNcurses(){
    initscr();            // Initialize ncurses
    clear();
    noecho();             // Disable echo input
    cbreak();             // Immediate input mode
    keypad(stdscr, TRUE); // Enable function keys
}

void MyMenu::Start(){
	this->initNcurses();

    int highlight = 0;
    int choice = -1;
    int c;

    displayMenu(highlight);
    while (1) {
        c = getch();
        switch (c) {
            case KEY_UP:
                if (highlight > 0)
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight < options.size() - 1)
                    ++highlight;
                break;
            case 10: // Enter-Key
                choice = highlight;
                break;
            default:
                break;
        }
        displayMenu(highlight);

        if (choice == options.size() - 1) // if "Exit" is selected 
            break;
		
		if (choice >= 0)
			this->manageChoice(choice, highlight);	

		choice = -1;
    }

    endwin(); // Stop ncurses
    return;
}

void MyMenu::manageChoice(int choice, int highlight){
    endwin(); // Stop ncurses
	std::system("clear");	

	options[choice]->Open();	

	this->initNcurses();
    displayMenu(highlight);
}

void MyMenu::displayMenu(int highlight) {
    clear();

    mvprintw(0, 0, "%s", this->menuTitle.c_str());

    for (int i = 0; i < options.size(); ++i) {
        if (i == highlight)
            attron(A_REVERSE); // Highlight
		mvprintw(i + 2, 0, "%s", options[i]->getItemName().c_str());

        if (i == highlight)
            attroff(A_REVERSE);
    }
    refresh();
}
