#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
using namespace std;

class workoutRoutine {
    private:
    public:
        string exerciseName;
        int duration;
        int rest;
};

// Bug: Number count error after count under 10
// Advance: Stop timer when user want to stop to do another things

// Function to display countdown
void countdown(int duration, int rest) {
    // Workout time
    for (int i = duration; i > 0; i--) {
        cout << i << flush;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\r";
    }

    // Rest time
    cout << "Take a rest..." << endl;
    for (int i = rest; i > 0; i--) {
        cout << i << flush;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\r";
    }
}
// Function to print a HIIT routine
void showHIITRoutines(workoutRoutine HIIT_Routines[], int size) {
    cout << "Here is your HIIT routine:" << endl;
    cout << "----------------------------------" << endl;
    for (int i = 0; i < size; ++i) {
        cout << HIIT_Routines[i].exerciseName << " - " << "Workout: " 
             << HIIT_Routines[i].duration << "s | " << "Rest: " 
             << HIIT_Routines[i].rest << "s" << endl;
    }
}

// Function to process user input
int processUserInput() {
    cout << "Start this workout? ";
    string input;
    cin >> input;
    // Convert user input to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    // Make sure the user enters the correct request. 
    // If the user enters the wrong request, re-enter it
    while (!(input == "yes" || input == "y" || input == "no" || input == "n")) {
        cout << "Invalid choice! Please enter YES or NO: ";
        cin >> input;
    }
    // Get user choice
    if (input == "yes" || input == "y") {
        return -1; // Start workout 
    } else if (input == "no" || input =="n") {
        cout << "Would you like to start higher or lower-level workout?: ";
        cin >> input;
        // Convert input to lowercase
        transform(input.begin(), input.end(), input.begin(), ::tolower);

/******************************************************************************
**  Haven't solved the problem of users don't want to workout                **
******************************************************************************/
        /* Make sure the user enters the correct request. 
        If the user enters the wrong request, re-enter it */
        while (!(input == "higher" || input == "h" ||
                 input == "lower" || input == "l")) {
            transform(input.begin(), input.end(), input.begin(), ::tolower);
            cout << "Invalid choice! Please enter higher or lower levels: ";
            cin >> input;

        }
        // Higher-level or Lower-level of HIIT
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input == "higher" || input == "h") {
            return 4; // Higher-level workout
        } else if (input == "lower" || input == "l") {
            return 0; // Lower-level workout
        } else {
            return -2;
        }
    }
    // Default: No workout
    return -2;
}

// Function to suggest HIIT workout
void suggestWorkout() {
    workoutRoutine HIIT_Routines[][10] = {
        // HIIT 0: Light HIIT, no jumping
        {
            {"Side Step Jack", 45, 15}, {"Squat Front Kick", 45, 15}, 
            {"Bodyweight Slam", 45, 15}, {"Knee Drive (Left)", 45, 15}, 
            {"Knee Drive (Right)", 45, 15}, {"Standing Side Crunch", 45, 15}, 
            {"Hand Workout", 45, 15}, {"Commando Plank with Mountain Climber", 45, 15}, 
            {"Bicycle Crunches", 45, 15}, {"Flutter Kick", 45, 0}
        },
        // HIIT 1: Basic
        {
            {"Jumping Jacks", 45, 15}, {"Burpee", 45, 15}, 
            {"Standing Side Crunch", 45, 15}, {"Mountain Climbers", 45, 15}, 
            {"Squat Jumps", 45, 15}, {"Russian Twists", 45, 15}, 
            {"Switching Lunges", 45, 15}, {"Push-ups", 45, 15},
            {"Skii Abs", 45, 15}, {"Skipping Rope", 45, 0}
        },
        // HIIT 2: Basic
        {
            {"Jumping Jacks", 45, 15}, {"Burpee", 45, 15}, 
            {"High Knees", 45, 15}, {"Mountain Climbers", 45, 15}, 
            {"Bicycle Crunches", 45, 15}, {"Plank Jacks", 45, 15}, 
            {"Switching Lunges", 45, 15}, {"Push-ups", 45, 15}, 
            {"Side to Side Plank", 45, 15}, {"Boat Holds", 45, 0}
        },
        // HIIT 3: Basic
        {
            {"Jumping Jacks", 45, 15}, {"Bodyweight Slam", 45, 15}, 
            {"Mountain Climbers", 45, 15}, {"Squat", 45, 15}, 
            {"Burpee", 45, 15},{"Plank", 45, 15}, 
            {"Russian Twists", 45, 15}, {"Push-ups", 45, 15}, 
            {"Standing Side Crunches", 45, 15}, {"Skipping Ropes", 45, 0}
        },
        // HIIT 4: Advanced HIIT
        {
            {"Standing Knee to Elbow", 45, 15}, {"Side to Side Skier", 45, 15}, 
            {"Scissor Jumps", 45, 15}, {"Squat Jumps", 45, 15}, 
            {"Jumping Jack and Toe Touches", 45, 15}, {"Switching Lunges", 45, 15}, 
            {"Plank Jack In and Out", 45, 15}, {"Spiderman Mountain Climber", 45, 15}, 
            {"Side to Side Plank", 45, 15}, {"Bicycle Crunches", 45, 0}
        }
    };

    // Select random HIIT exercise for user
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3); // Selecting from HIIT 1 to 3
    int routineIndex = dis(gen);

    showHIITRoutines(HIIT_Routines[routineIndex], 10);
    int choice = processUserInput();
    if (choice == -1) {
        cout << "Starting workout..." << endl;
        for (int i = 0; i < 10; ++i) {
            cout << "Performing: " << HIIT_Routines[routineIndex][i].exerciseName << endl;
            countdown(HIIT_Routines[routineIndex][i].duration,
                      HIIT_Routines[routineIndex][i].rest);
        }
        cout << "Workout finished!" << endl;
    } else if (choice == 4 || choice == 0) {
        routineIndex = choice;
        showHIITRoutines(HIIT_Routines[routineIndex], 10);
        cout << "Starting workout..." << endl;
        for (int i = 0; i < 10; ++i) {
            cout << "Performing: " << HIIT_Routines[routineIndex][i].exerciseName << endl;
            countdown(HIIT_Routines[routineIndex][i].duration,
                      HIIT_Routines[routineIndex][i].rest);
        }
        cout << "Workout finished!" << endl;
    } else {
        cout << "Okay! Have a nice day." << endl;
    }
} 