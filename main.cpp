//List and simple list customization


#include <iostream>
#include <cstring>
#include <conio.h>
#include <fstream>


using namespace std;

//****************Custom Node Description****//

struct sList
{
    struct sList_Node *pFirst;
    struct sList_Node *pLast;
    unsigned int listSize;
};

struct sList_Node
{
    struct sList_Node *pNext;
    struct sList_Node *pPrev;
};

struct sList_Node_Data
{
    struct sList_Node *pData;

    unsigned int userID;
    long long userPhone;
    char* userLogin;
    char* userSurname;
    int userPassword;
    double userMoney;

};

void DestroyList(sList *list);//Erase list and delete it
void EraseList(sList *list); // Erasing list
void ListInitialization(sList *list);//default list initialization(empty list)
sList* buildList();//Create memory for list
void AddNode(sList *list, sList_Node *node);//add node to back of the list
void CreateDataNode(sList *list);//Inputing new data from keyboard
void Load_List(sList* list);
sList_Node_Data* addDataNode(char* aUserLogin, char* aUserSurname, long long aUserPhone, int aUserPassword, double aUserMoney);//Template func for backup
void Show_Table_List(sList* list);//Display full list
void Save_Table_List(sList* list);// Save to file (work)
void Show_ID_Info(sList* list);
void Backup(sList* list);

int main()
{
    int choice = 0;
    sList userList;
    ListInitialization(&userList);

    do
    {
        system("cls");
        cout << "\t              **********Bank System Menu**********\t"<<endl<<"\t\t      *\t\t\t\t\t *"<<endl;
        cout << "\t\t      *     1. Upload test database: \t *"<<endl;
        cout << "\t\t      *     2. Display database: \t *"<<endl;
        cout << "\t\t      *     3. Erase database: \t\t *"<<endl;
        cout << "\t\t      *     4. Add element to database:  *"<<endl;
        cout << "\t\t      *     5. Destroy database: \t *"<<endl;
        cout << "\t\t      *     6. Find thrue ID: \t\t *"<<endl;
        cout << "\t\t      *     7. Quit&Save: \t\t *"<<endl;
        cout << "\t\t      *\t\t\t\t\t *"<<endl;
        cout << "\t\t      ************************************"<<endl<<endl;
        cout << " Input number of operation: "; cin>>choice;

        switch(choice)
        {
        case 1: Backup(&userList);break;
        case 2: Show_Table_List(&userList);break;
        case 3: EraseList(&userList);break;
        case 4: CreateDataNode(&userList); break;
        case 5: DestroyList(&userList); break;
        case 6: Show_ID_Info(&userList); break;
        case 7: Save_Table_List(&userList);exit(0);
        case 8: Load_List(&userList);
        }

    }while(choice != 7);

    return 0;
}


