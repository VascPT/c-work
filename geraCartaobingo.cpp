#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

int main() {
    srand(time(NULL));
    
    //PEDIR quantos cartões quer gerar
    int num_cartoes;
    cout << "Quantos cartoes de Bingo quer gerar? (1 a 500): ";
    cin >> num_cartoes;
    
    // Validar entrada
    if (num_cartoes < 1 || num_cartoes > 500) {
        cout << "Numero invalido! Deve ser entre 1 e 500." << endl;
        return 1;
    }
    
    int minimos[5] = {1, 21, 41, 61, 81};
    int maximos[5] = {20, 40, 60, 80, 100};
    
    //Gerar múltiplos cartões
    for (int cartao_num = 1; cartao_num <= num_cartoes; cartao_num++) {
        //CRIAR nome do ficheiro
        string nome_ficheiro = "cartao" + to_string(cartao_num) + ".txt";
        
        //ABRIR ficheiro para este cartão
        ofstream arquivo(nome_ficheiro);
        
        if (!arquivo.is_open()) {
            cout << "Erro ao criar ficheiro " << nome_ficheiro << "!" << endl;
            continue;  //Tenta o próximo cartão
        }
        
        int cartao[5][5];
        
        //Gera números para cada coluna
        for (int coluna = 0; coluna < 5; coluna++) {
            vector<int> numeros_coluna;
            
            while (numeros_coluna.size() < 5) {
                int numero = minimos[coluna] + rand() % (maximos[coluna] - minimos[coluna] + 1);
                
                bool repetido = false;
                for (int n : numeros_coluna) {
                    if (n == numero) {
                        repetido = true;
                        break;
                    }
                }
                
                if (!repetido) {
                    numeros_coluna.push_back(numero);
                }
            }
            
            for (int linha = 0; linha < 5; linha++) {
                cartao[linha][coluna] = numeros_coluna[linha];
            }
        }
        
        //ESCREVER no ficheiro
        arquivo << "Cartao de Bingo #" << cartao_num << "\n";
        arquivo << " B    I    N    G    O\n";
        arquivo << "----------------------\n";
        
        for (int linha = 0; linha < 5; linha++) {
            for (int coluna = 0; coluna < 5; coluna++) {
                if (coluna == 2 && linha == 2) {
                    arquivo << " ** ";
                } else {
                    if (cartao[linha][coluna] < 10) {
                        arquivo << "  " << cartao[linha][coluna] << " ";
                    } else {
                        arquivo << " " << cartao[linha][coluna] << " ";
                    }
                }
            }
            arquivo << endl;
        }
        
        //FECHAR este ficheiro
        arquivo.close();
        
        //Mostrar no terminal também
        cout << "Cartao " << cartao_num << " criado: " << nome_ficheiro << endl;
    }
    
    cout << "\n----------------------------------------\n";
    cout << "Foram criados " << num_cartoes << " ficheiros:\n";
    cout << "cartao1.txt, cartao2.txt, ... cartao" << num_cartoes << ".txt\n";
    
    return 0;
}
