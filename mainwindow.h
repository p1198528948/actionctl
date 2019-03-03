#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QMap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    QStringList mActionNames;

public:
    void setOpenActionEnable(bool flag);
    void setNewActionEnable(bool flag);
    void setSaveActionEnable(bool flag);
    void setSettingActionEnable(bool flag);
    void setEnableFunction(const QString &functionName);
    void setDisabledFunction(const QString &functionName);

private slots:
    void on_openAction_triggered();

    void on_newAction_triggered();

    void on_saveAction_triggered();

    void on_settingAction_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
