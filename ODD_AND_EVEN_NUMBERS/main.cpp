#include "library.h"
#include <ctime>
using namespace std;

int main()
{
    int  retry = -2;
    do
    {
        setlocale(LC_ALL, "RUS");
        srand(time(NULL));
        int n = -2, RandRows, RandCol, CountsRemainsPlaces, wrong1 = 3, wrong2 = 3, side = -2, choose = -2;
        int  h1 = -2, h2 = -2;
        int step;
        int CheckOnePlayer = 0, CheckTwoPlayers = 0;
        cout << "������ �������� ���� �������� ����� ������ (������ N x N)." << endl << "����� ������, ��������� ������ ���, ��������������� ����� ���������." << endl;
        do {
            cout << "����������� �� ����: [2;10]." << endl << endl;
            cout << "������� ������ �������� ����: ";
            cin >> n;
        } while (n > 10 || n < 2);
        do {
            cout << "�������� �����:\n\t1 - ���� �����.\n\t2 - ��� ������.\n";
            cin >> choose;
        } while (choose != 1 && choose != 2);
        if (choose == 1)
        {
            do {
                cout << "���� �� ������ ������ �� ��������, ������� '1'.\n���� �� ������ ������ �� ������, ������� '2'.\n";
                cin >> side;
            } while (side != 1 && side != 2);
        }
        cout << "\t\t***���� ��������***" << endl << endl << endl;
        CountsRemainsPlaces = n * n;
        step = rand() % 2;
        int* game = (int*)malloc(sizeof(int) * n * (n + 1));
        int* UniqNumbers = (int*)malloc(sizeof(int) * n * (n + 1));
        if (choose == 1) CheckOnePlayer = OnePlayer(UniqNumbers, game, n, RandRows, RandCol, wrong1, wrong2);
        if (choose == 2) CheckTwoPlayers = TwoPlayers(UniqNumbers, game, n, RandRows, RandCol, wrong1, wrong2);
        if ((wrong1 != 0) && (wrong2 != 0) && (not(CheckOnePlayer)) && (not(CheckTwoPlayers)))
        {
            cout << "�������, ���������� ����������� ����: " << endl;
            OutputReadyGame(game, n);
            AmountsRowsColumns(game, n, side, choose);
        }
        cout << endl << endl << "\t\t***���� ���������***" << endl << endl << endl;
        do
        {
            cout << endl << endl << "������� ������� ��� ���?\n������� '1', ����� ������� ��� ���.\n������� '2', ����� ��������� ����.\n";
            cin >> retry;
        } while (retry != 1 && retry != 2);
    } while (retry == 1);

}



