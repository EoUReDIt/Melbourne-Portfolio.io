// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

//Triangle.java
// This class is a subclass of the abstract class TwoDimensionalShape.
// It represents a triangle shape and provides methods to calculate its surface area.
// It also includes a constructor to initialize the triangle's base and height.
public class Triangle extends TwoDimensionalShape {

    // fields------------------>
    // base and height of the triangle
    // these are the dimensions of the triangle
    private double base;
    private double height;

    // method----------------------->
    // Constructor
    // This constructor initializes the base and height of the triangle.
    // It also validates that the base and height are positive values.
    public Triangle(double base, double height) {
        // Constructor

        // Error checking
        // check if the base and height are positive
        // validatePositive is a static method in the AbstractShape class
        AbstractShape.validatePositive(base, "Base");
        AbstractShape.validatePositive(height, "Height");

        // set value
        // set the base and height of the triangle
        this.base = base;
        this.height = height;

    }

    // there is no need for a setter method for the base and height
    // because they are set in the constructor and should not be changed
    // Override the getSurfaceArea method from the abstractshape class
    @Override
    protected double getSurfaceArea() {

        return 0.5 * base * height;
    }

    // Override the toString method
    // This method returns a string representation of the triangle's surface area.
    // It formats the output to two decimal places.
    @Override
    public String toString() {
        // creating output of the area
        return "The area of the Triangle is " + String.format("%.2f", getSurfaceArea()) + "\n";
    }

    // Override the getNumberOfDimensions method
    // This method returns the number of dimensions for the triangle, which is 2.
    // It is a static method in the AbstractShape class
    @Override
    protected int getNumberOfDimensions() {
        return 2;
    }
}