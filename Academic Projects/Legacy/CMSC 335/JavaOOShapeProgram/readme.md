# Java OO Shapes Program

## Overview

The **Java OO Shapes Program** is a console-based application that allows users to create and calculate properties (such as surface area and volume) of various 2D and 3D shapes. The program is designed using object-oriented principles, with a focus on abstraction, inheritance, and polymorphism.

## Project Structure

The project consists of the following files:

### Core Classes

- **`AbstractShape.java`**: The base abstract class for all shapes. It defines common methods such as `getNumberOfDimensions()` and includes a utility method `validatePositive()` for input validation.
- **`TwoDimensionalShape.java`**: An abstract class for all 2D shapes. It extends `AbstractShape` and defines the abstract method `getSurfaceArea()`.
- **`ThreeDimensionalShape.java`**: An abstract class for all 3D shapes. It extends `AbstractShape` and defines the abstract methods `getSurfaceArea()` and `getVolume()`.

### Shape Implementations

- **2D Shapes**:
  - `Circle.java`: Represents a circle. Calculates surface area using the radius.
  - `Rectangle.java`: Represents a rectangle. Calculates surface area using width and length.
  - `Square.java`: Represents a square. Calculates surface area using the side length.
  - `Triangle.java`: Represents a triangle. Calculates surface area using base and height.
- **3D Shapes**:
  - `Sphere.java`: Represents a sphere. Calculates surface area and volume using the radius.
  - `Cube.java`: Represents a cube. Calculates surface area and volume using the side length.
  - `Cone.java`: Represents a cone. Calculates surface area and volume using radius and height.
  - `Cylinder.java`: Represents a cylinder. Calculates surface area and volume using radius and height.
  - `Torus.java`: Represents a torus. Calculates surface area and volume using major and minor radii.

### Menu and Program Flow

- **`ShapeMenu.java`**: An `enum` that defines the menu options for the program. It includes methods to print the menu and retrieve descriptions for each option.
- **`MainMenu` (inner class in `JavaOOShapeProgram.java`)**: Displays the main menu and calls the `ShapeMenu.printMenu()` method.
- **`JavaOOShapeProgram.java`**: The main entry point of the program. It handles user input, validates it, and processes shape creation based on the selected menu option.

### Supporting Files

- **`menu.txt`**: A text file listing the menu options for constructing shapes.

## Program Flow

1. **Welcome Message**: The program starts by displaying a welcome message and the main menu.
2. **Menu Selection**: The user selects an option from the menu (1-10). Options 1-9 correspond to creating specific shapes, while option 10 exits the program.
3. **Input Validation**: The program validates the user's input to ensure it is a valid number within the menu range.
4. **Shape Creation**:
   - For options 1-9, the program prompts the user to enter the required dimensions for the selected shape.
   - Input validation ensures that all dimensions are positive numbers.
   - The program creates an instance of the selected shape and calculates its properties (e.g., surface area, volume).
   - The results are displayed to the user.
5. **Repeat or Exit**:
   - After creating a shape, the user is asked if they want to continue (Y/N).
   - If the user chooses "Y", they are returned to the main menu.
   - If the user chooses "N", they can exit the program by selecting option 10.
6. **Exit Message**: When the user exits, the program displays a goodbye message along with the current date and time.

## How to Run

1. Compile all `.java` files in the `WeekTwoProject` package.
2. Run the `JavaOOShapeProgram` class.
3. Follow the on-screen instructions to interact with the program.

## Example Usage

1. Start the program.
2. Select option `1` to create a Circle.
3. Enter the radius of the Circle (e.g., `5.0`).
4. View the calculated surface area of the Circle.
5. Choose to continue or exit the program.

## Notes

- The program uses `Scanner` for user input and validates all inputs to ensure they are positive numbers.
- The program is designed to handle invalid inputs gracefully, prompting the user to try again.
- The `ShapeMenu` enum ensures that the menu options are consistent and easy to manage.
- UML: ![JAVAOOSUML](https://github.com/EoUReDIt/Melbourne-Portfolio.io/blob/main/Academic%20Projects/Legacy/CMSC%20335/JavaOOShapeProgram/Assets/Class_diagrams.png?raw=true) 

## Dependencies

- Java 8 or higher.
- BlueJ IDE (optional, for viewing the project structure).

## Authors

- Melbourne Anderson