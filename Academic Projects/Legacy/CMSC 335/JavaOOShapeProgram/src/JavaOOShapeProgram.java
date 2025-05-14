// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// This section of code lists the imports used in the program.
import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

// This program is a Java application that allows users to construct various 2D and 3D shapes.
// It provides a menu-driven interface for users to select shapes and input their dimensions.
// The program includes error handling for invalid inputs and allows users to continue constructing shapes or exit the program.
// The program uses a Scanner object to read user input and includes methods for validating inputs.
// The program is designed to be user-friendly and provides clear instructions for each step.
// The program includes a main menu and a shape menu, allowing users to navigate through the options.
public class JavaOOShapeProgram {

    // This method validates the user's input for continuing or exiting the program.
    // It checks if the input is either "y" or "n" (case-insensitive).
    public static boolean validContinue(String s) {

        // Check if the input is either "y" or "n" (case-insensitive)
        // If it is, return true; otherwise, return false.
        if (s.equalsIgnoreCase("y") || s.equalsIgnoreCase("n")) {
            return true;
        } else {
            return false;
        }

    }

    // This is the main method of the program.
    public static void main(String[] args) {

        // fields---------->
        // This section of code initializes the Scanner object for user input and
        // creates a variable to hold the user's selection.
        // It also creates a variable to hold the user's selection for the menu.
        Scanner userData = new Scanner(System.in);// Create a Scanner Object
        int selection = 0;// create variable to hold input

        // LOOP
        // This section of code contains the main loop of the program.
        // It continues to display the menu and process user selections until the user
        // chooses to exit.
        do {

            // call menu
            // This section of code displays the main menu and prompts the user for their
            // selection.
            System.out.println();

            // Call the startMenu method to display the main menu
            MainMenu.startMenu();

            // Inner loop for input validation

            boolean isValidInput = false;

            // This section of code contains a loop that continues until the user provides a
            // valid input.
            // It checks if the input is a valid integer and within the range of 1 to 10.
            do {
                // error handling for invalid character
                try {

                    // Prompt the user for their selection
                    selection = Integer.parseInt(userData.nextLine());// user input

                    // Check if the selection is within the valid range (1 to 10)
                    if (selection > 0 && selection <= 10) {
                        isValidInput = true;
                    } else {
                        System.out.println("Please enter a number between 1 and 10.\n"); // Request valid input
                        isValidInput = false; // Set the flag to false to continue the loop
                    }

                } catch (Exception e) { // Catch any exception that occurs during input parsing

                    System.out.println("Please enter a Valid Input. \n"); // Request valid input Again
                }

            } while (!isValidInput);// Continue until a valid input is provided

            // Create a variable to hold the user's choice for continuing or exiting the
            // program
            // The variable is initialized to "n" to indicate that the user has not yet made
            // a choice.
            // This variable is used to control the subprogram loop for a specific shape.
            // It allows the user to continue constructing shapes or return to the shape
            // selection menu.
            String continueCheck = "n";// create variable for looping shape creation

            // shape creation
            // Process the selection using a switch statement
            switch (selection) {
                case 1:
                    // This section of code handles the construction of a Circle.
                    // It prompts the user for the radius of the circle and creates a Circle object.
                    // It also includes error handling for invalid inputs and allows the user to
                    // continue constructing shapes.
                    // The Circle class is assumed to be defined elsewhere in the program.
                    do {
                        System.out.println("Constructing a Circle... \n"); // Feedback to user on the next phase of the
                                                                           // program is

                        // local variable to control the loop for prompting the user for a valid radius
                        boolean validCircle = false;

                        // This section of code contains a loop that continues until the user provides a
                        // valid radius for the circle.
                        while (!validCircle) {
                            System.out.print("Enter the radius of the circle: ");
                            try {
                                // Request user input for the radius
                                // Parse the input as a double
                                // Create a Circle object with the provided radius
                                // Set the validCircle flag to true to exit the loop
                                double radius = Double.parseDouble(userData.nextLine()); // Read user input
                                Circle circle = new Circle(radius);
                                validCircle = true;
                                System.out.println(circle.toString()); // Print the circle's details

                            } catch (NumberFormatException e) {
                                // Handle invalid input for the radius
                                System.out.println("Please enter a valid decimal number for the radius.\n");

                            } catch (IllegalArgumentException e) {
                                // Handle invalid radius value (e.g., negative or zero)
                                // Print the error message and prompt the user to try again
                                System.out.println(e.getMessage() + " Please try again.\n");
                                System.out.println();
                            }
                            // End of inter-while loop
                        }

                        // This line prompts the user to decide whether they want to continue
                        // constructing a specific shape or exit to the previous menu
                        System.out.println("Would you like to continue? (Y or N): ");

                        // This section of code contains a loop that continues until the user provides a
                        // valid input for continuing or exiting.
                        // It checks if the input is either "y" or "n" (case-insensitive).
                        do {

                            continueCheck = userData.nextLine().toLowerCase();

                            if (!validContinue(continueCheck)) {
                                System.out.println("Sorry I do not understand. Enter Y or N");
                                continueCheck = userData.nextLine().toLowerCase();
                            }

                        } while (!validContinue(continueCheck)); // end of loop for checking valid input

                    } while (continueCheck.equalsIgnoreCase("y")); // end of loop for continueCheck

                    break;// breaking out of the while loop under the case 1

                case 2:
                    do {
                        // This section of code handles the construction of a Rectangle.
                        // It prompts the user for the length and width of the rectangle and creates a
                        // Rectangle object.
                        // It also includes error handling for invalid inputs and allows the user to
                        // continue constructing shapes.
                        System.out.println("Constructing a Rectangle...");

                        // local variable to control the loop for prompting the user for a valid length
                        // and width
                        boolean validRectangle = false;

                        // This section of code contains a loop that continues until the user provides
                        // valid dimensions for the rectangle.
                        while (!validRectangle) {
                            try {
                                // Request user input for the length and width
                                System.out.print("Enter the length of the rectangle: ");
                                double length = Double.parseDouble(userData.nextLine());

                                System.out.print("Enter the width of the rectangle: ");
                                double width = Double.parseDouble(userData.nextLine());

                                Rectangle rectangle = new Rectangle(width, length);
                                validRectangle = true; // Set the validRectangle flag to true to exit the loop

                                System.out.println(rectangle.toString()); // Print the rectangle's details

                            } catch (NumberFormatException e) {
                                // Handle invalid input for the length and width
                                // Print an error message and prompt the user to try again
                                System.out.println("Please enter a valid decimal number for the dimensions.\n");
                            } catch (IllegalArgumentException e) {
                                // Handle invalid length or width value (e.g., negative or zero)
                                System.out.println(e.getMessage() + " Please try again.\n");
                            }
                        } // End of inter-while loop that checks for valid input and creates a rectangle
                          // object

                        System.out.println("Would you like to continue? (Y or N): "); // Prompt the user to decide
                                                                                      // whether they want to continue
                                                                                      // constructing a specific shape
                                                                                      // or exit to the previous menu

                        // This section of code contains a loop that continues until the user provides a
                        // valid input for continuing or exiting.
                        // It checks if the input is either "y" or "n" (case-insensitive).
                        do {
                            // Prompt the user for their choice
                            continueCheck = userData.nextLine().toLowerCase();
                            if (!validContinue(continueCheck)) {
                                System.out.println("Sorry I do not understand. Enter Y or N");
                                continueCheck = userData.nextLine().toLowerCase();
                            }

                        } while (!validContinue(continueCheck));// end of loop for checking valid input

                    } while (continueCheck.equalsIgnoreCase("y"));// end of loop for continueCheck
                    break;// breaking out of the while loop under the case 2

                case 3:
                    do {
                        // This section of code handles the construction of a Square.
                        // It prompts the user for the side length of the square and creates a Square
                        // object.
                        // It also includes error handling for invalid inputs and allows the user to
                        // continue constructing shapes.

                        System.out.println("Constructing a Square...");

                        boolean validSquare = false;// local variable to control the loop for prompting the user for a
                                                    // valid side length

                        // This section of code contains a loop that continues until the user provides a
                        // valid side length for the square.
                        while (!validSquare) {
                            // Request user input for the side length
                            // Parse the input as a double
                            // Create a Square object with the provided side length
                            System.out.print("Enter the side length of the square: ");
                            try {
                                double side = Double.parseDouble(userData.nextLine());
                                Square square = new Square(side);

                                validSquare = true;// Set the validSquare flag to true to exit the loop

                                System.out.println(square.toString());// Print the square's details
                            } catch (NumberFormatException e) {
                                // Handle invalid input for the side length
                                // Print an error message and prompt the user to try again
                                System.out.println("Please enter a valid decimal number for the side length.\n");
                            } catch (IllegalArgumentException e) {
                                // Handle invalid side length value (e.g., negative or zero)
                                // Print the error message and prompt the user to try again
                                System.out.println(e.getMessage() + " Please try again.\n");
                            }
                        } // End of inter-while loop that checks for valid input and creates a square
                          // object

                        // This line prompts the user to decide whether they want to continue
                        // constructing a specific shape or exit to the previous menu
                        System.out.println("Would you like to continue? (Y or N): ");

                        // This section of code contains a loop that continues until the user provides a
                        // valid input for continuing or exiting.
                        // It checks if the input is either "y" or "n" (case-insensitive).
                        do {

                            continueCheck = userData.nextLine().toLowerCase();

                            if (!validContinue(continueCheck)) {
                                System.out.println("Sorry I do not understand. Enter Y or N");
                                continueCheck = userData.nextLine().toLowerCase();
                            }

                        } while (!validContinue(continueCheck));// end of loop for checking valid input

                    } while (continueCheck.equalsIgnoreCase("y")); // end of loop for continueCheck
                    break;// breaking out of the while loop under the case 3

                case 4:
                    do {

                        System.out.println("Constructing a Triangle...");
                        boolean validTriangle = false;
                        while (!validTriangle) {
                            try {
                                System.out.print("Enter the base of the triangle: ");
                                double base = Double.parseDouble(userData.nextLine());

                                System.out.print("Enter the height of the triangle: ");
                                double height = Double.parseDouble(userData.nextLine());

                                Triangle triangle = new Triangle(base, height);
                                validTriangle = true;
                                System.out.println(triangle.toString());
                            } catch (NumberFormatException e) {
                                System.out.println("Please enter a valid decimal number for the dimensions.\n");
                            } catch (IllegalArgumentException e) {
                                System.out.println(e.getMessage() + " Please try again.\n");
                            }
                        }

                        System.out.println("Would you like to continue? (Y or N): ");

                        do {

                            continueCheck = userData.nextLine().toLowerCase();

                            if (!validContinue(continueCheck)) {
                                System.out.println("Sorry I do not understand. Enter Y or N");
                                continueCheck = userData.nextLine().toLowerCase();
                            }

                        } while (!validContinue(continueCheck));

                    } while (continueCheck.equalsIgnoreCase("y"));
                    break;

                case 5:
                    do {

                        System.out.println("Constructing a Sphere...");
                        boolean validSphere = false;
                        while (!validSphere) {
                            System.out.print("Enter the radius of the sphere: ");
                            try {
                                double radius = Double.parseDouble(userData.nextLine());
                                Sphere sphere = new Sphere(radius);
                                validSphere = true;
                                System.out.println(sphere.toString());
                            } catch (NumberFormatException e) {
                                System.out.println("Please enter a valid decimal number for the radius.\n");
                            } catch (IllegalArgumentException e) {
                                System.out.println(e.getMessage() + " Please try again.\n");
                            }
                        }
                        System.out.println("Would you like to continue? (Y or N): ");

                        do {

                            continueCheck = userData.nextLine().toLowerCase();

                            if (!validContinue(continueCheck)) {
                                System.out.println("Sorry I do not understand. Enter Y or N");
                                continueCheck = userData.nextLine().toLowerCase();
                            }

                        } while (!validContinue(continueCheck));

                    } while (continueCheck.equalsIgnoreCase("y"));
                    break;

                case 6:
                    do {

                        System.out.println("Constructing a Cube...");
                        boolean validCube = false;
                        while (!validCube) {
                            System.out.print("Enter the side length of the cube: ");
                            try {
                                double side = Double.parseDouble(userData.nextLine());
                                Cube cube = new Cube(side);
                                validCube = true;
                                System.out.println(cube.toString());
                            } catch (NumberFormatException e) {
                                System.out.println("Please enter a valid decimal number for the side length.\n");
                            } catch (IllegalArgumentException e) {
                                System.out.println(e.getMessage() + " Please try again.\n");
                            }
                        }
                        System.out.println("Would you like to continue? (Y or N): ");

                        do {

                            continueCheck = userData.nextLine().toLowerCase();

                            if (!validContinue(continueCheck)) {
                                System.out.println("Sorry I do not understand. Enter Y or N");
                                continueCheck = userData.nextLine().toLowerCase();
                            }

                        } while (!validContinue(continueCheck));

                    } while (continueCheck.equalsIgnoreCase("y"));
                    break;

                case 7:
                    do {

                        System.out.println("Constructing a Cone...");
                        boolean validCone = false;
                        while (!validCone) {
                            try {
                                System.out.print("Enter the radius of the cone: ");
                                double radius = Double.parseDouble(userData.nextLine());

                                System.out.print("Enter the height of the cone: ");
                                double height = Double.parseDouble(userData.nextLine());

                                Cone cone = new Cone(radius, height);
                                validCone = true;
                                System.out.println(cone.toString());
                            } catch (NumberFormatException e) {
                                System.out.println("Please enter a valid decimal number for the dimensions.\n");
                            } catch (IllegalArgumentException e) {
                                System.out.println(e.getMessage() + " Please try again.\n");
                            }
                        }
                        System.out.println("Would you like to continue? (Y or N): ");

                        do {

                            continueCheck = userData.nextLine().toLowerCase();

                            if (!validContinue(continueCheck)) {
                                System.out.println("Sorry I do not understand. Enter Y or N");
                                continueCheck = userData.nextLine().toLowerCase();
                            }

                        } while (!validContinue(continueCheck));

                    } while (continueCheck.equalsIgnoreCase("y"));
                    break;

                case 8:
                    do {

                        System.out.println("Constructing a Cylinder...");
                        boolean validCylinder = false;
                        while (!validCylinder) {
                            try {
                                System.out.print("Enter the radius of the cylinder: ");
                                double radius = Double.parseDouble(userData.nextLine());

                                System.out.print("Enter the height of the cylinder: ");
                                double height = Double.parseDouble(userData.nextLine());

                                Cylinder cylinder = new Cylinder(radius, height);
                                validCylinder = true;
                                System.out.println(cylinder.toString());
                            } catch (NumberFormatException e) {
                                System.out.println("Please enter a valid decimal number for the dimensions.\n");
                            } catch (IllegalArgumentException e) {
                                System.out.println(e.getMessage() + " Please try again.\n");
                            }
                        }
                        System.out.println("Would you like to continue? (Y or N): ");

                        do {

                            continueCheck = userData.nextLine().toLowerCase();

                            if (!validContinue(continueCheck)) {
                                System.out.println("Sorry I do not understand. Enter Y or N");
                                continueCheck = userData.nextLine().toLowerCase();
                            }

                        } while (!validContinue(continueCheck));

                    } while (continueCheck.equalsIgnoreCase("y"));
                    break;

                case 9:
                    do {

                        System.out.println("Constructing a Torus...");
                        boolean validTorus = false;
                        while (!validTorus) {
                            try {
                                System.out.print("Enter the major radius of the torus: ");
                                double majorRadius = Double.parseDouble(userData.nextLine());

                                System.out.print("Enter the minor radius of the torus: ");
                                double minorRadius = Double.parseDouble(userData.nextLine());

                                Torus torus = new Torus(majorRadius, minorRadius);
                                validTorus = true;
                                System.out.println(torus.toString());
                            } catch (NumberFormatException e) {
                                System.out.println("Please enter a valid decimal number for the radii.\n");
                            } catch (IllegalArgumentException e) {
                                System.out.println(e.getMessage() + " Please try again.\n");
                            }
                        }
                        System.out.println("Would you like to continue? (Y or N): ");

                        do {

                            continueCheck = userData.nextLine().toLowerCase();

                            if (!validContinue(continueCheck)) {
                                System.out.println("Sorry I do not understand. Enter Y or N");
                                continueCheck = userData.nextLine().toLowerCase();
                            }

                        } while (!validContinue(continueCheck));

                    } while (continueCheck.equalsIgnoreCase("y"));
                    break;

                case 10:
                    System.out.println("Exiting the program. Goodbye!");
                    System.out.println("Thank you for using Java OO Shapes Program. \n");

                    // Get the current date and time
                    LocalDateTime currentDateTime = LocalDateTime.now();

                    // Define a format for date and time
                    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");

                    // Format and print the date and time
                    System.out.println("Current date and time: " + currentDateTime.format(formatter));
                    break;

                default:
                    // System.out.println("Invalid selection. Please choose a number between 1 and
                    // 10.");
                    break;
            }

        } while (selection != 10);// loop until user choose to exit.
        userData.close();// close scanner.

        // Close the program normally
        System.exit(0);
    }
}

class MainMenu {

    public static void startMenu() {
        // Start of Menu---------->
        System.out.println("******* Welcome to the Java OO Shapes Program *******. \n");

        System.out.println("Select from the menu below: .\n");
        ShapeMenu.printMenu();
        System.out.println();
        System.out.println("Please select a shape to construct (1-9): ");
        // End of Menu---------->
    }

}
