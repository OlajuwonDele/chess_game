# chess_game

**Chess Board Object-Oriented Implementation with Move History**

This repository contains a C++ program that demonstrates object-oriented programming techniques while extending the functionality of a chess board representation to record and display move history in a chess game. This project showcases the use of OOP and dynamic data structures like linked lists in C++.

**Project Components:**

1. **Application Class:** This class facilitates user interaction via standard input and output (std::cin and std::cout). Users can perform actions such as:
   - Creating a new chess board with standard starting positions for white and black chess pieces.
   - Displaying all the chess pieces and their positions on the board.
   - Moving chess pieces following the rules of the game.
   - Capturing opponent pieces when a move is valid.
   - Resetting the board to its initial state.

2. **Board Class:** This class represents the chess board itself. It contains a two-dimensional array of `chess_board_square` objects, each capable of holding a chess piece. The board can respond to messages sent by the application class.

3. **Chess Board Square Class:** Objects of this class represent individual squares on the chess board. They can:
   - Hold a chess piece or be empty.
   - Provide information about the presence or absence of a chess piece.
   - Provide information about the color and type of the chess piece, if present.

4. **Move History:** The program implements a dynamic data structure using a one-way linked list of move objects to record the complete history of a chess game. Key concepts include:
   - Recording each move as a C++ object.
   - Creating a chain of move objects, with each object linked to the next one.
   - Efficiently managing move history with dynamic sizing.
   - Allowing users to print the move sequence upon request.
   - Ensuring proper deletion of move objects to prevent memory leaks when resetting the board.
