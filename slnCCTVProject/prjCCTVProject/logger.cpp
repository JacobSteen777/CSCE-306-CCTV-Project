#pragma once
#include "logger.h"
#include <fstream>
#include <iostream>

void clearLog()
{
    std::ofstream fclear;
    fclear.open("acc1log.txt", std::ofstream::out | std::ofstream::trunc);
    fclear.close();
    fclear.open("acc2log.txt", std::ofstream::out | std::ofstream::trunc);
    fclear.close();
}

void readLog(std::string logfile)
{
    std::ifstream fin;
    std::string line;
    fin.open(logfile);
    while (fin) {
        getline(fin, line);
        std::cout << line << std::endl;
    }
    fin.close();
}

void addToLog(std::string action, std::string logfile)
{
    std::ofstream fout;
    std::string line = "";
    fout.open(logfile, std::ios::app);
    line = "Performed " + action + " action.";
    fout << line << std::endl;
}

void addToLog(std::string user, std::string action, std::string logfile)
{
    std::ofstream fout;
    std::string line = "";
    fout.open(logfile, std::ios::app);
    line = user + " performed " + action + " action.";
    fout << line << std::endl;
}

void addToLog(std::string user, std::string action, std::string value, std::string logfile)
{
    std::ofstream fout;
    std::string line = "";
    fout.open(logfile, std::ios::app);
    line = user + " performed " + action + " action while using value " + value + ".";
    fout << line << std::endl;
}