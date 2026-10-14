# C Programming
> A repositry from CSIT students made with purpose of learning C programming from the syllabus of the respective course.  
> It also contains UI from C made purely using a tiny library named "micro.ui"


# MicroUI Demo

A minimal [microui](https://github.com/rxi/microui) setup using SDL2 + OpenGL (fixed-function) for rendering.

## File Structure

|    File      | Source           | Purpose                                |
|--------------|------------------|                                        |
| `main.c`     | demo/ (modified) | Main loop, input, UI definition        |
| `renderer.c` | demo/            | SDL2 + OpenGL renderer                 |
| `renderer.h` | demo/            | Renderer API                           |
| `atlas.inl`  | demo/            | Bitmap font texture for text rendering |
| `microui.c`  | src/             | MicroUI implementation                 |
| `microui.h`  | src/             | MicroUI header                         |


## Prerequisites

- **SDL2** — download the [Windows dev package](https://www.libsdl.org/download-2.0.php)
- **Visual Studio** with C/C++ toolset

## Setup (Visual Studio)

1. Create a new **C++ Empty Project** (or C Console App).
2. Add all `.c` files to Source Files.
3. **Project Properties → C/C++ → General → Additional Include Directories:**   
4. **Project Properties → Linker → Input → Additional Dependencies:**   
5. **Project Properties → Linker → General → Additional Library Directories:**   
6. Copy `SDL2.dll` next to your `.exe` (in `Debug/` or `Release/`).
7. **Project Properties → C/C++ → Language → C Language Standard → ISO C11**


## Build & Run

- **F5** — Debug
- **Ctrl+F5** — Run Without Debugging
A separate SDL window will appear with the UI.


## Architecture
   
- `microui` never draws pixels — it only emits commands.
- `renderer.c` translates those commands into OpenGL calls.
- `atlas.inl` provides the font texture for text rendering.

## Key API Calls

| Function                                       | Purpose                         |
|------------------------------------------------|---------------------------------|
| `mu_init(ctx)`                                 | Initialize context              |
| `mu_begin(ctx)` / `mu_end(ctx)`                | Frame begin/end                 |
| `mu_begin_window(...)` / `mu_end_window(...)`  | Window block                    |
| `mu_layout_row(...)`                           | Grid layout                     |
| `mu_button(...)`                               | Button (returns true on click)  |
| `mu_label(...)`                                | Text label                      |
| `mu_input_mousemove(...)`                      | Feed mouse position             |
| `mu_input_mousepress(...)`                     | Feed mouse button state         |
| `mu_next_command(ctx, &cmd)`                   | Iterate draw commands           |
|------------------------------------------------|---------------------------------|


## Notes

- Uses **OpenGL 1.x** (immediate mode) — no shaders required.
- For loops generating controls, use `mu_push_id()` / `mu_pop_id()` for unique IDs.
- All UI is re-declared every frame (immediate mode pattern).   

## Run the MicroUI demo

The SDL2/OpenGL demo is in `UI/`. On Linux, install GCC, GDB, `pkg-config`,
SDL2 development files, and OpenGL development files. In VS Code, open **Run
and Debug**, select **Launch MicroUI UI (SDL2)**, and press **F5**. VS Code
builds the demo automatically before launching it.

The demo opens a native window and needs a graphical display with OpenGL
support. A headless remote workspace cannot display the window without a
configured graphical display.
 