# Raylib C++ template

## Features

- raylib integration
- Entity–Component–System (ECS)
- CMake-based build system

---

## Project Structure

```
ingenium/
├── engine/
│   ├── include/
│   │   ├── ecs/
│   │   ├── components/
│   │   ├── systems/
│   │   └── Engine.h
│   ├── src/
│   ├── vendor/
│   │   └── raylib/
│   └── CMakeLists.txt
│
├── game/
│   ├── assets/
│   ├── main.cpp
│   └── CMakeLists.txt
│
├── .clang-format
├── .gitignore
├── .gitmodules
└── CMakeLists.txt
```

---

## Building

### Clone

```bash
git clone --recursive <repo-url>
cd ingenium
git submodule update --init
```

### Build

```bash
cmake -B build
cmake --build build
```

---

## Running

```bash
./build/game/game
```

---

## Customization

- Add components in `engine/include/components`
- Add systems in `engine/include/systems`
- Game-specific logic belongs in `game/`
