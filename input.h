#ifndef INPUT_H
#define INPUT_H

#define STR_BUFFER_SIZE 64

struct InputData {
    int total_days;
    char departure_time[STR_BUFFER_SIZE];
    char arrival_time[STR_BUFFER_SIZE];
    int round_trip_fare;
    int car_rental;
    int miles_driven;
    int parking_fees;
    int taxi_fees;
    int conf_seminar_fees;
    int hotel;
    int breakfast;
    int lunch;
    int dinner;
};

extern struct InputData input_data;

void request_input_data();
void assert_valid_input();

#endif