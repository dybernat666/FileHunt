#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <filesystem>
#include <windows.h>
namespace fs = std::filesystem;
void easy () {
    const char* home = getenv("USERPROFILE"); // получаем путь
    std::string easy1 =std::string(home) + "\\Documents\\easy1.txt"; // создаем переменные с путями где будут  файлы
    std::string easy2 =std::string(home) + "\\Downloads\\easy2.txt";// (home) это то что мы получили в начале
    std::string easy3 =std::string(home) + "\\Desktop\\easy3.txt"; // home содержит в себе путь в диске до юзернейм
    // и тем самым home содержит в себе чото типо C://users/vanya и дальше уже можно чере плюс клеить пути
    if (!fs::exists(std::string(home) + "\\Desktop")) {
        easy3 = std::string(home) + "\\OneDrive\\Desktop\\easy3.txt"; // у некоторых рабочий стол в вандрайве
    }

    std::ofstream file(easy1);
    std::ofstream file1(easy2);
    std::ofstream file2(easy3);
    file << "secret file";
    file1 << "secret file";
    file2 << "secret";

    file.close();
    file1.close();
    file2.close();
    while (true) {
        if (fs::exists(easy1) || fs::exists(easy2) || fs::exists(easy3)) {
            std::cout << "try harder!\n";
            Sleep(10000);
        } else {
            std::cout << "level1 completed!";
            break;
        }
    }
}
void hard () {

    const char* home = getenv("USERPROFILE");
    std::string folder1 = std::string (home) + "\\AppData\\Local\\CrashDumps\\Archive\\2019\\";
    std::string folder2 = std::string (home) + "\\AppData\\Local\\Packages\\Cache\\Temp\\Index\\";
    std::string folder3 = std::string (home) + "\\AppData\\Roaming\\Sync\\Logs\\Old\\Session\\";
    fs::create_directories(folder1);
    fs::create_directories(folder2);
    fs::create_directories(folder3);
    std::string file1 = (folder1) + "samara.txt";
    std::string file2 = (folder2) + "index10281.txt";
    std::string file3 = (folder3) + "tsession.txt";
    std::ofstream lol1 (file1);
    std::ofstream lol2 (file2);
    std::ofstream lol3 (file3);
    lol1 << "SECRET_GAME_FILE!";
    lol2 << "SECRET_GAME_FILE!";
    lol3 << "SECRET_GAME_FILE!";
    lol1.close();
    lol2.close();
    lol3.close();
    SetFileAttributesA(file1.c_str(), FILE_ATTRIBUTE_HIDDEN);
    SetFileAttributesA(file2.c_str(), FILE_ATTRIBUTE_HIDDEN);
    SetFileAttributesA(file3.c_str(), FILE_ATTRIBUTE_HIDDEN);
    while (true) {
        if (fs::exists(file1) || fs::exists(file2) || fs::exists(file3)) {
            std::cout << "try harder bro\n";
            Sleep(5000);
        } else {
            std::cout << "HARD LEVEL COMPLETED!!!!good job!";
            break;
        }
    }
}
void medium () {
    const char* home = getenv("USERPROFILE");
    std::string folder4 = std::string(home) + "\\Desktop\\football\\chelsea\\";
    std::string folder2 = std::string(home) + "\\Downloads\\famili_pics2000";
    std::string lop = std::string(folder2) + "\\1";
    fs::create_directories(folder2);
    fs::create_directory(lop);
    fs::create_directories(folder4);
    std::string file1 = std::string(lop) + "\\secret.txt";
    std::ofstream lol1(file1);
    std::string file2 = std::string(folder4) + "secret.txt";
    std::ofstream lol2(file2);
    std::string folder8 = std::string(home) + "\\Videos\\meme\\lol\\";
    std::string folder6 = std::string(home) + "\\Videos\\meme\\trollface\\";
    std::string file3 = std::string(folder8) + "lol.txt";
    fs::create_directories(folder6);
    fs::create_directories(folder8);
    std::ofstream lol3(file3);
    lol1 << "SECRET_GAME_FILE";
    lol2 << "SECRET_GAME_FILE";
    lol3 << "SECRET_GAME_FILE";
    lol1.close();
    lol2.close();
    lol3.close();
    while (true) {
        if (fs::exists(file1) || fs::exists(file2) || fs::exists(file3)) {
            std::cout<<"try harder\n";
            Sleep(1000);
        } else{
            std::cout << "medium level completed!";
            break;
        }
    }
}
int main () {
    int choose;
    std::cout << "********************\n";
    std::cout << "*choose a diffucult*\n";
    std::cout << "********************\n";
    std::cout << "1 = easy, 2 = medium, 3 = hard";
    std::cin >> choose;
    if (choose == 1) {
        easy ();
    } else if (choose == 2) {
        medium();
    } else if (choose == 3) {
        hard ();
    } else {
        std::cout << "?";
}
