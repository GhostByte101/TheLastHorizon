# TheLastHorizon
The repository contains all the files needed to run the game.


**A simple C++ console RPG** where you choose one of three heroes (Wizard, Knight, or Elf) and follow their unique storylines complete with mini-games and boss battles.

---

## Project Structure

```
test5/                # Project root
├── include/           # Header files
│   ├── Common.h       # Shared utilities (waitForEnter, MG1/2/3 declarations)
│   ├── WizardModule.h # Wizard classes & wizardMain()
│   ├── KnightModule.h # Knight classes & knightMain()
│   └── ElfModule.h    # Elf classes & elfMain()
├── src/               # Implementation files
│   ├── Common.cpp     # Definitions for shared utilities
│   ├── WizardModule.cpp
│   ├── KnightModule.cpp
│   ├── ElfModule.cpp
│   └── main.cpp       # Entry-point with menu selection
└── README.md          # This file
```

---

## Prerequisites

- **GCC** (MinGW) or any C++17–capable compiler
- **Windows PowerShell** (or any terminal)

---

## Build Instructions

Open a terminal in the project root (`2024321_2024663_2024119/`) and run:

```powershell
# Single-line (no backslashes)
g++ -std=c++17 main.cpp Common.cpp WizardModule.cpp KnightModule.cpp ElfModule.cpp -Iinclude -o TheLastHorizon.exe
```

**Alternatively**, to break across lines in PowerShell, use backticks:

```powershell
g++ -std=c++17 `
    main.cpp `
    Common.cpp `
    WizardModule.cpp `
    KnightModule.cpp `
    ElfModule.cpp `
    -Iinclude `
    -o TheLastHorizon.exe
```

No trailing backslashes—PowerShell uses `` ` `` for line continuation. Ensure `-Iinclude` has no space.

---

## Running the Game

Once compiled, launch:

```powershell
.\TheLastHorizon.exe
```

You’ll see a menu:

```
Welcome to Avalon!
Choose your hero:
  1) Wizard
  2) Knight
  3) Elf
Enter 1, 2 or 3:
```

Enter your choice and follow the on-screen prompts to play.

---

## Project Details

- **Modular Design:** Each hero’s story is encapsulated in its own header+cpp pair, exporting a `wizardMain()`, `knightMain()`, or `elfMain()` entry-point.
- **Common Utilities:** `Common.h/.cpp` provide shared functions: a pause helper (`waitForEnter`) and three mini-games (`MG1`, `MG2`, `MG3`).
- **Separate Compilation:** Headers declare interfaces; each `.cpp` compiles independently and links into a single executable.

---

## Notes

- You do **not** need to ship `.cpp` or `.h` files—only `TheLastHorizon.exe` (and any required DLLs) for distribution.
- If you modify any header, rebuild to propagate changes.

Enjoy your adventure in Avalon!

