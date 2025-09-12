#include <iostream>
#include <windows.h>

using namespace std;
struct Pipe {
    string Name;
    float length;
    int diametr;
    bool status;
};
struct CS {
    string name;
    int number_work;
    int number_work_online;
    string class_cs;
};
void addpipe(Pipe& pipe) {
    system("cls");
    cout << "=== Добавление трубы ===" << endl;
    cout << "Введите километровую отметку (Название трубы): ";
    cin.ignore();
    cin >> pipe.Name;
    cout << "Введите длину трубы (км): ";
    while (!(cin >> pipe.length) || pipe.length <= 0) {
        cout << "Ошибка! Введите положительное число: ";
        cin.clear();
        cin.ignore(1000, '\n');

    }
    cout << "Введите диаметр трубы (мм): ";
    while (!(cin >> pipe.diametr) || pipe.diametr <= 0 || cin.peek() != '\n') {
        cout << "Ошибка! Введите положительное число: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Труба в ремонте? (1 - да, 0 - нет): ";
    int repairStatus;
    while (!(cin >> repairStatus) || (repairStatus != 0 && repairStatus != 1)) {
        cout << "Ошибка! Введите 0 или 1: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    pipe.status = (repairStatus == 1);

    cout << "Труба успешно добавлена!" << endl;
}
void ShowMenu() {
    int options;
    bool flag = true;
    Pipe pipe;
    while (flag) {
        cout << "Пример меню:\n 1. Добавить трубу\n 2. Добавить КС\n 3. Просмотр всех объектов\n 4. Редактировать трубу\n 5. Редактировать КС\n 6. Сохранить\n 7. Загрузить\n 0. Выход\n";
        cin >> options;
        switch (options) {
        case 0:
            cout << "Complete";
            flag = false;
            break;
        case 1:
            addpipe(pipe);
            system("cls");
            cout << "Труба успешно добавлена!" << endl;
            break;

        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ShowMenu();

}

