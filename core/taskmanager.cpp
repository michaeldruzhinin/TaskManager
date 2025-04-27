#include "taskmanager.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void TaskManager::addTask(std::unique_ptr<Task> task) {
    tasks.push_back(std::move(task));
}

void TaskManager::removeTask(std::size_t index) {
    if (index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

void TaskManager::listTasks(bool showCompleted) const {
    for (std::size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = *tasks[i];
        if (showCompleted || !task.isCompleted()) {
            std::cout << i << ") " << task.getTitle()
                << " [" << (task.getPriority() == 2 ? "High" : task.getPriority() == 1 ? "Medium" : "Low") << "]"
                << (task.isCompleted() ? " (Completed)" : "") << "\n";
        }
    }
}

void TaskManager::sortByPriority() {
    std::sort(tasks.begin(), tasks.end(), [](const std::unique_ptr<Task>& a, const std::unique_ptr<Task>& b) {
        return a->getPriority() > b->getPriority(); // от высокого к низкому
        });
}

void TaskManager::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename);
    for (const auto& task : tasks) {
        ofs << task->serialize() << "\n";
    }
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename);
    std::string line;
    while (std::getline(ifs, line)) {
        addTask(std::make_unique<Task>(Task::deserialize(line)));
    }
}

