#include <QtCore/QCoreApplication>
#include <queue.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        int option;
        DataType input;
        cListQueue objList;
        cVectQueue objVect;
        cQueue *Qtype[2] = {&objList,&objVect};
        cQueue* pQueue;

        while(1)
        {
            cout<<"Enter your selection: 1 for List, 2 for Vector \n";
            cin>>option;

            if(option == 1 || option == 2)
            {
                pQueue = Qtype[option-1];
                while(1)
                {
                    cout<<"Enter your selection: 1 for Add, 2 for Remove, 3 for Display, 4 for Exit\n";
                    cin>>option;

                    switch(option)
                    {
                    case 1:
                        cout<<"Enter your Data:\n";
                        cin>>input;
                        pQueue->Add(input);
                        break;
                    case 2:
                        pQueue->Remove();
                        cout<<"Fist data deleted successfully\n";
                        break;
                    case 3:
                        pQueue->Display();
                        break;
                    default:
                        option = 0;
                        break;
                    }
                    if(option == 0)
                        break;
                }
            }
        }
    }
    return a.exec();
}
