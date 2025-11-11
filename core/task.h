#pragma once
// Заголовочный файл
#include <string>
#include <fstream>

class Task {
private:
    std::string title;
    std::string description;
    int priority;
    bool completed;

public:
    // Конструктор
    Task(const std::string& title, const std::string& description, int priority);

    // Move-конструктор
    Task(Task&& other) noexcept;

    // Move-оператор
    Task& operator=(Task&& other) noexcept;

    // Геттеры
    const std::string& getTitle() const;
    const std::string& getDescription() const;
    int getPriority() const;
    bool isCompleted() const;

    // Отметить как выполненную
    void markComplete();

    // Сериализация
    void serialize(std::ostream& out) const;

    // Десериализация
    static Task deserialize(std::istream& in);
};