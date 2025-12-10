#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    //verificar se foi fornecido o número de cartões
    if (argc != 2) {
        cout << "Uso: ./geraCartaobingo [numero_de_cartoes]" << endl;
        cout << "Exemplo: ./geraCartaobingo 10" << endl;
        cout << "Minimo: 1 cartao, Maximo: 500 cartoes" << endl;
        return 1;
    }
    
    //converter argumento para número
    int num_cartoes = atoi(argv[1]);
    
    //validar entrada
    if (num_cartoes < 1 || num_cartoes > 500) {
        cout << "ERRO: Numero de cartoes deve estar entre 1 e 500!" << endl;
        return 1;
    }
    
    //inicializar gerador aleatório
    srand(time(NULL));
    
    //intervalos para cada coluna B-I-N-G-O
    int minimos[5] = {1, 21, 41, 61, 81};
    int maximos[5] = {20, 40, 60, 80, 100};
    
    cout << "A gerar " << num_cartoes << " cartoes de Bingo..." << endl;
    
    //gerar cada cartão
    for (int cartao_num = 1; cartao_num <= num_cartoes; cartao_num++) {
        //criar nome do ficheiro
        string nome_ficheiro = "cartao" + to_string(cartao_num) + ".txt";
        
        //abrir ficheiro
        ofstream arquivo(nome_ficheiro);
        
        if (!arquivo.is_open()) {
            cout << "Erro ao criar ficheiro: " << nome_ficheiro << endl;
            continue;
        }
        
        // Matriz para o cartão
        int cartao[5][5];
        
        //gerar números para cada coluna
        for (int coluna = 0; coluna < 5; coluna++) {
            vector<int> numeros_coluna;
            
            //gerar 5 números únicos para esta coluna
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
            
            //colocar números na matriz
            for (int linha = 0; linha < 5; linha++) {
                cartao[linha][coluna] = numeros_coluna[linha];
            }
        }
        
        //escrever cartão no ficheiro
        arquivo << "Cartao de Bingo #" << cartao_num << "\n\n";
        arquivo << " B    I    N    G    O\n";
        arquivo << "----------------------\n";
        
        for (int linha = 0; linha < 5; linha++) {
            for (int coluna = 0; coluna < 5; coluna++) {
                //espaço livre no centro
                if (coluna == 2 && linha == 2) {
                    arquivo << " ** ";
                } else {
                    //formatar com 2 dígitos
                    if (cartao[linha][coluna] < 10) {
                        arquivo << "  " << cartao[linha][coluna] << " ";
                    } else {
                        arquivo << " " << cartao[linha][coluna] << " ";
                    }
                }
            }
            arquivo << endl;
        }
        
        arquivo.close();
        cout << "Cartao " << cartao_num << " -> " << nome_ficheiro << endl;
    }
    
    cout << "\n----------------------------------------" << endl;
    cout << "GERACAO CONCLUIDA!" << endl;
    cout << "Total de cartoes gerados: " << num_cartoes << endl;
    cout << "Ficheiros criados: cartao1.txt a cartao" << num_cartoes << ".txt" << endl;
    
    return 0;
}n";
    cout << "cartao1.txt, cartao2.txt, ... cartao" << num_cartoes << ".txt\n";
    
    return 0;
}
