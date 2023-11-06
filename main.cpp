#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <fstream>

// Author: ig: @damixdamixx

using namespace std;

bool IsFileExists(const string& filePath) {
    ifstream file(filePath);
    return file.good();
}

void NewBroken(){
    string dysk;
    int znaktwo;
    do{
        cout << "1. Uruchom Broken Ranks" << "\n";
        cout << "2. Wylacz program" << "\n";
        cout << "Wybierz opcje: "; cin >> znaktwo;
        
        switch(znaktwo){
            case 1:
                system("cls");
                cout << "Podaj litere dysku na ktorym jest zainstalowany Broken Ranks: "; cin >> dysk;
                system(("C:\\Sandboxie\\Start.exe /box:DefaultBox " + dysk + ":\\Whitemoon\\BrokenRanks\\client\\BrokenRanks.exe").c_str());
                break;
            case 2:
                system("cls");
                system("exit");
                break;
            default:
                system("cls");
                cout << "Nie ma takiej opcji!!!!" << "\n";
                break;
        }

    }while(znaktwo = 1 && znaktwo != 2);
};

void InstallProg() {
    int znak;


    do {
        cout << "1. Zainstaluj program" << "\n";
        cout << "2. Przejdz dalej" << "\n";
        cout << "3. Wylacz program" << "\n";
        cout << "Wybierz opcje: "; cin >> znak;

        switch (znak) {

        case 1:
            system("cls");
            system("mkdir C:\\Sandboxie");
            system("winget settings --enable LocalManifestFiles");
            system("winget install --id=Sandboxie.Plus -e --location C:\\Sandboxie");
            Sleep(1000);
            system("cls");
            cout << "PO URUCHOMIENIU PROGRAMU KLIKAJ DALEJ, A PO PRZEJSCIU DALEJ WYJDZ Z PROGRAMU";
            system("C:\\Sandboxie\\SandMan.exe");
            break;
        case 2:
            NewBroken();
            break;
        case 3:
            system("exit");
            break;
        default:
            cout << "Nie ma takiej opcji!!!" << "\n";
            system("cls");
            break;
        }
    } while (znak == 1 && znak != 2);
};

void ScanPath(){
    string filePath = "C:\\Sandboxie\\Start.exe";
    if (IsFileExists(filePath)) {
        NewBroken();
    } else {
        InstallProg();
    }
}


int main() {
    system("cls");
    ScanPath();
    SetConsoleTitleA("Config Broken Multi BETA");
    return 0;
}