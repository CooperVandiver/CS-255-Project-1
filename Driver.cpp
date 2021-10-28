//******************************************************
// Name: Cooper Vandiver
// File: CooperVandiver-255-P1.cpp
// Description:
// Course: CS 255
// Due Date: Oct. 5, 2021
//******************************************************
#include "Fraction.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


//******************************************************
// Function Name: void calcFrac(Fraction& left, Fraction& right)
// Brief Description: Calculates the result of a user inputted expression
// Return Value: N/A
// Incoming Parameters: Two fractions passed by reference (left and right)
// Outgoing Parameters: Two fractions passed by reference (left and right)
//******************************************************
void calcFrac(Fraction& left, Fraction& right);

//******************************************************
// Function Name: void fracEquiv(Fraction& left, Fraction& right)
// Brief Description: Checks to see whether two fractions are equivalent
// Return Value: N/A
// Incoming Parameters: Two fractions passed by reference (left and right)
// Outgoing Parameters: Two fractions passed by reference (left and right)
//******************************************************
void fracEquiv(Fraction& left, Fraction& right);

//******************************************************
// Function Name: void fracCompare(Fraction& left, Fraction& right)
// Brief Description: Compares two fractions and outputs which is greater
// Return Value: N/A
// Incoming Parameters: Two fractions passed by reference (left and right)
// Outgoing Parameters: Two fractions passed by reference (left and right)
//******************************************************
void fracCompare(Fraction& left, Fraction& right);

//******************************************************
// Function Name: void reducePractice(Fraction& x)
// Brief Description: Provides a random fraction and prompts user to reduce it
// Return Value: N/A
// Incoming Parameters: One fraction passed by reference
// Outgoing Parameters: One fraction passed by reference
//******************************************************
void reducePractice(Fraction& x);

//******************************************************
// Function Name: void fractionQuiz(Fraction& x, Fraction& y)
// Brief Description: Randomly generates one fraction a relational operator or increment/decrement then asks
// user to provide a fraction to make the expression true
// Return Value: N/A
// Incoming Parameters: Two fractions passed by reference (left and right)
// Outgoing Parameters: Two fractions passed by reference (left and right)
//******************************************************
void fractionQuiz(Fraction& x, Fraction& y);

int main(){
    srand(time(NULL)); //setting seed for random number generation
    Fraction f1;       //initializing variables
    Fraction f2;
    int input = -1;
    cout<<
    "**************************************"<<endl<<
    "**********Fractions are fun!**********"<<endl<<     //outputting splash text
    "**************************************"<<endl<<endl;
    while(input != 0){ //setting up loop to run while user has not input quit value
        cout<<"To continue further, please input the number corresponding to the option you prefer."<<endl; //prompting user to select an option
        cout<<"1 - Fraction Calculator"<<endl;
        cout<<"2 - Fraction Equivalence Check"<<endl;
        cout<<"3 - Fraction Comparator"<<endl;          //outputting options to user
        cout<<"4 - Fraction Reducing Practice"<<endl;
        cout<<"5 - Fraction Expression Practice"<<endl;
        cout<<"0 - Quit Program"<<endl;
        cout<<endl;
        cin>>input;             //getting input from user
        if(input == 1){         //setting up cases for various options to be selected by user
            calcFrac(f1, f2);   //calling calculator function
            cout<<endl<<endl;
        }
        else if(input == 2){
            fracEquiv(f1, f2);  //calling function that checks equivalence
            cout<<endl<<endl;
        }
        else if(input == 3){
            fracCompare(f1, f2); //calling function that compares fractions' values
            cout<<endl<<endl;
        }
        else if(input == 4){
            reducePractice(f1); //calling function that allows user to practice reducing fractions
            cout<<endl<<endl;
        }
        else if(input == 5){
            fractionQuiz(f1, f2); //calling function that allows user to practice completing expressions with fractions
            cout<<endl<<endl;
        }
        else if(input == 0){
            cout<<"Thank you for using this program!"<<endl;      //output to user prior to them quitting
        }
        else{
            cout<<"Input not recognized, please input a valid option."<<endl; //outputting that user has selected an invalid option
        }
    }
    return 0;
}


void calcFrac(Fraction& left, Fraction& right){
    char op;
    cout<<"Please input the expression that you would like to be evaluated in \nthe form N/D (+, -, *, /) N/D."<<endl; //prompting user for input
    cin>>left>>op>>right; //getting input
    switch(op){ //switch case for various operators used in expression
    case '+':
        left = left + right; //adding fractions
        left.reduce();
        cout<<left;          //outputting result
        break;
    case '-':
        left = left - right; //subtracting fractions
        left.reduce();
        cout<<left;          //outputting result
        break;
    case '*':
        left = left * right; //multiplying fractions
        left.reduce();
        cout<<left;          //outputting result
        break;
    case '/':
        left = left / right; //dividing fractions
        left.reduce();
        cout<<left;          //outputting result
        break;
    }
}


void fracEquiv(Fraction& left, Fraction& right){
    cout<<"This checks to see if two fractions are equivalent."<<endl;  //outputting purpose of function
    cout<<"Please input the first fraction in the form N/D."<<endl;     //prompting input for first fraction
    cin>>left;                                                          //inputting first fraction
    cout<<"Please input the second fraction in the form N/D."<<endl;    //prompting input for second fraction
    cin>>right;                                                         //inputting second fraction
    if(left == right){                                                  //case for fractions being equal
        cout<<"The two fractions are equivalent."<<endl;
    }
    else if(left != right){                                             //case for fractions not being equal
        cout<<"The two fractions are not equivalent."<<endl;
    }
}


