
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidgetItem>
#include <QCloseEvent>
#include "../core/taskmanager.h"
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    manager.loadFromFile("tasks.txt");
    isSortedByPriority = false;
    for (const auto& task : manager.getTasks()) {
        QString text = QString::fromStdString(task->getTitle());
        QString priorityStr = task->getPriority() == 2 ? "High"
                              : task->getPriority() == 1 ? "Medium"
                                                         : "Low";

        if (task->isCompleted())
            text += " [" + priorityStr + "] (Completed)";
        else
            text += " [" + priorityStr + "]";

        ui->taskList->addItem(text);
    }
}

MainWindow::~MainWindow() {
    delete ui;

}

void MainWindow::on_addButton_clicked() {
    QString title = ui->taskInput->text();
    int priority = ui->priorityBox->currentIndex();

    if (title.isEmpty()) return;

    QString text = title + " [" + ui->priorityBox->currentText() + "]";
    ui->taskList->addItem(text);
    ui->taskInput->clear();


    manager.addTask(std::make_unique<Task>(
        title.toStdString(), "", priority
        ));
}


void MainWindow::on_completeButton_clicked() {
    int index = ui->taskList->currentRow();
    if (index >= 0 && !ui->taskList->currentItem()->text().contains("(Completed)")) {
        manager.completeTask(index);
        ui->taskList->currentItem()->setText(ui->taskList->currentItem()->text() + " (Completed)");
    }
}

void MainWindow::on_deleteButton_clicked() {
    int index = ui->taskList->currentRow();
    if (index >= 0) {
        manager.removeTask(index);
        delete ui->taskList->takeItem(index);
    }
}

void MainWindow::closeEvent(QCloseEvent* event) {
    manager.saveToFile("tasks.txt");
    QMainWindow::closeEvent(event);
}


void MainWindow::on_sortButton_clicked() {
    manager.sortByPriority();             // сортируем задачи в памяти
    manager.saveToFile("tasks.txt");      // пересохраняем файл
    ui->taskList->clear();                // очищаем визуальный список

    for (const auto& task : manager.getTasks()) {
        QString text = QString::fromStdString(task->getTitle());
        QString priorityStr = task->getPriority() == 2 ? "High"
                              : task->getPriority() == 1 ? "Medium"
                                                         : "Low";

        if (task->isCompleted())
            text += " [" + priorityStr + "] (Completed)";
        else
            text += " [" + priorityStr + "]";

        ui->taskList->addItem(text);
    }
}


