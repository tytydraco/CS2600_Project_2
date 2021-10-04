#ifndef INPUT_H
#define INPUT_H

#define STR_BUFFER_SIZE 64

struct InputData {
    int total_days;
    int departure_time;
    int arrival_time;
    int round_trip_fare;
    int car_rental;
    int miles_driven;
    int parking_fees;
    int taxi_fees;
    int conf_seminar_fees;
    int hotel;
    //int breakfast;
    //int lunch;
    //int dinner;
    float mealTotalExpenses;
    float mealTotalAllowed;
    float mealExcess;
    float mealSavings;
};

//extern struct InputData input_data;

struct InputData request_input_data();
void assert_valid_input(struct InputData input_data);

#endif