void fracCompare(Fraction& left, Fraction & right){
    cout<<"This checks to see which fraction is greater."<<endl;        //outputting purpose of function
    cout<<"Please input the first fraction in the form N/D."<<endl;     //prompting first input
    cin>>left;                                                          //getting first input
    cout<<"Please input the second fraction in the form N/D."<<endl;    //prompting second input
    cin>>right;                                                         //getting second input
    if(left > right){                                                   //case for left being larger
        cout<<left<<" is greater than "<<right<<endl;                   //outputting that left is greater
    }
    if(left < right){                                                   //case for left being less than right
        cout<<left<<" is less than "<<right<<endl;                      //outputting that left is less
    }
    else if(left == right){                                             //case for both being equal
        cout<<left<<" is equal to "<<right<<endl;                       //outputting that they are equal
    }
}


void reducePractice(Fraction& x){
    Fraction temp;                              //initializing temporary fraction
    Fraction random;                            //initializing fraction to be set equal to the first temporary fraction (the random generation prior to reduction)
    temp.SetNum(rand() % 20 + 1);               //assigning random value to temp's numerator
    temp.SetDen(rand() % 20 + 1);               //assigning second random value to temp's denominator
    random = temp;                              //assigning temp's current value to random's value
    temp.reduce();                              //reducing temp for later use in testing user
    cout<<"This tests how well you can reduce fractions."<<endl; //outputting purpose of function
    cout<<"Please input the reduced form of "<<random<<endl;     //prompting user to input reduced form of the random fraction
    cin>>x;                                                      //getting fraction input
    if(isExact(x, temp)){                                        //case for user fully reducing random fraction
        cout<<"Correct!"<<endl;                                  //outputting that user was correct
    }
    else if(x == temp && !(isExact(x, temp))){                   //case for user inputting an equivalent fraction but one that is not fully reduced
        cout<<"Equivalent, but not fully reduced. The reduced form of "<<random<<" is "<<temp<<endl; //outputting that fraction is equivalent but not fully reduced
    }
    else{                                                        //case for user inputting a fraction that is not equivalent and correct answer
        cout<<"Incorrect. The reduced form of "<<random<<" is "<<temp<<endl;
    }
}


void fractionQuiz(Fraction& x, Fraction& y){
    int num; //initializing integer to be used for randomly selecting operator to be used in partial expression
    cout<<"In this exercise, you will be tasked with inputting a fraction that makes the statement true."<<endl; //outputting purpose of function
    x.SetNum(rand() % 20 + 1);  //setting random value of fraction x
    x.SetDen(rand() % 20 + 1);
    num = rand() % 8;           //setting num equal to a random value between 0 and 7
    switch(num){                //creating switch cases for various values of num that correlate to an operator
    case 0:                     //case for operator being "=="
        cout<<x<<" == ";        //outputting partial expression
        cin>>y;                 //getting user input
        if(x == y){             //case for user being correct
            cout<<"Correct!"<<endl; //outputting that user is correct
        }
        else{                   //case for user being incorrect
            cout<<"Incorrect"<<endl; //outputting that user is incorrect
        }
        break;
    case 1:                     //case for operator being "<="
        cout<<x<<" <= ";        //outputting partial expression
        cin>>y;                 //getting user input
        if(x <= y){             //case for user being correct
            cout<<"Correct!"<<endl; //outputting that user is correct
        }
        else{                   //case for user being incorrect
            cout<<"Incorrect"<<endl; //outputting that user is incorrect
        }
        break;
    case 2:                     //case for operator being ">="
        cout<<x<<" >= ";        //outputting partial expression
        cin>>y;                 //getting user input
        if(x >= y){             //case for user being correct
            cout<<"Correct!"<<endl; //outputting that user is correct
        }
        else{                   //case for user being incorrect
            cout<<"Incorrect"<<endl; //outputting that user is incorrect
        }
        break;
    case 3:                     //case for operator being "!="
        cout<<x<<" != ";        //outputting partial expression
        cin>>y;                 //getting user input
        if(x != y){             //case for user being correct
            cout<<"Correct!"<<endl; //outputting that user is correct
        }
        else{                   //case for user being incorrect
            cout<<"Incorrect"<<endl; //outputting that user is incorrect
        }
        break;
    case 4:                     //case for operator being "<"
        cout<<x<<" < ";         //outputting partial expression
        cin>>y;                 //getting user input
        if(x < y){              //case for user being correct
            cout<<"Correct!"<<endl; //outputting that user is correct
        }
        else{                   //case for user being incorrect
            cout<<"Incorrect"<<endl; //outputting that user is incorrect
        }
        break;
    case 5:                     //case for operator being ">"
        cout<<x<<" > ";         //outputting partial expression
        cin>>y;                 //getting user input
        if(x > y){              //case for user being correct
            cout<<"Correct!"<<endl; //outputting that user is correct
        }
        else{                   //case for user being incorrect
            cout<<"Incorrect"<<endl; //outputting that user is incorrect
        }
        break;
    case 6:                     //case for operator being "++" (shown as "+1 =")
        cout<<x<<"+1 = ";       //outputting partial expression
        cin>>y;                 //getting user input
        if(y == ++x){           //case for user being correct
            cout<<"Correct!"<<endl; //outputting that user is correct
        }
        else{                   //case for user being incorrect
            cout<<"Incorrect."<<endl; //outputting that user is incorrect
        }
        break;
    case 7:                     //case for operator being "--" (shown as "-1 =")
        cout<<x<<"-1 =";        //outputting partial expression
        cin>>y;                 //getting user input
        if(y == --x){           //case for user being correct
            cout<<"Correct!"<<endl; //outputting that user is correct
        }
        else{                   //case for user being incorrect
            cout<<"Incorrect."<<endl; //outputting that user is incorrect
        }
        break;
    }

}
