#include <iostream>
#include <deque>
#include <string>
#include <conio.h>
using namespace std;

//decimal to binary conversion
deque<int> decimalToBinary(int decimal)
{
    deque<int> binary;

    for (int i = 0; decimal > 0; i++)
    {
        binary.push_front(decimal % 2);
        decimal = decimal / 2;
    }
    return binary;
}

//binary to decimal conversion
int binaryToDecimal(deque<int> binary)
{
    int decimal = 0;
    int j = binary.size();
    for (int i = 0; i < j; i++)
    {
        if (binary.back() == 1)
        {
            decimal += pow(2, i);
        }
        binary.pop_back();
    }
    return decimal;
}

//puts the necessary zeroes on the beginning of the number
deque<int> addZero(deque<int> &a, int c)
{
    for (int i = 0; i < c; i++)
    {
        a.push_front(0);
    }
    return a;
}

//Does what two above does, but at once
deque<int> precisionDecimalToBinary(int dec, int k)
{
    deque<int> bin;
    deque<int> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(0);
    }
    int binLength = 0;
    for (int i = 0; dec > 0; i++)
    {
        bin.push_front(dec % 2);
        dec = dec / 2;
        binLength++;
    }
    for (int i = 0; i < binLength; i++)
    {
        temp[abs(i - k + 1)] = bin[binLength - i - 1];
    }
    return temp;
}

//Shifts the bits to the left, most significant bit becomes least significant
deque<int> move_1_to_left(deque<int> a)
{
    int temp = a.front();
    a.pop_front();
    a.push_back(temp);
    return a;
}

//Shifts the bits to the right, least significant bit becomes most significant
deque<int> move_1_to_right(deque<int> a)
{
    int temp = a.back();
    a.pop_back();
    a.push_front(temp);
    return a;
}

//Returns generating matrix
deque<deque<int>> generateMatrix(int n, int k, int value, bool draw = true)
{
    deque<deque<int>> gen;
    deque<int> row = precisionDecimalToBinary(value, n);
    gen.push_back(row);
    for (int i = 0; i < k - 1; i++)
    {
        row = move_1_to_left(row);
        gen.push_back(row);
    }
    if (draw)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << gen[i][j];
            }
            cout << endl;
        }
    }
    return gen;
}

//Counts division remainder and result in CG(2)
deque<int> divisionRemainer(deque<int> a, deque<int> b)
{
    deque<int> result;
    while (b.size() <= a.size() && a.size() != 0)
    {
        if (a[0] == '1' || a[0] == 1)
        {
            a.pop_front();
            for (int i = 0; i < b.size() - 1; i++)
            {
                a[i] ^= b[i + 1];
            }
            if (a.size() > 0)
            {
                result.push_back(1);
            }
        }
        else
        {
            a.pop_front();
            result.push_back(0);
        }
    }
    return a;
}

//Counts ones in a binary number
int howManyOnes(deque<int> syndrom)
{
    int one = 0;
    for (int i = 0; i < syndrom.size(); i++)
    {
        if (syndrom[i] == 1)
            one++;
    }
    return one;
}

//Calculating syndrome
deque<int> syndrom(deque<deque<int>> htMatrix, deque<int> input, int n, int k)
{
    deque<int> syndrom;

    for (int i = 0; i < n - k; i++)
    {
        int value = 0;
        for (int j = 0; j < n; j++)
        {
            value ^= (input[j] && htMatrix[j][i]);
        }
        syndrom.push_back(value);
    }
    return syndrom;
}

//Counting d_minimum
int calculate_d_min(deque<deque<int>> matrix, int n, int k)
{
    int d_min;
    int counter = 0;
    for (int i = 0; i < n - k; i++)
    {
        if (matrix[0][i] == 1)
            counter++;
    }
    d_min = counter + 1;
    for (int i = 1; i < k; i++)
    {
        counter = 0;
        for (int j = 0; j < n - k; j++)
        {
            if (matrix[i][j] == 1)
                counter++;
        }
        if (counter < d_min)
            d_min = counter + 1;
    }
    return d_min;
}

//Getting code word from keyboard
deque<int> getWord(int n)
{
    deque<int> word;
    string input;
    cout << endl
         << "Prosze podac slowo kodowe o dlugosci " << n << " w postaci binarnej: " << endl;
    cin >> input;
    while (input.length() != n)
    {
        cout << "Wpisany zostal ciag niepoprawnej dlugosci. Sprobuj ponownie: " << endl;
        input.clear();
        cin >> input;
    }
    bool pass = false;
    while (!pass)
    {
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] != '1' && input[i] != '0')
            {
                cout << "Wpisany powinien byc ciag w postaci binarnej. Sprobuj ponownie: " << endl;
                input.clear();
                cin >> input;
            }
            else
                pass = true;
        }
    }
    for (int i = 0; i < input.length(); i++)
    {
        word.push_back(input[i] - 48);
    }
    return word;
};

