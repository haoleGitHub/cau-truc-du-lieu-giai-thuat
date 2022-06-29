#include<iostream>
#include<fstream>
#include<string>
#include<vector>
struct city {
    std::string name;
    int area;
    int poppulation;
};
void readFile(std::ifstream &filein, city &c) {
    std::getline(filein, c.name, ' ');
    filein >> c.area;
    filein >> c.poppulation;
}
void inputListCity(std::ifstream &filein, std::vector<city> &listCity) {
    city c;
    while (filein.eof() == false) {
        readFile(filein, c);
        listCity.push_back(c);
    }
}
void outCity(city c) {
    std::cout << c.name << ", " << c.area << ", " << c.poppulation;
}
void ouputListcity(std::vector<city> listCity) {
    for (int i = 0; i < listCity.size(); i++)
        outCity(listCity[i]);
}
int main() {
    std::vector<city> listCity;
    std::ifstream filein;
    std::ofstream fileout;
    filein.open("city.txt", std::ios_base::in);
    fileout.open("list_city.txt", std::ios::out);
    inputListCity(filein, listCity);
    std::cout << "=== CITY LIST ===\n";
    ouputListcity(listCity);
    filein.close();
    fileout.close();
    return 0;
}