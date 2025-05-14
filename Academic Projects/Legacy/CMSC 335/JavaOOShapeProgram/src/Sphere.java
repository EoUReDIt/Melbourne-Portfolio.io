// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

//Sphere.java
// This class is a subclass of the abstract class ThreeDimensionalShape.
// It represents a sphere shape and provides methods to calculate its volume and surface area.
// It also includes a constructor to initialize the sphere's radius.
public class Sphere extends ThreeDimensionalShape {

    // fields----------------------->
    // radius of the sphere
    private double radius;

    // method----------------------->
    // Constructor
    // This constructor initializes the radius of the sphere.
    // It also validates that the radius is a positive value.
    public Sphere(double radius) {
        // Error checking
        AbstractShape.validatePositive(radius, "Radius");

        // set value
        this.radius = radius;
    }

    // there is no need for a setter method for the radius
    // because it is set in the constructor and should not be changed
    // Override the getVolume method from the abstractshape class
    @Override
    protected double getVolume() {
        return (4.0 / 3.0) * Math.PI * Math.pow(radius, 3);
    }

    // Override the getSurfaceArea method from the abstractshape class
    // This method calculates the surface area of the sphere using the formula 4 * π
    // * r^2.
    @Override
    protected double getSurfaceArea() {
        return 4 * Math.PI * Math.pow(radius, 2);
    }

    // Override the toString method
    // This method returns a string representation of the sphere's surface area and
    // volume.
    // It formats the output to two decimal places.
    @Override
    public String toString() {
        return "The area of the Sphere is " + String.format("%.2f", getSurfaceArea()) + ", and the volume is "
                + String.format("%.2f", getVolume()) + "\n";
    }

    // Override the getNumberOfDimensions method
    // This method returns the number of dimensions for the sphere, which is 3.
    // It is used to determine the dimensionality of the shape.
    @Override
    protected int getNumberOfDimensions() {
        return 3;
    }
}
