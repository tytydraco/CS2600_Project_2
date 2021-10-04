#include <stdio.h>

#include "calculations.h"
#include "input.h"

float over = 0;
float under = 0;
float total = 0;
float totalAllowable = 0;

/*
     main struct hold little variables

    take each variable and add/subtract effect on total allowance of the trip.
    round trip airfaire, what alowed did they go over or under.
    car rentals
    -same
    miles driven 

    calc over and under.

*/

void calculations(struct InputData input_data){
    //dummy variables
    int numOfDays = input_data.total_days;
    int round_trip_faire = input_data.round_trip_fare;
    int priceOfCarRentals = input_data.car_rental;
    float conference = input_data.conf_seminar_fees;
    float hotelExpense = input_data.hotel;
   // float mealTotalExpenses;
    //float mealTotalAllowed;
    //float mealExcess;
    //float mealSavings;
    float vechileExpense = 0.27 * input_data.miles_driven;
    float allowedParkingFees = 6*numOfDays;
    float parkingFees = input_data.parking_fees;
    float allowedTaxi = 10*numOfDays;
    float taxiFees = input_data.taxi_fees;
    float allowedHotelExpense = 90*numOfDays;
    over = input_data.mealExcess;
    under = input_data.mealSavings;
    //so far this is the total of thing that don't need to be calculated.
    total = round_trip_faire + priceOfCarRentals + vechileExpense + conference + 
    input_data.mealTotalExpenses;

    // calc parking fees.
    if(allowedParkingFees < parkingFees){
        over += parkingFees-allowedParkingFees;
        total += allowedParkingFees;
    }else {
        under += allowedParkingFees - parkingFees;
        total+=parkingFees;
    }

    //taxi costs, total, over and under.
    if(allowedTaxi < taxiFees){
        over += taxiFees - allowedParkingFees;
        total += allowedParkingFees;
    } else {
        under += allowedTaxi-taxiFees;
        total += taxiFees;
    }

    
    //hotel costs, total, over, under.
    if(allowedHotelExpense < hotelExpense){
        over += hotelExpense - allowedHotelExpense;
        total += allowedHotelExpense;
    }else {
        under += allowedHotelExpense - hotelExpense;
        total += hotelExpense;
    }
    
    totalAllowable += round_trip_faire + priceOfCarRentals  + conference + 
    allowedHotelExpense + allowedParkingFees + allowedTaxi +  vechileExpense
    + input_data.mealTotalAllowed;
    
   // printf("Total amount paid: %.2f\nTotal Allowed Expenses: %.2f\nAmount overbudget: %f\nAmount Saved: %.2f,\n", total, totalAllowable, over, under);
}
