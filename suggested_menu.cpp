#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Class to represent a menu item with day of the week
class menuItem {
    public:
        /**********************************************************************
        **  Create 3 main meals instead of just 1 meal currently
        **********************************************************************/
        string dayOfWeek;
        string dish;
        string dishOption;
};

// Function to display menu
void showMenu(menuItem menu[], int size) {
    cout << "Suggested Menu for the Week:" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << menu[i].dayOfWeek << ": " << menu[i].dish << endl;
    }
}

// Function to get user's choice
bool getUserChoice(string& dayOfWeek, string& dish, string& dishOption) {
    string confirmChoice;
    while (true) {
    // Check user input, compare with default character
        cout << dayOfWeek << ": " << "Do you wanna change " << dish << " to " << dishOption << "? ";
        cin >> confirmChoice;
        // Convert input to lowercase
        transform(confirmChoice.begin(), confirmChoice.end(),
        confirmChoice.begin(), ::tolower);
        // Get user choice
        if (confirmChoice == "yes" || confirmChoice == "y") {
            cout << "Great choice! Updated for " << dayOfWeek 
                 << ": " << dishOption << endl;
            return true;
        } else if (confirmChoice == "no" || confirmChoice == "n") {
            return false;
        } else {
            cout << "Invalid choice! Please enter YES or NO." << endl;
        }
    }
}

// Function to suggest menu based on BMI
void suggestMenu(float BMI) {

/******************************************************************************
**              Edit the menu to specific meals of the day                   **
******************************************************************************/
    menuItem menu[][7] = {
        // Menu 0: For BMI >= 30
        {   {"Monday", "Grilled chicken salad", 
            "Grilled chicken breast with steamed vegetables"},

            {"Tuesday", "Steamed vegetables with quinoa", 
            "Quinoa salad with mixed greens and avocado"},

            {"Wednesday", "Baked fish with mixed greens", 
            "Baked fish with lemon and herbs served with asparagus"},

            {"Thursday", "Vegetable stir-fry with tofu", 
            "Vegetable stir-fry with tofu and brown rice"},

            {"Friday", "Lentil soup with whole grain bread", 
            "Lentil soup with whole grain bread"},

            {"Saturday", "Grilled salmon with asparagus", 
            "Grilled salmon with broccoli and sweet potato"},

            {"Sunday", "Vegetable and bean chili", 
            "Vegetable and bean chili with a side of green salad"}},
           
        // Menu 1: For BMI < 18.5   
        {   {"Monday", "Avocado toast with poached eggs", 
            "Grilled lamb chops with roasted sweet potatoes and collard greens"},

            {"Tuesday", "Fruit smoothie with oats",
            "Steamed brown rice with chicken and lettuce"},

            {"Wednesday", "Quinoa salad with nuts and berries", 
            "Stewed beef pasta with tomato sauce"},

            {"Thursday", "Chickpea and vegetable curry",
            "Chicken salad with onions, cucumbers and pumpkin seeds"},

            {"Friday", "Vegetable and bean soup", 
            "Chicken sandwich and Beef with raw vegetables and soy sauce"},

            {"Saturday", "Grilled tofu with brown rice", 
            "Snakehead fish sour soup with green vegetables and tomatoes"},

            {"Sunday", "Stir-fried vegetables with tofu", 
            "Tuna sandwich with coconut nuts and raw vegetables"}},

        // Menu 2: For Normal BMI
        {   {"Monday", "Grilled chicken with brown rice and broccoli", 
            "Beef stir-fry with mixed vegetables and brown rice"},

            {"Tuesday", "Greek yogurt with fruits and nuts", 
            "Fruit and nut granola with yogurt"},

            {"Wednesday", "Spinach and feta omelette", 
            "Mushroom and cheese omelette with whole grain toast"},

            {"Thursday", "Turkey sandwich with whole wheat bread", 
            "Grilled vegetable wrap with hummus"},

            {"Friday", "Salmon with sweet potato and green beans", 
            "Baked chicken breast with roasted potatoes and steamed broccoli"},

            {"Saturday", "Quinoa salad with grilled vegetables", 
            "Grilled shrimp salad with avocado and citrus dressing"},

            {"Sunday", "Lentil soup with whole grain bread", 
            "Vegetable and bean burritos with salsa"}}
    };

    // Categorize menus based on BMI
    int menuIndex = (BMI >= 30) ? 0 : (BMI < 18.5) ? 1 : 2;

    // Show suggested menu
    showMenu(menu[menuIndex], 7);
    // Change the menu based on user requested
    bool changedMenu = false;
    string choice;
    cout << "Would you like to change the menu? ";
    cin >> choice;
    
    // Convert user choice to lowercase
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
    while (!(choice == "yes" || choice == "y" || choice == "no" || choice == "n")) {
        cout << "Invalid choice! Please enter YES or NO: ";
        cin >> choice;
    }
    // Get user choice
    if (choice == "yes" || choice == "y") {
        cout << "Some recommended dishes for you:" << endl;
        cout << "----------------------------------" << endl;
        for (int i = 0; i < 7; ++i) {
            if (getUserChoice(menu[menuIndex][i].dayOfWeek, menu[menuIndex][i].dish,
                              menu[menuIndex][i].dishOption)) {
                menu[menuIndex][i].dish = menu[menuIndex][i].dishOption;
                changedMenu = true;
            }
        }
        // Menu after updating
        if (changedMenu) {
            cout << "----------------------------------" << endl;
            showMenu(menu[menuIndex], 7);
            cout << "----------------------------------" << endl;
        } else {
            cout << "----------------------------------" << endl;
        }
    } else {
        cout << "Okay! Have a nice day." << endl;
    }
}