void Show_ID_Info(sList *list)
{
    unsigned int findId;
    if(nullptr == list->pFirst)
    {
        system("cls");
        cout << "Upload database firstly..." << endl;
    }
    else {
        system("cls");
        bool isFind = false;
        int isSave = 0;
        sList_Node* flag = list->pFirst;

        cout << "Input ID: ";
        cin >>  findId;


        for(unsigned int ID(0); flag != nullptr; flag = flag->pNext)
        {

            ++ID;
            ((sList_Node_Data*)flag)->userID = ID;
            if(findId == ((sList_Node_Data*)flag)->userID)
            {
                system("cls");
                isFind = true;
                cout << "\t\t\t\t  ****" << ((sList_Node_Data*)flag)->userLogin << "'s profile founded****\t" << endl << endl;
                cout << "**************************************" << endl;
                cout << "ID#:      " << ((sList_Node_Data*)flag)->userID   << "\t\t\t     *" << endl
                     << "Name:     " << ((sList_Node_Data*)flag)->userLogin    << "\t\t\t     *" << endl
                     << "Phone:    " << ((sList_Node_Data*)flag)->userPhone    << "\t\t     *" << endl
                     << "Surname:  " << ((sList_Node_Data*)flag)->userSurname  << "\t\t     *" << endl
                     << "Password: " << ((sList_Node_Data*)flag)->userPassword << "\t\t\t     *" << endl
                     << "Cash:     " << ((sList_Node_Data*)flag)->userMoney    << "\t\t\t     *" << endl <<"\t\t\t\t     *"<< endl;
                cout << "**************************************" << endl<<endl;
                //cout << "Press Enter to continue..." << endl;
                //--->Save
                cout << "Save to file?(1-yes;2-no)" << endl;
                cin >> isSave;
                if(1 == isSave)
                {
                    //isopen
                    ofstream infOut("Last_User_Info.txt", ios::out);
                    infOut << "  ****" << ((sList_Node_Data*)flag)->userLogin << "'s profile data****\t\n";
                    infOut << "**************************************\n";
                    infOut << "ID#:      " << ((sList_Node_Data*)flag)->userID   << "\t\t\t     *\n"
                         << "Name:     " << ((sList_Node_Data*)flag)->userLogin    << "\t\t\t     *\n"
                         << "Phone:    " << ((sList_Node_Data*)flag)->userPhone    << "\t\t     *\n"
                         << "Surname:  " << ((sList_Node_Data*)flag)->userSurname  << "\t\t     *\n"
                         << "Password: " << ((sList_Node_Data*)flag)->userPassword << "\t\t\t     *\n"
                         << "Cash:     " << ((sList_Node_Data*)flag)->userMoney    << "\t\t\t     *\n\t\t\t\t     *\n";
                    infOut << "**************************************\n";
                    infOut.close();
                    cout<<"Saved...\n";
                }
                else
                {
                    break;
                }
                //-->>Save
                break;
            }
            else system("cls");
        }
        if(false == isFind)
        {
            cout << "We found nothing..."<<endl;
        }
        _getch();
    }
}

void Backup(sList *list)
{
    system("cls");
    AddNode(list, (sList_Node*)addDataNode((char*)"Vova",(char*)"Petriv",   380638423102, 1234, 5000));
    AddNode(list, (sList_Node*)addDataNode((char*)"Dima",(char*)"Motriy",   380668527302, 4463, 3200));
    AddNode(list, (sList_Node*)addDataNode((char*)"Kostya",(char*)"Sydnyk", 381668821302, 1111, 1328));
    AddNode(list, (sList_Node*)addDataNode((char*)"Anton",(char*)"Nechip",  384646526322, 1212, 132.5));
    cout << "Test database was uploaded..." << endl;
    cout << "Press Enter to continue..." << endl;
    _getch();
}



void CreateDataNode(sList *list)
{
    system("cls");
    char* myLogin = new char[20];
    char* mySurname = new char[20];
    int myPass = 0;
    double myMoney = 0;
    long long myPhone = 0;



    cout << "\t\t\t\t  ****Add element****\t"<<endl<<endl;
    cout << "1) NAME: ";
    scanf("%19s", myLogin);
    cout << "2) SURNAME: ";
    scanf("%19s", mySurname);
    cout << "3) Phone number: ";
    cin >> myPhone;
    cout << "3) PASSWORD: ";
    cin >> myPass;
    cout << "4) CARD CASH: ";
    cin >> myMoney;

    AddNode(list,(sList_Node*)addDataNode(myLogin, mySurname, myPhone, myPass, myMoney));

}

void Load_List(sList *list)
{
    system("cls");
    char* myLogin = new char[20];
    char* mySurname = new char[20];
    int myPass = 0;
    double myMoney = 0;
    long long myPhone = 0;
    ifstream loadlist("List_load.txt");
    for(int id = 0; id<=2; ++id)
    {
        loadlist >> myLogin;
        loadlist >> mySurname;
        loadlist >> myPhone;
        loadlist >> myPass;
        loadlist >> myMoney;
        AddNode(list,(sList_Node*)addDataNode(myLogin, mySurname, myPhone, myPass, myMoney));
    }
    loadlist.close();
}


