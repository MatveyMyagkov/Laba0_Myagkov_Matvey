#include <iostream>
#include <windows.h>
using namespace std;
struct Pipe {
    string Name;
    float lenght;
    int diametr;
    bool status;
 };
struct CS {
    string name;
    int number_work;
    int number_work_online;
    string class_cs;
};
void ShowMenu() {
    int options;
    while (1) {
        cout << "Пример меню:\n 1. Добавить трубу\n 2. Добавить КС\n 3. Просмотр всех объектов\n 4. Редактировать трубу\n 5. Редактировать КС\n 6. Сохранить\n 7. Загрузить\n 0. Выход\n";
        cin >> options;
        switch (options) {
        case 0:
            break;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ShowMenu();

}
