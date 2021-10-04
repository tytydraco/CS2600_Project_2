#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "input.h"

static void totalExpenses(float mealCost, float allowedExpenses, float *total, float *allowableExpenses, float *excess, float *savings)
{
    if(mealCost >= allowedExpenses)
    {
        *total += mealCost;                            
        *allowableExpenses += allowedExpenses;                 
        *excess += (mealCost - allowedExpenses);               
    } else if(mealCost < allowedExpenses)
    {
        *total += mealCost;                        
        *allowableExpenses += mealCost;                          
        *savings += (allowedExpenses - mealCost);    
    }
}

static float askForFoodCosts(char* meal)
{
    float cost; 
    do {
        printf("\nEnter %s cost: ", meal);
        scanf("%f", &cost); 
        if(cost < 0)
        {
            printf("Invalid value input try again");
        }
    } while(cost < 0);
    return cost;
}

void calcMeal(float *total, float *allowableExpenses, float *excess, float *savings, int days, int startTime, int endTime)
{
    for(int counter = 0; counter < days; counter++)
    {
        char bf[] = "Breakfast";
        char l[] = "Lunch";
        char d[] = "Dinner";
        float breakfastExpense = 9;
        float lunchExpense = 12;
        float dinnerExpense = 16;

        printf("\nDay %d\n", (counter + 1));
        float breakfast = askForFoodCosts(bf);
        float lunch = askForFoodCosts(l);
        float dinner = askForFoodCosts(d);

        if(counter == 0)
        {
            if(startTime < 7)
            {
                totalExpenses(breakfast, breakfastExpense, total, allowableExpenses, excess, savings);
                totalExpenses(lunch, lunchExpense, total, allowableExpenses, excess, savings);
                totalExpenses(dinner, dinnerExpense, total, allowableExpenses, excess, savings);
            } else if(startTime < 12 && startTime >= 7)
            {
                totalExpenses(breakfast, 0, total, allowableExpenses, excess, savings);
                totalExpenses(lunch, lunchExpense, total, allowableExpenses, excess, savings);
                totalExpenses(dinner, dinnerExpense, total, allowableExpenses, excess, savings);
            } else if(startTime < 18 && startTime >= 12)
            {
                totalExpenses(breakfast, 0, total, allowableExpenses, excess, savings);
                totalExpenses(lunch, 0, total, allowableExpenses, excess, savings);
                totalExpenses(dinner, dinnerExpense, total, allowableExpenses, excess, savings);
            } else 
            {
                totalExpenses(breakfast, 0, total, allowableExpenses, excess, savings);
                totalExpenses(lunch, 0, total, allowableExpenses, excess, savings);
                totalExpenses(dinner, 0, total, allowableExpenses, excess, savings);
            }
        } else if(counter == (days - 1))
        {
            if(endTime < 8)
            {
                totalExpenses(breakfast, 0, total, allowableExpenses, excess, savings);
                totalExpenses(lunch, 0, total, allowableExpenses, excess, savings);
                totalExpenses(dinner, 0, total, allowableExpenses, excess, savings);
            } else if(endTime < 13 && endTime >= 8)
            {
                totalExpenses(breakfast, breakfastExpense, total, allowableExpenses, excess, savings);
                totalExpenses(lunch, 0, total, allowableExpenses, excess, savings);
                totalExpenses(dinner, 0, total, allowableExpenses, excess, savings);
            } else if(endTime < 19 && endTime >= 13)
            {
                totalExpenses(breakfast, breakfastExpense, total, allowableExpenses, excess, savings);
                totalExpenses(lunch, lunchExpense, total, allowableExpenses, excess, savings);
                totalExpenses(dinner, 0, total, allowableExpenses, excess, savings);
            } else 
            {
                totalExpenses(breakfast, breakfastExpense, total, allowableExpenses, excess, savings);
                totalExpenses(lunch, lunchExpense, total, allowableExpenses, excess, savings);
                totalExpenses(dinner, dinnerExpense, total, allowableExpenses, excess, savings);
            }
        } else 
        {
            totalExpenses(breakfast, breakfastExpense, total, allowableExpenses, excess, savings);
            totalExpenses(lunch, lunchExpense, total, allowableExpenses, excess, savings);
            totalExpenses(dinner, dinnerExpense, total, allowableExpenses, excess, savings);
        }
    }
}