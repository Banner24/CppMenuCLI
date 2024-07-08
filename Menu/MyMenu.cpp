#include "MyMenu.h"
#include "ExitItem.h"

MyMenu::MyMenu(std::string menuTitle){
	this->menuTitle = menuTitle;
	
	// adds an ExitItem.
	auto exit = std::make_unique<ExitItem>("Exit");
	this->menuItems.push_back(std::move(exit));
}

void MyMenu::AppendItem(std::unique_ptr<IMenuItem> item){
	this->menuItems.insert(menuItems.end()-1, std::move(item));
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
                if (highlight < menuItems.size() - 1)
                    ++highlight;
                break;
            case 10: // Enter-Key
                choice = highlight;
                break;
            default:
                break;
        }
        displayMenu(highlight);

        if (choice == menuItems.size() - 1) // if "Exit" is selected 
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

	menuItems[choice]->Open();	

	this->initNcurses();
    displayMenu(highlight);
}

void MyMenu::displayMenu(int highlight) {
    clear();

    mvprintw(0, 0, "%s", this->menuTitle.c_str());

    for (int i = 0; i < menuItems.size(); ++i) {
        if (i == highlight)
            attron(A_REVERSE); // Highlight
		mvprintw(i + 2, 0, "%s", menuItems[i]->getItemName().c_str());

        if (i == highlight)
            attroff(A_REVERSE);
    }
    refresh();
}
