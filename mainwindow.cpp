#include "mainwindow.h"
#include "windows.h"
#include "qwindow.h"
#include "qwidget.h"
#include "qmessagebox.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

//    HWND hwnd = FindWindow(L"", L"");
//    QWindow* noteWindow = QWindow::fromWinId((WId)hwnd);
//    QWidget* noteWidgt = QWidget::find((WId)hwnd);
//    noteWindow->showFullScreen();
//    ui->plainTextEdit->setPlainText(noteWindow->);

//    HWND AppWnd;
//    QString ClassName("Notepad");
//    QString AppName("无标题 - 记事本");
//    LPCWSTR App = reinterpret_cast <LPCWSTR>(ClassName.data());
//    LPCWSTR AppCaption = reinterpret_cast <LPCWSTR>(AppName.data());

    HWND hWnd = ::FindWindowW(L"Notepad", NULL);

    if (hWnd != 0) {
//        char text[255];
//        ::GetWindowTextA(hWnd, text, 255);
//        QMessageBox::information(this,tr("Success"), QString::fromLocal8Bit(text, 255));
//        ::SendMessageW(hWnd, WM_SETTEXT, (WPARAM)"", (LPARAM)"ChangeTitle");

        HWND sonHWnd = FindWindowExW(hWnd, 0, L"Edit", NULL);
        if(sonHWnd != 0) {
            char text[255];
            ::SendMessageA(sonHWnd, WM_GETTEXT, sizeof(text), (LPARAM)text);
//            QMessageBox::information(this,tr("Success"), QString::fromLocal8Bit(text, 255));
            ui->plainTextEdit->setPlainText(QString::fromLocal8Bit(text, 255));
        }
    }

}
