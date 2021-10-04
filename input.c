#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "input.h"
#include "foodCalc.h"

struct InputData input_data;

static void panic(char* msg) {
    printf("ERROR: %s\n", msg);
    exit(1);
}

static void ui_str(char* query, char* buffer) {
    printf("%s: ", query);
    fgets(buffer, STR_BUFFER_SIZE, stdin);
}

static bool is_valid_time_format(int hour) {
    if (hour < 0 || hour > 24)
        return false;
    
    return true;
}

static int ui_int(char* query) {
    char buffer[64];

    printf("%s: ", query);
    fgets(buffer, STR_BUFFER_SIZE, stdin);

    return atoi(buffer);
}

struct InputData request_input_data() {
    struct InputData b;
    b.total_days = ui_int("Total days spent on the trip");
    b.departure_time = ui_int("Departure time (hour in 24h)");
    b.arrival_time = ui_int("Arrival time (hour in 24h)");
    b.round_trip_fare = ui_int("Price of round trip fare");
    b.car_rental = ui_int("Price of car rental");
    b.miles_driven = ui_int("Number of miles driven");
    b.parking_fees = ui_int("Price of parking fees");
    b.taxi_fees = ui_int("Price of taxi fees");
    b.conf_seminar_fees = ui_int("Price of conference/seminar fees");
    b.hotel = ui_int("Price of hotel");
    //input_data.breakfast = ui_int("Number of breakfasts");
    //input_data.lunch = ui_int("Number of lunches");
    //input_data.dinner = ui_int("Number of dinners");

    calcMeal(&b.mealTotalExpenses, &b.mealTotalAllowed, &b.mealExcess,
    &b.mealSavings,b.total_days, b.arrival_time, 
    b.departure_time);

    return b;
    
}

void assert_valid_input(struct InputData input_data) {
    if (input_data.total_days < 1)
        panic("Total days must be one or more");

    if (input_data.round_trip_fare < 0 ||
        input_data.car_rental < 0 ||
        input_data.parking_fees < 0 ||
        input_data.taxi_fees < 0 ||
        input_data.conf_seminar_fees < 0 ||
        input_data.hotel < 0)
        panic("One or more prices are negative");
    
    if (input_data.miles_driven < 1)
        panic("Miles driven must be one or more");
    
    //if (input_data.breakfast < 0 ||
    //    input_data.lunch < 0 ||
    //    input_data.dinner < 0)
    //    panic("Cannot have negative number of meals");
    
    if (!is_valid_time_format(input_data.departure_time) ||
        !is_valid_time_format(input_data.arrival_time))
        panic("Time format is invalid");
}