//Multiplying matrix
deque<int> multiplyMatrix(deque<int> a, deque<deque<int>> b, int n, int k)
{
    deque<int> result;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum ^= (a[j] && b[j][i]);
        }
        result.push_back(sum);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[result.size() - 1 - i];
    }
    cout << ", ";
    return result;
}

//Prints all code words
void printCodeWords(deque<deque<int>> gen, int n, int k)
{
    deque<int> codeWord;
    for (int c = 0; c < pow(2, 8); c++)
    {
        multiplyMatrix(precisionDecimalToBinary(c, k), gen, n, k);
    }
    cout << endl;
}

//For a given codeword, checks for error and if it can be corrected.
//Error is corrected if possible.
void correct(deque<deque<int>> htMatrix, int n, int k)
{
    int t = (calculate_d_min(htMatrix, n, k) - 1) / 2;
    int tilt = 0;
    deque<int> input = getWord(n);
    deque<int> syn = syndrom(htMatrix, input, n, k);

    cout << endl
         << "Syndrom przed przesunieciem: ";
    for (int i = 0; i < syn.size(); i++)
    {
        cout << syn[i];
    }
    cout << endl;
    if (howManyOnes(syndrom(htMatrix, input, n, k)) == 0)
    {
        cout << "Pobrany ciag jest slowem kodowym!" << endl;
    }
    else
    {
        while (howManyOnes(syndrom(htMatrix, input, n, k)) > t)
        {
            tilt++;
            input = move_1_to_left(input);
            syn = syndrom(htMatrix, input, n, k);
            cout << "Syndrom po " << tilt << " przesunieciu: ";
            for (int i = 0; i < syn.size(); i++)
            {
                cout << syn[i];
            }
            cout << endl;
            if (tilt == n - 1)
            {
                cout << endl
                     << "Blad niekorygowalny" << endl;
                return;
            }
        }
        addZero(syn, k);
        deque<int> ans;
        for (int i = 0; i < input.size(); i++)
        {
            ans.push_back((input[i] ^ syn[i]));
        }
        for (int i = 0; i < tilt; i++)
        {
            ans = move_1_to_right(ans);
        }
        cout << endl
             << "Po korekcji bledu: ";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
    }
}

//Counts and prints u_i matrix, generating matrix, systematic matrix, corrected matrix and prints code properties
deque<deque<int>> controlMatrix(int n, int k, int gx, bool draw)
{
    deque<deque<int>> uMatrix;
    deque<deque<int>> gMatrix;
    deque<deque<int>> htMatrix;

    for (int i = n - 1; i >= n - k; i--)
    {
        int xi = 0;
        xi = 1 << i;
        uMatrix.push_back(divisionRemainer(decimalToBinary(xi), decimalToBinary(gx)));
    }

    gMatrix = uMatrix;
    for (int i = 0; i < k; i++)
    {
        for (int j = k - 1; j > -1; j--)
        {
            if (j == i)
                gMatrix[i].push_front(1);
            else
                gMatrix[i].push_front(0);
        }
    }

    htMatrix = uMatrix;
    deque<int> tempMatrix;
    for (int i = 0; i < n - k; i++)
    {
        for (int j = 0; j < n - k; j++)
        {
            if (i == j)
                tempMatrix.push_back(1);
            else
                tempMatrix.push_back(0);
        }
        htMatrix.push_back(tempMatrix);
        tempMatrix.clear();
    }

    if (draw)
    {
        cout << endl
             << "Macierz generujaca systematyczna Gs: " << endl
             << endl;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << gMatrix[i][j];
            }
            cout << endl;
        }

        cout << endl
             << "Macierz kontrolna H^T: " << endl
             << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - k; j++)
            {
                cout << htMatrix[i][j];
            }
            cout << endl;
        }
        int d_min = calculate_d_min(htMatrix, n, k);
        int e = (d_min - 1);
        int t = (d_min - 1) / 2;
        cout << endl
             << "Odleglosc minimalna: " << d_min << endl;
        cout << "Zdolnosc detekcyjna: " << e << endl;
        cout << "Zdolnosc korekcyjna: " << t << endl;
    }

    return htMatrix;
}

//Checking code correctness, matrix division
bool check(int n, deque<int> gen)
{

    deque<int> a;
    for (int i = 0; i < n + 1; i++)
    {
        if (i == 0 || i == n)
            a.push_back(1);
        else
            a.push_back(0);
    }
    deque<int> result;
    result = divisionRemainer(a, gen);
    cout << endl
         << "Reszta z dzielenia x^" << n << " + x^0 przez wielomian generujacy: ";
    int ones = howManyOnes(gen);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    if (binaryToDecimal(result) == 0)
    {
        cout << endl
             << "Wprowadzone parametry sa poprawne";
        return true;
    }
    return false;
}

