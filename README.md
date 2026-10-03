# FileHunt

Hide and seek, but your own PC is the playground.

FileHunt is a small Windows console game written in C++. When you start it, the program hides a few secret files somewhere on your computer, and you have to track them all down and delete them. Delete the last one and you win.

I started learning C++ just recently and wanted a project that's actually fun to build, not another calculator. So this is it. The code is simple on purpose, because I'm figuring it all out as I go.

```
********************
*choose a difficulty*
********************
1 = easy, 2 = medium, 3 = hard
> 1
try harder!
try harder!
try harder!
level1 completed!
```

## The three levels

**Easy.** Three files called `easy1.txt`, `easy2.txt` and `easy3.txt`, sitting in Documents, Downloads and on the Desktop. The Windows search bar finds them in about ten seconds. Think of it as a warm-up.

**Medium.** The files are buried a few folders deep and have boring names, so you can't just search for a name, because you don't know it. You'll have to dig through folders like an actual detective.

**Hard.** Files hidden inside `AppData` with the "hidden" attribute turned on. They won't show up in Explorer until you enable hidden items, and that's only the first trick. Good luck, you'll need it.

## Running it

You need Windows and a compiler that supports C++17 (I use Visual Studio).

In Visual Studio, make a console project, set the language standard to C++17, drop in `main.cpp` and hit run.

If you prefer the command line with MinGW:

```
g++ -std=c++17 main.cpp -o filehunt.exe
filehunt.exe
```

## Will it mess up my PC?

No. A few rules I stuck to:

- Everything is created inside your own user folder. It never touches `C:\Windows` or `Program Files`.
- Every secret file has the text `SECRET_GAME_FILE` inside, so the game can always tell its files apart from yours.
- If you close the game halfway through and some files stay behind, just search your PC for files containing `SECRET_GAME_FILE` and delete them. For Hard, turn on "Show hidden items" first, since `AppData` is hidden too.

## Stuff I learned while building this

- `std::filesystem` for making folders and checking if a file still exists
- `std::ofstream` for writing files
- `getenv("USERPROFILE")` to find the current user's folder, so the game works on any PC and not just mine
- `SetFileAttributesA` from `windows.h` to make files hidden
- `Sleep` so the game doesn't check a million times per second
- A very painful lesson about `&&` vs `||` in the game loop (it took me a few tries, don't ask)

## Plans

- [x] Easy, Medium and Hard levels
- [x] Difficulty menu
- [ ] Timer, and you lose if time runs out
- [ ] Auto-delete leftover files on a loss, but only the ones with the marker inside
- [ ] More files and deeper folders on Hard
- [ ] An "I give up" option that shows you where everything was
- [ ] Clean up the code (arrays and loops instead of copy-paste)

## Status

Work in progress. If you read the code and something looks weird, it's probably because I'm still learning. Feedback is welcome though, just be nice :)
