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


void TaskManager::completeTask(std::size_t index) {
    if (index < tasks.size()) {
        tasks[index]->markComplete();  
    }
}

void TaskManager::listTasks(bool showCompleted) const {
    for (std::size_t i = 0; i < tasks.size(); ++i) {
        const Task& task = *tasks[i];
        if (showCompleted || !task.isCompleted()) {
            std::cout << i << ") " << task.getTitle()
                << " [" << (task.getPriority() == 2 ? "High" :
                    task.getPriority() == 1 ? "Medium" : "Low") << "]"
                << (task.isCompleted() ? " (Completed)" : "") << "\n"
                << "    → " << task.getDescription() << "\n";
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
        task->serialize(ofs);
    }
}

void TaskManager::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename);
    while (ifs.peek() != EOF) {
        addTask(std::make_unique<Task>(Task::deserialize(ifs)));
    }
}

const std::vector<std::unique_ptr<Task>>& TaskManager::getTasks() const {
    return tasks;
}
