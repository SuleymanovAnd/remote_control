//
// Created by Андрей on 08.02.2023.
//

#ifndef REMOTE_CONTROL_REMOTECTRLMAINWINDOW_H
#define REMOTE_CONTROL_REMOTECTRLMAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLCDNumber>
#include <string>

class RemoteCtrlWindow : public QMainWindow {
    Q_OBJECT
    QString ch = "1 ch";
    QString vlm = "100 ";
public:
    RemoteCtrlWindow (QWidget* parent = nullptr) : QMainWindow (parent){}
    QLCDNumber *lcdNumber;
public slots:
    void pushBtn(){
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
                if(btn->text().toStdString() == "︿"){
                    std::string chTmp = ch.toStdString();
                    int chanel = stoi(chTmp);
                    if(chanel !=9) {chanel += 1;
                        std::string temp;
                        temp += std::to_string(chanel) + " ch";
                        ch.clear();
                        ch.append(temp.c_str());}

                }
                else if(btn->text().toStdString() == "﹀"){
                    std::string chTmp = ch.toStdString();
                    int chanel = stoi(chTmp);
                    if(chanel !=0) {chanel -= 1;
                        std::string temp;
                        temp += std::to_string(chanel) + " ch";
                        ch.clear();
                        ch.append(temp.c_str());}

                }
                else if (btn->text().toStdString() == " ︿ "){int volume  = vlm.toInt(); if(volume !=100) vlm = (volume + 10) + " ";}
                else if (btn->text().toStdString() == " ﹀ "){int volume  = vlm.toInt(); if(volume !=0) vlm = (volume - 10) + " ";}
            }
             QString lcd = vlm + ch;
            lcdNumber->display(lcd);

    };
};
#endif //REMOTE_CONTROL_REMOTECTRLMAINWINDOW_H
