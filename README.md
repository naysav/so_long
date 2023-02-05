# so_long

This project is a small 2D game with minilibx (graphic library made by school21), 
where the player has to pick all collectibles and go the exit making as few as possible moves. 
The game is about a dino in the desert who collects water drops to drink from a puddle. 
The project only works on MacOS, make sure you have installed the required 
elements to run the minilibx (library is located in the mlx folder)

## How to play

Use ``WASD`` or ``arrows`` to move. ``Esc`` or ``red button`` to exit.

The game is able to play any map you want as long as it follow some specific rules:
* The map has to be a ``.ber`` file.
* It can only contain some of the following characters:

| Character | Object |
| - | - |
| 1 | Wall. |
| 0 | Empty space. |
| C | Collectable. |
| E | Exit. |
| P | Player starting position. |
| H | Horizontal enemy. It moves to left and right, changing direction when its path is blocked. |
| V | Vertical enemy. Moving up and down. |

* The map must be a rectangle surrounded by walls ‘1’.
* It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.

See some examples in the ``maps`` folder of this project.
