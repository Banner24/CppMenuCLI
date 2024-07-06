#include "Menu/MyMenu.h"
#include "Menu/Items/DemoItem1.h"
#include "Menu/Items/DemoItem2.h"

int main() {
    // Create a new instance of MyMenu with "Main Menu" title
    MyMenu *menu = new MyMenu("Main Menu"); 	

    // Create a new DemoItem1 instance with name "Test"
    DemoItem1 *item = new DemoItem1("Test");

    // Create a new DemoItem2 instance with name "Test2"
    DemoItem2 *item2 = new DemoItem2("Test2");
	
    // Append DemoItem1 and DemoItem2 to the menu
    menu->AppendItem(item);
    menu->AppendItem(item2);

    // Start the menu interaction
    menu->Start();

    // Clean up
    delete menu;

    return 0;
}

/*
 * cmake -S . -B build/
 * in build/ : "make"
 *
 */
