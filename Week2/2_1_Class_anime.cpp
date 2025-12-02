#include <iostream>
#include <string>
using namespace std;

// struct declaration
struct anime
{
    string full_name;
    string author;
    int total_episode;
    int length_per_episode; // Average running time in Seconds

    int playing_episode; // last played episode
    int playing_sec;     // last played seconds in episode
};

// function declaration
void play(anime *, int);

int main()
{
    anime a1, a2;
    a1.full_name = "The Melancholy of Haruhi Suzumiya";
    a1.author = "Nagaru Tanigawa";
    a1.total_episode = 2;
    a1.length_per_episode = 1200;
    a1.playing_episode = 1;
    a1.playing_sec = 0;

    a2.full_name = "Spy x Family Part 1";
    a2.author = "Tatsuya Endo";
    a2.total_episode = 12;
    a2.length_per_episode = 840;
    a2.playing_episode = 1;
    a2.playing_sec = 0;

    system("cls");
    cout << "1. play a1 time 200 sec" << endl;
    play(&a1, 200);
    cout << "2. play a1 time 500 sec" << endl;
    play(&a1, 500);
    cout << "3. play a1 time 999999 sec" << endl;
    play(&a1, 99999);
    cout << "4. play a1 time 700 sec" << endl;
    play(&a1, 700);
    cout << "5. play a1 time 700 sec" << endl;
    play(&a1, 700);
    cout << "6. play a1 time 700 sec" << endl;
    play(&a1, 700);

    return 0;
}

// function definition
void play(anime *a, int time)
{
    a->playing_sec += time;
    if (a->playing_sec >= a->length_per_episode)
        {a->playing_sec = a->length_per_episode;}
    int remaining_time = a->length_per_episode - a->playing_sec;
    if (remaining_time < 0)
        {remaining_time = 0;}
    cout << " playing => [" << a->full_name << "]" << " Author => [" << a->author << "]\n";
    cout << " Episode => [EP." << a->playing_episode;
    cout << "] playing time = " << " [" << a->playing_sec << " sec]\n";
    if (a->playing_sec >= a->length_per_episode)
      { a->playing_sec = 0;
        a->playing_episode++;
        cout << "  ---> full Episode <---\n";
        if (a->playing_episode > a->total_episode)
        {cout << "  ---> All Episodes completed. Restarting from Episode 1 <---\n";
         a->playing_episode = 1;}
    }
}