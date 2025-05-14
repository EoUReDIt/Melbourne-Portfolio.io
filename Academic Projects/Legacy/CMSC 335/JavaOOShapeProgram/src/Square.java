// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// Cube.java
// This class represents a cube and extends the ThreeDimensionalShape class.
// It provides methods to calculate the volume and surface area of the cube.
// It also includes a constructor to initialize the cube's side length.
// The Cube class is a subclass of the abstract class ThreeDimensionalShape.
public class Square extends TwoDimensionalShape {

    // fields----------------------->
    // side of the square
    private double side;

    // method----------------------->
    // Constructor
    // This constructor initializes the side of the square.
    // It also validates that the side is a positive value.
    public Square(double side) {

        // Error checking
        // check if the side is positive
        // validatePositive is a static method in the AbstractShape class
        AbstractShape.validatePositive(side, "Side");

        // set the side of the square
        this.side = side;

    }

    // there is no need for a setter method for the side
    // because it is set in the constructor and should not be changed
    protected double getSurfaceArea() {

        return side * side;
    }

    // Override the toString method
    // This method returns a string representation of the square's surface area.
    // It formats the output to two decimal places.
    @Override
    public String toString() {

        return "The area of the square is " + String.format("%.2f", getSurfaceArea()) + "\n";
    }

    // Override the getNumberOfDimensions method
    // This method returns the number of dimensions for the square, which is 2.
    @Override
    protected int getNumberOfDimensions() {
        return 2;
    }
}
