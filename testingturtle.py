import turtle
import time

# Screen setup
screen = turtle.Screen()
screen.title("Path Movement on Grid")
screen.bgcolor("white")

# Setting floorplan as background
screen.bgpic("C:/Users/humna/Downloads/floorplan.gif")

# Create a turtle for drawing the path
path_turtle = turtle.Turtle()
path_turtle.speed(0.1)  # Adjust speed as needed
path_turtle.pensize(2)
path_turtle.color("blue")

# Function to adjust coordinates to shift (0, 0) to top-right corner
def adjust_coordinates(x, y):
    adjusted_x = x + 231 # Adjust X coordinates to shift origin to top-right
    adjusted_y = 366 - y  # Adjust Y coordinates to shift origin to top-right
    return adjusted_x, adjusted_y

# Setting the users starting position (this may not always apply)
initial_position = (0,0)
adjusted_initial = adjust_coordinates(initial_position[0], initial_position[1])
# List to store the coordinates
coordinates = [adjusted_initial]

# Function to update and draw the path based on the file's content
def update_position():
    try:
        with open("C:/Users/humna/Downloads/tag_position.txt", "r") as file:
            data = file.read().strip()
            if data:
                x, y = map(float, data.split())
                adjusted_x, adjusted_y = adjust_coordinates(x, y)
                
                # Add the new position to the coordinates list
                coordinates.append((adjusted_x, adjusted_y))
                print(adjusted_x)
                print(adjusted_y)
                
                # Draw the path
                path_turtle.clear()  # Clear previous drawings
                path_turtle.penup()
                path_turtle.goto(coordinates[0])  # Start at the first coordinate
                path_turtle.pendown()
                for coord in coordinates[1:]:  # Draw lines to each subsequent coordinate
                    path_turtle.goto(coord)
                    
    except FileNotFoundError:
        print("Position file not found.")
    except Exception as e:
        print(f"Error reading position file: {e}")

# Continuously update the position and redraw the path
while True:
    update_position()
    time.sleep(1)

# Keep the window open until closed by the user
turtle.done()
