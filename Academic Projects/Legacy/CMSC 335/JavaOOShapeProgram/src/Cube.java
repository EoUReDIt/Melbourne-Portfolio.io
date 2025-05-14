// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// Cube.java
// This class represents a cube and extends the ThreeDimensionalShape class.
// It provides methods to calculate the volume and surface area of the cube.
// It contains mandatory error checking for the side length.
// It also overrides the toString method to provide a string representation of the cube's properties.

public class Cube extends ThreeDimensionalShape {

    // The length of the sides of the cube
    // This field is private to ensure encapsulation and can only be accessed
    // through methods of this class.
    // It is a double to allow for decimal values, but should be positive.
    private double sideLength;

    // Constructor for the Cube class
    // It takes the side length as a parameter and validates it.
    // If the side length is not positive, an IllegalArgumentException is thrown.
    // The constructor initializes the sideLength field with the provided value.
    public Cube(double sideLength) {
        // Error checking
        AbstractShape.validatePositive(sideLength, "sideLength");

        // set value
        this.sideLength = sideLength;
    }

    // Getter method for the side length
    // This method returns the value of the sideLength field.
    @Override
    protected double getVolume() {
        return Math.pow(sideLength, 3);
    }

    // Getter method for the surface area
    // This method calculates the surface area of the cube using the formula 6 *
    // sideLength^2.
    // It returns the calculated surface area.
    @Override
    protected double getSurfaceArea() {
        return 6 * Math.pow(sideLength, 2);
    }

    // This method overrides the toString method from the AbstractShape class.
    // It provides a string representation of the cube's properties, including its
    // surface area and volume.
    @Override
    public String toString() {
        return "The area of the cube is " + String.format("%.2f", getSurfaceArea()) + ", and the volume is "
                + String.format("%.2f", getVolume()) + "\n";
    }

    @Override
    protected int getNumberOfDimensions() {
        return 3;
    }
}
