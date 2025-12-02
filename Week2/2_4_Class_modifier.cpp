#include <iostream>
#include <string>
using namespace std;

// struct declaration
struct anime
{

    int playing_episode; // last played episode
    int playing_sec;     // last played seconds in episode

public:
    string full_name;
    string author;
    int total_episode;
    int length_per_episode; // Average running time in Seconds

    void play(int time)
    {
        playing_sec += time;
        if (playing_sec >= length_per_episode)
        {
            playing_sec = length_per_episode;
        }
        int remaining_time = length_per_episode - playing_sec;
        if (remaining_time < 0)
        {
            remaining_time = 0;
        }
        cout << " playing => [" << full_name << "]" << " Author => [" << author << "]\n";
        cout << " Episode => [EP." << playing_episode;
        cout << "] playing time = " << " [" << playing_sec << " sec]\n";
        if (playing_sec >= length_per_episode)
        {
            playing_sec = 0;
            playing_episode++;
            cout << "  ---> full Episode <---\n";
            if (playing_episode > total_episode)
            {
                cout << "  ---> All Episodes completed. Restarting from Episode 1 <---\n";
                playing_episode = 1;
            }
        }
    }

    void select_episode(int _ep)
    {
        if (_ep <= 0)
            return;
        if (_ep > total_episode)
            return;

        playing_episode = _ep;
        playing_sec = 0;
    }

    anime()
    {
        cout << "this is default constructor " << endl;

        playing_episode = 1;
        playing_sec = 0;
    }

    anime(string _name, string _author, int _ep, int length)
    {
        cout << "this is constructor for " << _name << endl;

        full_name = _name;
        author = _author;
        total_episode = _ep;
        length_per_episode = length;

        playing_episode = 1;
        playing_sec = 0;
    }

    ~anime()
    {
        cout << full_name << " has destroyed" << endl;
    }
};

anime a1("The Melancholy of Haruhi Suzumiya", "Nagaru Tanigawa", 24, 1200);

int main()
{
    anime a1;
    anime a2("Spy x Family Part 1", "Tatsuya Endo", 12, 1440);
    if (true)
    {
        anime a3("detective conan", "Gosho Aoyama", 1067, 1200);
        a3.play(20);
    }
    a1.full_name = "AAA";
    a1.total_episode = -2;
    a1.playing_sec = -2;
    a1.select_episode(3);
    cout << "============" << endl;
    a1.play(500);
    a2.play(99999);
    cout << "++++++++++++" << endl;
    return 0;
}
