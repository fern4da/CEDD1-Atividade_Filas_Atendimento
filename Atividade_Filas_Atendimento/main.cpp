#include <iostream>
using namespace std;

const int TAM = 100;

class Fila {
private:
    int dados[TAM];
    int inicio;
    int fim;
    int quantidade;

public:
    Fila() {
        inicio = 0;
        fim = -1;
        quantidade = 0;
    }

    bool vazia() {
        return quantidade == 0;
    }

    bool cheia() {
        return quantidade == TAM;
    }

    void enfileirar(int valor) {
        if (!cheia()) {
            fim = (fim + 1) % TAM;
            dados[fim] = valor;
            quantidade++;
        }
    }

    int desenfileirar() {
        if (!vazia()) {
            int valor = dados[inicio];
            inicio = (inicio + 1) % TAM;
            quantidade--;
            return valor;
        }
        return -1;
    }

    int tamanho() {
        return quantidade;
    }
};


int main() {

    Fila senhasGeradas;
    Fila senhasAtendidas;

    int opcao;
    int contadorSenha = 0;

    do {

        cout << "\n=================================\n";
        cout << "Senhas aguardando: "
             << senhasGeradas.tamanho() << endl;
        cout << "=================================\n";

        cout << "0 - Sair\n";
        cout << "1 - Gerar senha\n";
        cout << "2 - Realizar atendimento\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {

            case 1: {

                contadorSenha++;

                senhasGeradas.enfileirar(contadorSenha);

                cout << "Senha gerada: "
                     << contadorSenha << endl;

                break;
            }

            case 2: {

                if (senhasGeradas.vazia()) {

                    cout << "Nao existem senhas aguardando.\n";

                } else {

                    int senha =
                        senhasGeradas.desenfileirar();

                    cout << "Atendendo senha: "
                         << senha << endl;

                    senhasAtendidas.enfileirar(senha);
                }

                break;
            }

            case 0: {

                if (!senhasGeradas.vazia()) {

                    cout << "Ainda existem senhas aguardando atendimento!\n";
                    opcao = -1;
                }

                break;
            }

            default:
                if (opcao != -1)
                    cout << "Opcao invalida!\n";
        }

    } while (opcao != 0);

    cout << "\nSistema encerrado.\n";

    cout << "Quantidade de senhas atendidas: "
         << senhasAtendidas.tamanho()
         << endl;

    return 0;
}