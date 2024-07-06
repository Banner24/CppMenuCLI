# Project Overview
This project is a simple command-line interface (CLI) menu implemented in C++ using the `ncurses` library. It allows you to create menu items (DemoItem1/2 in this case) and interact with them using arrow keys and Enter key.

### Usage
1. To add a new menu item, you can create a class that inherits from IMenuItem interface.
DemoItem1/2 are provided as examples.
2. In the main function, create an instance of MyMenu and add instances of your menu items using AppendItem:
```
    // Create an instance of MyMenu with a title
    MyMenu menu("My CLI Menu");

    // Create instances of your menu items
    DemoItem1* item1 = new DemoItem1("Test1");
    DemoItem1* item2 = new DemoItem1("Test2");
    
    // Append menu items to the menu
    menu.AppendItem(item1);
    menu.AppendItem(item2);
    
    // Start the menu loop
    menu.Start();
```
3. Navigating the Menu:

- Once the program is executed, the CLI menu will display with the specified title and menu items.
Use arrow keys (up and down) to navigate through menu items.
Press Enter to execute the selected menu item's Execute function, which in this example, prints the item's name.
Press 'q' to quit and exit the program.

### Usage
To compile (project dir):
```
cmake -S . -B build/
cd build
make
```

# Preview
![screenshot](https://github.com/Banner24/CppMenuCLI/blob/main/screens/pic1.gif)
