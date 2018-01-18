#include <QCoreApplication>
#include <QStack>
#include <iostream>
#include <fstream>
#define MAX_LENGTH 2048
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path = QCoreApplication::applicationDirPath() + "/example.txt";
    QString  path_out= QCoreApplication::applicationDirPath() + "/example_out.txt";

    ifstream in( path.toLatin1().data());
    char line[MAX_LENGTH];

    QStack<string> stack;
    char seps[] = ".,;!?- ";

   if (!in.fail())
      {
        in.getline(line,MAX_LENGTH);
        in.close();
      }
    else cout<<"Error open file"<<endl;

    char * pch = strtok (line, seps );

   while (pch != NULL)
     {
        stack.push(pch);
        pch = strtok (NULL, seps );
     }
ofstream out(path_out.toLatin1().data());

   while (!stack.isEmpty())
        out << stack.pop()<<" ";

   out.close();
}

