// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// Recangle.java
// This class is a subclass of the abstract class TwoDimensionalShape.
// It represents a rectangle shape and provides methods to calculate its surface area.
// It also includes a constructor to initialize the rectangle's width and length,
public class Rectangle extends TwoDimensionalShape {

    // fields----------------------->
    // width and length of the rectangle
    // these are the dimensions of the rectangle
    private double width;
    private double length;

    // method----------------------->
    // Constructor
    // This constructor initializes the width and length of the rectangle.
    // It also validates that the width and length are positive values.
    public Rectangle(double width, double length) {
        // Constructor

        // Error checking
        // check if the width and length are positive
        AbstractShape.validatePositive(width, "Width");
        AbstractShape.validatePositive(length, "Length");

        // set value
        this.width = width;
        this.length = length;

    }

    // there is no need for a setter method for the width and length
    // because they are set in the constructor and should not be changed
    protected double getSurfaceArea() {
        // returns the surface area of all triangle object
        return width * length;
    }

    // Override the toString method
    // This method returns a string representation of the rectangle's surface area.
    @Override
    public String toString() {
        // creating output of the area
        return "The area of the Triangle is " + String.format("%.2f", getSurfaceArea()) + "\n";
    }

    // Override the getNumberOfDimensions method
    // This method returns the number of dimensions for the rectangle, which is 2.
    @Override
    protected int getNumberOfDimensions() {
        return 2;
    }
}
