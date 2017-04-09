//  ポケモンの名前あてゲーム
// シャッフルされたポケモンの名前をあてるゲーム
// プレイヤーはヒントを聞くことができる


#include <iostream>
#include <string>
#include <cstdlib> // srand, rand
#include <ctime> // time

using namespace std;

int main(){
    enum elements { POKEMON, HINT1, HINT2, NUM_ELEMENT };
    const int NUM_POKEMON = 10;
    const string POKEMONS[NUM_POKEMON][NUM_ELEMENT] = // POKEMONS[10][3]
    {
        {"dragonite", "dragon", "flying"},
        {"snorlax", "normal", "-"},
        {"scyther", "bug", "flying"},
        {"chansey", "normal", "-"},
        {"flareon", "fire", "-"},
        {"aerodactyl", "rock", "flying"},
        {"moltres", "fire", "flying"},
        {"arcanine", "fire", "-"},
        {"poliwrath", "water", "fighting"},
        {"alakazam", "phychic", "-"}
    };

    srand(static_cast<unsigned int>(time(0)));
    int choice = (rand()%NUM_POKEMON);

    string pokemon = POKEMONS[choice][POKEMON];
    string hint1 = POKEMONS[choice][HINT1];
    string hint2 = POKEMONS[choice][HINT2];
    string jumble = pokemon; // 文字を並び替える用のstring
    int length = jumble.size();

    // 文字の並び替え
    for(int i=0; i<length; ++i){
        int index1 = (rand()%length);
        int index2 = (rand()%length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "Uncranble the letters to make a name of a Pokemon.\n\n";
    cout << "To see hint, enter 'hint'. You can use hint twice.\n";
    cout << "To quit, enter 'quit'\n\n";
    cout << "Jumble : " << jumble << "\n\n";

    string guess;
    cout << "Your guess is : ";
    cin >> guess;
    int num_hint = 0;

    while((guess != pokemon) && (guess != "quit")){
        if(guess != "hint")
            cout << "Nope, thas is not right. Give it another shot!\n\n";
        else { // guess == hint
            if(num_hint==0)
                cout << "First hint : Pokemon's first type is " << hint1 << endl;
            else if(num_hint==1)
                cout << "Second hint : Pokemon's second type is " << hint2 << endl;
            else // num_hint > 1
                cout << "You have used up all your hints!\n";
            ++num_hint;
        }
        
        cout << "\nYour guess is : ";
        cin >> guess;
    }

    if(guess != "quit")  cout << "\nCorrect!! Nicely done!!\n" << endl;
    return 0;
}
