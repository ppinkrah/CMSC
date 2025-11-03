/*
 * Class: CMSC140 CRN
 * Instructor:Wu
 * Project 2
 * Programmer: Prince Pinkrah
 * Description: Simulates a movie ticket booking system with age verification,
 *              ticket pricing, and change calculation.
 * Due Date: Oct. 14, 2025
 * I pledge that I have completed the programming assignment independently.
 * I have not copied the code from a student or any source.
 * I have not given my code to any student.
 * Print your Name here: Prince Pinkrah
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constants
const int AGE_G = 0;
const int AGE_PG = 7;
const int AGE_PG13 = 13;
const int AGE_R = 17;
const int AGE_NC17 = 18;

const double ADULT_PRICE = 12.00;
const double CHILD_PRICE = 8.00;

int main() {
    int movieChoice, age;
    int adultTickets, childTickets;
    double totalCost, amountTendered, change;
    string movieTitle, movieRating;
    int requiredAge;

    // Display menu
    cout << "********** Movie Ticket Booking **********" << endl;
    cout << "Today's Movies:" << endl;
    cout << "1. Baby Boy - Rated R" << endl;
    cout << "2. Menace II Society - Rated NC-17" << endl;
    cout << "3. Friday - Rated PG-13" << endl;
    cout << "4. All About the Benjamins - Rated PG" << endl;
    cout << "5. Poetic Justice - Rated G" << endl;
    cout << "Please select a movie by entering its number: ";
    cin >> movieChoice;

    if (movieChoice < 1 || movieChoice > 5) {
        cout << "Error: Invalid movie number." << endl;
        return 0;
    }

    switch (movieChoice) {
    case 1:
        movieTitle = "Baby Boy";
        movieRating = "R";
        requiredAge = AGE_R;
        break;
    case 2:
        movieTitle = "Menace II Society";
        movieRating = "NC-17";
        requiredAge = AGE_NC17;
        break;
    case 3:
        movieTitle = "Friday";
        movieRating = "PG-13";
        requiredAge = AGE_PG13;
        break;
    case 4:
        movieTitle = "All About the Benjamins";
        movieRating = "PG";
        requiredAge = AGE_PG;
        break;
    case 5:
        movieTitle = "Poetic Justice";
        movieRating = "G";
        requiredAge = AGE_G;
        break;
    }

    cout << movieTitle << " is rated " << movieRating << ". Please enter your age: ";
    cin >> age;

    if (age < 0) {
        cout << "Error: Invalid age entered." << endl;
        return 0;
    }

    if (age < requiredAge) {
        cout << "Sorry, you must be at least " << requiredAge << " to watch \"" << movieTitle << "\"." << endl;
        return 0;
    }

    cout << "You have selected \"" << movieTitle << "\" - Rated " << movieRating << "." << endl;
    cout << "How many adult tickets would you like to purchase? ";
    cin >> adultTickets;

    if (adultTickets < 0) {
        cout << "Error: Invalid number of tickets." << endl;
        return 0;
    }

    cout << "How many child tickets would you like to purchase? ";
    cin >> childTickets;

    if (childTickets < 0) {
        cout << "Error: Invalid number of tickets." << endl;
        return 0;
    }

    if ((movieRating == "R" || movieRating == "NC-17") && childTickets > 0) {
        cout << "Error: Children cannot purchase tickets for this movie." << endl;
        return 0;
    }

    totalCost = (adultTickets * ADULT_PRICE) + (childTickets * CHILD_PRICE);
    cout << fixed << setprecision(2);
    cout << "Total cost: $" << totalCost << endl;

    cout << "Please enter the amount you are tendering: $";
    cin >> amountTendered;

    if (amountTendered < 0) {
        cout << "Error: Invalid payment amount." << endl;
        return 0;
    }

    if (amountTendered < totalCost) {
        cout << "Error: Amount tendered is less than the total cost. Transaction Cancelled." << endl;
        return 0;
    }

    change = amountTendered - totalCost;
    cout << "Payment accepted." << endl;
    cout << "Change: $" << change << endl;

    cout << endl;
    cout << "Programmer: Prince Pinkrah" << endl;
    cout << "Project 2" << endl;
    cout << "Due: Oct. 14, 2025" << endl;

    return 0;
}
