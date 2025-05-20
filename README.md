# Legol Compiler - Phase 2a

## A simple C program that simulates building and stacking Legol Building Blocks.

-   [ ] I am a huge Lego fan so I decided that I want to create a simple compiler based on this. A basic Legol-building-block language and output instructions. A single Legol command will be read from the user and then processes it. Then it will print what it is doing. Lastly the program will end.
-   [ ] Phase 3 of this project now has a Symbol table to remember all your commands

## What phase 2a does?

-   [ ] This program now has:
    -   [ ] A "symbol table" that remembers all your commands
    -   [ ] It has descriptions for each type of word -> aka tokens
    -   [ ] All your commands are neatly displayed at the end

## How to Use

-   [ ] Run the program
-   [ ] Type one of these commands:
    -   [ ] `BUILD` `<color>` `<size>` (Example: `BUILD pink large`)
    -   [ ] `STACK` `<color>` `<size>` (Example: `STACK mint medium`)
    -   [ ] `END` (to stop the program)
-   [ ] Then you will see:
    -   [ ] What type each word is -> `Command` | `Color` | `Size`
    -   [ ] A table showing all words with their types and descriptions

## Example

```
-> Welcome to the Legol Mini Compiler!
-> Enter a Legol command (BUILD <color> <size>) or (STACK <color> <size>) or END:
-> BUILD white medium
-> BUILD tokword
-> white tokcolor
-> medium toksize

SYMBOL TABLE:
Word Type Description
BUILD  | Command | Command to build a Legol Block
white  | Color   | Color of the Legol Block
medium | Size    | Size of the Legol Block
```

## What You'll Learn: Phase 2a

-   [ ] This version shows:
    -   [ ] How compilers remember words (symbol tables)
    -   [ ] Using structure in C to organize data
    -   [ ] Adding descriptions to different word types
    -   [ ] Displaying organized information in tables

## Enjoying it's Growth

-   [ ] This program is now starting to act like a real compiler:

    -   [ ] Keeping track of everything you type
    -   [ ] Adding helpful descriptions
    -   [ ] Showing everything neatly at the end

-   [ ] Encompass:
    -   [ ] C Programming Language
-   [ ] C → This language is best to use when writing a compiler, it is fast, and close to how computers actually work.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
