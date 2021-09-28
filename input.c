#include <stdio.h>
#include <stdlib.h>

#include "input.h"

static void ui_str(char* query, char* buffer) {
    printf("%s: ", query);
    fgets(buffer, 64, stdin);
}

static int ui_int(char* query) {
    char buffer[64];

    printf("%s: ", query);
    fgets(buffer, 64, stdin);

    return atoi(buffer);
}

int ask_total_days() {
    return 0;
}

char* ask_departure_time() {
    return "";
}

char* ask_arrival_time() {
    return "";
}

int ask_round_trip_fare() {
    return 0;
}

int ask_car_rental() {
    return 0;
}

int ask_miles_driven() {
    return 0;
}

int ask_parking_fees() {
    return 0;
}

int ask_taxi_fees() {
    return 0;
}

int ask_conf_seminar_fees() {
    return 0;
}

int ask_hotel() {
    return 0;
}

int ask_each_meal() {
    return 0;
}