void DestroyList(sList *list)
{
    EraseList(list);
    delete[] list;
}

void EraseList(sList *list)
{
    if(nullptr == list->pFirst)
    {
        system("cls");
        cout << "No such data for erase/delete..." << endl;
        cout << "Press Enter to continue..." << endl;
        _getch();
    }
    else
    {
        system("cls");
        sList_Node* flag = list->pFirst;
        while(flag)
        {
            sList_Node* nextFlag = flag->pNext;
            delete[] flag;
            flag = nextFlag;
        }
        ListInitialization(list);
        cout << "Erase complete sucessfuly" << endl;
        _getch();
    }
}


void Show_Table_List(sList *list)
{
    if(nullptr == list->pFirst)
    {
        system("cls");
        cout << "Upload database firstly..." << endl;
    }
    else {
        system("cls");
        sList_Node* flag = list->pFirst;

        cout << "\t\t\t      ****Full Database****\t"<<endl<<"*********************************************************************************"<<endl;
        cout << "ID#" <<"\t|\t    " << "NAME" <<"\t|\t  "
             << "PASSWORD" <<"\t|    " << "   CARD BALANCE" <<"\t*\t    " <<endl;
        cout <<"*********************************************************************************"<<endl;
        for(int ID(0) ; flag != nullptr; flag = flag->pNext)
        {
            ++ID;
            ((sList_Node_Data*)flag)->userID = ID;
            cout << ((sList_Node_Data*)flag)->userID <<"\t|\t    " << ((sList_Node_Data*)flag)->userLogin <<"\t|\t    "
                 << "****" <<"\t|\t    " << ((sList_Node_Data*)flag)->userMoney <<"\t*\t    " <<endl;    // "****" swap to ((sList_Node_Data*)flag)->userPassword
            //cout <<"---------------------------------------------------------------------------------"<<endl;

        }
        cout <<"*********************************************************************************"<<endl;
    }
    cout << "Press Enter to continue..." << endl;
    _getch();
}

void Save_Table_List(sList *list)
{
    ofstream saveList("List.txt", ios::out);
    if(saveList)
    {
        system("cls");
        sList_Node* flag = list->pFirst;

        for(int ID(0) ; flag != nullptr; flag = flag->pNext)
        {
            ++ID;
            ((sList_Node_Data*)flag)->userID = ID;
            saveList << ((sList_Node_Data*)flag)->userLogin <<"\n"
                     << ((sList_Node_Data*)flag)->userSurname <<"\n"
                     << ((sList_Node_Data*)flag)->userPhone <<"\n"
                     << ((sList_Node_Data*)flag)->userPassword <<"\n"
                     << ((sList_Node_Data*)flag)->userMoney <<"\n";
        }
        saveList.close();
    }
    else
    {
        cout << "Saving error<<--\n";
    }
}


void ListInitialization(sList *list)
{
    list->pFirst = nullptr;//in C :  list->pFirst = NULL
    list->pLast = nullptr;
    list->listSize = 0;
}


sList* buildList()
{
    sList *list = new sList;
    ListInitialization(list);
    return list;
}

void AddNode(sList *list, sList_Node *node)
{

    sList_Node* last = list->pLast;

    if(last)
    {
        last->pNext = node;
        node->pPrev = last;
    }
    else
    {
        list->pFirst = node;
        node->pPrev = nullptr;
    }
    list->pLast = node;
    node->pNext = nullptr;

    ++list->listSize;
}

sList_Node_Data* addDataNode(char* aUserLogin, char* aUserSurname, long long aUserPhone, int aUserPassword, double aUserMoney)
{

    sList_Node_Data *data = new sList_Node_Data;

    data->userLogin = aUserLogin;
    data->userSurname = aUserSurname;
    data->userPhone = aUserPhone;
    data->userPassword = aUserPassword;
    data->userMoney = aUserMoney;

    return data;
}
