# Paint-for-Kids

This is a desktop application for kids that allows them to create drawings using various shapes and colors. The application is implemented in C++ and follows an object-oriented programming (OOP) approach, resulting in a well-structured codebase.

## Features

The Kids Paint Desktop App offers the following main features:

### Drawing Shapes

- Rectangle: Allows the user to draw rectangles on the canvas.
- Square: Enables drawing squares of equal length sides.
- Triangle: Provides the ability to draw triangles.
- Hexagon: Allows drawing hexagons with six equal sides.
- Circle: Enables the creation of circles on the canvas.

### Interaction with Shapes

- Select: Allows the user to select a shape on the canvas for further modification.
- Move: Enables moving the selected shape to a new position on the canvas.
- Change Fill Color: Allows changing the fill color of the selected shape.
- Change Draw Color: Allows changing the draw color of the selected shape.
- Delete: Removes the selected shape from the canvas.

### Saving and Loading

- Save: Saves the current drawing to a file.
- Load: Loads a previously saved drawing from a file.

### Additional Features

- Undo and Redo: Provides the ability to undo and redo previous actions performed on the canvas.
- Sound Effects: Enables or disables sound effects within the application.
- Recording: Allows the user to record their actions on the canvas and play them back later.

## Code Structure

The codebase of the Kids Paint Desktop App is well-structured and follows an object-oriented design. The main components of the application include:

### The Application Manager

The `ApplicationManager` class is responsible for managing the overall flow of the application. It handles the execution of various actions based on user input and maintains a list of shapes present on the canvas.

### Actions

Actions are represented by different classes, each corresponding to a specific operation that can be performed on the canvas. Each action class inherits from a base `Action` class and implements the `Execute` method to perform its specific functionality.

### Shapes

Different shape classes, such as `Rectangle`, `Square`, `Triangle`, `Hexagon`, and `Circle`, are implemented to represent the various shapes that can be drawn on the canvas. Each shape class provides methods for drawing, selecting, moving, and modifying the shape's properties.

### Saving and Loading

The `Save` and `Load` actions are responsible for saving and loading the drawing to and from a file, respectively. The `SaveAll` method in the `ApplicationManager` class is used to save all the shapes' data to the file.

### Undo and Redo

The `UndoAction` and `RedoAction` classes provide the ability to undo and redo previous actions performed on the canvas. These actions utilize a stack-based approach to store the executed actions, allowing for easy reversal and restoration of actions.

### Sound Effects

The `Sound` action allows the user to enable or disable sound effects within the application. It interacts with the underlying audio system to play sound effects when certain actions are performed.

### Recording

The `StartRec`, `StopRec`, and `PlayRec` actions are responsible for recording the user's actions on the canvas, stopping the recording, and playing back the recorded actions, respectively. These actions utilize a recording mechanism to store the sequence of actions performed by the user.

## Contributing

Contributions to the Kids Paint Desktop App are welcome! If you have any ideas, bug reports, or feature requests, please open an issue or submit a pull request on the GitHub repository.

## License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). See the [LICENSE](LICENSE) file for more details.
