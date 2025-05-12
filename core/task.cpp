// Реализация будет здесь
// Конструктор
#include "task.h"
Task::Task(const std::string& title, const std::string& description, int priority)
    : title(title), description(description), priority(priority), completed(false) {}

// Move-конструктор
Task::Task(Task&& other) noexcept
    : title(std::move(other.title)),
      description(std::move(other.description)),
      priority(other.priority),
      completed(other.completed) {}

// Move-оператор
Task& Task::operator=(Task&& other) noexcept {
    if (this != &other) {
        title = std::move(other.title);
        description = std::move(other.description);
        priority = other.priority;
        completed = other.completed;
    }
    return *this;
}

// Геттеры
const std::string& Task::getTitle() const { return title; }
const std::string& Task::getDescription() const { return description; }
int Task::getPriority() const { return priority; }
bool Task::isCompleted() const { return completed; }

// Отметить задачу как выполненную
void Task::markComplete() {
    completed = true;
}

// Сериализация
void Task::serialize(std::ostream& out) const {
    out << title << '\n'
        << description << '\n'
        << priority << '\n'
        << completed << '\n';
}

//// Десериализация(устаревшая)
//void Task::deserialize(std::istream& in) {
//    std::getline(in, title);
//    std::getline(in, description);
//    in >> priority;
//    in >> completed;
//    in.ignore(); // убрать перевод строки после чтения completed
//}

// Десериализация
Task Task::deserialize(std::istream& in) {
    std::string title, description;
    int priority;
    bool completed;

    std::getline(in, title);
    std::getline(in, description);
    in >> priority;
    in >> completed;
    in.ignore(); // убрать \n после completed

    Task task(title, description, priority);
    if (completed) task.markComplete();
    return task;
}


