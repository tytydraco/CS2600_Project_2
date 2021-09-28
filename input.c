#include <stdio.h>
#include <stdlib.h>

#include "input.h"

struct InputData input_data;

static void ui_str(char* query, char* buffer) {
    printf("%s: ", query);
    fgets(buffer, STR_BUFFER_SIZE, stdin);
}

static int ui_int(char* query) {
    char buffer[64];

    printf("%s: ", query);
    fgets(buffer, STR_BUFFER_SIZE, stdin);

    return atoi(buffer);
}

void request_input_data() {
    input_data.total_days = ui_int("Total days spent on the trip");
    ui_str("Departure time", input_data.departure_time);
    ui_str("Arrival time", input_data.arrival_time);
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
