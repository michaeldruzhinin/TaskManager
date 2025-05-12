// Точка входа будет здесь
#include "../core/taskmanager.h"
#include <iostream>
#include <windows.h>
int main() {
    SetConsoleOutputCP(CP_UTF8); // переключаем вывод на UTF-8
    TaskManager manager;

    manager.addTask(std::make_unique<Task>("Сдать курсовую", "18-00 в тимсе подключиться", 2));
    manager.addTask(std::make_unique<Task>("Погулять с собакой", "не забыть зайти на вб между делом", 0));
    manager.addTask(std::make_unique<Task>("Купить хлеб и чеснок", "чеснок купить обязательно молодой", 1));



    std::cout << "\nЗадачи до сортировки:\n";
    manager.listTasks();

    manager.sortByPriority();
    manager.completeTask(1); // Помечаем задачу 1 как выполненную
    manager.removeTask(2);
    std::cout << "\nЗадачи после сортировки:\n";
    manager.listTasks();

    manager.saveToFile("tasks.txt");

    std::cout << "\n--- Загружаем из файла в новый менеджер ---\n";

    TaskManager loaded;
    loaded.loadFromFile("tasks.txt");
    loaded.listTasks();

    return 0;
}
