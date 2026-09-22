# Image Steganography

## Description

Image Steganography is a C project that hides secret data inside a BMP image without visibly changing the image. The hidden data can later be extracted from the stego image using the decoding process.

## Features

* Encode secret text/data into a BMP image
* Decode hidden data from a stego image
* Preserve the visual appearance of the image
* Validate input files and extensions
* Handle file operations using C

## Technologies Used

* C
* File Handling
* Pointers
* Bitwise Operations
* Structures
* Dynamic Memory Allocation

## Steganography Process

### Encoding

The encoding process hides the secret data inside the image by modifying the least significant bits (LSB) of the image data.

```text
Secret Data
     ↓
Read BMP Image
     ↓
Encode Data using LSB
     ↓
Generate Stego Image
```

### Decoding

The decoding process extracts the hidden data from the stego image.

```text
Stego Image
     ↓
Read Image Data
     ↓
Extract LSB Data
     ↓
Recover Secret Data
```

## Project Structure

* `main.c` - Controls the program flow
* `encode.c` - Handles encoding operations
* `decode.c` - Handles decoding operations
* `encode.h` - Encoding declarations
* `decode.h` - Decoding declarations
* `types.h` - Project data types and structures
* `common.h` - Common macros and definitions

## How to Run

Compile the project using:

```bash
make
```

### Encoding

```bash
./a.out -e source.bmp secret.txt stego.bmp
```

### Decoding

```bash
./a.out -d stego.bmp output.txt
```

> The exact command-line arguments may vary depending on the implementation of the project.

## Concepts Learned

* Bitwise manipulation
* Least Significant Bit (LSB) steganography
* BMP image file handling
* Command-line arguments
* File pointers and binary file operations
* Structures and pointers in C

## Author

**Deepak Kumar Singh**
