#include "iteracao.h"

void menuOpcoes() //paulo drumond 18/05
{
    int num_opcao; // op��o de 1 a 5 escolhida pelo utilizador
   
    cout << "1.Remover passageiros nos autocarros." << endl;
    cout << "2.Remover passageiros em fila de espera" << endl;
    cout << "3.Apresentar bilhetes por paragem" << endl;
    cout << "4.Alterar motorista" << endl;
    cout << "5.Remover bilhete da paragem" << endl;
    cout << "-- Introduza o numero da op��o a que pretende aceder --" << endl;

    cin >> num_opcao;

    switch (num_opcao)
    {

    case 1:
        cout << "Escolheu a op��o: 1.Remover passageiros nos autocarros." << endl;
        break;
    case 2:
        cout << "Escolheu a op��o: 2.Remover passageiros em fila de espera" << endl;
        break;
    case 3:
        cout << "Escolheu a op��o : 3.Apresentar bilhetes por paragem" << endl;
        break;
    case 4:
        cout << "Escolheu a op��o: 4.Alterar motorista" << endl;
        break;
    case 5:
        cout << "Escolheu a op��o: 5.Remover bilhete da paragem" << endl;

    default:
        break;
    }
}
