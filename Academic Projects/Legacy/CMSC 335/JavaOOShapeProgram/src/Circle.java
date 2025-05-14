// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// Circle.java
// This class represents a Circle shape and extends the TwoDimensionalShape class.
// It contains a constructor to initialize the radius of the circle and methods to calculate the surface area.
public class Circle extends TwoDimensionalShape {
    // class for all 2D circle shapes.

    // fields
    private double radius;

    // Constructor
    // This constructor initializes the radius of the circle.
    // It also validates that the radius is a positive number.
    public Circle(double radius) {
        // Constructor

        // Error checking
        // check if radius is positive
        // if not, throw an exception
        AbstractShape.validatePositive(radius, "Radius");

        // if radius is positive, set the radius
        // to the value passed in
        this.radius = radius;

    }

    // This method calculates the surface area of the circle.
    // The formula for the area of a circle is pi * radius^2.
    // It overrides the getSurfaceArea method defined in the TwoDimensionalShape
    // class.
    // It is a mandatory method to implement from the AbstractShape class.
    // It is a protected method, meaning it can be accessed within the same package
    protected double getSurfaceArea() {

        // Calculating the area of the circle
        // using the formula area = pi * radius^2
        // returning the area
        return Math.PI * radius * radius;
    }

    // it overrides the toString method defined in the AbstractShape class.
    // It is used to provide a string representation of the Circle object.
    @Override
    public String toString() {
        // creating output of the area
        return "The area of the Circle is " + String.format("%.2f", getSurfaceArea()) + "\n";
    }

    // This method overrides the getNumberOfDimensions method from the abstract
    // class AbstractShape.
    // It returns the number of dimensions for the Circle shape, which is 2.
    // The method is protected, meaning it can be accessed within the same package
    // or by subclasses.
    @Override
    protected int getNumberOfDimensions() {
        return 2;
    }
}
