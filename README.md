# TrilaterationPosition


Trilateration Algorithm using anchor positions and distances to calculate the current tag position.


## How it Works?

The trilateration algorithm determines the position of a tag based on the distances from multiple anchors with known positions. This repository contains a C++ implementation of the trilateration algorithm that calculates the tag's approximate position in 2D space.

Once executed, the algorithm will save a local file (`tag_position.txt`) to be used by the following Python Script to provide real-time visualization.  

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

## Next Steps? 

The next steps of the project using this algorithm: 

### Real-Time Data Integration

To enable real-time position updates, integrate the trilateration algorithm with live sensor data. Configure sensors to provide frequent distance measurements and use efficient communication methods to transmit this data to your system. Implement real-time processing to continuously update the tag's position and visualize it dynamically on a web interface or graphical display.


# Python Visualization Algorithm (Turtle) 

This Python Turtle script visualizes the calculated tag position on a 2D grid in real time. The algorithm is designed to integrate with the trilateration algorithm above, offering a live representation of the tag’s location on a graphical interface.

## How it Works? 

1. **Real-Time Position Tracking:** The script continuously reads a local file (tag_position.txt), where the tag’s x and y coordinates are stored. These coordinates are then updated on a 2D grid.
2. **Dynamic Visualization:** The program operates in a constant loop, ensuring that the tag’s position is updated in real time as new data becomes available.
3. **Coordinate Adjustment:** The script adjusts the coordinates to align with the graphical grid, positioning the origin (0, 0) at the upper-right corner of the layout.


## 2D Grid and Layout 

A floor layout image can be set as the background of the Turtle graphics window. The script adjusts the coordinate system to ensure that the upper-right corner represents the origin.

# Replace with the current floorplan and adjust the offsets as needed: 

```
screen.bgpic("C:/Users/humna/Downloads/floorplan.gif")
```

Adjust the `adjust_coordinates` function and fine-tune the placement on the grid. 



## Next Steps? 

### Integration with Trilateration: 

To fully integrate this with the trilateration algorithm, feed the output coordinates from the algorithm into the Turtle graphics script. This is done using the `tag_position.txt` file created by the trilateration algorithm, and read by the Trutle algorithm. The integration of the two can be improved to be more efficient and will allow real-time updates of the tag’s position on the graphical grid.

### Efficient Floor Plan Implementation

The current method of uploading and adjusting the floor plan is hard-coded. Future improvements could include more dynamic ways to handle different floor plans and coordinate systems to develop maintainable code.
