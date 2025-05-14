// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// Torus.java
// This class represents a torus shape and extends the ThreeDimensionalShape class.
// It provides methods to calculate the volume and surface area of the torus.
// It also includes a constructor to initialize the torus's major and minor radii.

public class Torus extends ThreeDimensionalShape {

    // fields----------------------->
    private double majorRadius; // R: distance from the center of the tube to the center of the torus
    private double minorRadius; // r: radius of the tube

    // method----------------------->
    // Constructor
    // This constructor initializes the major and minor radii of the torus.
    // It also validates that the major and minor radii are positive values.
    public Torus(double majorRadius, double minorRadius) {

        // Error checking
        // check if the major and minor radii are positive
        // validatePositive is a static method in the AbstractShape class
        // it checks if the value is positive and throws an exception if not
        AbstractShape.validatePositive(majorRadius, "Major Radius");
        AbstractShape.validatePositive(minorRadius, "Minor Radius");

        // set value
        // set the major and minor radii of the torus
        // majorRadius is the distance from the center of the tube to the center of the
        // torus
        // minorRadius is the radius of the tube
        // these values are set in the constructor and should not be changed
        this.majorRadius = majorRadius;
        this.minorRadius = minorRadius;
    }

    // there is no need for a setter method for the major and minor radii
    @Override
    protected double getVolume() {
        return 2 * Math.PI * Math.PI * majorRadius * Math.pow(minorRadius, 2);
    }

    // Override the getSurfaceArea method from the abstractshape class
    // This method calculates the surface area of the torus using the formula 4 *
    // π^2 * R * r.
    @Override
    protected double getSurfaceArea() {
        return 4 * Math.PI * Math.PI * majorRadius * minorRadius;
    }

    // Override the toString method
    // This method returns a string representation of the torus's surface area and
    // volume.
    @Override
    public String toString() {
        return "The area of the Torus is " + String.format("%.2f", getSurfaceArea()) + ", and the volume is "
                + String.format("%.2f", getVolume()) + "\n";
    }

    // Override the getNumberOfDimensions method
    // This method returns the number of dimensions for the torus, which is 3.
    @Override
    protected int getNumberOfDimensions() {
        return 3;
    }
}