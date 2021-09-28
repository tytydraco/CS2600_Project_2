#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "input.h"

struct InputData input_data;

static void panic(char* msg) {
    printf("ERROR: %s\n", msg);
    exit(1);
}

static void ui_str(char* query, char* buffer) {
    printf("%s: ", query);
    fgets(buffer, STR_BUFFER_SIZE, stdin);
}

static bool is_valid_time_format(char* time_str) {
    int hour;
    int minute;

    sscanf(time_str, "%d:%d", &hour, &minute);

    if (hour < 0 || hour > 24)
        return false;
    if (minute < 0 || minute > 59)
        return false;
    
    return true;
}

static int ui_int(char* query) {
    char buffer[64];

    printf("%s: ", query);
    fgets(buffer, STR_BUFFER_SIZE, stdin);

    return atoi(buffer);
}

void request_input_data() {
    input_data.total_days = ui_int("Total days spent on the trip");
    ui_str("Departure time (HH:MM)", input_data.departure_time);
    ui_str("Arrival time (HH:MM)", input_data.arrival_time);
    input_data.round_trip_fare = ui_int("Price of round trip fare");
    input_data.car_rental = ui_int("Price of car rental");
    input_data.miles_driven = ui_int("Number of miles driven");
    input_data.parking_fees = ui_int("Price of parking fees");
    input_data.taxi_fees = ui_int("Price of taxi fees");
    input_data.conf_seminar_fees = ui_int("Price of conference/seminar fees");
    input_data.hotel = ui_int("Price of hotel");
    input_data.breakfast = ui_int("Number of breakfasts");
    input_data.lunch = ui_int("Number of lunches");
    input_data.dinner = ui_int("Number of dinners");
}

void assert_valid_input() {
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
    
    if (input_data.breakfast < 0 ||
        input_data.lunch < 0 ||
        input_data.dinner < 0)
        panic("Cannot have negative number of meals");
    
    if (!is_valid_time_format(input_data.departure_time) ||
        !is_valid_time_format(input_data.arrival_time))
        panic("Time format is invalid");
}
