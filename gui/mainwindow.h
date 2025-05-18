#pragma once
#include <QMainWindow>
#include "../core/taskmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();


protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_addButton_clicked();
    void on_completeButton_clicked();
    void on_deleteButton_clicked();
    void on_sortButton_clicked();

private:
    TaskManager manager;
    Ui::MainWindow* ui;
    bool isSortedByPriority = false;
};
