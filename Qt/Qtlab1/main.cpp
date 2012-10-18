#include <QtCore/QCoreApplication>
#include <QtGui/QApplication>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QDebug>
#include <QString>
#include <iostream>


using namespace std;
int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
    QFile file("file.txt");

    QString text;
    QTextStream in(&file);
    if(!file.open(QIODevice::ReadOnly))
    {
        cout<<"";
    }
    else
    {
        int i = 0;
        QString textBuf;
        while(!in.atEnd())
        {
            textBuf = in.readLine();
            if(i==0)

            {
                text = "<html><body><head><h1>"+textBuf+"</h1></head>";
                i++;

            }
            else
            {
                text=text+textBuf+"</br>";
            }
        }
        text = text+"</body></html>";
    }
    file.close();

    QFile new_file("new_file.htm");
    QTextStream out(&new_file);
    if (new_file.open(QIODevice::WriteOnly))
    {
        out << text;
    }
    //new_file.flush();
    new_file.close();


       return a.exec();

}
