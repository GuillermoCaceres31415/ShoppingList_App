#include <iostream>
#include "Account.h"
#include "unordered_map"

void ShowMainMenu(Account &account,bool &loop);

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

        switch (command) {
            case 1: { // crea account
                std::cout << "si scelga un nome: ";
                std::string name;
                std::cin >> name;

                std::cout << "si sclega una password: ";
                std::string password;
                std::cin >> password;

                Account account(name, password);

                if (DataBase.find(name) == DataBase.end()) {
                    DataBase.insert(std::pair<std::string, Account>(name, account));
                } else
                    std::cerr << "nome utente già usato" << std::endl;
                ShowMainMenu(account,loop);

                break;
            }
            case 2: {
                std::cout << "si scriva il nome: ";
                std::string name;
                std::cin >> name;


                auto it = DataBase.find(name);

                if (it != DataBase.end()) {
                    std::cout << "si scriva la password: ";
                    std::string password;
                    std::cin >> password;
                    if (password == (it->second).getPassword()) {
                        Account account = (it->second);
                        ShowMainMenu(account,loop);
                    } else
                        std::cout << "password errata" << std::endl;
                } else
                    std::cout << "nome utente non trovato" << std::endl;

            }
            case 3:
                loop= false;
                break;

            default:
                std::cout << "comando non valido" << std::endl;


        }

    }

    return 0;

}

void ShowMainMenu(Account &account,bool &loop){

bool innerLoop= true;
    while (innerLoop) {
        std::cout << R"(
╔═════════════════════════════════════════╗
║    BENVENUTO )" << account.getName() << R"(                       ║
╠═════════════════════════════════════════╣
║    N° PRODOTTI:)" << 40 << R"(                       ║
╠═════════════════════════════════════════╣
║                                         ║
║    [1] AGGIUNGI PRODOTTO                ║
║    [2] RIMUOVERE PRODOTTO               ║
║    [3] STAMPA LISTA                     ║
║    [4] ESCI                             ║
║                                         ║
║                                         ║
╚═════════════════════════════════════════╝
)" << std::endl;

        std::cout << "inserire un comando: ";
        int command;
        std::cin >> command;

        switch (command) {
            case 1: {

                std::cout << "inserire nome prodotto: ";
                std::string nameProduct;
                std::cin >> nameProduct;

                std::cout << "inserire categoria: ";
                std::string CategoryProduct;
                std::cin >> CategoryProduct;

                std::cout << "inserire quantità: ";
                unsigned int qty;
                std::cin >> qty;

                ShoppingList shoppingList;

                shoppingList=account.getList();

                shoppingList.AddProduct(nameProduct,CategoryProduct,qty);

                account.setList(shoppingList);



                break;
            }
            case 2: {
                std::cout << "inserire nome prodotto: ";
                std::string nameProduct;
                std::cin >> nameProduct;

                ShoppingList shoppingList;

                shoppingList=account.getList();

                shoppingList.RemoveProduct(nameProduct);

                account.setList(shoppingList);

                break;
            }
            case 3: {
                account.getList().PrintList();
                break;
            }
            case 4:
                innerLoop= false;
                loop = false;
                break;

            default:
                std::cout << "comando non valido" << std::endl;
        }

    }

std::string ba="ff";
ShoppingList shoppingList;
shoppingList.AddProduct(ba,ba,5);
shoppingList.AddProduct(ba,ba,5);
shoppingList.PrintList();


}
