// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// This class represents a cylinder and extends the abstract class ThreeDimensionalShape.
// It provides methods to calculate the volume and surface area of the cylinder.
//contains mandatory methods from the abstract class
public class Cylinder extends ThreeDimensionalShape {

    // field
    private double radius;
    private double height;

    // Constructor
    // This constructor initializes the radius and height of the cylinder.
    // It also validates that the radius and height are positive values.
    public Cylinder(double radius, double height) {

        // Error checking
        AbstractShape.validatePositive(radius, "Radius");
        AbstractShape.validatePositive(height, "Height");

        // set value
        this.radius = radius;
        this.height = height;
    }

    // This method calculates the volume of the cylinder using the formula: V = π *
    // r^2 * h
    // where r is the radius and h is the height.
    // It overrides the getVolume method from the abstract class
    // ThreeDimensionalShape.
    // It returns the volume of the cylinder.
    @Override
    protected double getVolume() {
        return Math.PI * Math.pow(radius, 2) * height;
    }

    // This method calculates the surface area of the cylinder using the formula: A
    // = 2 * π * r * (r + h)
    // where r is the radius and h is the height.
    // It overrides the getSurfaceArea method from the abstract class
    // ThreeDimensionalShape.
    @Override
    protected double getSurfaceArea() {
        return 2 * Math.PI * radius * (radius + height);
    }

    // This method returns a string representation of the cylinder.
    // It includes the surface area and volume of the cylinder formatted to two
    // decimal places.
    // It overrides the toString method from the abstract class
    // ThreeDimensionalShape.
    @Override
    public String toString() {
        return "The area of the Cylinder is " + String.format("%.2f", getSurfaceArea()) + ", and the volume is "
                + String.format("%.2f", getVolume()) + "\n";
    }

    // This method returns the number of dimensions for the cylinder, which is 3.
    // It overrides the getNumberOfDimensions method from the abstractshape class.
    @Override
    protected int getNumberOfDimensions() {
        return 3;
    }
}
