#include <iostream>
#include <vector>
#include "MusicalInstrument.h"
#include "StringInstrument.h"
#include "ElectronicInstrument.h"
#include "ElectricViolin.h"

using namespace std;

void runPolyphonicTest(const vector<MusicalInstrument*>& instruments) {
    cout << "\n===== ТЕСТ: описание звучания через указатель на MusicalInstrument =====\n";
    for (size_t i = 0; i < instruments.size(); i++) {
        cout << "\nИнструмент " << i + 1 << ":\n";
        instruments[i]->play();
        cout << "\n";
    }
    cout << "\nТест пройден. Все вызовы через MusicalInstrument*\n";
}

void clearInstruments(vector<MusicalInstrument*>& instruments) {
    for (size_t i = 0; i < instruments.size(); i++) {
        delete instruments[i];
    }
    instruments.clear();
}

int main() {
    vector<MusicalInstrument*> instruments;
    int choice;

    cout << "\nДОБРО ПОЖАЛОВАТЬ В ПУНКТ ПРОКАТА ИНСТРУМЕНТОВ\n";
    cout << "Иерархия с ромбовидным наследованием (virtual inheritance)\n";
    cout << "Абстрактный класс MusicalInstrument с чистой вирт. функцией play()\n";
    cout << "\n===== ПРОКАТ ИНСТРУМЕНТОВ ДЛЯ КОНЦЕРТОВ =====\n";
    cout << "1. Сдать струнный инструмент в прокат\n";
    cout << "2. Сдать электронный инструмент в прокат\n";
    cout << "3. Сдать ЭЛЕКТРОСКРИПКУ в прокат (множ. насл.)\n";
    cout << "4. Показать все инструменты в прокате\n";
    cout << "5. Описание звучания инструмента (play)\n";
    cout << "6. Вернуть инструмент из проката (удалить последний)\n";
    cout << "7. ЗАПУСТИТЬ ТЕСТ (полиморфизм)\n";
    cout << "8. Выход\n";

    while (true) {
        cout << "\nВаш выбор: ";
        
        if (!(cin >> choice)) {
            cout << "Ошибка ввода. Завершение работы.\n";
            clearInstruments(instruments);
            break;
        }

        switch (choice) {
            case 1: {
                string name, material;
                double price;
                int strings;
                cout << "Название: ";
                cin.ignore();
                getline(cin, name);
                cout << "Цена проката за день: ";
                cin >> price;
                cout << "Количество струн: ";
                cin >> strings;
                cout << "Материал струн: ";
                cin >> material;
                instruments.push_back(new StringInstrument(name, price, strings, material));
                cout << "Струнный инструмент принят в прокат!";
                break;
            }
            case 2: {
                string name;
                double price;
                int watts;
                char amp;
                cout << "Название: ";
                cin.ignore();
                getline(cin, name);
                cout << "Цена проката за день: ";
                cin >> price;
                cout << "Мощность (Вт): ";
                cin >> watts;
                cout << "Есть усилитель? (y/n): ";
                cin >> amp;
                instruments.push_back(new ElectronicInstrument(name, price, watts, (amp == 'y')));
                cout << "Электронный инструмент принят в прокат!";
                break;
            }
            case 3: {
                string name, material, bodyMaterial;
                double price;
                int strings, watts;
                char amp;
                cout << "Модель электроскрипки: ";
                cin.ignore();
                getline(cin, name);
                cout << "Цена проката за день: ";
                cin >> price;
                cout << "Количество струн (обычно 4): ";
                cin >> strings;
                cout << "Материал струн: ";
                cin >> material;
                cout << "Есть встроенный усилитель? (y/n): ";
    		cin >> amp;
    		cout << "Мощность усилителя (Вт): ";
    		cin >> watts;
		cout << "Материал корпуса: ";
                cin >> bodyMaterial;
                
                instruments.push_back(new ElectricViolin(name, price, strings, material,
                                                          watts, (amp == 'y'), bodyMaterial));
                cout << "Электроскрипка принята в прокат!";
                break;
            }
            case 4: {
                if (instruments.empty()) {
                    cout << "В прокате нет инструментов.";
                } else {
                    cout << "\nСПИСОК ИНСТРУМЕНТОВ В ПРОКАТЕ:\n";
                    cout << "----------------------------------------\n";
                    for (size_t i = 0; i < instruments.size(); i++) {
                        cout << i + 1 << ". ";
                        instruments[i]->printInfo();
                        cout << "\n";
                    }
                    cout << "----------------------------------------";
                }
                break;
            }
            case 5: {
                if (instruments.empty()) {
                    cout << "Нет инструментов в прокате.";
                } else {
                    int idx;
                    cout << "Выберите номер инструмента (1-" << instruments.size() << "): ";
                    cin >> idx;
                    if (idx >= 1 && idx <= (int)instruments.size()) {
                        cout << "\nОПИСАНИЕ ЗВУЧАНИЯ:\n";
                        instruments[idx - 1]->play();
                        cout << "";
                    } else {
                        cout << "Неверный номер.";
                    }
                }
                break;
            }
            case 6: {
                if (!instruments.empty()) {
                    delete instruments.back();
                    instruments.pop_back();
                    cout << "Инструмент возвращён из проката.";
                } else {
                    cout << "Нет инструментов для возврата.";
                }
                break;
            }
            case 7: {
                if (instruments.empty()) {
                    cout << "Сначала примите хотя бы один инструмент в прокат.";
                } else {
                    runPolyphonicTest(instruments);
                }
                break;
            }
            case 8: {
                clearInstruments(instruments);
                cout << "Работа проката завершена. До свидания!\n";
                
		exit(0);
    	    }	
            default:
                cout << "Неверный выбор. Попробуйте снова.";
        }
    }

    return 0;
}
