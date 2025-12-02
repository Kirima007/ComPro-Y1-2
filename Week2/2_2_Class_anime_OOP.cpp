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

    void play(int time)
     {  playing_sec += time;
        if (playing_sec >= length_per_episode)
            {playing_sec = length_per_episode;}
        int remaining_time = length_per_episode - playing_sec;
        if (remaining_time < 0)
            {remaining_time = 0;}
        cout << " playing => [" << full_name << "]" << " Author => [" << author << "]\n";
        cout << " Episode => [EP." << playing_episode;
        cout << "] playing time = " << " [" << playing_sec << " sec]\n";
        if (playing_sec >= length_per_episode)
            {playing_sec = 0;
            playing_episode++;
            cout << "  ---> full Episode <---\n";
            if (playing_episode > total_episode)
                {cout << "  ---> All Episodes completed. Restarting from Episode 1 <---\n";
                playing_episode = 1;}}}
};

int main()
{

    // variable declaration
    anime a1, a2;
    int i = 0;
    cout << i << endl;
    system("cls");
    a1.full_name = "The Melancholy of Haruhi Suzumiya";
    a1.author = "Nagaru Tanigawa";
    a1.total_episode = 24;
    a1.length_per_episode = 1200;
    a1.playing_episode = 1;
    a1.playing_sec = 0;

    a2.full_name = "Spy x Family Part 1";
    a2.author = "Tatsuya Endo";
    a2.total_episode = 12;
    a2.length_per_episode = 1440;
    a2.playing_episode = 1;
    a2.playing_sec = 0;

    a1.play(500); // playing The Melancholy of Haruhi Suzumiya EP.1 [500 sec]
    cout << "----------(a1)--------------" << endl;
    a1.play(500); // playing The Melancholy of Haruhi Suzumiya EP.1 [500 sec]
    cout << "----------(a1)--------------" << endl;
    a1.play(99999); // playing The Melancholy of Haruhi Suzumiya EP.1 [700 sec]
    cout << "----------(a1)--------------" << endl;
    a1.play(99999); // playing The Melancholy of Haruhi Suzumiya EP.2 [1200 sec]
    cout << "-----------(a1)-------------" << endl;
    a2.play(100); // playing Spy x Family Part 1 EP.1 [100 sec]
    cout << "-----------(a2)-------------" << endl;
    a2.play(100); // playing Spy x Family Part 1 EP.1 [100 sec]
    cout << "-----------(a2)-------------" << endl;
    a2.play(100); // playing Spy x Family Part 1 EP.1 [100 sec]
    cout << "-----------(a2)-------------" << endl;
    a2.play(99999); // playing Spy x Family Part 1 EP.1 [1140 sec]
    cout << "-----------(a2)-------------" << endl;
    a1.play(500); // playing The Melancholy of Haruhi Suzumiya EP.3 [500 sec]
    cout << "-----------(a1)-------------" << endl;
    a1.play(99999); // playing The Melancholy of Haruhi Suzumiya EP.3 [700 sec]
    cout << "-----------(a1)-------------" << endl;

    return 0;
}
