// Copyright (c) 2025 Atri Sarker All rights reserved.
// .
// Created By: Atri S
// Date: May 13, 2025
// Calculator

#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>

double Calculate(std::string sign, double num1, double num2) {
    // Match sign with operator
    if (sign == "+") {
        return (num1 + num2);
    } else if (sign == "-") {
        return (num1 - num2);
    } else if (sign == "*") {
        return (num1 * num2);
    } else if (sign == "/") {
        return (num1 / num2);
    } else if (sign == "%") {
        // (num1 % num2) causes an error
        // So I implemented modulo differently
        return num1 - (num2*floor(num1 / num2));
    }
    // Purely for appeasing the linter
    return 987.789;
}

int main() {
    // Get user's operator
    std::string userSign;
    printf("Enter a sign (+, -, *, /, %): ");
    std::getline(std::cin, userSign);
    // Initialize variables for user's numbers
    float num1, num2;
    // Get user's first number as a string
    printf("Enter the first number: ");
    std::string num1String;
    std::getline(std::cin, num1String);
    // Get user's second number as a string
    printf("Enter the second number: ");
    std::string num2String;
    std::getline(std::cin, num2String);
    try {
        // Convert the user's input to a double
        double num1 = std::stod(num1String);
        try {
            // Convert the user's input to a double
            double num2 = std::stod(num2String);
            // Check if the user's sign is allowed
            if (userSign == "+" || userSign == "-" ||
                userSign == "*" || userSign == "/" ||
                userSign == "%") {
                // Prevent division by 0
                if ((num2 == 0) && (userSign == "/" || userSign == "%")) {
                    printf("Division by 0 is prohibited.\n");
                } else {
                    // CALL Calculate() and get the result
                    double result = Calculate(userSign, num1, num2);
                    // Display the result
                    printf("%g %s %g = %g\n", num1,
                        userSign.c_str(), num2, result);
                }
            } else {
                printf("%s is not a recognized operator.\n", userSign.c_str());
            }
        } catch (std::invalid_argument) {
            // Tell the user that their input wasn't a number
            printf("%s is not a valid number.\n", num2String.c_str());
        }
    } catch (std::invalid_argument) {
        // Tell the user that their input wasn't a number
        printf("%s is not a valid number.\n", num1String.c_str());
    }
}
