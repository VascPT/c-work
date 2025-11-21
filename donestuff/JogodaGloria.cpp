// Código feito por Vasco Franco
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
//#include <windows.h>
#include <limits>
#include <string>
using namespace std;

void clear(){
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

const int N = 30;                 // 30 casas, índices 0..29
const int Perde_Jogada     = 4;   // casa 4
const int Volta_tres_casas = 10;  // casa 10
const int Avanca_tres_casas= 5;   // casa 5
const int Joga_novament    = 15;  // casa 15
const int Espera_passg     = 20;  // casa 20

string nomeP1, nomeP2;

// ---------- Tabuleiro ----------
void iniciarCasas(string casas[N]){
    for (int i=0; i<N; i++) casas[i] = "-";
    casas[Perde_Jogada     -1] = "PJ"; // Perde a vez
    casas[Volta_tres_casas -1] = "V3"; // Volta 3
    casas[Avanca_tres_casas-1] = "A3"; // Avança 3
    casas[Joga_novament    -1] = "JN"; // Joga novamente
    casas[Espera_passg     -1] = "EP"; // Espera passagem
}

// imprime cabeçalho 1..30 e a linha das casas (P1/P2/P*)
void imprimirCasas(const string casas[N], int posP1, int posP2){
    // cabeçalho números
    for (int i=0; i<N; i++)
        cout << (i+1<10 ? " " : "") << i+1 << " ";
    cout << "\n";

    // linha das casas
    for (int i=0; i<N; i++){
        string cell = casas[i];
        bool p1 = (posP1 == i);
        bool p2 = (posP2 == i);
        if (p1 && p2)      cell = "P*";
        else if (p1)       cell = "P1";
        else if (p2)       cell = "P2";
        if (cell.size()==1) cell = " " + cell; // largura fixa 2
        cout << cell << " ";
    }
    cout << "\n\n";
}
int rolarDado(){
    return 1 + (rand() % 6);
}


int limitarCasa(int idx){//limita o jogador ao tabuleiro
    if (idx < 0) idx = 0;
    if (idx > N-1) idx = N-1;
    return idx;
}
bool chegouAoFim(int pos){ return pos >= N-1; }

// Aplica o efeito da casa onde o jogador parou.
// Devolve flags de estado por referência.
void aplicarCasaEspecial(
    int &posJog, int posOutro,
    bool &perdeVez, bool &extraTurno, bool &esperaPassagem
){
    int casa = posJog + 1; // converter índice 0..29 -> casa 1..30
    perdeVez = false;
    extraTurno = false;
    // esperaPassagem mantém-se se já estava true (só será limpo quando ultrapassado)
    // Aqui só a ativamos se for EP válida.

    if (casa == Perde_Jogada){
        perdeVez = true;
    }
    else if (casa == Volta_tres_casas){
        posJog = limitarCasa(posJog - 3);
    }
    else if (casa == Avanca_tres_casas){
        posJog = limitarCasa(posJog + 3);
    }
    else if (casa == Joga_novament){
        extraTurno = true; // joga outra vez já
    }
    else if (casa == Espera_passg){
        // Só ativa se houver jogador atrás (isto é, o outro está numa posição menor)
        if (posOutro < posJog) {
            esperaPassagem = true; // fica à espera até ser ultrapassado
        }
        // Se não houver ninguém atrás, a casa é “invalida” → efeito ignorado
    }
}

// Mostra estado curto no topo
void mostrarEstado(const string casas[N], int posP1, int posP2, const string& msg){
    clear();
    cout << msg << "\n\n";
    imprimirCasas(casas, posP1, posP2);
}

int main(){
    clear();

    cout << "Selecione o nome para o Player 1: ";
    cin >> nomeP1;
    cout << "\nOla " << nomeP1 << "! Vamos avancar para o Player 2...\n";
#ifdef _WIN32
    Sleep(1200);
#else
    sleep(1);
#endif
    clear();

    cout << "Selecione o nome para o Player 2: ";
    cin >> nomeP2;
    cout << "\nOla " << nomeP2 << "! Prima ENTER para comecar o jogo.";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    // semente para o dado
    srand((unsigned)time(nullptr));

    string casas[N];
    iniciarCasas(casas);

    int posP1 = 0, posP2 = 0;          // índices 0..29
    bool skipP1 = false, skipP2 = false;               // perde vez
    bool waitP1 = false, waitP2 = false;               // espera passagem
    bool vezP1 = true;                                 // começa P1

    mostrarEstado(casas, posP1, posP2, "Inicio do jogo!");

    // Loop principal
    while (true){
        // Seleciona jogador atual
        string nomeAtual   = vezP1 ? nomeP1 : nomeP2;
        int    &posAtual   = vezP1 ? posP1  : posP2;
        int    posOutro    = vezP1 ? posP2  : posP1;
        bool   &skipAtual  = vezP1 ? skipP1 : skipP2;
        bool   &waitAtual  = vezP1 ? waitP1 : waitP2;

        // Espera passagem: só joga quando for ultrapassado
        if (waitAtual){
            if (posOutro > posAtual){
                waitAtual = false; // foi ultrapassado -> volta a poder jogar
            } else {
                mostrarEstado(casas, posP1, posP2,
                    nomeAtual + " esta a esperar ser ultrapassado... (EP)");
#ifdef _WIN32
                Sleep(1200);
#else
                sleep(1);
#endif
                vezP1 = !vezP1; // passa a vez
                continue;
            }
        }

        // Perdeu a vez: salta este turno
        if (skipAtual){
            skipAtual = false; // cumpre a penalização
            mostrarEstado(casas, posP1, posP2, nomeAtual + " perdeu a vez (PJ).");
#ifdef _WIN32
            Sleep(1200);
#else
            sleep(1);
#endif
            vezP1 = !vezP1;
            continue;
        }

        // Jogada normal
        cout << nomeAtual << ", prima ENTER para rolar o dado...";
        cin.get();

        int d = rolarDado();
        mostrarEstado(casas, posP1, posP2, nomeAtual + " rolou " + to_string(d) + "!");
#ifdef _WIN32
        Sleep(800);
#else
        sleep(1);
#endif

        posAtual = limitarCasa(posAtual + d);
        if (chegouAoFim(posAtual)){
            mostrarEstado(casas, posP1, posP2, nomeAtual + " chegou a casa 30! FIM DE JOGO");
            cout << "Vencedor: " << nomeAtual << "\n";
            break;
        }

        // aplicar efeito da casa onde parou
        bool perdeVez=false, extraTurno=false;
        aplicarCasaEspecial(posAtual, posOutro, perdeVez, extraTurno,
                            vezP1 ? waitP1 : waitP2);

        // se mexeu por -3/+3, pode ter chegado ao fim ou voltado ao início
        if (chegouAoFim(posAtual)){
            mostrarEstado(casas, posP1, posP2, nomeAtual + " chegou a casa 30! FIM DE JOGO");
            cout << "Vencedor: " << nomeAtual << "\n";
            break;
        }

        // Mostrar o estado após aplicar a casa
        {
            string efeito = "";
            int casa = posAtual + 1;
            if (casa == Perde_Jogada)          efeito = " (PJ: perde a proxima vez)";
            else if (casa == Volta_tres_casas)  efeito = " (V3: recuou 3)";
            else if (casa == Avanca_tres_casas) efeito = " (A3: avancou 3)";
            else if (casa == Joga_novament)     efeito = " (JN: joga novamente)";
            else if (casa == Espera_passg) {
                if ((vezP1?waitP1:waitP2)) efeito = " (EP: vai esperar ser ultrapassado)";
                else                        efeito = " (EP sem efeito: ninguem atras)";
            }
            mostrarEstado(casas, posP1, posP2, nomeAtual + " esta na casa " + to_string(posAtual+1) + efeito);
#ifdef _WIN32
            Sleep(800);
#else
            sleep(1);
#endif
        }

        // aplicar flags ao jogador certo
        if (perdeVez)  (vezP1 ? skipP1 : skipP2) = true;

        // Decidir próxima vez
        if (extraTurno){
            // mantém a mesma vez
            continue;
        } else {
            vezP1 = !vezP1; // alterna jogador
        }
    }

    cout << "\nObrigado por jogar!\n";
    return 0;
}
