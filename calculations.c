#include <stdio.h>


/*
     main struct hold little variables

    take each variable and add/subtract effect on total allowance of the trip.
    round trip airfaire, what alowed did they go over or under.
    car rentals
    -same
    miles driven 

    calc over and under.

*/

float calculations(){
    //dummy variables
    int numOfDays = 0;
    int round_trip_faire = 0;
    int priceOfCarRentals = 0;
    float conference = 0;
    float hotelExpense;
    float mealCost;
    float vechileExpense = 0.27 * miles_driven;
    float allowedParkingFees = 6*numOfDays;
    float parkingFees = parking_fees;
    float allowedTaxi = 10*numOfDays;
    float taxiFees = taxi_fees;
    float allowedHotelExpense = 90*numOfDays;
    float over = 0;
    float under =0;
    //so far this is the total of thing that don't need to be calculated.
    float total = round_trip_faire + priceOfCarRentals + vechileExpense + conference;

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

    
    

}