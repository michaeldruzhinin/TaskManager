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
    void listTasks(bool showCompleted = true) const;  //Выводит на экран список задач
    void sortByPriority();

    void saveToFile(const std::string& filename) const; //Сохраняет все задачи в файл
    void loadFromFile(const std::string& filename); //Загружает задачи из файла.
};

