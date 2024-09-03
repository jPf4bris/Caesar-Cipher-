#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

void ler_Arquivo(const string& nomeArquivo){

    string nomeArq = "texto_legal";

    ifstream arquivo(nomeArq);
        if(!arquivo){
            cout << "Erro ao abrir o arquivo." << endl;
           return;
        }
        cout << "Conteudo do arquivo: \n";
        string linha;
            while(getline(arquivo, linha)){
                cout << linha << endl;
            }
        arquivo.close();

}
string cifra(const string& texto, int posicao){

    string final = texto;
        for(size_t i = 0; i < texto.size(); i++){
            char c = texto[i];
                if(isalpha(c)){
                    char base = islower(c) ? 'a' : 'A';
                    final[i] = (c - base + posicao) % 26 + base;
                }
        }
    return final;

}
void criptografar_Arquivo(const string& nomeArquivo, int posicao){

    ifstream arquivo(nomeArquivo);
        if(!arquivo){
            cout << "Erro ao abrir o arquivo.\n" << endl;
           return;
        }
    string conteudo((istreambuf_iterator<char>(arquivo)), istreambuf_iterator<char>());
        arquivo.close();

    string conteudoCriptografado = cifra(conteudo, posicao);

    ofstream arquivoCriptografado(nomeArquivo);
        arquivoCriptografado << conteudoCriptografado;
        arquivoCriptografado.close();

    cout << "Texto criptografado.\n" << endl;
}
void descriptografar_Arquivo(const string& nomeArquivo, int posicao) {

    criptografar_Arquivo(nomeArquivo, 26 - posicao);
        cout << "Texto descriptografado.\n" << endl;
}


int main(){
    string nomeArq = "texto_legal";
    int op, posicao = 2;
    do
    {
        cout << "\n...Menu...\n";
                cout << "1. Criptografar texto.\n";
                cout << "2. Descriptografar texto.\n";
                cout << "3. Mostrar texto.\n";
                cout << "9. Sair.\n";
                cout << "Digite sua escolha: ";
                    cin >> op;
                cout << endl;
        
        switch (op)
        {
        case 1:
            criptografar_Arquivo(nomeArq, posicao);
            break;
        case 2:
            descriptografar_Arquivo(nomeArq, posicao);
            break;
        case 3:
            ler_Arquivo(nomeArq);
            break;
        case 9:
            cout << "Saindo.\n";
            break;
        default:
            cout << "Opcao invalida." << endl;
            break;
        }
    } while (op != 9);
   
return 0;
}