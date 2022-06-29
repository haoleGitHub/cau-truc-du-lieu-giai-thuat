#include<iostream>
#include<string>
#include<fstream>
struct classList {
    std::string name, surname;
    float math, physic, chemistry;
};
void readFile(std::ifstream &filein, classList &c);
void outputFile(std::fstream);
void outClass(classList);
int main() {
    classList c;
    std::ifstream file;
    file.open("class.txt", std::ios_base::in);
    readFile(file, c);
    // outClass(c);
    file.close();
    return 0;
}
void readFile(std::ifstream &filein, classList &c) {
    if (filein.fail())
        std::cout << "File doesn't exist!";
    else {
        while (!filein.eof()) {
            filein >> c.name >> c.surname >> c.math >> c.physic >> c.chemistry;
            std::cout << "Ten: " << c.name << " | Ho: " << c.surname << " | Toan: " << c.math << " | Ly: " << c.physic << " | Hoa: " << c.chemistry << "\n";
        }
    }
}
void outClass(classList c) {
    std::cout << c.name << ", " << c.surname << ", " << c.math << ", " << c.physic << ", " << c.chemistry << "\n";
}