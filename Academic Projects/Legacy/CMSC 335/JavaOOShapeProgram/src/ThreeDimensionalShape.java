// CMSC 335 Object-Oriented and Concurrent Programming
// Project 1
// UMGC
// fall 2024
//Melbourne Anderson

// ThreeDimensionalShape.java
// This class represents a three-dimensional shape.
// It extends the AbstractShape class
public abstract class ThreeDimensionalShape extends AbstractShape {

    // field------------------------>
    // none

    // All classes that extend this class must implement the following methods:
    // method----------------------->
    protected abstract double getVolume(); // Calculates volume

    protected abstract double getSurfaceArea(); // Calculates surface area

}
