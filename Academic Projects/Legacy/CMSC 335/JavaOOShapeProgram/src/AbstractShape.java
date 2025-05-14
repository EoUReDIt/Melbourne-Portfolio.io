// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// AbstractShape.java
// This is an abstract class that serves as a base for different shapes.
// It contains an abstract method to get the number of dimensions and a method to validate positive values.
// It also includes an abstract toString method for string representation of the shape.
// It is designed to be extended by specific shape classes like Circle, Rectangle, etc.
// The class is not intended to be instantiated directly.

public abstract class AbstractShape {
    // fields
    // none

    // method----------------------->
    protected abstract int getNumberOfDimensions(); // Abstract method

    // This method is abstract and must be implemented by subclasses
    // It is intended to return a string representation of the shape.
    // The actual implementation will depend on the specific shape class that
    // extends AbstractShape.
    // The method is declared as abstract, meaning that any concrete subclass must
    // provide an implementation for it.
    @Override
    public abstract String toString(); // Abstract method

    // Validation method to check if a value is positive
    protected static void validatePositive(double value, String name) {
        // Check if the value is less than or equal to zero
        // If so, throw an IllegalArgumentException with a message
        if (value <= 0) {
            throw new IllegalArgumentException(name + " must be positive and greater than zero. \n");
        }
    }

}
