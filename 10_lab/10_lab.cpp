#include <iostream>
#include <iomanip>

using namespace std;

const float PERSON_WT = 170.0;
const float LBS_PER_GAL = 6.7;
const float EMPTY_WEIGHT = 9887.0;
const float EMPTY_MOMENT = 3185853.0;

float CargoMoment(int, int);
float CrewMoment(int);
float FuelMoment(int);
void  GetData(int&, int&, int&, int&, int&);
float PassengerMoment(int);
void PrintWarning(float);
int main()
{
    int crew, passengers, closet, baggage, fuel;
    float totalWt;
    float centerOfGravity;

    cout << fixed << showpoint << setprecision(2);

    // Getting input data from the user
    GetData(crew, passengers, closet, baggage, fuel);

    // Calculating the total weight and the center of gravity of the aircraft
    totalWt = EMPTY_WEIGHT + float(passengers + crew) * PERSON_WT + float(baggage + closet) + float(fuel) * LBS_PER_GAL;
    centerOfGravity = (CrewMoment(crew) + PassengerMoment(passengers) + CargoMoment(closet, baggage) + FuelMoment(fuel) + EMPTY_MOMENT) / totalWt;

    // Displaying the results
    cout << "The total weight is " << totalWt << " pounds." << endl;
    cout << "The center of gravity is located " << centerOfGravity << " inches from the front of the aircraft:" << endl;

    // Checking the center of gravity and displaying a warning
    PrintWarning(centerOfGravity);


    return 0;
}
void GetData(int& crew, int& passengers, int& closet, int& baggage, int& fuel)
{
    // Function to get input data from the user
    cout << "Enter the number of crew members:" << endl;
    cin >> crew;
    cout << "Enter the number of passengers:" << endl;
    cin >> passengers;
    cout << "Enter the weight, in pounds, of the closet rounded to the nearest whole number:" << endl;
    cin >> closet;
    cout << "Enter the weight, in pounds, of the baggage compartment rounded to the nearest whole number:" << endl;
    cin >> baggage;
    cout << "Enter the number of gallons of fuel loaded, rounded to the nearest whole number:" << endl;
    cin >> fuel;
    cout << endl;
    cout << "  | Data input as entered:                |" << endl;
    cout << "  |---------------------------------------|" << endl;
    cout << "  | Crew:               " << "|" << setw(8) << crew << " persons |" << endl;
    cout << "  | Passengers:         " << "|" << setw(9) << passengers << " persons|" << endl;
    cout << "  | Weight of clothing: " << "|" << setw(9) << closet << " pounds |" << endl;
    cout << "  | Baggage weight:     " << "|" << setw(9) << baggage << " pounds |" << endl;
    cout << "  | Fuel:               " << "|" << setw(8) << fuel << " gallons |" << endl;
    cout << "  |---------------------------------------|" << endl;
}
float CrewMoment(int crew)
{
    const float CREW_DISTANCE = 143.0;

    return float(crew) * PERSON_WT * CREW_DISTANCE;
}
float PassengerMoment(int passengers)
{
    // Function to calculate the moment for passengers
    const float ROW1_DIST = 219.0;

    const float ROW2_DIST = 265.0;
    const float ROW3_DIST = 295.0;
    const float ROW4_DIST = 341.0;

    float moment = 0.0;


    switch (passengers)
    {
    case 8:
    case 7:   moment += float(passengers - 6) * PERSON_WT * ROW4_DIST;
        passengers = 6;
    case 6:
    case 5:   moment += float(passengers - 4) * PERSON_WT * ROW3_DIST;
        passengers = 4;
    case 4:
    case 3:   moment += float(passengers - 2) * PERSON_WT * ROW1_DIST;
        passengers = 2;
    case 2:
    case 1:   moment += float(passengers) * PERSON_WT * ROW2_DIST;
    }

    return moment;
}
float CargoMoment(int closet, int baggage) {// Function to calculate the moment for cargo
    const float CLOSET_DIST = 182.0;
    const float BAGGAGE_DIST = 386.0;


    return (float(closet) * CLOSET_DIST) + (float(baggage) * BAGGAGE_DIST);
}
float FuelMoment(int fuel)
{ // Function to calculate the moment for fuel
    float fuelWt;
    float fuelDistance;

    fuelWt = float(fuel) * LBS_PER_GAL;
    if (fuel < 60)
        fuelDistance = float(fuel) * 314.6;
    else if (fuel < 361)
        fuelDistance = 305.8 + (-0.01233 * float(fuel - 60));
    else if (fuel < 521)
        fuelDistance = 303.0 + (0.12500 * float(fuel - 361));
    else
        fuelDistance = 323.0 + (-0.04444 * float(fuel - 521));
    return fuelDistance * fuelWt;
}
void PrintWarning(float centerOfGravity) {
    // Function to print a warning if the center of gravity is critical
    if (centerOfGravity < 3181833.0 || centerOfGravity > 3187873.0) {
        cout << "Warning: The center of gravity is approaching a critical limit. Exercise caution!" << endl;
    }
}
/