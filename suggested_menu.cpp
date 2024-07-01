#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Class to represent a menu item with the day of the week and two dish options
class MenuItem {
public:
    string dayOfWeek;
    string dish;
    string dishOption;
};

// Function to display the menu
void showMenu(MenuItem menu[], int size) {
    cout << "Suggested Menu for the Week:" << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << menu[i].dayOfWeek << ": " << menu[i].dish << endl;
    }
}

// Function to get user's choice to change the dish
bool getUserChoice(string& dayOfWeek, string& dish, string& dishOption) {
    string confirmChoice;
    for (;;) {
        cout << dayOfWeek << ": " << "Do you want to change " << dish << " to " << dishOption << "?: ";
        cin >> confirmChoice;
        transform(confirmChoice.begin(), confirmChoice.end(), confirmChoice.begin(), ::tolower);

        if (confirmChoice == "yes" || confirmChoice == "y") {
            dish = dishOption;
            cout << "Great choice! Updated for " << dayOfWeek << ": " << dish << endl;
            return true;
        } else if (confirmChoice == "no" || confirmChoice == "n") {
            return false;
        } else {
            cout << "Invalid choice! Please enter YES or NO." << endl;
        }
    }
}

// Function to suggest a menu based on BMI
void suggestMenu(float BMI) {
    MenuItem menu[][7] = {
        // Menu 0: For BMI >= 30
        {{"Monday", "Grilled chicken salad", 
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
        {{"Monday", "Avocado toast with poached eggs", 
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
        {{"Monday", "Grilled chicken with brown rice and broccoli", 
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

    int menuIndex = (BMI >= 30) ? 0 : (BMI < 18.5) ? 1 : 2;

    // Show the suggested menu
    showMenu(menu[menuIndex], 7);

    // Check if the user wants to change the menu
    string choice;
    cout << "Would you like to change the menu? (yes/no): ";
    cin >> choice;
    transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

    if (choice == "yes" || choice == "y") {
        bool changedMenu = false;
        for (int i = 0; i < 7; ++i) {
            if (getUserChoice(menu[menuIndex][i].dayOfWeek, menu[menuIndex][i].dish, 
                              menu[menuIndex][i].dishOption)) {
                changedMenu = true;
            }
        }
        // Show the updated menu
        if (changedMenu) {
            cout << "-----------------------------" << endl;
            showMenu(menu[menuIndex], 7);
        }
    } else {
        cout << "Okay! Have a nice day." << endl;
    }
}