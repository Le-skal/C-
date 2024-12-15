#include "Utils.h"
#include <sstream>
#include <cctype>
#include <limits>

bool estNombreValide(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
bool estDateValide(const std::string& date) {
    if (date.length() != 10 || date[2] != '/' || date[5] != '/') {
        return false;
    }
    std::istringstream ss(date);
    int jour, mois, annee;
    char c1, c2;
    if (!(ss >> jour >> c1 >> mois >> c2 >> annee) || c1 != '/' || c2 != '/') {
        return false;
    }
    if (jour < 1 || jour > 31 || mois < 1 || mois > 12 || annee < 2020 || annee > 2050) {
        return false;
    }
    return true;
}

bool estHeureValide(const std::string& heure) {
    if (heure.length() != 5 || heure[2] != ':') {
        return false;
    }
    std::istringstream ss(heure);
    int heures, minutes;
    char c;
    if (!(ss >> heures >> c >> minutes) || c != ':') {
        return false;
    }
    if (heures < 0 || heures > 23 || minutes < 0 || minutes > 59) {
        return false;
    }
    return true;
}
void pauseConsole() {
    std::cout << "Appuyez sur Entrée pour continuer...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void viderBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}