#include <stdio.h>


void calculations(){
    //dummy variables
    int numOfDays = 5;
    int round_trip_faire = 100;
    int priceOfCarRentals = 250;
    float conference = 100;
    float hotelExpense = 450;
    float miles_driven = 50;
    float parkingFees= 40;
    float taxiFees = 50;
    
    //dummy vars for others
    
    //allowable
    float vechileExpense = 0.27 * miles_driven;
    float allowedParkingFees = 6*numOfDays;
    float allowedTaxi = 10*numOfDays; 
    float allowedHotelExpense = 90*numOfDays;
    float over = 0;
    float under =0;
    //so far this is the total of thing that don't need to be calculated.
    float total = round_trip_faire + priceOfCarRentals + vechileExpense + conference;
    float totalAllowable;
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
    
    totalAllowable += round_trip_faire + priceOfCarRentals  + conference + allowedHotelExpense + allowedParkingFees + allowedTaxi +  vechileExpense;
    
   // printf("Total amount paid: %.2f\nTotal Allowed Expenses: %.2f\nAmount overbudget: %f\nAmount Saved: %.2f,\n", total, totalAllowable, over, under);
}
