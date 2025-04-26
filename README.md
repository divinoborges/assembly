# Assembly Programs

This repository contains several simple Assembly programs written for the Linux operating system using NASM (Netwide Assembler) and system calls via `int 0x80`.

Each program demonstrates basic input/output and arithmetic operations.

## Programs

### 1. Hello World (`Hello World/hello.asm`)
A simple program that prints "Hello World!" followed by a new line.

**Functionality:**
- Displays a "Hello World!" message to the standard output.

### 2. Input and Echo (`Entrada/entrada.asm`)
Reads the user's first name from the keyboard and prints it back.

**Functionality:**
- Prompts the user to enter their first name.
- Echoes the entered name back to the screen.

### 3. Addition (`Soma/soma.asm`)
Adds two single-digit numbers provided by the user.

**Functionality:**
- Prompts the user to input two numbers.
- Calculates the sum of the two numbers.
- Displays the result.

### 4. Subtraction (`Subtrair/subtrair.asm`)
Subtracts one single-digit number from another.

**Functionality:**
- Prompts the user to input two numbers.
- Subtracts the second number from the first.
- Displays the result.

### 5. Multiplication (`Multiplicar/multiplicar.asm`)
Multiplies two single-digit numbers provided by the user.

**Functionality:**
- Prompts the user to input two numbers.
- Calculates the product of the two numbers.
- Displays the result.

## Requirements

- Linux operating system
- NASM assembler
- Linker (`ld`)

## How to Assemble and Run

```bash
nasm -f elf32 program.asm -o program.o
ld -m elf_i386 program.o -o program
./program
```

Replace `program.asm` with the path to the desired file you want to assemble and execute.

## Notes

- These programs use Linux system calls (`int 0x80`) directly.
- They are written for 32-bit architecture (x86).
- Ensure you have `nasm` installed (`sudo apt install nasm` on Debian-based systems).
- Input handling is basic and expects single or two-character inputs for numbers.

