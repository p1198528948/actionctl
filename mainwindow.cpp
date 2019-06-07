#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QToolBar>
#include <QToolButton>

/**
 * 快捷键出现冲突时，IDE无法检测，只有在运行时才知道。
 * @brief MainWindow::MainWindow
 * @param parent
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mActionNames.append("openAction");
    mActionNames.append("newAction");
    mActionNames.append("saveAction");
    mActionNames.append("settingAction");

    //遍历
    for(int i = 0; i< mActionNames.size();++i)
    {
        QString tmp = mActionNames.at(i);
        qDebug()<<QString("actionNames[%1] = %2").arg(i).arg(tmp);

        this->setEnableFunction(tmp);
        //this->setDisabledFunction(tmp);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOpenActionEnable(bool flag)
{
    ui->openAction->setEnabled(flag);
}

void MainWindow::setNewActionEnable(bool flag)
{
    ui->newAction->setEnabled(flag);
}

void MainWindow::setSaveActionEnable(bool flag)
{
    ui->saveAction->setEnabled(flag);
}

void MainWindow::setSettingActionEnable(bool flag)
{
    ui->settingAction->setEnabled(flag);
}

void MainWindow::on_openAction_triggered()
{
    QMessageBox::information(this, "INFO", ui->openAction->text());
}

void MainWindow::on_newAction_triggered()
{
    QMessageBox::information(this, "INFO", ui->newAction->text());
}

void MainWindow::on_saveAction_triggered()
{
    QMessageBox::information(this, "INFO", ui->saveAction->text());
}

void MainWindow::on_settingAction_triggered()
{
    QMessageBox::information(this, "INFO", ui->settingAction->text());
}

void MainWindow::setEnableFunction(const QString &functionName)
{
    bool flag = true;

    // 这里注意使用objectName 而不是text
    if(functionName == "openAction")
    {
        //this->setOpenActionEnable(flag);
        // 直接用
        ui->openAction->setEnabled(flag);
    }
    else if(functionName == "newAction")
    {
        this->setNewActionEnable(flag);
    }
    else if(functionName == "saveAction")
    {
        this->setSaveActionEnable(flag);
    }
    else if(functionName == "settingAction")
    {
        this->setSettingActionEnable(flag);
    }
}

void MainWindow::setDisabledFunction(const QString &functionName)
{
    bool flag = false;
    if(functionName == "openAction")
    {
        this->setOpenActionEnable(flag);
    }
    else if(functionName == "newAction")
    {
        this->setNewActionEnable(flag);
    }
    else if(functionName == "saveAction")
    {
        this->setSaveActionEnable(flag);
    }
    else if(functionName == "settingAction")
    {
        this->setSettingActionEnable(flag);
    }
}
