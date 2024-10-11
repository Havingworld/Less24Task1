#include <iostream>
#include <map>
#include <ctime>

void endTask(std::string& currentTask, std::time_t& currentStart, std::map<std::string, std::time_t>& tasks) {
    if (currentTask.empty()) return;

    std::time_t duration = std::time(nullptr) - currentStart;
    tasks[currentTask] += duration;
    std::cout << "Task \"" << currentTask << "\" ended. Duration: " << duration / 3600 << ":" << (duration % 3600) / 60 << ":" << (duration % 3600) % 60 << " hours." << std::endl;
    currentTask = { "" };
    currentStart = { 0 };
}

void beginTask(std::string& currentTask, std::time_t& currentStart, std::map<std::string, std::time_t>& tasks) {
    if (!currentTask.empty()) endTask(currentTask, currentStart, tasks);

    std::cout << "Enter task name: ";
    std::cin >> currentTask;
    currentStart = std::time(nullptr);
    std::cout << "Task \"" << currentTask << "\" started." << std::endl;
}

void showStatus(std::string& currentTask, std::map<std::string, std::time_t>& tasks) {
    std::cout << "Current task: ";
    if (currentTask.empty()) {
        std::cout << "None" << std::endl;
    }
    else {
        std::cout << "\"" << currentTask << "\"" << std::endl;
    }
    std::cout << "Completed tasks:" << std::endl;;
    //auto it = tasks.begin();
    for (auto& it : tasks) {
        std::cout << "\"" << it.first << "\": " << it.second / 3600 << ":" << (it.second % 3600) / 60 << ":" << (it.second % 3600) % 60 << " hours" << std::endl;
    }
}

int main() {
    std::map<std::string, std::time_t> tasks;
    std::string currentTask{ "" };
    std::time_t currentStart{ 0 };
    std::string command{ "" };

    std::cout << "begin - start new task; " << std::endl;
    std::cout << "end - end task; " << std::endl;
    std::cout << "status - displays information about all completed tasks; " << std::endl;
    std::cout << "exit - close the programm; " << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;

    while (command != "exit") {
        std::cout << "Enter command (begin, end, status, exit): ";
        std::cin >> command;
        if (command == "begin") beginTask(currentTask, currentStart, tasks);
        else if (command == "end") endTask(currentTask, currentStart, tasks);
        else if (command == "status") showStatus(currentTask, tasks);
        else if (command == "exit") break;
        else std::cout << "Invalid command." << std::endl;
    }
    return 0;
}
