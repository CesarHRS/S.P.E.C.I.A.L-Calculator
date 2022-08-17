#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void menu();
void clean_terminal();
void collect_data();
void print_special();
void jump_line(unsigned short int n);
void calculate_data();
void write_file();

struct special{
    string name, sex;
    unsigned short age;
    unsigned short ST = 5, PE = 5, EN = 5, CH = 5, IN = 5, AG = 5, LK = 5;
    short small_guns, big_guns, energy_weapons, unarmed, melee_weapons, throwing, first_aid, doctor, sneak, lockpick, steal, traps, science, repair, speech, barter, gambling, outdoorsman;
    short HP, AC, CW, AP, MD, DR, PR, SQ, HR;
};

special sheet;

int main() {

    menu();

    return 0;
}

void menu(){
    unsigned short int menu;
    do{
        clean_terminal();
        cout << "Type 1 to create yout sheet" << endl;
        cout << "Type 0 to close" << endl;
        cin >> menu;
        clean_terminal();

        if(menu == 1){
            collect_data();
            calculate_data();
            write_file();
        }
    }while(menu != 0);
}

void clear_terminal()
{
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void collect_data(){
    unsigned short int char_points = 5;
    string letter;

    getchar();
    cout << "Type your name!" << "\t" << endl;
    getline(cin, sheet.name);
    cout << "Type your age!" << "\t" << endl;
    cin >> sheet.age;
    getchar();
    cout << "Type your sex!" << "\t" << endl;
    getline(cin, sheet.sex);

    clear_terminal();
    do {
        print_special();
        cout << "Char Points: " << char_points << endl;
        cout << "Type the letter of the special "<< endl;
        cin >> letter;

        if(letter == "S" || letter == "s" && sheet.ST < 10 && char_points > 0){
            sheet.ST++;
            char_points--;
        }
        else if(letter == "-S" || letter == "-s" && sheet.ST > 1){
            sheet.ST--;
            char_points++;
        }
        else if(letter == "P" || letter == "p" && sheet.PE < 10 && char_points > 0){
            sheet.PE++;
            char_points--;
        }
        else if(letter == "-P" || letter == "-p" && sheet.PE > 1){
            sheet.PE--;
            char_points++;
        }
        else if(letter == "E" || letter == "e" && sheet.EN < 10 && char_points > 0){
            sheet.EN++;
            char_points--;
        }
        else if(letter == "-E" || letter == "-e" && sheet.EN > 1){
            sheet.EN--;
            char_points++;
        }
        else if(letter == "C" || letter == "c" && sheet.CH < 10 && char_points > 0){
            sheet.CH++;
            char_points--;
        }
        else if(letter == "-C" || letter == "-c" && sheet.CH > 1){
            sheet.CH--;
            char_points++;
        }
        else if(letter == "I" || letter == "i" && sheet.IN < 10 && char_points > 0){
            sheet.IN++;
            char_points--;
        }
        else if(letter == "-I" || letter == "-i" && sheet.IN > 1){
            sheet.IN--;
            char_points++;
        }
        else if(letter == "A" || letter == "a" && sheet.AG < 10 && char_points > 0){
            sheet.AG++;
            char_points--;
        }
        else if(letter == "-A" || letter == "-a" && sheet.AG > 1){
            sheet.AG--;
            char_points++;
        }
        else if(letter == "L" || letter == "l" && sheet.LK < 10 && char_points > 0){
            sheet.LK++;
            char_points--;
        }
        else if(letter == "-L" || letter == "-l" && sheet.LK > 1){
            sheet.LK--;
            char_points++;
        }
    }while(letter != "end");

    cout << "S.P.E.C.I.A.L pronto!" << endl;
}

void print_special(){
    clear_terminal();
    cout << "S = " << sheet.ST << "\t" << endl;
    cout << "P = " << sheet.PE << "\t" << endl;
    cout << "E = " << sheet.EN << "\t" << endl;
    cout << "C = " << sheet.CH << "\t" << endl;
    cout << "I = " << sheet.IN << "\t" << endl;
    cout << "A = " << sheet.AG << "\t" << endl;
    cout << "L = " << sheet.LK << "\t" << endl;
    jump_line(1);
}

void jump_line(unsigned short int n){
    for (unsigned short int i = 0; i < n; i++){
        cout << endl;
    }
}

void calculate_data(){
    sheet.HP = 15 + sheet.ST + sheet.EN  * 2;
    sheet.AC = sheet.AG;
    sheet.AP = 5 + (sheet.AG / 2);
    sheet.CW = (25 + (sheet.ST * 25)) / 2.205;
    if((sheet.ST - 5) > 1){
        sheet.MD = sheet.ST - 5;
    }
    else{
        sheet.MD = 1;
    }
    sheet.DR = 0;
    sheet.PR = sheet.EN * 5;
    sheet.SQ = 2 * sheet.PE;
    if (sheet.EN / 3 > 1){
        sheet.HR = sheet.EN / 3;
    }
    else{
        sheet.HR = 1;
    }
    sheet.small_guns = 5 + 4 * sheet.AG;
    sheet.big_guns = 2 * sheet.AG;
    sheet.energy_weapons = 2 * sheet.AG;
    sheet.unarmed = 30 + 2 * (sheet.AG + sheet.ST);
    sheet.melee_weapons = 20 + 2 * (sheet.AG + sheet.ST);
    sheet.throwing = 4 * sheet.AG;
    sheet.first_aid = 2 * (sheet.PE + sheet.IN);
    sheet.doctor = 5 + (sheet.PE + sheet.IN);
    sheet.sneak = 5 + 3 * sheet.AG;
    sheet.lockpick = 10 + (sheet.PE + sheet.AG);
    sheet.steal = 3 * sheet.AG;
    sheet.traps = 10 + (sheet.PE + sheet.AG);
    sheet.science = 4 * sheet.IN;
    sheet.repair = 3 * sheet.IN;
    sheet.speech = 5 * sheet.CH;
    sheet.barter = 4 * sheet.CH;
    sheet.gambling = 5 * sheet.LK;
    sheet.outdoorsman = 2 * (sheet.EN + sheet.IN);
};

void write_file(){
    ofstream File;
    File.open("sheet.txt");

    File << "Name = " << sheet.name << "\t" << endl;
    File << "Age = " << sheet.age << "\t" << endl;
    File << "Sex = " << sheet.sex << "\t" << endl;

    File << endl;

    File << "S = " << sheet.ST << "\t" << endl;
    File << "P = " << sheet.PE << "\t" << endl;
    File << "E = " << sheet.EN << "\t" << endl;
    File << "C = " << sheet.CH << "\t" << endl;
    File << "I = " << sheet.IN << "\t" << endl;
    File << "A = " << sheet.AG << "\t" << endl;
    File << "L = " << sheet.LK << "\t" << endl;

    File << endl;

    File << "HP = " << sheet.HP << "\t" << endl;
    File << "Armor Class = " << sheet.AC << "\t" << endl;
    File << "Action Points = " << sheet.AP << "\t" << endl;
    File << "Carry Weight = " << sheet.CW << "\t" << endl;
    File << "Melee Damage = " << sheet.MD << "\t" << endl;
    File << "Damage Resistance = " << sheet.DR << "\t" << endl;
    File << "Poison Resistance = " << sheet.PR << "\t" << endl;
    File << "Sequence = " << sheet.SQ << "\t" << endl;
    File << "Healing Rate = " << sheet.HR << "\t" << endl;
    File << "Critical Chance = " << sheet.LK << "\t" << endl;

    File << endl;

    File << "Small Guns = " << sheet.small_guns << "\t" << endl ;
    File << "Big Guns = " << sheet.big_guns << "\t" << endl;
    File << "Energy Weapons = " << sheet.energy_weapons << "\t" << endl;
    File << "Unarmed = " << sheet.unarmed << "\t" << endl;
    File << "Melee Weapons = " << sheet.melee_weapons << "\t" << endl;
    File << "Throwing = " << sheet.throwing << "\t" << endl;
    File << "First Aid = " << sheet.first_aid << "\t" << endl;
    File << "Doctor = " << sheet.doctor << "\t" << endl;
    File << "Sneak = " << sheet.sneak << "\t" << endl;
    File << "Lockpick = " << sheet.lockpick << "\t" << endl;
    File << "Steal = " << sheet.steal << "\t" << endl;
    File << "Traps = " << sheet.traps << "\t" << endl;
    File << "Science = " << sheet.science << "\t" << endl;
    File << "Repair = " << sheet.repair << "\t" << endl;
    File << "Speech = " << sheet.speech << "\t" << endl;
    File << "Barter = " << sheet.barter << "\t" << endl;
    File << "Gambling = " << sheet.gambling << "\t" << endl;
    File << "Outdoorsman = " << sheet.outdoorsman << "\t" << endl;

    File.close();
}


