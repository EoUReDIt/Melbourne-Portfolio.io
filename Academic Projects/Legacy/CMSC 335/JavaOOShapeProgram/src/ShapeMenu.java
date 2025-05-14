// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// This enum represents a menu for constructing various shapes.
// It includes options for 2D and 3D shapes, along with an exit option.
// Each option has a number and a description.
// The enum provides a method to print all menu options.
public enum ShapeMenu {
    CIRCLE(1, "Construct a Circle"),
    RECTANGLE(2, "Construct a Rectangle"),
    SQUARE(3, "Construct a Square"),
    TRIANGLE(4, "Construct a Triangle"),
    SPHERE(5, "Construct a Sphere"),
    CUBE(6, "Construct a Cube"),
    CONE(7, "Construct a Cone"),
    CYLINDER(8, "Construct a Cylinder"),
    TORUS(9, "Construct a Torus"),
    EXIT(10, "Exit the program");

    // Fields
    // Each enum constant has an option number and a description.
    // The option number is used to identify the menu option.
    // The description provides a human-readable name for the option.
    // The option number is used to identify the menu option.
    private final int optionNumber;
    private final String description;

    // Constructor
    // This constructor initializes the option number and description for each enum
    // constant.
    ShapeMenu(int optionNumber, String description) {
        this.optionNumber = optionNumber;
        this.description = description;
    }

    // Getters
    // These methods provide access to the option number and description of each
    // enum constant.
    // The getOptionNumber method returns the option number of the menu option.
    public int getOptionNumber() {
        return optionNumber;
    }

    // The getDescription method returns the description of the menu option.
    // It provides a human-readable name for the option.
    // This method is used to display the menu options to the user.
    public String getDescription() {
        return description;
    }

    // Method to print all menu options
    public static void printMenu() {
        for (ShapeMenu option : ShapeMenu.values()) {
            System.out.println(option.optionNumber + ". " + option.description);
        }
    }
}