//Checking if given string is a binary number
bool binaryCheck(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '1' && str[i] != '0')
        {
            return false;
        }
    }
    return true;
}

//Adding custom code parameters
void getNewPoly(int &n, int &k, int &value)
{
    deque<int> temp;
    string str;

    cout << "Podaj nowa wartosc n: ";
    cin >> n;

    cout << "Podaj nowa wartosc k: ";
    cin >> k;

    cout << "Podaj nowy wielomian generujacy (jako liczba binarna): ";
    cin >> str;
    while (!binaryCheck(str))
    {
        cout << "Wprowadzony ciag powinien byc liczba binarna, sproboj ponownie:";
        cin >> str;
    }
    for (int i = 0; i < str.length(); i++)
    {
        temp.push_back(str[i] - 48);
    }
    value = binaryToDecimal(temp);
}

//Printing menu
void printPoly(deque<int> poly)
{
    int ones = howManyOnes(poly);
    for (int i = 0; i < poly.size(); i++)
    {
        if (poly[i] == 1)
        {
            cout << "x^" << poly.size() - i - 1;
            ones--;
            if (ones > 0)
                cout << "+";
        }
    }
}
//more menu printing
void printPlainText(int n, int k, deque<int> poly)
{
    cout << "Aktualny kod:(" << n << ", " << k << ") ";
    int ones = howManyOnes(poly);
    for (int i = 0; i < poly.size(); i++)
    {
        if (poly[i] == 1)
        {
            cout << poly.size() - i - 1;
            ones--;
            if (ones > 0)
                cout << " ";
        }
    }
}

//menu function
void mainMenu(int n = 18, int k = 8, int gx = 1533)
{
    system("cls");
    cout << "KODOWANIE 2 -- PROJEKT -- PAWEL LAWRYNOWICZ (249404)" << endl
         << endl;
    printPlainText(n, k, decimalToBinary(gx));
    cout << endl
         << endl;
    cout << "Wielomian generujacy: ";
    printPoly(decimalToBinary(gx));
    cout << endl
         << endl;
    cout << "MENU: " << endl;
    cout << "1. Macierz generujaca" << endl;
    cout << "2. Macierz generujaca systematyczna, macierz kontrolna, odleglosc minimalna, zdolnosc detekcyjna i korekcyjna" << endl;
    cout << "3. Tablica slow kodowych" << endl;
    cout << "4. Wykrywanie i korekcja bledow" << endl;
    cout << "5. Sprawdzenie poprawnosci metoda dzielenia wielomianow" << endl;
    cout << "6. Zmien parametry kodu" << endl;
    cout << "0. Wyjscie z programu" << endl;
}

//more menu function
void optMenu()
{
    int n = 18;    //18
    int k = 8;     //8
    int gx = 1533; //1533
    while (1)
    {
        switch (_getch())
        {
        case '1':
            system("cls");
            mainMenu(n, k, gx);
            cout << endl;
            generateMatrix(n, k, gx);
            break;
        case '2':
            system("cls");
            mainMenu(n, k, gx);
            controlMatrix(n, k, gx, true);
            break;
        case '3':
            system("cls");
            mainMenu(n, k, gx);
            printCodeWords(generateMatrix(n, k, gx, false), n, k);
            break;
        case '4':
            system("cls");
            mainMenu(n, k, gx);
            correct(controlMatrix(n, k, gx, false), n, k);
            break;
        case '5':
            system("cls");
            mainMenu(n, k, gx);
            check(n, decimalToBinary(gx));
            break;
        case '6':
        {
            system("cls");
            getNewPoly(n, k, gx);
            bool correct = check(n, decimalToBinary(gx));
            int chances = 10;
            while (!correct)
            {
                chances--;
                cout << "Wprowadzone dane nie sa poprawne, pozostale szanse (" << chances << ")" << endl;
                getNewPoly(n, k, gx);
                correct = check(n, decimalToBinary(gx));
                if (chances == 0)
                {
                    cout << "Bardzo sie starales, lecz z gry wyleciales HeHe" << endl;
                    _getch();
                    exit(0);
                }
            }
            _getch();
            mainMenu(n, k, gx);
            break;
        }
        case '0':
            exit(0);
            break;
        default:
            system("cls");
            mainMenu(n, k, gx);
            cout << endl
                 << "francesinha (tost kielbasa kotlet boczek parowki jakies smazone mieso ser tost jajko sadzone - frytki i wszystko ratuje tlusty sos) :) Portugalskie narodowe danie";
            break;
        }
    }
}
void menu()
{
    mainMenu();
    optMenu();
}

int main()
{

    menu();

    return 0;
}
