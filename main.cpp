// Include memory for smart pointers
#include <memory> 

#include "Menu/MyMenu.h"
#include "Menu/Items/DemoItem1.h"
#include "Menu/Items/DemoItem2.h"


int main() {
    // Create a new instance of MyMenu with "Main Menu" title
    auto menu = std::make_unique<MyMenu>("Main Menu");

    // Create a new DemoItem1 instance with name "Test"
    auto item = std::make_unique<DemoItem1>("Test");
    // Create a new DemoItem2 instance with name "Test2"
    auto item2 = std::make_unique<DemoItem2>("Test2");

    // Append DemoItem1 and DemoItem2 to the menu
    menu->AppendItem(std::move(item));
    menu->AppendItem(std::move(item2));

    // Start the menu interaction
    menu->Start();

    return 0;
}

/*
 * cmake -S . -B build/
 * in build/ : "make"
 *
 */
