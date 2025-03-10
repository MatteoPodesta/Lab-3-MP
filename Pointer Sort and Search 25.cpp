#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

class Creature {

public:
    string getStrenght() const { return to_string(strength); }
    string getHealth() const { return to_string(health); }
    string getName() const { return name; }
    string getType() const { return type; }
    string getDamage() { return to_string(damage); }

    //mutator function to set ALL member variables
    void setCreature(int newStrenght, int newHealth, string newName, string newType);

private:
    //Strength and Health are both set to the minimum of each category, rather than 0, as to prevent errors from occuring within the damage's rand() function
    string name = "placeholder";
    string type = "none";
    int strength = 50;
    int health = 75;
    int damage = ((rand() % strength) + 1);

};

enum Options {

    PRINT = 1,
    SORT = 2,
    SEARCH = 3,
    QUIT = 4,

    SORT_CONFIRM = 5,
    RETURN_SORT = 6,

    SEARCH_CONFIRM = 7,
    RETURN_SEARCH = 8



};

void printTheList(Creature list[20]);
void printBySorted(Creature list[20]);
void searchInList(Creature list[20]);

int main()
{
    int switchInput = 0;
    Creature creatureList[20];
    Creature sortedList[20];
    string typesList[4] = {"Water", "Table", "Bones", "Radiation"};

    ifstream infile;
    infile.open("FileName.dat");
    if (!infile) {
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }
     
    string tempName;

    for (int i = 0; i < 20; i++) {
        
        infile >> tempName;

        if (tempName == "") {

            tempName = "placeholder";

        }

        //setCreature(strength, health, ID)
        creatureList[i].setCreature((rand() % 176) + 75, (rand() % 151) + 50, tempName, typesList[rand() % 4]);
        sortedList[i] = creatureList[i];
        tempName = "";
    }


    while (switchInput != 4) {

        cout << "\nMenu:\n"
            "1.Print\n"
            "2.Sort\n"
            "3.Search\n"
            "4.Quit" 
            "\nInput: ";
        
        cin >> switchInput;

        switch (switchInput) {
        case PRINT:
            printTheList(creatureList);
            break;
        case SORT:
            while (switchInput != 6) {

                cout << "\nSort:\n"
                    "5.Ascending order by name\n"
                    "6.Return to Menu\n"
                    "\nInput: ";

                cin >> switchInput;

                switch (switchInput) {

                case SORT_CONFIRM:
                    printBySorted(sortedList);
                    break;
                case RETURN_SORT:
                    break;
                default:
                    cout << "Please input a valid option\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

            }
            break;
        case SEARCH:
            while (switchInput != 8) {

                cout << "\nSort:\n"
                    "7.Search by creature type\n"
                    "8.Return to Menu\n"
                    "\nInput: ";

                cin >> switchInput;

                switch (switchInput) {

                case SEARCH_CONFIRM:
                    searchInList(creatureList);
                    break;
                case RETURN_SEARCH:
                    break;
                default:
                    cout << "Please input a valid option\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

            }
            break;
        default:
            cout << "Please input a valid option\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

    }
    
}

void printTheList(Creature list[20]) {

    cout << "| Name" << setw(11) << "Health" << setw(10) << "Strenght" << setw(9) << "Type" << setw(16) << "Damage |\n"
        "+" << setw(49) << setfill('-') << "+" << setfill(' ') << endl;


    for (int i = 0; i < 20; i++) {

        cout << "| " << left << setw(10) << list[i].getName() << right << setw(5) << list[i].getHealth() << right << setw(10) << list[i].getStrenght() << setw(5) << "" << left << setw(10) << list[i].getType() << right << setw(6) << list[i].getDamage() << " |" << endl;

    }

}
void printBySorted(Creature list[20]) {

    Creature temp;

    for (int i = 0; i < 20; i++) {
        for (int j = i + 1; j < 20; j++) {

            if (list[j].getName() < list[i].getName()) {

                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }

        }

    }

    printTheList(list);
}
void searchInList(Creature list[20]) {

    string searchingFor = "";
    
    cout << "Search for: ";
    cin >> searchingFor;

    for (char& x : searchingFor) {
        x = toupper(x);
    }

    cout << "| Name" << setw(11) << "Health" << setw(10) << "Strenght" << setw(9) << "Type" << setw(16) << "Damage |\n"
        "+" << setw(49) << setfill('-') << "+" << setfill(' ') << endl;

    for (int i = 0; i < 20; i++) {

        string searchingIn = (list[i].getType());
        for (char& x : searchingIn) {
            x = toupper(x);
        }
        size_t found_index = searchingIn.find(searchingFor);

        if (found_index != string::npos) {
            
            cout << "| " << left << setw(10) << list[i].getName() << right << setw(5) << list[i].getHealth() << right << setw(10) << list[i].getStrenght() << setw(5) << "" << left << setw(10) << list[i].getType() << right << setw(6) << list[i].getDamage() << " |" << endl;

        }

    }





}

void Creature::setCreature(int newStrenght, int newHealth, string newName, string newType) {

    strength = newStrenght;
    health = newHealth; 
    name = newName; 
    type = newType;

}


/*
Test runs--------------------------------------------------------
1 - Empty FileName.dat

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 1
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| placeholder  154       245     Radiation     42 |
| placeholder   56       163     Table         18 |
| placeholder   60       168     Table         35 |
| placeholder   78        87     Water          1 |
| placeholder  191       224     Bones         20 |
| placeholder  166       136     Radiation     25 |
| placeholder   73       247     Table         29 |
| placeholder  194       157     Radiation      9 |
| placeholder  107       139     Water         13 |
| placeholder  137       195     Bones         15 |
| placeholder  148       125     Bones          6 |
| placeholder  109       113     Table         46 |
| placeholder  196       180     Bones         32 |
| placeholder  200       202     Water         28 |
| placeholder   72       175     Water         12 |
| placeholder  184       235     Water         42 |
| placeholder   84       123     Radiation     46 |
| placeholder   63       134     Radiation     43 |
| placeholder  146       177     Table         28 |
| placeholder  178       248     Bones         37 |

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 2

Sort:
5.Ascending order by name
6.Return to Menu

Input: 5
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| placeholder  154       245     Radiation     42 |
| placeholder   56       163     Table         18 |
| placeholder   60       168     Table         35 |
| placeholder   78        87     Water          1 |
| placeholder  191       224     Bones         20 |
| placeholder  166       136     Radiation     25 |
| placeholder   73       247     Table         29 |
| placeholder  194       157     Radiation      9 |
| placeholder  107       139     Water         13 |
| placeholder  137       195     Bones         15 |
| placeholder  148       125     Bones          6 |
| placeholder  109       113     Table         46 |
| placeholder  196       180     Bones         32 |
| placeholder  200       202     Water         28 |
| placeholder   72       175     Water         12 |
| placeholder  184       235     Water         42 |
| placeholder   84       123     Radiation     46 |
| placeholder   63       134     Radiation     43 |
| placeholder  146       177     Table         28 |
| placeholder  178       248     Bones         37 |

Sort:
5.Ascending order by name
6.Return to Menu

Input: 6

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 3

Sort:
7.Search by creature type
8.Return to Menu

Input: 7
Search for: E
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| placeholder   56       163     Table         18 |
| placeholder   60       168     Table         35 |
| placeholder   78        87     Water          1 |
| placeholder  191       224     Bones         20 |
| placeholder   73       247     Table         29 |
| placeholder  107       139     Water         13 |
| placeholder  137       195     Bones         15 |
| placeholder  148       125     Bones          6 |
| placeholder  109       113     Table         46 |
| placeholder  196       180     Bones         32 |
| placeholder  200       202     Water         28 |
| placeholder   72       175     Water         12 |
| placeholder  184       235     Water         42 |
| placeholder  146       177     Table         28 |
| placeholder  178       248     Bones         37 |

Sort:
7.Search by creature type
8.Return to Menu

Input: 8

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 4
Please input a valid option

C:\Users\Matteo\source\repos\Pointer Sort and Search 25\x64\Debug\Pointer Sort and Search 25.exe (process 12640) exited with code 0.
Press any key to close this window . . .

-------------------------------
2 - All numbers in FileName.dat

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 1
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| 1           154       245     Radiation     42 |
| 2            56       163     Table         18 |
| 14           60       168     Table         35 |
| 5            78        87     Water          1 |
| 6           191       224     Bones         20 |
| 7           166       136     Radiation     25 |
| 90           73       247     Table         29 |
| 1           194       157     Radiation      9 |
| 4           107       139     Water         13 |
| 2           137       195     Bones         15 |
| 87          148       125     Bones          6 |
| 55          109       113     Table         46 |
| 22          196       180     Bones         32 |
| 3           200       202     Water         28 |
| 4            72       175     Water         12 |
| 1           184       235     Water         42 |
| 1            84       123     Radiation     46 |
| 2            63       134     Radiation     43 |
| 45          146       177     Table         28 |
| 4           178       248     Bones         37 |

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 2

Sort:
5.Ascending order by name
6.Return to Menu

Input: 5
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| 1           154       245     Radiation     42 |
| 1           194       157     Radiation      9 |
| 1           184       235     Water         42 |
| 1            84       123     Radiation     46 |
| 14           60       168     Table         35 |
| 2            56       163     Table         18 |
| 2           137       195     Bones         15 |
| 2            63       134     Radiation     43 |
| 22          196       180     Bones         32 |
| 3           200       202     Water         28 |
| 4            72       175     Water         12 |
| 4           107       139     Water         13 |
| 4           178       248     Bones         37 |
| 45          146       177     Table         28 |
| 5            78        87     Water          1 |
| 55          109       113     Table         46 |
| 6           191       224     Bones         20 |
| 7           166       136     Radiation     25 |
| 87          148       125     Bones          6 |
| 90           73       247     Table         29 |

Sort:
5.Ascending order by name
6.Return to Menu

Input: 6

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 3

Sort:
7.Search by creature type
8.Return to Menu

Input: 7
Search for: eR
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| 5            78        87     Water          1 |
| 4           107       139     Water         13 |
| 3           200       202     Water         28 |
| 4            72       175     Water         12 |
| 1           184       235     Water         42 |

Sort:
7.Search by creature type
8.Return to Menu

Input: 8

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 4
Please input a valid option

C:\Users\Matteo\source\repos\Pointer Sort and Search 25\x64\Debug\Pointer Sort and Search 25.exe (process 16060) exited with code 0.
Press any key to close this window . . .
//Due to the fact that the Name variable in the creature is a string, the numbers are read like a string and sorted as such.

-------------------------------
2 - Mixed numbers and words


Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 1
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| Billy       154       245     Radiation     42 |
| Cheese       56       163     Table         18 |
| m0nst4r      60       168     Table         35 |
| MonN         78        87     Water          1 |
| piKaCHU     191       224     Bones         20 |
| 12          166       136     Radiation     25 |
| Terry        73       247     Table         29 |
| 45          194       157     Radiation      9 |
| p000        107       139     Water         13 |
| STEVE       137       195     Bones         15 |
| m           148       125     Bones          6 |
| 1           109       113     Table         46 |
| 90          196       180     Bones         32 |
| RemMY       200       202     Water         28 |
| DAVID        72       175     Water         12 |
| prancer     184       235     Water         42 |
| 90           84       123     Radiation     46 |
| 133          63       134     Radiation     43 |
| 5           146       177     Table         28 |
| TiM         178       248     Bones         37 |

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 2

Sort:
5.Ascending order by name
6.Return to Menu

Input: 5
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| 1           109       113     Table         46 |
| 12          166       136     Radiation     25 |
| 133          63       134     Radiation     43 |
| 45          194       157     Radiation      9 |
| 5           146       177     Table         28 |
| 90          196       180     Bones         32 |
| 90           84       123     Radiation     46 |
| Billy       154       245     Radiation     42 |
| Cheese       56       163     Table         18 |
| DAVID        72       175     Water         12 |
| MonN         78        87     Water          1 |
| RemMY       200       202     Water         28 |
| STEVE       137       195     Bones         15 |
| Terry        73       247     Table         29 |
| TiM         178       248     Bones         37 |
| m           148       125     Bones          6 |
| m0nst4r      60       168     Table         35 |
| p000        107       139     Water         13 |
| piKaCHU     191       224     Bones         20 |
| prancer     184       235     Water         42 |

Sort:
5.Ascending order by name
6.Return to Menu

Input: 6

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 3

Sort:
7.Search by creature type
8.Return to Menu

Input: 7
Search for: a
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| Billy       154       245     Radiation     42 |
| Cheese       56       163     Table         18 |
| m0nst4r      60       168     Table         35 |
| MonN         78        87     Water          1 |
| 12          166       136     Radiation     25 |
| Terry        73       247     Table         29 |
| 45          194       157     Radiation      9 |
| p000        107       139     Water         13 |
| 1           109       113     Table         46 |
| RemMY       200       202     Water         28 |
| DAVID        72       175     Water         12 |
| prancer     184       235     Water         42 |
| 90           84       123     Radiation     46 |
| 133          63       134     Radiation     43 |
| 5           146       177     Table         28 |

Sort:
7.Search by creature type
8.Return to Menu

Input: 7
Search for: A
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| Billy       154       245     Radiation     42 |
| Cheese       56       163     Table         18 |
| m0nst4r      60       168     Table         35 |
| MonN         78        87     Water          1 |
| 12          166       136     Radiation     25 |
| Terry        73       247     Table         29 |
| 45          194       157     Radiation      9 |
| p000        107       139     Water         13 |
| 1           109       113     Table         46 |
| RemMY       200       202     Water         28 |
| DAVID        72       175     Water         12 |
| prancer     184       235     Water         42 |
| 90           84       123     Radiation     46 |
| 133          63       134     Radiation     43 |
| 5           146       177     Table         28 |

Sort:
7.Search by creature type
8.Return to Menu

Input: 8

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 4
Please input a valid option

C:\Users\Matteo\source\repos\Pointer Sort and Search 25\x64\Debug\Pointer Sort and Search 25.exe (process 21136) exited with code 0.
Press any key to close this window . . .

-------------------------------
2 - Overlfowing FileName.dat (+20 names)


Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 1
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| Billy       154       245     Radiation     42 |
| Cheese       56       163     Table         18 |
| m0nst4r      60       168     Table         35 |
| MonN         78        87     Water          1 |
| piKaCHU     191       224     Bones         20 |
| 12          166       136     Radiation     25 |
| Terry        73       247     Table         29 |
| 45          194       157     Radiation      9 |
| p000        107       139     Water         13 |
| STEVE       137       195     Bones         15 |
| m           148       125     Bones          6 |
| 1           109       113     Table         46 |
| 90          196       180     Bones         32 |
| RemMY       200       202     Water         28 |
| DAVID        72       175     Water         12 |
| prancer     184       235     Water         42 |
| 90           84       123     Radiation     46 |
| 133          63       134     Radiation     43 |
| 5           146       177     Table         28 |
| TiM         178       248     Bones         37 |

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 2

Sort:
5.Ascending order by name
6.Return to Menu

Input: 5
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| 1           109       113     Table         46 |
| 12          166       136     Radiation     25 |
| 133          63       134     Radiation     43 |
| 45          194       157     Radiation      9 |
| 5           146       177     Table         28 |
| 90          196       180     Bones         32 |
| 90           84       123     Radiation     46 |
| Billy       154       245     Radiation     42 |
| Cheese       56       163     Table         18 |
| DAVID        72       175     Water         12 |
| MonN         78        87     Water          1 |
| RemMY       200       202     Water         28 |
| STEVE       137       195     Bones         15 |
| Terry        73       247     Table         29 |
| TiM         178       248     Bones         37 |
| m           148       125     Bones          6 |
| m0nst4r      60       168     Table         35 |
| p000        107       139     Water         13 |
| piKaCHU     191       224     Bones         20 |
| prancer     184       235     Water         42 |

Sort:
5.Ascending order by name
6.Return to Menu

Input: 6

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 3

Sort:
7.Search by creature type
8.Return to Menu

Input: 7
Search for: B
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| Cheese       56       163     Table         18 |
| m0nst4r      60       168     Table         35 |
| piKaCHU     191       224     Bones         20 |
| Terry        73       247     Table         29 |
| STEVE       137       195     Bones         15 |
| m           148       125     Bones          6 |
| 1           109       113     Table         46 |
| 90          196       180     Bones         32 |
| 5           146       177     Table         28 |
| TiM         178       248     Bones         37 |

Sort:
7.Search by creature type
8.Return to Menu

Input: 7
Search for: be
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+

Sort:
7.Search by creature type
8.Return to Menu

Input: 8

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 4
Please input a valid option

C:\Users\Matteo\source\repos\Pointer Sort and Search 25\x64\Debug\Pointer Sort and Search 25.exe (process 25696) exited with code 0.
Press any key to close this window . . .

-------------------------------
2 - less than 20 names in FileName.dat


Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 1
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| Billy       154       245     Radiation     42 |
| Cheese       56       163     Table         18 |
| m0nst4r      60       168     Table         35 |
| MonN         78        87     Water          1 |
| piKaCHU     191       224     Bones         20 |
| 12          166       136     Radiation     25 |
| Terry        73       247     Table         29 |
| 45          194       157     Radiation      9 |
| placeholder  107       139     Water         13 |
| placeholder  137       195     Bones         15 |
| placeholder  148       125     Bones          6 |
| placeholder  109       113     Table         46 |
| placeholder  196       180     Bones         32 |
| placeholder  200       202     Water         28 |
| placeholder   72       175     Water         12 |
| placeholder  184       235     Water         42 |
| placeholder   84       123     Radiation     46 |
| placeholder   63       134     Radiation     43 |
| placeholder  146       177     Table         28 |
| placeholder  178       248     Bones         37 |

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 2

Sort:
5.Ascending order by name
6.Return to Menu

Input: 5
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| 12          166       136     Radiation     25 |
| 45          194       157     Radiation      9 |
| Billy       154       245     Radiation     42 |
| Cheese       56       163     Table         18 |
| MonN         78        87     Water          1 |
| Terry        73       247     Table         29 |
| m0nst4r      60       168     Table         35 |
| piKaCHU     191       224     Bones         20 |
| placeholder  107       139     Water         13 |
| placeholder  137       195     Bones         15 |
| placeholder  148       125     Bones          6 |
| placeholder  109       113     Table         46 |
| placeholder  196       180     Bones         32 |
| placeholder  200       202     Water         28 |
| placeholder   72       175     Water         12 |
| placeholder  184       235     Water         42 |
| placeholder   84       123     Radiation     46 |
| placeholder   63       134     Radiation     43 |
| placeholder  146       177     Table         28 |
| placeholder  178       248     Bones         37 |

Sort:
5.Ascending order by name
6.Return to Menu

Input: 6

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 3

Sort:
7.Search by creature type
8.Return to Menu

Input: 7
Search for: RAdiAtion
| Name     Health  Strenght     Type      Damage |
+------------------------------------------------+
| Billy       154       245     Radiation     42 |
| 12          166       136     Radiation     25 |
| 45          194       157     Radiation      9 |
| placeholder   84       123     Radiation     46 |
| placeholder   63       134     Radiation     43 |

Sort:
7.Search by creature type
8.Return to Menu

Input: 8

Menu:
1.Print
2.Sort
3.Search
4.Quit
Input: 4
Please input a valid option

C:\Users\Matteo\source\repos\Pointer Sort and Search 25\x64\Debug\Pointer Sort and Search 25.exe (process 15128) exited with code 0.
Press any key to close this window . . .

-------------------------------
*/