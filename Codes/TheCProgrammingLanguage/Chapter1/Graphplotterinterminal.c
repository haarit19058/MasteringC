#include <stdio.h>
#include <stdlib.h>

int main() {
    float lower_x, upper_x, lower_y, upper_y;
    int num_datapoints;

    // Input data
    printf("Enter the number of Datapoints to plot: ");
    scanf("%d", &num_datapoints);
    printf("Enter Lower limit of x-axis: ");
    scanf("%f", &lower_x);
    printf("Enter Upper limit of x-axis: ");
    scanf("%f", &upper_x);
    printf("Enter Lower limit of y-axis: ");
    scanf("%f", &lower_y);
    printf("Enter Upper limit of y-axis: ");
    scanf("%f", &upper_y);

    // Allocate memory for data points
    float *x_values = malloc(sizeof(float) * num_datapoints);
    float *y_values = malloc(sizeof(float) * num_datapoints);

    // Input x and y values
    float temp1, temp2;
    for (int i = 0; i < num_datapoints; i++) {
        printf("Enter x and y values for point %d: ", i + 1);
        scanf("%f %f", &temp1, &temp2);
        *(x_values + i) = temp1;
        *(y_values + i) = temp2;
    }

    // Print the graph
    for (int row = upper_y; row >= lower_y; row--) {
        printf("%3d|", row);
        for (int col = lower_x; col <= upper_x; col++) {
            int pointFound = 0;
            for (int i = 0; i < num_datapoints; i++) {
                if (row == *(y_values + i) && col == *(x_values + i)) {
                    printf(" * ");
                    pointFound = 1;
                    break;
                }
            }
            if (!pointFound) {
                printf("   ");
            }
        }
        printf("\n");
    }

    // Print x-axis
    printf("   ");
    for (int col = lower_x; col <= upper_x; col++) {
        printf("---");
    }
    printf("\n");

    // Print x-axis labels
    printf("   ");
    for (int col = lower_x; col <= upper_x; col++) {
        printf("%3d", col);
    }
    printf("\n");

    // Free allocated memory
    free(x_values);
    free(y_values);

    return 0;
}





/*

//Same code but using array of structures.

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a data point
typedef struct {
    float x;
    float y;
} DataPoint;

int main() {
    float lower_x, upper_x, lower_y, upper_y;
    int num_datapoints;

    // Input data
    printf("Enter the number of Datapoints to plot: ");
    scanf("%d", &num_datapoints);
    printf("Enter Lower limit of x-axis: ");
    scanf("%f", &lower_x);
    printf("Enter Upper limit of x-axis: ");
    scanf("%f", &upper_x);
    printf("Enter Lower limit of y-axis: ");
    scanf("%f", &lower_y);
    printf("Enter Upper limit of y-axis: ");
    scanf("%f", &upper_y);

    // Allocate memory for an array of DataPoint structures
    DataPoint *data_points = malloc(sizeof(DataPoint) * num_datapoints);

    // Input x and y values for each data point
    for (int i = 0; i < num_datapoints; i++) {
        printf("Enter x and y values for point %d: ", i + 1);
        scanf("%f %f", &data_points[i].x, &data_points[i].y);
    }

    // Print the graph
    for (int row = upper_y; row >= lower_y; row--) {
        printf("%3d|", row);
        for (int col = lower_x; col <= upper_x; col++) {
            int pointFound = 0;
            for (int i = 0; i < num_datapoints; i++) {
                if (row == data_points[i].y && col == data_points[i].x) {
                    printf(" * ");
                    pointFound = 1;
                    break;
                }
            }
            if (!pointFound) {
                printf("   ");
            }
        }
        printf("\n");
    }

    // Print x-axis
    printf("   ");
    for (int col = lower_x; col <= upper_x; col++) {
        printf("---");
    }
    printf("\n");

    // Print x-axis labels
    printf("   ");
    for (int col = lower_x; col <= upper_x; col++) {
        printf("%3d", col);
    }
    printf("\n");

    // Free allocated memory
    free(data_points);

    return 0;
}



*/