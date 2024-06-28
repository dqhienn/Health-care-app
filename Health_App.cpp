#include "BMI_calculation.cpp"
#include "suggested_menu.cpp"
#include "suggested_workout.cpp"

int main(float BMI) {
    BMI_results();
    suggestMenu(BMI);
    suggestWorkout();
    return 0;
}