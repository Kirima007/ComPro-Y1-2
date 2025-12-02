#include <iostream>
#include <string>
using namespace std;

// struct declaration
struct anime
{
private:
    int playing_episode; // last played episode
    int playing_sec;     // last played seconds in episode

public:
    string full_name;
    string author;
    int total_episode=12;
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
    void select_time(int _playing_sec)
    {
        if(_playing_sec <= 0) return;
        else if(_playing_sec > length_per_episode)return;
        playing_sec = _playing_sec;
    }

    anime()
    {
        cout << "this is default constructor" << endl;

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
     anime(string _name, string _author, int length)
    {
        cout << "this is constructor for " << _name << endl;

        full_name = _name;
        author = _author;
         
        length_per_episode = length;

        playing_episode = 1;
        playing_sec = 0;
    }

    ~anime()
    {
        int remain_ep = total_episode - playing_episode;
        cout << full_name << "[" << remain_ep << "] episode remaining" << endl;
    }
};

int main()
{
    system("cls");
    anime a1("The Melancholy of Haruhi Suzumiya", "Nagaru Tanigawa", 24, 1200); // (1)
    anime a2("Spy x Family Part 1", "Tatsuya Endo", 1440);                      // (2)
    
    {
        anime a3("detective conan", "Gosho Aoyama", 1067, 1200);                 // (3)
        anime a4("The Legend of Muay Thai: 9 Satra", "Pongsa Kornsri", 1, 6120); // (4)
        a4.play(99999);                                                          // (5)
        a4.play(99999);                                                          // (6)
    } // (7)(8)
    anime a5("k-on season1", "Kakifly", 1440); // (9)

    a1.play(20);    //   (10)
    a2.play(99999); //   (11)
    a2.play(30);    //   (12)

    a5.select_episode(0);
    a5.play(10); //   (13)

    a5.select_episode(13);
    a5.select_time(1300);
    
    a5.play(200); //   (14)
    a5.play(200); //   (15)

    a2.select_time(-1);
    a2.play(10); // (16)
    a2.select_time(2);
    a2.play(99999); // (17)
    cout << endl
         << "--- End of Programe ---" << endl;
         
    return 0;
} // (18)(19)(20)
/* Expected
this is constructor for The Melancholy of Haruhi Suzumiya
this is constructor for Spy x Family Part 1
this is constructor for detective conan
this is constructor for The Legend of Muay Thai: 9 Satra
 playing => [The Legend of Muay Thai: 9 Satra] Author => [Pongsa Kornsri]
 Episode => [EP.1] playing time =  [6120 sec]
  ---> full Episode <---
  ---> All Episodes completed. Restarting from Episode 1 <---
 playing => [The Legend of Muay Thai: 9 Satra] Author => [Pongsa Kornsri]
 Episode => [EP.1] playing time =  [6120 sec]
  ---> full Episode <---
  ---> All Episodes completed. Restarting from Episode 1 <---
The Legend of Muay Thai: 9 Satra[0] episode remaining
detective conan[1066] episode remaining
this is constructor for k-on season1
 playing => [The Melancholy of Haruhi Suzumiya] Author => [Nagaru Tanigawa]
 Episode => [EP.1] playing time =  [20 sec]
 playing => [Spy x Family Part 1] Author => [Tatsuya Endo]
 Episode => [EP.1] playing time =  [1440 sec]
  ---> full Episode <---
 playing => [Spy x Family Part 1] Author => [Tatsuya Endo]
 Episode => [EP.2] playing time =  [30 sec]
 playing => [k-on season1] Author => [Kakifly]
 Episode => [EP.1] playing time =  [10 sec]
 playing => [k-on season1] Author => [Kakifly]
 Episode => [EP.1] playing time =  [1440 sec]
  ---> full Episode <---
 playing => [k-on season1] Author => [Kakifly]
 Episode => [EP.2] playing time =  [200 sec]
 playing => [Spy x Family Part 1] Author => [Tatsuya Endo]
 Episode => [EP.2] playing time =  [40 sec]
 playing => [Spy x Family Part 1] Author => [Tatsuya Endo]
 Episode => [EP.2] playing time =  [1440 sec]
  ---> full Episode <---

--- End of Programe ---
k-on season1[10] episode remaining
Spy x Family Part 1[9] episode remaining
The Melancholy of Haruhi Suzumiya[23] episode remaining
*/