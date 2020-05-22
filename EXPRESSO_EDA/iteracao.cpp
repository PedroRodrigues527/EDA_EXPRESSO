#include "iteracao.h"

void menuOpcoes() //paulo drumond 18/05
{
    int num_opcao; // opção de 1 a 5 escolhida pelo utilizador
   
    cout << "1.Remover passageiros nos autocarros." << endl;
    cout << "2.Remover passageiros em fila de espera" << endl;
    cout << "3.Apresentar bilhetes por paragem" << endl;
    cout << "4.Alterar motorista" << endl;
    cout << "5.Remover bilhete da paragem" << endl;
    cout << "-- Introduza o numero da opção a que pretende aceder --" << endl;

    cin >> num_opcao;

    switch (num_opcao)
    {

    case 1:
        cout << "Escolheu a opção: 1.Remover passageiros nos autocarros." << endl;
        break;
    case 2:
        cout << "Escolheu a opção: 2.Remover passageiros em fila de espera" << endl;
        break;
    case 3:
        cout << "Escolheu a opção : 3.Apresentar bilhetes por paragem" << endl;
        break;
    case 4:
        cout << "Escolheu a opção: 4.Alterar motorista" << endl;
        break;
    case 5:
        cout << "Escolheu a opção: 5.Remover bilhete da paragem" << endl;

    default:
        break;
    }
}

void cria_autocarro(string pnomes[NUM_P_NOMES], string unomes[NUM_U_NOMES]) //Cupido e Pedro 18/05
{
    // 0123456789 ABCDEF
    char hexadecimal[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    char matricula[4];
    for (int i = 0; i < 4; i++) {
        matricula[i] = hexadecimal[rand() % 16];
    }

    for (int j = 0; j < 4; j++) {
        cout << matricula[j];
    }

    //Motorista
    string PrimeiroNomeMotorista = pnomes[rand() % NUM_P_NOMES];
    string UltimoNomeMotorista = unomes[rand() % NUM_U_NOMES];

    //capacidade
    int capacidadepassageiros = rand() % 6 + 5; //de 5 a 10

    //teste
    //cout << " " << PrimeiroNomeMotorista << " " << UltimoNomeMotorista << " " << capacidadepassageiros << endl;
}
