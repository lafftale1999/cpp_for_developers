# CMAKE COMMANDS

## 1. Create build files
Create all files that that is needed for building the project (even a Makefile)
```sh
cmake -S . -B build
```

## 2. Build the executable
Command to compile.
```sh
cmake --build build
```

## 3. Run the executable
```sh
build/Debug/main.exe
```

## 4. Extra command
Build and run the executable consequently
```sh
cmake --build build --target run --config Debug
```