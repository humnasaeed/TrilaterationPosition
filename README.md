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

## Next Steps? 

Accuracy: Enhancing overall accuracy and ensuring the tag position increases accuracy with added anchors. 

Live Updates: Implement real-time position updates by integrating the algorithm with live data sources or sensors. This could involve using sockets or other communication methods to update the tag's position dynamically.
