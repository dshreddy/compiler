# SIL Compiler

This repository contains a compiler written in C++ for a C-like Simple Integer Language (SIL) using Flex and Bison. This compiler supports various control flow structures, including conditional statements, loops, and their nested forms.

## Features

- **Lexer and Parser:** Utilizes Flex for lexical analysis and Bison for syntax parsing.
- **Control Flow Support:** Handles if-else statements, for-loops, and while-loops.
- **Semantic Analysis:** Ensures the program adheres to the language's semantics.
- **Intermediate Code Generation:** Produces three-address assembly code.

## Sample Program

The following program is a sample input to the compiler:

```c
decl
  integer array[5];
  integer key, found;
  integer index;
enddecl

begin
  read(array[0], array[1], array[2]);
  read(array[3], array[4]);
  read(key);

  found = 0;
  for (index = 0; index < 4; index++) {
    if (array[index] == key) {
      found = 1;
    }
  }
  
  if (found == 1) {
    write(1);
  } else {
    write(0);
  }
end
```

## Project Structure

- **Lexer:** The lexer matches the regular expressions specified in `./compiler/src/compiler.l` and generates tokens.
- **Parser:** The parser receives tokens from the lexer and builds the parse tree according to the grammar rules defined in `./compiler/src/compiler.y`.
- **Semantic Analysis:** Ensures the correctness of the program semantics.
- **Code Generation:** Produces three-address code as the intermediate representation.

## Usage

1. **Clone the Repository:**
    ```sh
    git clone https://github.com/dshreddy/compiler/
    cd compiler
    ```

2. **Build the Compiler:**
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the Compiler:**
    ```sh
    ./sil_compiler path/to/your_program.sil
    ```

## Future Developments

1. **Optimizing Intermediate Code:** Implement optimizations for the generated intermediate code.
2. **Backend Development:** Generate target-specific assembly code.
3. **Error Handling:** Improve error reporting and handling mechanisms.
4. **Extended Language Features:** Add support for more complex data structures and operations.

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your changes. For major changes, please open an issue to discuss what you would like to contribute.

Feel free to customize this README further based on the specific details and requirements of your project.
