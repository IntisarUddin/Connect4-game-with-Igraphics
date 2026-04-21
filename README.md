# 🎮 Connect 4 Game (C++ OpenGL)

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Windows-green)
![Graphics](https://img.shields.io/badge/OpenGL-GLUT-orange)
![Status](https://img.shields.io/badge/Project-Complete-success)

A fully interactive **Connect 4 game** built using **C++**, **OpenGL (GLUT)**, and a custom graphics engine (`iGraphics`).

---

## 📺 Demo

▶️ https://youtu.be/96X_ane3bIw

---

## ✨ Features

- 🎯 Classic Connect 4 gameplay (6×7 grid)
- 🎨 GUI using OpenGL + custom graphics library
- 🔊 Sound effects & background music
- 🧠 Smart win detection (horizontal, vertical, diagonal)
- 🏆 Leaderboard system (file-based)
- 👥 Player name input system
- ⏸ Pause / Resume controls
- 🖼 Bitmap-based UI rendering
- 🎵 Music toggle (mute/unmute)

---

## 🗂 Project Structure

```
.
├── .vscode/
├── button/
├── image/
├── music/
├── LICENSE
├── Scores.txt
├── leaderboard.txt
├── glut32.dll
├── iGraphics.h
├── iMain.cpp
├── iMain.exe
├── stb_image.h
```

---

## ⚙️ Requirements

- Windows OS
- OpenGL
- GLUT (FreeGLUT or legacy)
- WinMM library

---

## 🚀 Getting Started

### 🔹 Run Prebuilt Version

```bash
./iMain.exe
```

---

### 🔹 Build from Source

#### Compile

```bash
g++ iMain.cpp -o game -lglut32 -lopengl32 -lglu32 -lwinmm
```

#### Run

```bash
./game
```

---

## 🎮 Gameplay

- Enter player names
- Take turns dropping discs
- First to connect **4 discs** wins:
  - Horizontal
  - Vertical
  - Diagonal

---

## 🧠 Technical Overview

### Game Board

```cpp
object ball[6][7];
```

### Win Detection

```cpp
int check_win(int row, int col, int player, object board[6][7]);
```

### Graphics Engine

- `iGraphics.h` wraps OpenGL
- Provides rendering, input, animation

### Image Handling

- Uses `stb_image.h` for loading textures

### Leaderboard

- Stored in:
  - `leaderboard.txt`
  - `Scores.txt`

---

## 🔊 Sound

Uses Windows multimedia API:

```cpp
#pragma comment(lib, "Winmm.lib")
```

---

## ⚠️ Notes

- Windows-only project
- Requires `glut32.dll`
- Keep asset folders intact

---

## 📌 Future Improvements

- AI opponent
- Cross-platform support
- Modern OpenGL (GLFW)
- Multiplayer mode

---

## 👨‍💻 Author

- Graphics Library: S. M. Shahriar Nirjon  
- Modified by: Mohammad Saifur Rahman  
- Project by: You  

---

## 📜 License

See `LICENSE` file

---

## ⭐ Support

If you like this project, give it a ⭐ on GitHub!
