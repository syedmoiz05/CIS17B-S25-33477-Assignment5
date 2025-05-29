# Smart Packaging System - User Instructions

## How to Compile

1. Open a terminal or command prompt.
2. Navigate to the directory containing the source file 
3. Compile the code using:

   g++ -std=c++11 -o SmartPackagingSystem  SmartPackagingSystem .cpp

  

## How to Run

- On Linux or macOS:
  ./SmartPackagingSystem 

- On Windows:
 SmartPackagingSystem.exe

## How to Use
1. Launch the program.
2. It will automatically demonstrate every template and specialization by printing to the console:
 - Generic package
 - Book package 
 - Fragile package 
 - Adding items to a `Box<std::string,3>` and listing its contents
 - Shipping of `int`, `std::string`, and `double` (temperature-controlled) items
3. No user input is required you just observe the printed output to verify that:
 - All `Package<T>`, `Package<std::string>`, and `Package<T*>` `label()` calls work
 - The `Box<T,Size>` correctly stores and prints up to 3 items
 - The general `shipItem<T>` and the `double` specialization work
