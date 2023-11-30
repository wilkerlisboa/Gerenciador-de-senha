#include <iostream>
#include <vector>
#include <string>

struct PasswordEntry {
    std::string serviceName;
    std::string username;
    std::string password;
};

class PasswordManager {
private:
    std::vector<PasswordEntry> passwords;

public:
    void addPassword(const std::string& serviceName, const std::string& username, const std::string& password) {
        PasswordEntry entry;
        entry.serviceName = serviceName;
        entry.username = username;
        entry.password = password;
        passwords.push_back(entry);
        std::cout << "Senha adicionada com sucesso para " << serviceName << std::endl;
    }

    void displayPasswords() {
        std::cout << "\n\nSenhas armazenadas:" << std::endl << std::endl;
        for (const auto& entry : passwords) {
            std::cout << "Servico: " << entry.serviceName << std::endl << "Usuario: " << entry.username << std::endl << "Senha: " << entry.password << std::endl<< std::endl;
        }
    }
};

int main() {
    PasswordManager passwordManager;

    while (true) {
        std::cout << "\nSistema de Gerenciamento de Senhas" << std::endl;
        std::cout << "1. Adicionar Senha" << std::endl;
        std::cout << "2. Visualizar Senhas" << std::endl;
        std::cout << "3. Sair" << std::endl;

        int choice;
        std::cout << "Escolha a opcao: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string serviceName, username, password;
                std::cout << "Informe o servico: ";
                std::cin >> serviceName;
                std::cout << "Informe o usuario: ";
                std::cin >> username;
                std::cout << "Informe a senha: ";
                std::cin >> password;
                passwordManager.addPassword(serviceName, username, password);
                break;
            }
            case 2:
                passwordManager.displayPasswords();
                break;
            case 3:
                std::cout << "Saindo do programa." << std::endl;
                return 0;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }
    }

    return 0;
}

