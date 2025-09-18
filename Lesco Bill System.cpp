#include <iostream>

using namespace std;

int main()
{
    float unit_Consumed ;
    const float fixed_Charges = 200.0f ;
    const float unit_Rate = 37.99f  ;
    const float fuel_Price_Adjustment = -273.35f ;
    float FC_Surcharge = 1169.26f ; // if units > 300
    float quaterly_Tariff_Adjustment = 497.98f ; // if unit > 200
    float electricity_Duty ; // 1.5% of cost of electricity
    float cost_of_Electricity ;  // unit_consumed * unit_Rate
    const float TV_Fee = 35.0f ;
    float GST ; // 17% of cost_of_Electricity + Fixed_Charges + fuel_Price_Adjustment
    float income_Tax ; // 15% if unit_Consumed > 300
    float total_Bill ; // Total bill: Cost of Electricity+Fixed Charges+F.C. Surcharge+FPA+Quarterly Adjustment+Taxes
    float late_Payment_charges ; // 10% of current bill
    float bill_after_due ;

    cout << "Enter unit consumed in a month: " << endl ;
    cin >> unit_Consumed ;

    cost_of_Electricity = unit_Consumed * unit_Rate ;

    if (unit_Consumed < 0)
    {
        cout << "Invalid Input !" << endl;
        return 0;
    }

    if (unit_Consumed <= 100.0) 
    {
        income_Tax = 0.0f;
        electricity_Duty = 0.015 * cost_of_Electricity;
        GST = 0.17 * (cost_of_Electricity + fixed_Charges + fuel_Price_Adjustment );
        total_Bill = cost_of_Electricity + fixed_Charges + fuel_Price_Adjustment + TV_Fee + electricity_Duty + GST + income_Tax;
    }
    else if (unit_Consumed > 100.0 && unit_Consumed <= 200.0) 
    {
        income_Tax = 0.0f;
        electricity_Duty = 0.015 * cost_of_Electricity;
        GST = 0.17 * (cost_of_Electricity + fixed_Charges + fuel_Price_Adjustment );
        total_Bill = cost_of_Electricity + fixed_Charges + fuel_Price_Adjustment + TV_Fee + electricity_Duty + GST + income_Tax ;
    }
    else if (unit_Consumed > 200.0 && unit_Consumed <= 300.0) 
    {
        income_Tax = 0.0f;
        electricity_Duty = 0.015 * cost_of_Electricity;
        GST = 0.17 * (cost_of_Electricity + fixed_Charges + fuel_Price_Adjustment + quaterly_Tariff_Adjustment );
        total_Bill = cost_of_Electricity + fixed_Charges + fuel_Price_Adjustment + TV_Fee + electricity_Duty + GST + income_Tax + quaterly_Tariff_Adjustment ;
    }
    else if (unit_Consumed > 300.0 ) 
    {
        income_Tax = 0.15 * cost_of_Electricity;
        electricity_Duty = 0.015 * cost_of_Electricity;
        GST = 0.17 * (cost_of_Electricity + fixed_Charges + fuel_Price_Adjustment + quaterly_Tariff_Adjustment + FC_Surcharge );
        total_Bill = cost_of_Electricity + fixed_Charges + fuel_Price_Adjustment + TV_Fee + electricity_Duty + GST + income_Tax + quaterly_Tariff_Adjustment + FC_Surcharge ;
    }

    late_Payment_charges = ( 0.10 * total_Bill ) ;
    bill_after_due = late_Payment_charges + total_Bill ;

    cout << "---------------------------------" << endl;
    cout << "Unit Consumed : " << unit_Consumed << endl;
    cout << "Government Tariff Rate (Price per unit) : " << unit_Rate << endl;
    cout << "Fixed Charges : " << fixed_Charges << endl;
    cout << "Fuel Price Adjustment FPA : " << fuel_Price_Adjustment << endl;
    cout << "";
    cout << "Electricity Duty (1.5%) : " << electricity_Duty << endl;
    cout << "TV - Fee (flat) : " << TV_Fee << endl;
    cout << "General Sales Tax GST (17%) : " << GST << endl;
    cout << "Income Tax : " << income_Tax << endl;
    cout << "---------------------------------" << endl;
    cout << "Total Bill : " << total_Bill << endl;
    cout << "Late Payment Fine : " << late_Payment_charges << endl;
    cout << "Bill after due date : " << bill_after_due << endl;
    cout << "---------------------------------" << endl;

    return 0;

}