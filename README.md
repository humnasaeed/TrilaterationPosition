# TrilaterationPosition


Trilateration Algorithm using anchor positions and distances to calculate the current tag position.


## How it Works?

The trilateration algorithm determines the position of a tag based on the distances from multiple anchors with known positions. This repository contains a C++ implementation of the trilateration algorithm that calculates the tag's approximate position in 2D space.

### 1. Set Up Anchor Coordinates and Distances: 

Modify the main method in the C++ code to update the coordinates of the anchors and the distances from the tag to each anchor. Ensure you input the correct x, y (and optionally z) coordinates for each anchor. Provide the distances from the tag to each anchor.


### 2. Compile and Run Code: 

Compile using g++ compiler
```
g++ -o trilateration trilateration.cpp
```

Run the executable to compute the tag's position
```
./trilateration
```

#### Example Setup: 

```
    const int numAnchors = 4;
    float x_anchors[numAnchors] = {0, 4, 2, 1};
    float y_anchors[numAnchors] = {0, 0, 4, 1};
    float z_anchors[numAnchors] = {0, 0, 0, 1};
    float r[numAnchors] = {2.828, 2.828, 2, 1.732};
```

## Algorithm Computations: 

to finish.

## Next Steps? 

The next steps of the project using this algorithm: 

### Real-Time Data Integration

To enable real-time position updates, integrate the trilateration algorithm with live sensor data. Configure sensors to provide frequent distance measurements and use efficient communication methods to transmit this data to your system. Implement real-time processing to continuously update the tag's position and visualize it dynamically on a web interface or graphical display.
