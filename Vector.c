#include <stdio.h>
#include <math.h>

// Structure to represent a 3D vector
typedef struct
{
    double x;
    double y;
    double z;
} Vector3D;

// Function to add two 3D vectors
Vector3D addVectors(Vector3D v1, Vector3D v2)
{
    return (Vector3D){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

// Function to subtract two 3D vectors
Vector3D subtractVectors(Vector3D v1, Vector3D v2)
{
    return (Vector3D){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

// Function to calculate the dot product of two 3D vectors
double dotProduct(Vector3D v1, Vector3D v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Function to calculate the cross product of two 3D vectors
Vector3D crossProduct(Vector3D v1, Vector3D v2)
{
    return (Vector3D){
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x};
}

// Function to calculate the magnitude of a vector
double magnitude(Vector3D v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Function to scale a vector by a scalar
Vector3D scalarMultiply(Vector3D v, double scalar)
{
    return (Vector3D){v.x * scalar, v.y * scalar, v.z * scalar};
}

// Function to calculate the unit vector of a vector
Vector3D unitVector(Vector3D v)
{
    double mag = magnitude(v);
    if (mag == 0.0)
    {
        return (Vector3D){0.0, 0.0, 0.0}; // Avoid division by zero
    }
    return (Vector3D){v.x / mag, v.y / mag, v.z / mag};
}

// Function to calculate the scalar projection of vector v1 onto v2
double scalarProjection(Vector3D v1, Vector3D v2)
{
    double dot = dotProduct(v1, v2);
    double mag2 = dotProduct(v2, v2);
    if (mag2 == 0.0)
    {
        return 0.0; // Avoid division by zero
    }
    return dot / sqrt(mag2);
}

// Function to calculate the vector triple product
Vector3D vectorTripleProduct(Vector3D a, Vector3D b, Vector3D c)
{
    Vector3D result = crossProduct(a, crossProduct(b, c));
    return result;
}

// Function to calculate the angle (in degrees) between two vectors
double angleBetweenVectors(Vector3D v1, Vector3D v2)
{
    double dot = dotProduct(v1, v2);
    double mag1 = magnitude(v1);
    double mag2 = magnitude(v2);

    // Check for division by zero (to avoid NaN)
    if (mag1 == 0 || mag2 == 0)
    {
        return 0.0;
    }

    double cosTheta = dot / (mag1 * mag2);
    return acos(cosTheta) * 180.0 / M_PI; // Convert radians to degrees
}

// Function to display the equation of a plane given normal vector and a point on the plane
void displayPlaneEquation(Vector3D normal, Vector3D point)
{
    printf("Plane Equation: %.2fx + %.2fy + %.2fz = %.2f\n", normal.x, normal.y, normal.z,
           normal.x * point.x + normal.y * point.y + normal.z * point.z);
}

// Function to display the equation of a line given a point on the line and its direction vector
void displayLineEquation(Vector3D point, Vector3D direction)
{
    printf("Line Equation: x = %.2f + %.2ft, y = %.2f + %.2ft, z = %.2f + %.2ft\n",
           point.x, direction.x, point.y, direction.y, point.z, direction.z);
}

int main()
{
    int choice;
    Vector3D vector1, vector2, vector3;

    // Input for vector1
    printf("Enter components of the first 3D vector (x y z): ");
    scanf("%lf %lf %lf", &vector1.x, &vector1.y, &vector1.z);

    // Input for vector2
    printf("Enter components of the second 3D vector (x y z): ");
    scanf("%lf %lf %lf", &vector2.x, &vector2.y, &vector2.z);

    // Menu for vector operations
    printf("\nChoose a vector operation:\n");
    printf("1. Vector Addition\n");
    printf("2. Vector Subtraction\n");
    printf("3. Dot Product\n");
    printf("4. Cross Product\n");
    printf("5. Vector Projection\n");
    printf("6. Magnitude\n");
    printf("7. Scalar Projection\n");
    printf("8. Vector Triple Product\n");
    printf("9. Angle Between Vectors\n");
    printf("10. Unit Vector\n");
    printf("11. Plane Equation\n");
    printf("12. Line Equation\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // User choice
    switch (choice)
    {
    case 1:
    {
        // Vector Addition
        Vector3D sum = addVectors(vector1, vector2);
        printf("Vector Addition: (%.2f, %.2f, %.2f) + (%.2f, %.2f, %.2f) = (%.2f, %.2f, %.2f)\n",
               vector1.x, vector1.y, vector1.z, vector2.x, vector2.y, vector2.z, sum.x, sum.y, sum.z);
        break;
    }
    case 2:
    {
        // Vector Subtraction
        Vector3D difference = subtractVectors(vector1, vector2);
        printf("Vector Subtraction: (%.2f, %.2f, %.2f) - (%.2f, %.2f, %.2f) = (%.2f, %.2f, %.2f)\n",
               vector1.x, vector1.y, vector1.z, vector2.x, vector2.y, vector2.z, difference.x, difference.y, difference.z);
        break;
    }
    case 3:
    {
        // Dot Product
        double dot = dotProduct(vector1, vector2);
        printf("Dot Product: %.2f\n", dot);
        break;
    }
    case 4:
    {
        // Cross Product
        Vector3D cross = crossProduct(vector1, vector2);
        printf("Cross Product: (%.2f, %.2f, %.2f) x (%.2f, %.2f, %.2f) = (%.2f, %.2f, %.2f)\n",
               vector1.x, vector1.y, vector1.z, vector2.x, vector2.y, vector2.z, cross.x, cross.y, cross.z);
        break;
    }

    case 5:
    {
        // Vector Projection
        double dot = dotProduct(vector1, vector2);
        double magSquared = dotProduct(vector2, vector2);
        Vector3D projection = scalarMultiply(vector2, dot / magSquared);
        printf("Vector Projection: (%.2f, %.2f, %.2f) projected onto (%.2f, %.2f, %.2f) = (%.2f, %.2f, %.2f)\n",
               vector1.x, vector1.y, vector1.z, vector2.x, vector2.y, vector2.z, projection.x, projection.y, projection.z);
        break;
    }

    case 6:
    {
        // Magnitude
        double mag1 = magnitude(vector1);
        double mag2 = magnitude(vector2);
        printf("Magnitude of Vector 1: %.2f\n", mag1);
        printf("Magnitude of Vector 2: %.2f\n", mag2);
        break;
    }
    case 7:
    {
        // Scalar Projection
        double scalarProj = scalarProjection(vector1, vector2);
        printf("Scalar Projection of Vector 1 onto Vector 2: %.2f\n", scalarProj);
        break;
    }
    case 8:
    {
        // Vector Triple Product
        Vector3D vector3;
        printf("Enter components of the third 3D vector (x y z): ");
        scanf("%lf %lf %lf", &vector3.x, &vector3.y, &vector3.z);
        Vector3D tripleProduct = vectorTripleProduct(vector1, vector2, vector3);
        printf("Vector Triple Product: ((%.2f, %.2f, %.2f) x (%.2f, %.2f, %.2f)) x (%.2f, %.2f, %.2f) = (%.2f, %.2f, %.2f)\n",
               vector1.x, vector1.y, vector1.z, vector2.x, vector2.y, vector2.z, vector3.x, vector3.y, vector3.z, tripleProduct.x, tripleProduct.y, tripleProduct.z);
        break;
    }
    case 9:
    {
        // Angle Between Vectors
        double angle = angleBetweenVectors(vector1, vector2);
        printf("Angle Between Vectors 1 and 2: %.2f degrees\n", angle);
        break;
    }
    case 10:
    {
        // Unit Vector
        Vector3D unitVec1 = unitVector(vector1);
        Vector3D unitVec2 = unitVector(vector2);
        printf("Unit Vector of Vector 1: (%.2f, %.2f, %.2f)\n", unitVec1.x, unitVec1.y, unitVec1.z);
        printf("Unit Vector of Vector 2: (%.2f, %.2f, %.2f)\n", unitVec2.x, unitVec2.y, unitVec2.z);
        break;
    }
    case 11:
    {
        // Plane Equation
        Vector3D normal, point;
        printf("Enter the normal vector of the plane (x y z): ");
        scanf("%lf %lf %lf", &normal.x, &normal.y, &normal.z);
        printf("Enter a point on the plane (x y z): ");
        scanf("%lf %lf %lf", &point.x, &point.y, &point.z);
        displayPlaneEquation(normal, point);
        break;
    }
    case 12:
    {
        // Line Equation
        Vector3D linePoint, lineDirection;
        printf("Enter a point on the line (x y z): ");
        scanf("%lf %lf %lf", &linePoint.x, &linePoint.y, &linePoint.z);
        printf("Enter the direction vector of the line (x y z): ");
        scanf("%lf %lf %lf", &lineDirection.x, &lineDirection.y, &lineDirection.z);

        // Display the line equation
        displayLineEquation(linePoint, lineDirection);
        break;
    }
    case 13:
    {
        // Unique Vector
        // Implement the logic for the unique vector operation
        printf("This is the Unique Vector operation.\n");
        break;
    }
    default:
    {
        printf("Invalid choice. Please choose a valid option from the menu.\n");
    }
    }

    return 0;
}
