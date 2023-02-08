//
// Created by Андрей on 08.02.2023.
//

#ifndef REMOTE_CONTROL_REMOTECTRLMAINWINDOW_H
#define REMOTE_CONTROL_REMOTECTRLMAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLCDNumber>


class RemoteCtrlWindow : public QMainWindow {
    Q_OBJECT
public:
    RemoteCtrlWindow (QWidget* parent = nullptr) : QMainWindow (parent){}
    QLCDNumber *lcdNumber;
public slots:
    void pushBtn(){
        QString ch = "0 ch";
        QString vlm = "100 ";
        bool ok;
        QPushButton *btn = dynamic_cast<QPushButton*>(sender());
        int temp = btn->text().toInt(&ok,10);
            if(ok){
                if(temp == 1) ch = "1 ch";
                else if(temp == 2) ch = "2 ch";
                else if(temp == 3) ch = "3 ch";
                else if(temp == 4) ch = "4 ch";
                else if(temp == 5) ch = "5 ch";
                else if(temp == 6) ch = "6 ch";
                else if(temp == 7) ch = "7 ch";
                else if(temp == 8) ch = "8 ch";
                else if(temp == 9) ch = "9 ch";
                else if(temp == 0) ch = "0 ch";
            } else {
                if(btn->text().toStdString() == "ChUp"){int chanel = ch.toInt(); if(chanel !=9) ch.front() = (chanel + 1);}
                else if(btn->text().toStdString() == "ChDwn"){int chanel = ch.toInt(); if(chanel !=0) ch.front() = (chanel - 1);}
                else if (btn->text().toStdString() == "VlmUp"){int volume  = vlm.toInt(); if(volume !=100) vlm = (volume + 10) + " ";}
                else if (btn->text().toStdString() == "VlmDwn"){int volume  = vlm.toInt(); if(volume !=0) vlm = (volume - 10) + " ";}
            }
             QString lcd = vlm + ch;
            lcdNumber->display(lcd);

    };
};
#endif //REMOTE_CONTROL_REMOTECTRLMAINWINDOW_H
