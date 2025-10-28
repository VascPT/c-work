//Codigo feito por Vasco Franco e Bernardo Teves
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

// --- Constantes do jogo ---
const int N = 10; // Tamanho do tabuleiro 10x10
const int NUM_SHIPS = 5; // Número de barcos
const int SHIP_SIZES[NUM_SHIPS] = {5,4,3,3,2}; // Tamanhos dos barcos

// --- Estrutura que representa um barco ---
struct Ship {
    int size;        // Tamanho do barco
    bool horizontal; // Orientação: true = horizontal, false = vertical
    int row;         // Linha inicial do barco (0 a 9)
    int col;         // Coluna inicial do barco (0 a 9)
    bool sunk = false; // Se o barco foi afundado
};

// --- Função para limpar o terminal ---
void clear(){
    #ifdef WIN32
        system("CLS");
    #else
        system("clear");
    #endif
}

// --- Inicializa o tabuleiro com '.' (água) ---
void initBoard(char board[N][N]){
    for(int r=0;r<N;r++)
        for(int c=0;c<N;c++)
            board[r][c]='.';
}

// --- Imprime o tabuleiro ---
void printBoard(char board[N][N], bool showShips){
    cout<<"   A B C D E F G H I J\n"; // Cabeçalho das colunas
    for(int r=0;r<N;r++){
        cout<<(r+1<10?" ":"")<<r+1<<" "; // Cabeçalho das linhas
        for(int c=0;c<N;c++){
            char ch=board[r][c];
            if(!showShips && ch=='S') ch='.'; // Não mostrar barcos do inimigo
            cout<<ch<<" ";
        }
        cout<<"\n";
    }
}

// --- Tenta colocar um barco no tabuleiro ---
bool placeShip(char board[N][N], Ship ship){
    if(ship.horizontal){
        if(ship.col+ship.size>N) return false; // Limite da borda
        for(int i=0;i<ship.size;i++) if(board[ship.row][ship.col+i]!='.') return false; // Checa colisão
        for(int i=0;i<ship.size;i++) board[ship.row][ship.col+i]='S'; // Coloca barco
    } else {
        if(ship.row+ship.size>N) return false;
        for(int i=0;i<ship.size;i++) if(board[ship.row+i][ship.col]!='.') return false;
        for(int i=0;i<ship.size;i++) board[ship.row+i][ship.col]='S';
    }
    return true;
}

// --- Checa se um barco está afundado ---
bool isSunk(Ship ship, char board[N][N]){
    if(ship.horizontal){
        for(int i=0;i<ship.size;i++) if(board[ship.row][ship.col+i]!='X') return false;
    } else {
        for(int i=0;i<ship.size;i++) if(board[ship.row+i][ship.col]!='X') return false;
    }
    return true;
}

// --- Verifica se todos os barcos foram destruídos ---
bool allShipsDestroyed(char board[N][N]){
    for(int r=0;r<N;r++)
        for(int c=0;c<N;c++)
            if(board[r][c]=='S') return false;
    return true;
}

// --- Colocação dos barcos do jogador ---
void playerPlaceShips(char board[N][N], Ship playerShips[NUM_SHIPS]){
    for(int i=0;i<NUM_SHIPS;i++){
        Ship ship; ship.size=SHIP_SIZES[i]; bool placed=false;
        while(!placed){
            printBoard(board,true); // Mostra tabuleiro atual

            // --- Escolha da direção ---
            char dir; 
            while(true){
                cout<<"\nColoca o barco de tamanho "<<ship.size<<"\nDireção (h/v): ";
                cin>>dir; dir=tolower(dir);
                if(dir=='h'||dir=='v') break;
                clear(); printBoard(board,true);
                cout<<"Direção inválida! Tenta novamente.\n";
            }
            ship.horizontal=(dir=='h');

            // --- Escolha das coordenadas iniciais ---
            char col; int row;
            while(true){
                cout<<"Coordenadas iniciais (ex: A5): ";
                cin>>col>>row;
                if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); clear(); printBoard(board,true); cout<<"Entrada inválida! Tenta novamente.\n"; continue;}
                col=toupper(col);
                if(col>='A' && col<='J' && row>=1 && row<=10) break;
                clear(); printBoard(board,true); cout<<"Coordenadas inválidas! Tenta novamente.\n";
            }
            ship.row=row-1; ship.col=col-'A';

            // --- Verifica conflito com outros barcos ---
            bool conflict=false;
            if(ship.horizontal){for(int j=0;j<ship.size;j++) if(board[ship.row][ship.col+j]=='S') conflict=true;}
            else {for(int j=0;j<ship.size;j++) if(board[ship.row+j][ship.col]=='S') conflict=true;}
            if(conflict){ clear(); printBoard(board,true); cout<<"Já existe um barco nesse local! Tenta novamente.\n"; continue;}

            placed=placeShip(board,ship);
            if(!placed){  printBoard(board,true); clear(); cout<<"Não é possível colocar o barco aqui!\n"; continue;}
            playerShips[i] = ship; // Salva barco no array
            clear();
        }
    }
}

// --- Colocação dos barcos do CPU ---
void cpuPlaceShips(char board[N][N], Ship cpuShips[NUM_SHIPS]){
    srand(time(0));
    for(int i=0;i<NUM_SHIPS;i++){
        Ship ship; ship.size=SHIP_SIZES[i]; bool placed=false;
        while(!placed){
            ship.horizontal=rand()%2;
            ship.row=rand()%N; ship.col=rand()%N;
            placed=placeShip(board,ship);
        }
        cpuShips[i] = ship; // Salva barco no array
    }
}

