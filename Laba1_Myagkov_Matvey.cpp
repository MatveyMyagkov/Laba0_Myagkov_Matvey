#include <iostream>
#include <windows.h>
#include <limits>
using namespace std;
struct Pipe {
    string Name;
    float length;
    int diametr;
    bool status;
};
struct CS {
    string Name;
    int number_work;
    int number_work_online;
    string class_cs;
};
void Addpipe(Pipe& pipe) {
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

}

void Addcs(CS& cs) {
    system("cls");
    cout << "=== Добавление трубы ===" << endl;
    cout << "Введите название КС: ";
    cin.ignore();
    cin >> cs.Name;
    cout << "Введите количество цехов: ";
    while (!(cin >> cs.number_work) || cs.number_work <= 0 || cin.peek() != '\n') {
        cout << "Ошибка! Введите положительное целое число: ";
        cin.clear();
        cin.ignore(1000, '\n');

    }
    cout << "Введите диаметр трубы (мм): ";
    while (!(cin >> cs.number_work_online) || cs.number_work_online <= 0 || cin.peek() != '\n' || cs.number_work < cs.number_work_online) {
        cout << "Ошибка! Введите положительное целое число (Онлайн цехи не могут превышать количество цехов): ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cout << "Введите класс станций(некий показатель, обобщающий различные специфические характеристики): ";
    cin.ignore();
    cin >> cs.class_cs;

}

void ViewAllObjects(const Pipe& pipe, const CS& cs) {
    system("cls");
    cout << "Просмотр всех объектов" << endl;

    if (pipe.Name.empty()) {
        cout << "Труба: не добавлена\n";
    }
    else {
        cout << "Труба" << endl;
        cout << "Название: " << pipe.Name << endl;
        cout << "Длина: " << pipe.length << " км" << endl;
        cout << "Диаметр: " << pipe.diametr << " мм" << endl;
        cout << "Статус: " << (pipe.status ? "В ремонте" : "Работает") << endl;
    }

    cout << endl;


    if (cs.Name.empty()) {
        cout << "КС: не добавлена" << endl;
    }
    else {
        cout << "Компрессорная станция" << endl;
        cout << "Название: " << cs.Name << endl;
        cout << "Всего цехов: " << cs.number_work << endl;
        cout << "Цехов онлайн: " << cs.number_work_online  << endl;
        cout << "Класс: " << cs.class_cs << endl;
    }


    cout << "Нажмите Enter для продолжения...";
    cin.ignore(1000, '\n');
    while (cin.get() != '\n');
}
void ShowMenu() {
    int options;
    bool flag = true;
    Pipe pipe;
    CS cs;
    while (flag) {
        system("cls");
        cout << "Пример меню:\n 1. Добавить трубу\n 2. Добавить КС\n 3. Просмотр всех объектов\n 4. Редактировать трубу\n 5. Редактировать КС\n 6. Сохранить\n 7. Загрузить\n 0. Выход\n";
        cin >> options;
        switch (options) {
        case 0:
            cout << "Complete";
            flag = false;
            break;
        case 1:
            Addpipe(pipe);       
            cout << "Труба успешно добавлена!" << endl;
            break;
        case 2:
            Addcs(cs);
            cout << "КС успешно добавлена!" << endl;
            break;

        case 3:
            ViewAllObjects(pipe, cs);
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

