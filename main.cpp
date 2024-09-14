#include <iostream>
#include "Account.h"
#include "unordered_map"

int main() {

    std::unordered_map<std::string,Account> DataBase;

    bool loop= true;

    while (loop) {

        std::cout << R"(
╔═════════════════════════════════════════╗
║    BENVENUTO IN SHOPPING LIST APP       ║
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
                    } else
                        std::cerr << "password errata" << std::endl;
                } else
                    std::cerr << "nome utente non trovato" << std::endl;

            }
            case 3:
                loop= false;
                break;

            default:
                std::cerr << "comando non valido" << std::endl;


        }


    }


    return 0;
}
