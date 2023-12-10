# EmuDeck CueWizard


## Overview
EmuDeck CueWizard is a C program specifically designed to enhance the experience of emulating PlayStation 1 (PS1) multi-disk games. It simplifies the management of `.cue` files for game disk images, making it particularly useful for users of EmuDeck, as well as other emulators.



## Features
- Tailored for PS1 multi-disk game emulation.
- Moves `.cue` files from a specified source directory to a destination directory.
- Creates an `.m3u` playlist file in the source directory.
- The `.m3u` file is named after the game, aiding in easy identification and access in emulators.
- Multi disk games with automatically switch to next disk

## Prerequisites
- A C compiler (like GCC) installed on your system.
- Basic knowledge of terminal or command line operations.

## Setup and Compilation
1. Clone or download the repository to your local machine.
2. Navigate to the directory containing the `main.c` file.
3. Compile the program using GCC:
   
   `
   gcc -o CueWizard CueWizard.c`



## Running the Program

Execute the program in the terminal:

`./CueWizard`

## Usage Example
1. When prompted, enter the path to the directory containing the `.cue` files for a PS1 multi-disk game.
2. Enter the path to the directory where you want to move these `.cue` files.
3. Enter the name of the game for the `.m3u` playlist file.

The program will move the `.cue` files to the specified destination and create an `.m3u` file in the source directory listing these files. This `.m3u` file can then be used in EmuDeck or any other emulator to easily manage and access multi-disk games.

## Contributing
Contributions to the Game File Manager are welcome. Please feel free to fork the repository, make changes, and submit pull requests.
