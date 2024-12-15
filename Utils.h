#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>

bool estNombreValide(const std::string& str);
bool estDateValide(const std::string& date);
bool estHeureValide(const std::string& heure);
void pauseConsole();
void viderBuffer();

#endif