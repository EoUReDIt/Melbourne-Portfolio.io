// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// TwoDimensionalShape.java
// This class represents a Two Dimensional Shape and extends the AbstractShape class.
// It contains an abstract method to calculate the surface area.
// It is designed to be extended by specific two-dimensional shape classes like Circle, Rectangle, etc.
// The class is not intended to be instantiated directly.

public abstract class TwoDimensionalShape extends AbstractShape {

    // fields------------------>
    // none

    // This method is abstract and must be implemented by subclasses
    // It is intended to return the surface area of the shape.
    protected abstract double getSurfaceArea();

}
