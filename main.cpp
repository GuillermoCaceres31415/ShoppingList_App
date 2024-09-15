#include <iostream>
#include "Account.h"
#include "unordered_map"
#include "DisplayShowQty.h"


void ShowMainMenu(Account &account);

int main() {
    std::unordered_map<std::string,Account> DataBase;
    bool loop= true;

    while (loop) {
        std::cout << R"(
╔═════════════════════════════════════════╗
║            MENU DI LOGIN                ║
╠═════════════════════════════════════════╣
║                                         ║
║    [1] 📝 Crea un nuovo account         ║
║    [2] 🔑 Accedi al tuo account         ║
║    [3] 🚪 Esci                          ║
║                                         ║
╚═════════════════════════════════════════╝
)" << std::endl;

        int command;
        std::cout<<"inserire un comando: ";
        std::cin >> command;
        Account *account = nullptr;

        switch (command) {
            case 1: { // crea account
                std::cout << "scegliere un nome: ";
                std::string name;
                std::cin >> name;

                std::cout << "crea una password: ";
                std::string password;
                std::cin >> password;

                 account=new Account(name, password);

                if (DataBase.find(name) == DataBase.end()) {
                    DataBase.insert({name, *account});

                    ShowMainMenu(DataBase.find(name)->second);

                } else
                    std::cout << "nome utente già usato" << std::endl;
                break;
            }
            case 2: {  // log-in account
                std::cout << "scrivere il nome dell'account: ";
                std::string name;
                std::cin >> name;

                if (DataBase.find(name) != DataBase.end()) {
                    std::cout << "scrivere la password: ";
                    std::string password;
                    std::cin >> password;
                    if (password == DataBase.find(name)->second.getPassword()) {
                        ShowMainMenu(DataBase.find(name)->second);
                    } else {
                        std::cout << "password errata" << std::endl;
                    }
                } else {
                    std::cout << "nome utente non trovato" << std::endl;
                }
                break;
            }
            case 3:
                loop= false;
                break;
            default:
                std::cout<<"inserire un comando valido"<<std::endl;
                break;
        }
    }
    return 0;
}

void ShowMainMenu(Account &account) {



    DisplayShowQty displayShowQty(&account.getList());

    bool innerLoop = true;
    while (innerLoop) {
        std::cout << R"(
╔═════════════════════════════════════════╗
║    BENVENUTO )" << account.getName() << R"(                      ║
╠═════════════════════════════════════════╣
║    N° PRODOTTI:)" << displayShowQty.ShowQty() << R"(                       ║
╠═════════════════════════════════════════╣
║                                         ║
║    [1] AGGIUNGI PRODOTTO                ║
║    [2] RIMUOVERE PRODOTTO               ║
║    [3] STAMPA LISTA                     ║
║    [4] ESCI                             ║
║                                         ║
╚═════════════════════════════════════════╝
)" << std::endl;

        int command;
        std::cout << "inserire un comando: ";
        std::cin >> command;

        switch (command) {
            case 1: {  // Aggiungi prodotto
                std::cout << "inserire nome prodotto: ";
                std::string nameProduct;
                std::cin >> nameProduct;

                std::cout << "inserire categoria: ";
                std::string CategoryProduct;
                std::cin >> CategoryProduct;

                std::cout << "inserire quantità: ";
                unsigned int qty;
                std::cin >> qty;

                account.getList().AddProduct(nameProduct, CategoryProduct, qty);
                std::cout << "prodotto aggiunto con successo" << std::endl;

                break;
            }
            case 2: {  // Rimuovi prodotto
                std::cout << "inserire nome prodotto: ";
                std::string nameProduct;
                std::cin >> nameProduct;

                account.getList().RemoveProduct(nameProduct);
                std::cout << "prodotto rimosso con successo" << std::endl;

                break;
            }
            case 3:  // Stampa lista
                account.getList().PrintList();
                break;

            case 4:  // Esci dal menu
                innerLoop = false;
                break;

            default:
                std::cout << "comando non valido" << std::endl;
        }
    }
}

