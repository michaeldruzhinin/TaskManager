#pragma once
#include <vector>
#include <memory>
#include <string>
#include "task.h" 

class TaskManager {
private:
    std::vector<std::unique_ptr<Task>> tasks;

public:
    void addTask(std::unique_ptr<Task> task);
    void removeTask(std::size_t index);
    void listTasks(bool showCompleted = true) const;  
    void sortByPriority();

    void completeTask(std::size_t index);
    void saveToFile(const std::string& filename) const; 
    void loadFromFile(const std::string& filename); 

    const std::vector<std::unique_ptr<Task>>& getTasks() const;
};

