#include <iostream>
using namespace std;

struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();

int main() {
    menu();
}

void menu() {
    int op = 0;
    while (op != 7) {
        system("cls");
        cout << "Menu Lista Ligada\n\n";
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";
        cout << "Opcao: ";
        cin >> op;

        switch (op) {
        case 1: inicializar(); break;
        case 2: exibirQuantidadeElementos(); break;
        case 3: exibirElementos(); break;
        case 4: buscarElemento(); break;
        case 5: inserirElemento(); break;
        case 6: excluirElemento(); break;
        case 7: return;
        default: break;
        }
        system("pause");
    }
}

void inicializar() {
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }
    primeiro = NULL;
    ultimo = NULL;
    cout << "Lista inicializada\n";
}

void exibirQuantidadeElementos() {
    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos() {
    if (primeiro == NULL) {
        cout << "Lista vazia\n";
        return;
    }
    NO* aux = primeiro;
    cout << "Elementos:\n";
    while (aux != NULL) {
        cout << aux->valor << endl;
        aux = aux->prox;
    }
}

void inserirElemento() {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return;

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
        ultimo = novo;
        return;
    }

    NO* atual = primeiro;
    NO* anterior = NULL;
    while (atual != NULL && atual->valor < novo->valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->valor == novo->valor) {
        cout << "Elemento duplicado, não inserido\n";
        free(novo);
        return;
    }

    if (anterior == NULL) {
        novo->prox = primeiro;
        primeiro = novo;
    }
    else {
        novo->prox = atual;
        anterior->prox = novo;
    }

    if (novo->prox == NULL) ultimo = novo;
}

void buscarElemento() {
    if (primeiro == NULL) {
        cout << "Lista vazia\n";
        return;
    }

    int numero;
    cout << "Digite o numero a buscar: ";
    cin >> numero;

    NO* aux = primeiro;
    while (aux != NULL) {
        if (aux->valor == numero) {
            cout << "ENCONTRADO\n";
            return;
        }
        if (aux->valor > numero) break;
        aux = aux->prox;
    }
    cout << "ELEMENTO NAO ENCONTRADO\n";
}

void excluirElemento() {
    if (primeiro == NULL) {
        cout << "Lista vazia\n";
        return;
    }

    int numero;
    cout << "Digite o numero a excluir: ";
    cin >> numero;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor < numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL || atual->valor != numero) {
        cout << "ELEMENTO NAO ENCONTRADO\n";
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    if (atual->prox == NULL) ultimo = anterior;

    free(atual);
    cout << "Elemento excluido\n";
}
