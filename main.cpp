#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void menu();
void clear_terminal();
void collect_data();
void print_special();
void print_skills();
void jump_line(unsigned short int n);
void calculate_data();
void write_file();

struct skills {
    short porcentage;
    bool is_tagged;
};

struct special{
    string name, sex;
    unsigned short age;
    unsigned short ST = 5, PE = 5, EN = 5, CH = 5, IN = 5, AG = 5, LK = 5;
    struct skills small_guns, big_guns, energy_weapons, unarmed, melee_weapons, throwing, first_aid, doctor, sneak, lockpick, steal, traps, science, repair, speech, barter, gambling, outdoorsman;
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
        clear_terminal();
        cout << "Type 1 to create yout sheet" << endl;
        cout << "Type 0 to close" << endl;
        cin >> menu;
        clear_terminal();

        if(menu == 1){
            collect_data();
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
    unsigned short int char_points = 5, tags = 3;
    string input;

    cin.ignore();
    cout << "Type your name!" << "\t" << endl;
    getline(cin, sheet.name);
    cout << "Type your age!" << "\t" << endl;
    cin >> sheet.age;
    cin.ignore();
    cout << "Type your sex!" << "\t" << endl;
    getline(cin, sheet.sex);

    clear_terminal();
    do {
        print_special();
        cout << "Char Points: " << char_points << endl;
        cout << "Type the letter of the special "<< endl;
        getline(cin, input);

        if(input == "S" || input == "s" && sheet.ST < 10 && char_points > 0){
            sheet.ST++;
            char_points--;
        }
        else if(input == "-S" || input == "-s" && sheet.ST > 1){
            sheet.ST--;
            char_points++;
        }
        else if(input == "P" || input == "p" && sheet.PE < 10 && char_points > 0){
            sheet.PE++;
            char_points--;
        }
        else if(input == "-P" || input == "-p" && sheet.PE > 1){
            sheet.PE--;
            char_points++;
        }
        else if(input == "E" || input == "e" && sheet.EN < 10 && char_points > 0){
            sheet.EN++;
            char_points--;
        }
        else if(input == "-E" || input == "-e" && sheet.EN > 1){
            sheet.EN--;
            char_points++;
        }
        else if(input == "C" || input == "c" && sheet.CH < 10 && char_points > 0){
            sheet.CH++;
            char_points--;
        }
        else if(input == "-C" || input == "-c" && sheet.CH > 1){
            sheet.CH--;
            char_points++;
        }
        else if(input == "I" || input == "i" && sheet.IN < 10 && char_points > 0){
            sheet.IN++;
            char_points--;
        }
        else if(input == "-I" || input == "-i" && sheet.IN > 1){
            sheet.IN--;
            char_points++;
        }
        else if(input == "A" || input == "a" && sheet.AG < 10 && char_points > 0){
            sheet.AG++;
            char_points--;
        }
        else if(input == "-A" || input == "-a" && sheet.AG > 1){
            sheet.AG--;
            char_points++;
        }
        else if(input == "L" || input == "l" && sheet.LK < 10 && char_points > 0){
            sheet.LK++;
            char_points--;
        }
        else if(input == "-L" || input == "-l" && sheet.LK > 1){
            sheet.LK--;
            char_points++;
        }
    }while(input != "end");

    input = ' ';

    do{
        calculate_data();
        print_skills();
        cout << "Tags remaining: " << tags << endl;
        cout << "Type the skill name to tag it! (lowercase only)"<< endl;
        cout << "To remove it, type -skillname." << endl;
        getline(cin, input);

        if(input == "small-guns" && tags > 0){
            if(!sheet.small_guns.is_tagged){
                sheet.small_guns.is_tagged = true;
                tags--;
            }
        }
        if(input == "-small-guns" && tags > 0){
            if(sheet.small_guns.is_tagged){
                sheet.small_guns.porcentage -= 20;
                tags++;
            }
            sheet.small_guns.is_tagged = false;
        }
        else if(input == "big-guns" && tags > 0){
            if(!sheet.big_guns.is_tagged){
                sheet.big_guns.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-big-guns" && tags > 0){
            if(sheet.big_guns.is_tagged){
                sheet.big_guns.porcentage -= 20;
                tags++;
            }
            sheet.big_guns.is_tagged = false;
        }
        else if(input == "energy-weapons" && tags > 0){
            if(!sheet.energy_weapons.is_tagged){
                sheet.energy_weapons.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-energy-weapons" && tags > 0){
            if(sheet.energy_weapons.is_tagged){
                sheet.energy_weapons.porcentage -= 20;
                tags++;
            }
            sheet.energy_weapons.is_tagged = false;
            }
        else if(input == "unarmed" && tags > 0){
            if(!sheet.unarmed.is_tagged){
                sheet.unarmed.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-unarmed" && tags > 0){
            if(sheet.unarmed.is_tagged){
                sheet.unarmed.porcentage -= 20;
                tags++;
            }
            sheet.unarmed.is_tagged = false;
        }
        else if(input == "melee-weapons" && tags > 0){
            if(!sheet.melee_weapons.is_tagged){
                sheet.melee_weapons.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-melee-weapons" && tags > 0){
            if(sheet.melee_weapons.is_tagged){
                sheet.melee_weapons.porcentage -= 20;
                tags++;
            }
            sheet.melee_weapons.is_tagged = false;
        }
        else if(input == "throwing" && tags > 0){
            if(!sheet.throwing.is_tagged){
                sheet.throwing.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-throwing" && tags > 0){
            if(sheet.throwing.is_tagged){
                sheet.throwing.porcentage -= 20;
                tags++;
            }
            sheet.throwing.is_tagged = false;
        }
        else if(input == "first-aid" && tags > 0){
            if(!sheet.first_aid.is_tagged){
                sheet.first_aid.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-first-aid" && tags > 0){
            if(sheet.first_aid.is_tagged){
                sheet.first_aid.porcentage -= 20;
                tags++;
            }
            sheet.first_aid.is_tagged = false;
        }
        else if(input == "doctor" && tags > 0){
            if(!sheet.doctor.is_tagged){
                sheet.doctor.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-doctor" && tags > 0){
            if(sheet.doctor.is_tagged){
                sheet.doctor.porcentage -= 20;
                tags++;
            }
            sheet.doctor.is_tagged = false;
        }
        else if(input == "sneak" && tags > 0){
            if(!sheet.sneak.is_tagged){
                sheet.sneak.is_tagged = true;
                tags--;
            }
        }

        else if(input == "-sneak" && tags > 0){
            if(sheet.sneak.is_tagged) {
                sheet.sneak.porcentage -= 20;
                tags++;
            }
            sheet.sneak.is_tagged = false;
        }
        else if(input == "lockpick" && tags > 0){
            if(!sheet.lockpick.is_tagged){
                sheet.lockpick.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-lockpick" && tags > 0){
            if(sheet.lockpick.is_tagged){
                sheet.lockpick.porcentage -= 20;
                tags++;
            }
            sheet.lockpick.is_tagged = false;
        }
        else if(input == "steal" && tags > 0){
            if(!sheet.steal.is_tagged){
                sheet.steal.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-steal" && tags > 0){
            sheet.steal.is_tagged = false;
            sheet.steal.porcentage -= 20;
            tags++;
        }
        else if(input == "traps" && tags > 0){
            if(!sheet.traps.is_tagged){
                sheet.traps.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-traps" && tags > 0){
            if(sheet.traps.is_tagged){
                sheet.traps.porcentage -= 20;
                tags++;
            }
            sheet.traps.is_tagged = false;
        }
        else if(input == "science" && tags > 0){
            if(!sheet.science.is_tagged){
                sheet.science.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-science" && tags > 0){
            if(sheet.science.is_tagged){
                sheet.science.porcentage -= 20;
                tags++;
            }
            sheet.science.is_tagged = false;
        }
        else if(input == "repair" && tags > 0){
            if(!sheet.repair.is_tagged){
                sheet.repair.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-repair" && tags > 0){
            if(sheet.repair.is_tagged){
                sheet.repair.porcentage -= 20;
                tags++;
            }
            sheet.repair.is_tagged = false;
        }
        else if(input == "speech" && tags > 0){
            if(!sheet.speech.is_tagged){
                sheet.speech.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-speech" && tags > 0){
            if(sheet.speech.is_tagged){
                sheet.speech.porcentage -= 20;
                tags++;
            }
            sheet.speech.is_tagged = false;
        }
        else if(input == "barter" && tags > 0){
            if(!sheet.barter.is_tagged){
                sheet.barter.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-barter" && tags > 0){
            if(sheet.barter.is_tagged){
                sheet.barter.porcentage -= 20;
                tags++;
            }
            sheet.barter.is_tagged = false;
        }
        else if(input == "gambling" && tags > 0){
            if(!sheet.gambling.is_tagged){
                sheet.gambling.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-gambling" && tags > 0){
            if(sheet.gambling.is_tagged){
                sheet.gambling.porcentage -= 20;
                tags++;
            }
            sheet.gambling.is_tagged = false;
        }
        else if(input == "outdoorsman" && tags > 0){
            if(!sheet.outdoorsman.is_tagged){
                sheet.outdoorsman.is_tagged = true;
                tags--;
            }
        }
        else if(input == "-outdoorsman" && tags > 0){
            sheet.outdoorsman.is_tagged = false;
            if(sheet.outdoorsman.is_tagged){
                sheet.outdoorsman.porcentage -= 20;
                tags++;
            }
        }
    }while(input != "end");

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

void print_skills(){
    clear_terminal();
    cout << "Small Guns = " << sheet.small_guns.porcentage << "\t" << endl ;
    cout << "Big Guns = " << sheet.big_guns.porcentage << "\t" << endl;
    cout << "Energy Weapons = " << sheet.energy_weapons.porcentage << "\t" << endl;
    cout << "Unarmed = " << sheet.unarmed.porcentage << "\t" << endl;
    cout << "Melee Weapons = " << sheet.melee_weapons.porcentage << "\t" << endl;
    cout << "Throwing = " << sheet.throwing.porcentage << "\t" << endl;
    cout << "First Aid = " << sheet.first_aid.porcentage << "\t" << endl;
    cout << "Doctor = " << sheet.doctor.porcentage << "\t" << endl;
    cout << "Sneak = " << sheet.sneak.porcentage << "\t" << endl;
    cout << "Lockpick = " << sheet.lockpick.porcentage << "\t" << endl;
    cout << "Steal = " << sheet.steal.porcentage << "\t" << endl;
    cout << "Traps = " << sheet.traps.porcentage << "\t" << endl;
    cout << "Science = " << sheet.science.porcentage << "\t" << endl;
    cout << "Repair = " << sheet.repair.porcentage << "\t" << endl;
    cout << "Speech = " << sheet.speech.porcentage << "\t" << endl;
    cout << "Barter = " << sheet.barter.porcentage << "\t" << endl;
    cout << "Gambling = " << sheet.gambling.porcentage << "\t" << endl;
    cout << "Outdoorsman = " << sheet.outdoorsman.porcentage << "\t" << endl;
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
    sheet.small_guns.porcentage = 5 + 4 * sheet.AG;
    sheet.big_guns.porcentage = 2 * sheet.AG;
    sheet.energy_weapons.porcentage = 2 * sheet.AG;
    sheet.unarmed.porcentage = 30 + 2 * (sheet.AG + sheet.ST);
    sheet.melee_weapons.porcentage = 20 + 2 * (sheet.AG + sheet.ST);
    sheet.throwing.porcentage = 4 * sheet.AG;
    sheet.first_aid.porcentage = 2 * (sheet.PE + sheet.IN);
    sheet.doctor.porcentage = 5 + (sheet.PE + sheet.IN);
    sheet.sneak.porcentage = 5 + 3 * sheet.AG;
    sheet.lockpick.porcentage = 10 + (sheet.PE + sheet.AG);
    sheet.steal.porcentage = 3 * sheet.AG;
    sheet.traps.porcentage = 10 + (sheet.PE + sheet.AG);
    sheet.science.porcentage = 4 * sheet.IN;
    sheet.repair.porcentage = 3 * sheet.IN;
    sheet.speech.porcentage = 5 * sheet.CH;
    sheet.barter.porcentage = 4 * sheet.CH;
    sheet.gambling.porcentage = 5 * sheet.LK;
    sheet.outdoorsman.porcentage = 2 * (sheet.EN + sheet.IN);

    if(sheet.small_guns.is_tagged){
        sheet.small_guns.porcentage+=20;
    }
    else if(sheet.big_guns.is_tagged){
        sheet.big_guns.porcentage+=20;
    }
    else if(sheet.energy_weapons.is_tagged){
        sheet.energy_weapons.porcentage+=20;
    }
    else if(sheet.unarmed.is_tagged){
        sheet.unarmed.porcentage+=20;
    }
    else if(sheet.melee_weapons.is_tagged){
        sheet.melee_weapons.porcentage+=20;
    }
    else if(sheet.throwing.is_tagged){
        sheet.throwing.porcentage+=20;
    }
    else if(sheet.first_aid.is_tagged){
        sheet.first_aid.porcentage+=20;
    }
    else if(sheet.doctor.is_tagged){
        sheet.doctor.porcentage+=20;
    }
    else if(sheet.sneak.is_tagged){
        sheet.sneak.porcentage+=20;
    }
    else if(sheet.lockpick.is_tagged){
        sheet.lockpick.porcentage+=20;
    }
    else if(sheet.steal.is_tagged){
        sheet.steal.porcentage+=20;
    }
    else if(sheet.traps.is_tagged){
        sheet.traps.porcentage+=20;
    }
    else if(sheet.science.is_tagged){
        sheet.science.porcentage+=20;
    }
    else if(sheet.repair.is_tagged){
        sheet.repair.porcentage+=20;
    }
    else if(sheet.speech.is_tagged){
        sheet.speech.porcentage+=20;
    }
    else if(sheet.barter.is_tagged){
        sheet.barter.porcentage+=20;
    }
    else if(sheet.gambling.is_tagged){
        sheet.gambling.porcentage+=20;
    }
    else if(sheet.outdoorsman.is_tagged){
        sheet.outdoorsman.porcentage+=20;
    }
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

    File << "Small Guns = " << sheet.small_guns.porcentage << "\t" << endl ;
    File << "Big Guns = " << sheet.big_guns.porcentage << "\t" << endl;
    File << "Energy Weapons = " << sheet.energy_weapons.porcentage << "\t" << endl;
    File << "Unarmed = " << sheet.unarmed.porcentage << "\t" << endl;
    File << "Melee Weapons = " << sheet.melee_weapons.porcentage << "\t" << endl;
    File << "Throwing = " << sheet.throwing.porcentage << "\t" << endl;
    File << "First Aid = " << sheet.first_aid.porcentage << "\t" << endl;
    File << "Doctor = " << sheet.doctor.porcentage << "\t" << endl;
    File << "Sneak = " << sheet.sneak.porcentage << "\t" << endl;
    File << "Lockpick = " << sheet.lockpick.porcentage << "\t" << endl;
    File << "Steal = " << sheet.steal.porcentage << "\t" << endl;
    File << "Traps = " << sheet.traps.porcentage << "\t" << endl;
    File << "Science = " << sheet.science.porcentage << "\t" << endl;
    File << "Repair = " << sheet.repair.porcentage << "\t" << endl;
    File << "Speech = " << sheet.speech.porcentage << "\t" << endl;
    File << "Barter = " << sheet.barter.porcentage << "\t" << endl;
    File << "Gambling = " << sheet.gambling.porcentage << "\t" << endl;
    File << "Outdoorsman = " << sheet.outdoorsman.porcentage << "\t" << endl;

    File.close();
}


