# BSQ
## The aim of this project is to find the biggest square on a map, avoiding obstacles.


A file containing the map will be provided. 
It’ll have to be passed as an argument for your program.
1. The first line of the map contains information on how to read the map :  
- The number of lines on the map;
- The "empty" character;
- The "obstacle" character;
- The "full" character.
2. The map is made up of ’"empty" characters’, lines and ’"obstacle" characters’.
3. The aim of the program is to replace ’"empty" characters’ by ’"full" characters’ in order to represent the biggest square possible.
4. In the case that more than one solution exists, we’ll choose to represent the square that’s closest to the top of the map, then the one that’s most to the left.

5. Definition of a valid map :
* All lines must have the same length.
* There’s at least one line of at least one box.
* At each end of line, there’s a line break.
* The characters on the map can only be those introduced in the first line.
* In case of an invalid map, your program should display map error on the error output followed by a line break. Your program will then move on to the next map.
6. Here’s an example of how it should work :
<img width="274" alt="Снимок экрана 2022-03-19 в 17 51 02" src="https://user-images.githubusercontent.com/74757833/159125940-dc4cb0b5-d542-4862-9b3b-5ddd49519352.png">
