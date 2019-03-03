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

    // 方法1 失败
    // 目前来看这个方法不行
    // 遍历工具栏
    QObjectList toolBarList = ui->mainToolBar->children();
    QObjectList::Iterator it;
    for (it = toolBarList.begin(); it != toolBarList.end(); ++it)
    {
        QToolButton* act = qobject_cast<QToolButton *>(*it);
        if(act != NULL)
        {
            qDebug() << QString("objectName : %1").arg(act->objectName());
            qDebug() << QString("text : %1").arg(act->text());
            act->setDisabled(true);
        }
    }

    //QObjectList menuBarList = ui->menuBar->children();
    //QObjectList::Iterator it;

}

MainWindow::~MainWindow()
{
    delete ui;
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
