# ECS Cpp Demo
> Simple ECS implementation in C++

# Dependencies
This repo uses CMake and GoogleTest (as submodule under `lib/`).

## CMake generation
The project is built using CMake.
```sh
cmake -B build -S . -G <your-favorite-generator>
```

## Build the tests
Once configured just run the build (triggers the chosen generator)
```sh
cmake --build build/
```

## Run the tests
The test program lies under `build/test/`. Simply execute this line (depending on relative path).
```sh
./build/test/light2d-ecs_test
```

## Run the demo
The build example should be found at `<build_folder>/example/ecs-demo-example`
