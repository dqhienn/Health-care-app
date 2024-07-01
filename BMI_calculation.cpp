#include <iostream>
#include <cmath>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

class BMIInfo {
    public:
        float minBMI;
        float maxBMI;
        string categories;
        string advices;
};

const string BMI_CATEGORIES[6] = {"Obese class III", "Obese class II",
                                 "Obese class I", "Overweight", "Standard BMI",
                                 "Underweight"};

string BMI_ADVICE[6] = {
    "Consult with a healthcare professional to create a personalized weight \nloss plan that includes a balanced diet, regular physical activity, \nand possibly medical or surgical interventions.",
    "Adopt a balanced diet and regular exercise routine, while also seeking \nguidance from a healthcare professional to develop a tailored weight management plan.",
    "Focus on a healthy eating plan, increase physical activity, \nand consult with a healthcare provider to monitor and manage weight effectively.",
    "Adopt a balanced diet, engage in regular physical activity, \nand make sustainable lifestyle changes to gradually achieve a healthier weight.",
    "Maintain their healthy weight by continuing to eat a balanced diet, \nstaying active with regular exercise, and keeping up with healthy lifestyle habits.",
    "Focus on gaining weight healthily by consuming nutrient-dense foods, \nincreasing calorie intake with balanced meals and snacks, \nand incorporating strength training workouts to build muscle mass."
};

// BMI ranges
const float BMI_MIN[6] = {40, 35, 30, 25, 18.5, 0};
const float BMI_MAX[6] = {INFINITY, 39.9, 34.9, 29.9, 24.9, 18.4};

// Get weight from user
float getUserWeight() {
    float weight;
    for(;;) {
        cout << "May I know your weight(kg)?: ";
        if(cin >> weight) {
            return weight;
        } else {
            cout << "I don't quiet understand what you mean. Please re-enter: " << endl;
            // Clear cin's error flag, continue receiving new input
            cin.clear();
            // Skip all character in current line until catch \n
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

float getUserHeight() {
    float height;
    for(;;) {
        cout << "May I know your height(m)?: ";
        if(cin >> height) {
            return height;
        } else {
            cout << "I don't quiet understand what you mean. Please re-enter: " << endl;
            // Clear cin's error flag, continue receiving new input
            cin.clear();
            // Skip all character in current line until catch \n
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Function get weight and height
float BMI_calculation(float weight, float height) {
    return weight / (height * height);
}

void BMI_advices(float BMI) {
    string category = "Unknown";
    string advice = "Unknown";
    /* Calculate number of elements in the BMI_MIN array. 
    Determines number of iterations of the loop. */
    for (int i = 0; i < sizeof(BMI_MIN) / sizeof(BMI_MIN[0]); ++i) {
        // Check if user's BMI is in BMI_MIN[i] to BMI_MAX[i] 
        if (BMI >= BMI_MIN[i] && BMI <= BMI_MAX[i]) {
            category = BMI_CATEGORIES[i];
            advice = BMI_ADVICE[i];
            break;
        }
    }
    // Show BMI category and advice
    cout << "----------------------------------" << endl;
    cout << "Your BMI: " << BMI << ". " << category << "!" << endl;
    cout << "Advice: " << advice << endl;
    cout << "----------------------------------" << endl;
}

// Function to get user's weight and height, calculate BMI, and interpret it
void BMI_results() {
    float weight = getUserWeight();
    float height = getUserHeight();
    float BMI = BMI_calculation(weight, height);
    BMI_advices(BMI);
}
