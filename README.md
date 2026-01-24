# Pong-SFML

A classic Pong game built from the ground up in C++ using the SFML library. This project is a deep dive into object-oriented design, creating a foundational game engine architecture with a focus on clean, scalable, and robust code.

## Gameplay Demo
<p align="center">
   <img src="Pong-Media/PingPong.gif" alt="Pong-SFML Gameplay Demo" width="800">
 </p>

## Screenshots
<p align="center">
   <img src="Pong-Media/Pong.png" alt="Game Screenshot" width="400">
 </p>

## Key Features

*   **Object-Oriented Design:** Fully object-oriented architecture using modern C++ principles.
*   **Frame-Rate Independent:** Smooth, consistent gameplay on any hardware thanks to a delta time-based game loop.
*   **Component-Based Architecture:** Clear separation of concerns with dedicated managers for Gameplay, Window, Events, UI, and Sound.
*   **Dynamic Collision Detection:** Real-time collision detection between the ball, paddles, and boundaries.
*   **Sound System:** Integrated sound effects for collisions and background music.
*   **UI System:** On-screen score tracking that updates in real-time.
*   **Local Multiplayer:** Two players can compete on a single keyboard.

## Controls

The game is designed for two players on a single keyboard.

*   **Player 1 (Left Paddle):**
    *   `W` - Move Up
    *   `S` - Move Down

*   **Player 2 (Right Paddle):**
    *   `Up Arrow` - Move Up
    *   `Down Arrow` - Move Down

## Architectural Overview

This project was built not just as a game, but as a mini game engine, emphasizing professional software engineering practices.

### Central Orchestrator (`GameLoop`)

The entire application is driven by a central `GameLoop` class. This class is the single orchestrator responsible for creating and managing the lifecycle of all major engine systems. It ensures a consistent sequence of operations every frame: polling events, updating game state, and rendering the scene. This centralized approach keeps the main application logic clean and easy to follow.

### Single Responsibility Principle (SRP)

The architecture strictly adheres to SRP. Each class has one, and only one, reason to change, which makes the system highly modular and maintainable:

*   `GameWindowManager`: Manages the SFML window's creation, state, and display.
*   `EventManager`: Handles all user input from the keyboard and mouse.
*   `GameplayManager`: Manages all game objects (Ball, Paddles) and the rules of the game.
*   `TimeService`: Provides frame-rate independent time calculations (`deltaTime`).
*   `UIService`: Manages and renders all user interface elements, like the score.
*   `SoundManager`: Handles the loading and playback of all audio.

### Composition and Ownership

The engine is built on a strong **Composition** model. The `GameLoop` *owns* all the main manager instances, and the `GameplayManager` in turn *owns* all the game objects (Ball, Paddles, etc.). This creates a clear ownership hierarchy.

Memory is managed responsibly using heap-based allocation (`new`) with corresponding cleanup in class destructors (`delete`). This follows the **RAII (Resource Acquisition Is Initialization)** principle, ensuring that resources are automatically released when their controlling object goes out of scope, preventing memory leaks.

### Abstraction and Encapsulation

Each manager provides a clean public interface while hiding its internal implementation details. For example, the `GameLoop` simply calls `gameplay_manager->update()`, abstracting away the complexity of how the ball moves, how collisions are checked, or how the score is updated. This encapsulation makes the system easier to reason about and reduces the risk of unintended side effects.

## UML Class Diagram

The following diagram illustrates the high-level architecture, showing the composition and dependency relationships between the major components of the engine.

!UML Diagram
![UML Diagram](Pong-Media/PongUML.png)

## Folder Structure

The project maintains a clean and scalable folder structure, separating interface (`Header/`) from implementation (`Source/`). This is a standard C++ practice that improves organization and can reduce compile times.

```
Pong-SFML/
├── Header/
│   ├── Core/
│   ├── Event/
│   ├── GamePlay/
│   │   ├── Ball/
│   │   ├── Paddle/
│   │   └── Boundary/
│   ├── UI/
│   ├── Utility/
│   └── Sounds/
└── Source/
    ├── Core/
    ├── Event/
    ├── GamePlay/
    │   ├── Ball/
    │   ├── Paddle/
    │   └── Boundary/
    ├── UI/
    ├── Utility/
    └── Sounds/
```

## How to Build and Run

*(This is a placeholder section. You can add instructions here on how to compile your project.)*

1.  Clone the repository.
2.  Ensure you have SFML configured in your build environment.
3.  Compile the source files using your C++ compiler (e.g., g++, MSVC).
4.  Run the generated executable.

## Dependencies

*   **C++17** (or later)
*   **SFML 2.5.1** (or later)