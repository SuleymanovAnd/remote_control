#include <QApplication>
#include <QPushButton>
#include "RemoteCtrlMainWindow.h"
#include "./ui_remoteCtrl.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RemoteCtrlWindow window(nullptr);
    Ui_MainWindow remoteCtrl;
    remoteCtrl.setupUi(&window);
    window.lcdNumber = remoteCtrl.lcdNumber;
    window.show();
    return QApplication::exec();
}
