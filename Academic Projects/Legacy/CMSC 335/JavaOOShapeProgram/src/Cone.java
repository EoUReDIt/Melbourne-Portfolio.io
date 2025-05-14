// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// Cone.java
// This class represents a Cone shape and extends the ThreeDimensionalShape class.
// It contains a constructor to initialize the radius and height of the cone
// and methods to calculate the surface area and volume.
public class Cone extends ThreeDimensionalShape {

    // fields
    private double radius;
    private double height;

    // Constructor
    // This constructor initializes the radius and height of the cone.
    // It also validates that the radius and height are positive numbers.
    public Cone(double radius, double height) {

        // Error checking
        AbstractShape.validatePositive(radius, "Radius");
        AbstractShape.validatePositive(height, "Height");

        // set value
        this.radius = radius;
        this.height = height;
    }

    // This method calculates the volume of the cone.
    // The formula for the volume of a cone is (1/3) * pi * radius^2 * height.
    // It overrides the getVolume method defined in the ThreeDimensionalShape class.
    @Override
    protected double getVolume() {
        return (1.0 / 3.0) * Math.PI * Math.pow(radius, 2) * height;
    }

    // This method calculates the surface area of the cone.
    // The formula for the surface area of a cone is pi * radius * (radius + slant
    // height),
    // overrides the getSurfaceArea method defined in the ThreeDimensionalShape
    // class.
    @Override
    protected double getSurfaceArea() {
        double slantHeight = Math.sqrt(Math.pow(radius, 2) + Math.pow(height, 2));
        return Math.PI * radius * (radius + slantHeight);
    }

    // This method returns a string representation of the Cone object.
    // It includes the surface area and volume of the cone, formatted to two decimal
    // places.
    // It overrides the toString method defined in the Object class.
    // It is a mandatory method to implement from the AbstractShape class.
    @Override
    public String toString() {
        return "The area of the Cone is " + String.format("%.2f", getSurfaceArea()) + ", and the volume is "
                + String.format("%.2f", getVolume()) + "\n";
    }

    // This method returns the number of dimensions of the Cone object.
    // It overrides the getNumberOfDimensions method defined in the AbstractShape
    // class.
    // It is a mandatory method to implement from the AbstractShape class.
    @Override
    protected int getNumberOfDimensions() {
        return 3;
    }
}