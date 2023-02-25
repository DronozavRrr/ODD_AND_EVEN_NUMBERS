#include "library.h"
using namespace std;

int IsUniqNumber(int* UniqNumbers, int n, int RandRows, int RandCol)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (UniqNumbers[RandRows * n + RandCol] == i * n + j) return 0;
        }
    }
    return 1;
}

int TwoPlayers(int* UniqNumbers, int* game, int& n, int& RandRows, int& RandCol, int& wrong1, int& wrong2)
{
    int CountsRemainsPlaces;
    int h1 = -2, h2 = -2;
    int step;
    CountsRemainsPlaces = n * n;
    step = rand() % 2;
    clock_t start = clock();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            start = clock();
            if (wrong2 != 0 && wrong1 != 0) {
                step++;
                RandRows = rand() % n + 1;
                RandCol = rand() % n + 1;
                if (IsUniqNumber(UniqNumbers, n, RandRows, RandCol))
                {
                    UniqNumbers[RandRows * n + RandCol] = RandRows * n + RandCol;
                    if (step % 2 == 0)
                    {
                        cout << endl << "�� ����� ������ 5 ������, � ��������� ������ �� ����������." << endl;
                        cout << "��� ������� ������(�������):" << endl;

                        do {
                            cout << "������� ���� 0, ���� 1: ";
                            while ((!_kbhit()))
                            {
                                if (((clock() - start) / CLOCKS_PER_SEC) >= 5)
                                {
                                    cout << endl << "� ���������, ���� ����� �������, � �� ���������." << endl;
                                    return 1;
                                }
                            }
                            cin >> h2;
                            if (h2 != 0 && h2 != 1)
                            {
                                --wrong2;
                                cout << "� ��� �������� " << wrong2 << " �������, ����� ������ ���������� ��������, ����� �� ������������� ����������." << endl;

                            }
                            if (wrong2 == 0)
                            {
                                cout << "�� ��������� ��-�� �������� ���������� ����� ������������ ��������" << endl;
                                break;
                            }
                        } while (h2 != 0 && h2 != 1);
                        if (wrong2 != 0 && wrong1 != 0)
                        {
                            cout << endl << "������, � ������� ���� �������� ��������: " << "[" << RandRows << "][" << RandCol << "] " << endl << "������� ��������� �����: " << --CountsRemainsPlaces << endl;
                            game[RandRows * n + RandCol] = h2;
                        }
                    }
                    else
                    {
                        cout << endl << "�� ����� ������ 5 ������, � ��������� ������ �� ����������." << endl;
                        cout << "��� ������� ������(���������):" << endl;

                        do {
                            cout << "������� ���� 0, ���� 1: ";
                            while ((!_kbhit()))
                            {
                                if (((clock() - start) / CLOCKS_PER_SEC) >= 5)
                                {
                                    cout << endl << "� ���������, ���� ����� �������, � �� ���������." << endl;
                                    return 1;
                                }
                            }
                            cin >> h1;
                            if (h1 != 0 && h1 != 1)
                            {
                                --wrong1;
                                cout << "� ��� �������� " << wrong1 << " �������, ����� ������ ���������� ��������, ����� �� ������������� ����������." << endl;
                            }
                            if (wrong1 == 0)
                            {
                                cout << "�� ��������� ��-�� �������� ���������� ����� ������������ ��������" << endl;
                                break;
                            }
                        } while (h1 != 0 && h1 != 1);
                        if (wrong2 != 0 && wrong1 != 0)
                        {
                            cout << endl << "������, � ������� ���� �������� ��������: " << "[" << RandRows << "][" << RandCol << "] " << endl << "������� ��������� �����: " << --CountsRemainsPlaces << endl;
                            game[RandRows * n + RandCol] = h1;
                        }
                    }
                }
                else
                {
                    while (not(IsUniqNumber(UniqNumbers, n, RandRows, RandCol)))
                    {
                        RandRows = rand() % n + 1;
                        RandCol = rand() % n + 1;
                    }
                    UniqNumbers[RandRows * n + RandCol] = RandRows * n + RandCol;
                    if (step % 2 == 0)
                    {
                        cout << endl << "�� ����� ������ 5 ������, � ��������� ������ �� ����������." << endl;
                        cout << "��� ������� ������(�������):" << endl;

                        do {
                            cout << "������� ���� 0, ���� 1: ";
                            while ((!_kbhit()))
                            {
                                if (((clock() - start) / CLOCKS_PER_SEC) >= 5)
                                {
                                    cout << endl << "� ���������, ���� ����� �������, � �� ���������." << endl;
                                    return 1;
                                }
                            }
                            cin >> h2;
                            if (h2 != 0 && h2 != 1)
                            {
                                --wrong2;
                                cout << "� ��� �������� " << wrong2 << " �������, ����� ������ ���������� ��������, ����� �� ������������� ����������." << endl;
                            }
                            if (wrong2 == 0)
                            {
                                cout << "�� ��������� ��-�� �������� ���������� ����� ������������ ��������" << endl;
                                break;
                            }
                        } while (h2 != 0 && h2 != 1);
                        if (wrong2 != 0 && wrong1 != 0)
                        {
                            cout << endl << "������, � ������� ���� �������� ��������: " << "[" << RandRows << "][" << RandCol << "] " << endl << "������� ��������� �����: " << --CountsRemainsPlaces << endl;
                            game[RandRows * n + RandCol] = h2;
                        }
                    }
                    else
                    {
                        cout << endl << "�� ����� ������ 5 ������, � ��������� ������ �� ����������." << endl;
                        cout << "��� ������� ������(���������):" << endl;

                        do {
                            cout << "������� ���� 0, ���� 1: ";
                            while ((!_kbhit()))
                            {
                                if (((clock() - start) / CLOCKS_PER_SEC) >= 5)
                                {
                                    cout << endl << "� ���������, ���� ����� �������, � �� ���������." << endl;
                                    return 1;
                                }
                            }
                            cin >> h1;
                            if (h1 != 0 && h1 != 1)
                            {
                                --wrong1;
                                cout << "� ��� �������� " << wrong1 << " �������, ����� ������ ���������� ��������, ����� �� ������������� ����������." << endl;
                            }
                            if (wrong1 == 0)
                            {
                                cout << "�� ��������� ��-�� �������� ���������� ����� ������������ ��������" << endl;
                                break;
                            }
                        } while (h1 != 0 && h1 != 1);
                        if (wrong2 != 0 && wrong1 != 0)
                        {
                            cout << endl << "������, � ������� ���� �������� ��������: " << "[" << RandRows << "][" << RandCol << "] " << endl << "������� ��������� �����: " << --CountsRemainsPlaces << endl;
                            game[RandRows * n + RandCol] = h1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}


int OnePlayer(int* UniqNumbers, int* game, int& n, int& RandRows, int& RandCol, int& wrong1, int& wrong2)
{
    int CountsRemainsPlaces;
    int h1 = -2, h2 = -2;
    int step;
    CountsRemainsPlaces = n * n;
    clock_t start = clock();
    step = rand() % 2;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            start = clock();
            if (wrong2 != 0 && wrong1 != 0) {
                step++;
                RandRows = rand() % n + 1;
                RandCol = rand() % n + 1;
                if (IsUniqNumber(UniqNumbers, n, RandRows, RandCol))
                {
                    UniqNumbers[RandRows * n + RandCol] = RandRows * n + RandCol;
                    if (step % 2 == 0)
                    {
                        cout << endl << "�� ����� ������ 5 ������, � ��������� ������ �� ����������." << endl;
                        cout << "��� ���:" << endl;

                        do {
                            cout << "������� ���� 0, ���� 1: ";
                            while ((!_kbhit()))
                            {
                                if (((clock() - start) / CLOCKS_PER_SEC) >= 5)
                                {
                                    cout << endl << "� ���������, ���� ����� �������, � �� ���������." << endl;
                                    return 1;
                                }
                            }
                            cin >> h2;
                            if (h2 != 0 && h2 != 1)
                            {
                                --wrong2;
                                cout << "� ��� �������� " << wrong2 << " �������, ����� ������ ���������� ��������, ����� �� ������������� ����������." << endl;

                            }
                            if (wrong2 == 0)
                            {
                                cout << "�� ��������� ��-�� �������� ���������� ����� ������������ ��������" << endl;
                                break;
                            }
                        } while (h2 != 0 && h2 != 1);
                        if (wrong2 != 0 && wrong1 != 0)
                        {
                            cout << "������, � ������� ���� �������� ��������: " << "[" << RandRows << "][" << RandCol << "] " << endl << "������� ��������� �����: " << --CountsRemainsPlaces << endl;
                            game[RandRows * n + RandCol] = h2;
                        }
                    }
                    else
                    {
                        cout << endl << "��� ���������: ";
                        if (wrong2 != 0 && wrong1 != 0)
                        {
                            game[RandRows * n + RandCol] = rand() % 2;
                            cout << game[RandRows * n + RandCol] << endl << "������, � ������� ���� �������� ��������: " << "[" << RandRows << "][" << RandCol << "]" << endl << "������� ��������� �����: " << --CountsRemainsPlaces << endl;

                        }
                    }
                }
                else
                {
                    while (not(IsUniqNumber(UniqNumbers, n, RandRows, RandCol)))
                    {
                        RandRows = rand() % n + 1;
                        RandCol = rand() % n + 1;
                    }
                    UniqNumbers[RandRows * n + RandCol] = RandRows * n + RandCol;
                    if (step % 2 == 0)
                    {
                        cout << endl << "�� ����� ������ 5 ������, � ��������� ������ �� ����������." << endl;
                        cout << "��� ���: " << endl;

                        do {
                            cout << "������� ���� 0, ���� 1: ";
                            while ((!_kbhit()))
                            {
                                if (((clock() - start) / CLOCKS_PER_SEC) >= 5)
                                {
                                    cout << endl << "� ���������, ���� ����� �������, � �� ���������." << endl;
                                    return 1;
                                }
                            }
                            cin >> h2;
                            if (h2 != 0 && h2 != 1)
                            {
                                --wrong2;
                                cout << "� ��� �������� " << wrong2 << " �������, ����� ������ ���������� ��������, ����� �� ������������� ����������." << endl;
                            }
                            if (wrong2 == 0)
                            {
                                cout << "�� ��������� ��-�� �������� ���������� ����� ������������ ��������" << endl;
                                break;
                            }
                        } while (h2 != 0 && h2 != 1);
                        if (wrong2 != 0 && wrong1 != 0)
                        {
                            cout << "������, � ������� ���� �������� ��������: " << "[" << RandRows << "][" << RandCol << "] " << endl << "������� ��������� �����: " << --CountsRemainsPlaces << endl;
                            game[RandRows * n + RandCol] = h2;
                        }
                    }
                    else
                    {
                        cout << endl << "��� ���������: ";
                        if (wrong2 != 0 && wrong1 != 0)
                        {
                            game[RandRows * n + RandCol] = rand() % 2;
                            cout << game[RandRows * n + RandCol] << endl << "������, � ������� ���� �������� ��������: " << "[" << RandRows << "][" << RandCol << "]" << endl << "������� ��������� �����: " << --CountsRemainsPlaces << endl;

                        }
                    }
                }
            }

        }
    }
    return 0;
}


void OutputReadyGame(int* game, int n)
{

    for (int i = 1; i <= n; ++i)
    {

        for (int j = 1; j <= n; ++j)
        {
            cout << "|";
            cout << " " << game[i * n + j] << " ";
        }
        cout << "|";
        cout << endl;

    }
    cout << endl;

}


void AmountsRowsColumns(int* game, int n, int side, int choose)
{
    int swap[10][10];
    int SummRows, SummCol, MainDiag = 0, SecondaryDiag = 0, ch = -1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            swap[i][j] = game[i * n + j];
        }
    }
    int chet = 0, nechet = 0;
    for (int i = 1; i <= n; ++i)
    {
        MainDiag += swap[i][i];
        SecondaryDiag += swap[i][n - i + 1];
        SummRows = 0;
        SummCol = 0;
        for (int j = 1; j <= n; ++j)
        {
            ch++;

            SummRows += swap[i][j];
            SummCol += swap[j][i];
        }
        if (SummRows % 2 == 0) chet++;
        else nechet++;
        if (SummCol % 2 == 0) chet++;
        else nechet++;
    }
    if (MainDiag % 2 == 0) chet++;
    else nechet++;
    if (SecondaryDiag % 2 == 0) chet++;
    else nechet++;
    cout << "���������� ������ ���� - " << chet << endl << "���������� �������� ���� - " << nechet << endl << endl << endl;
    if (side != -2 && choose == 1)
    {
        if ((side == 1) && (nechet > chet))
        {
            cout << "�����������, �� ��������!" << endl;
        }
        if ((side == 1) && (nechet < chet))
        {
            cout << "� ���������, �� ���������." << endl;
        }
        if ((side == 2) && (nechet > chet))
        {
            cout << "� ���������, �� ���������." << endl;
        }
        if ((side == 2) && (nechet < chet))
        {
            cout << "�����������, �� ��������!" << endl;
        }
        if (chet == nechet)
        {
            cout << "�����." << endl;
        }
    }
    if (choose == 2)
    {
        if (chet > nechet) cout << "������� ������ �����!" << endl;
        if (nechet > chet)cout << "������� �������� �����!" << endl;
        if (nechet == chet)cout << "�����!" << endl;
    }
}
