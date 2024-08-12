# TrilaterationPosition


Trilateration Algorithm using anchor positions and distances to calculate the current tag position.


## How it Works?

The trilateration algorithm determines the position of a tag based on the distances from multiple anchors with known positions. This repository contains a C++ implementation of the trilateration algorithm that calculates the tag's approximate position in 2D space.

### 1. Set Up Anchor Coordinates and Distances: 

Modify the main method in the C++ code to update the coordinates of the anchors and the distances from the tag to each anchor. Ensure you input the correct x, y (and optionally z) coordinates for each anchor. Provide the distances from the tag to each anchor.


### 2. Compile and Run Code: 

```
g++ -o trilateration trilateration.cpp
```
