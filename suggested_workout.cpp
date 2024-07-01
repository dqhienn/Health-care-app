#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <algorithm> // for std::transform
using namespace std;

class workoutRoutine {
public:
    string exerciseName;
    int duration;
    int rest;
};

// Function to display countdown
void countdown(int duration, int rest) {
    auto displayCountdown = [](int time, const string& message) {
        for (int i = time; i > 0; --i) {
            cout << i << flush;
            this_thread::sleep_for(chrono::seconds(1));
            cout << "\r";
        }
        cout << message << endl;
    };

    displayCountdown(rest, "Take a rest...");
}

// Function to print a HIIT routine
void showHIITRoutines(workoutRoutine HIIT_Routines[], int size) {
    cout << "Here is your HIIT routine:" << endl;
    cout << "-----------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << HIIT_Routines[i].exerciseName << " - " 
             << "Workout: " << HIIT_Routines[i].duration << "s | " 
             << "Rest: " << HIIT_Routines[i].rest << "s" << endl;
    }
}

// Function to process user input
int processUserInput() {
    string confirmChoice;
    while (true) {
        cout << "Start this workout? (yes/no): ";
        cin >> confirmChoice;
        transform(confirmChoice.begin(), confirmChoice.end(), confirmChoice.begin(), ::tolower);
        
        if (confirmChoice == "yes" || confirmChoice == "y") {
            return -1; // Start workout
        } else if (confirmChoice == "no" || confirmChoice == "n") {
            cout << "Would you like to start a higher or lower-level workout? (higher/lower): ";
            cin >> confirmChoice;
            transform(confirmChoice.begin(), confirmChoice.end(), confirmChoice.begin(), ::tolower);
            
            if (confirmChoice == "higher" || confirmChoice == "h") {
                return 4; // Higher-level workout
            } else if (confirmChoice == "lower" || confirmChoice == "l") {
                return 0; // Lower-level workout
            } else {
            cout << "Okay! Have a nice day." << endl;
            return -2;
            }
        }
    }
    return -2; // Default: No workout
}

// Function to suggest HIIT workout
void suggestWorkout() {
    workoutRoutine HIIT_Routines[][10] = {
        {
            {"Side Step Jack", 45, 15}, {"Squat Front Kick", 45, 15}, 
            {"Bodyweight Slam", 45, 15}, {"Knee Drive (Left)", 45, 15}, 
            {"Knee Drive (Right)", 45, 15}, {"Standing Side Crunch", 45, 15}, 
            {"Hand Workout", 45, 15}, {"Commando Plank with Mountain Climber", 45, 15}, 
            {"Bicycle Crunches", 45, 15}, {"Flutter Kick", 45, 0}
        },
        {
            {"Jumping Jacks", 45, 15}, {"Burpee", 45, 15}, 
            {"Standing Side Crunch", 45, 15}, {"Mountain Climbers", 45, 15}, 
            {"Squat Jumps", 45, 15}, {"Russian Twists", 45, 15}, 
            {"Switching Lunges", 45, 15}, {"Push-ups", 45, 15},
            {"Skii Abs", 45, 15}, {"Skipping Rope", 45, 0}
        },
        {
            {"Jumping Jacks", 45, 15}, {"Burpee", 45, 15}, 
            {"High Knees", 45, 15}, {"Mountain Climbers", 45, 15}, 
            {"Bicycle Crunches", 45, 15}, {"Plank Jacks", 45, 15}, 
            {"Switching Lunges", 45, 15}, {"Push-ups", 45, 15}, 
            {"Side to Side Plank", 45, 15}, {"Boat Holds", 45, 0}
        },
        {
            {"Jumping Jacks", 45, 15}, {"Bodyweight Slam", 45, 15}, 
            {"Mountain Climbers", 45, 15}, {"Squat", 45, 15}, 
            {"Burpee", 45, 15},{"Plank", 45, 15}, 
            {"Russian Twists", 45, 15}, {"Push-ups", 45, 15}, 
            {"Standing Side Crunches", 45, 15}, {"Skipping Ropes", 45, 0}
        },
        {
            {"Standing Knee to Elbow", 45, 15}, {"Side to Side Skier", 45, 15}, 
            {"Scissor Jumps", 45, 15}, {"Squat Jumps", 45, 15}, 
            {"Jumping Jack and Toe Touches", 45, 15}, {"Switching Lunges", 45, 15}, 
            {"Plank Jack In and Out", 45, 15}, {"Spiderman Mountain Climber", 45, 15}, 
            {"Side to Side Plank", 45, 15}, {"Bicycle Crunches", 45, 0}
        }
    };

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3); // Selecting from HIIT 1 to 3
    int routineIndex = dis(gen);

    showHIITRoutines(HIIT_Routines[routineIndex], 10);
    int choice = processUserInput();
    
    if (choice == -1) {
        cout << "Starting workout..." << endl;
    } else if (choice == 4 || choice == 0) {
        routineIndex = choice;
        showHIITRoutines(HIIT_Routines[routineIndex], 10);
        cout << "Starting workout..." << endl;
    } else {
        return;     // Exit if user doesn't want to workout
    }

    for (int i = 0; i < 10; ++i) {
        cout << "Performing: " << HIIT_Routines[routineIndex][i].exerciseName << endl;
        countdown(HIIT_Routines[routineIndex][i].duration, HIIT_Routines[routineIndex][i].rest);
    }
    cout << "Workout finished!" << endl;
}