int main(){
    clear();
    char playerBoard[N][N], cpuBoard[N][N], cpuView[N][N];
    Ship playerShips[NUM_SHIPS], cpuShips[NUM_SHIPS]; // Arrays fixos para os barcos

    initBoard(playerBoard); initBoard(cpuBoard); initBoard(cpuView);

    cout<<"==== BATALHA NAVAL ====\n\n";
    cout << endl << "Prima ENTER para jogar! ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    clear();
    cout<<"Primeiro, coloca os teus barcos!\n\n";
    playerPlaceShips(playerBoard,playerShips);
    cpuPlaceShips(cpuBoard,cpuShips);
    clear();

    cout<<"Os barcos foram colocados! Prima ENTER para começar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); cin.get();

    srand(time(0));
    while(true){
        clear();
        cout<<"=== O teu tabuleiro ===\n"; printBoard(playerBoard,true);
        cout<<"\n=== Ataques ao inimigo ===\n"; printBoard(cpuView,true);

        // --- Turno do jogador ---
        char col; int row;
        /*while(true){
            cout<<"\nEscolhe onde atacar (ex: B7): ";
            cin>>col>>row;
            if(cin.fail()){ cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); clear(); cout<<"Entrada inválida!\n"; continue;}
            col=toupper(col);
            if(col<'A'||col>'J'||row<1||row>10){ clear(); cout<<"Coordenadas inválidas!\n"; continue;}
            int r=row-1, c=col-'A';
            if(cpuView[r][c]=='X'||cpuView[r][c]=='O'){ clear(); cout<<"Já atacaste nesse local!\n"; continue;}
            break;
        }*/
        while (true) {
            clear(); // limpa só no início de cada iteração
            cout << "=== O teu tabuleiro ===\n";
            printBoard(playerBoard, true);
            cout << "\n=== Ataques ao inimigo ===\n";
            printBoard(cpuView, true); // usa false se quiseres esconder 'S'
        
            cout << "\nEscolhe onde atacar (ex: B7): ";
            cin >> col >> row;
        
            // 1) Falha de leitura (ex: escreveu só 'B' ou texto inválido)
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa resto da linha
                cout << "\nEntrada inválida! Usa formato como B7.\n";
                cout << "Prima ENTER para continuar...";
                cin.get(); // espera 1 ENTER
                continue;  // volta a mostrar os tabuleiros
            }
        
            col = toupper(col);
        
            // 2) Fora dos limites
            if (col < 'A' || col > 'J' || row < 1 || row > 10) {
                // limpa newline remanescente do '>>'
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nCoordenadas inválidas! Usa A-J e 1-10.\n";
                cout << "Prima ENTER para continuar...";
                cin.get();
                continue;
            }
        
            int r = row - 1;
            int c = col - 'A';
        
            // 3) Já foi jogado
            if (cpuView[r][c] == 'X' || cpuView[r][c] == 'O') {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nJá atacaste " << col << row << "! Escolhe outra célula.\n";
                cout << "Prima ENTER para continuar...";
                cin.get();
                continue;
            }
        
            // Input válido → sai do loop para prosseguir o turno
            // (aqui NÃO limpamos o ecrã; a jogada segue no código seguinte)
            break;
        }

        int r=row-1, c=col-'A';
        if(cpuBoard[r][c]=='S'){ cpuBoard[r][c]='X'; cpuView[r][c]='X'; cout<<"Acertaste no barco!\n";}
        else { cpuBoard[r][c]='O'; cpuView[r][c]='O'; cout<<"Falhaste! Água!\n"; }

        // --- Verifica se afundou algum barco do CPU ---
        for(int i=0;i<NUM_SHIPS;i++){
            if(!cpuShips[i].sunk && isSunk(cpuShips[i],cpuBoard)){
                cpuShips[i].sunk=true;
                cout<<"Afundaste um barco inimigo de tamanho "<<cpuShips[i].size<<"!\n";
            }
        }

        if(allShipsDestroyed(cpuBoard)){ cout<<"\nParabéns! Afundaste todos os barcos inimigos!\n"; break;}

        // --- Turno do computador ---
        int rr, cc;
        do{ rr=rand()%N; cc=rand()%N; }while(playerBoard[rr][cc]=='X'||playerBoard[rr][cc]=='O');
        if(playerBoard[rr][cc]=='S'){ playerBoard[rr][cc]='X'; cout<<"\nO computador acertou em "<<char('A'+cc)<<rr+1<<"\n";}
        else { playerBoard[rr][cc]='O'; cout<<"\nO computador falhou em "<<char('A'+cc)<<rr+1<<"\n"; }

        // --- Verifica se afundou algum barco do jogador ---
        for(int i=0;i<NUM_SHIPS;i++){
            if(!playerShips[i].sunk && isSunk(playerShips[i],playerBoard)){
                playerShips[i].sunk=true;
                cout<<"O computador afundou o teu barco de tamanho "<<playerShips[i].size<<"!\n";
            }
        }

        if(allShipsDestroyed(playerBoard)){ cout<<"\nPerdeste! O computador afundou todos os teus barcos.\n"; break;}

        cout<<"\nPrima ENTER para continuar..."; cin.ignore(numeric_limits<streamsize>::max(), '\n'); cin.get();
    }

    cout<<"\nFim do jogo.\n";
    return 0;
}
