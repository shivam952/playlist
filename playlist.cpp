#include<bits/stdc++.h>
using namespace std;
class song
{
  friend ostream &operator<<(ostream &os,const song &s);
  string name;
  string artist;
  int rating;
public:
  song()=default;
  song(string name,string artist,int rating)
  :name{name},artist{artist},rating{rating}{}
//  string get_name()const {return name;}
  //string get_artist()const {return artist;}
  //string get_rating()const {return rating;}
  bool operator <(const song &rhs)const
  {return this->name<rhs.name;}
  bool operator ==(const song &rhs)const
  {return this->name==rhs.name;}
};
ostream &operator<<(ostream &os,const song &s)
{
os<<setw(20)<<left<<s.name
<<setw(30)<<left<<s.artist
<<setw(2)<<left<<s.rating;
return os;
}
void display_menu()
{
  cout<<"\nF - Play first Song"<<endl;
  cout<<"N - Play next song"<<endl;
  cout<<"P - Play previous song"<<endl;
  cout<<"A - Add new song"<<endl;
  cout<<"L - List the current playlist"<<endl;
  cout<<"============================================================="<<endl;
  cout<<"enter Q to quit"<<endl;
}
void play_current_song(const song &song)
{
  cout<<"Playing"<<endl;
  cout<<song<<endl;
}
void display_playlist(const list<song>&playlist, const song &cr)
{
  for(const song &song:playlist)
  {
    cout<<song<<endl;
  }
  cout<<"current song "<<endl;
  cout<<cr<<endl;
}
int main()
{
  list<song>playlist
  {
    {"New divide", "linkin park",5},
    {"castle of glass", "linkin park",5 },
    {"bohemian rhapsody","queen",5},
    {"payphone","maroon 5",4},
    {"disater","bleeker",4}
  };

list<song>::iterator cr=playlist.begin();
display_playlist(playlist,*cr);
char s;
do
{
  display_menu();
  cin>>s;
  s=toupper(s);
  if(s=='F')
  {
    cout<<"playing first song"<<endl;
    cr=playlist.begin();
    play_current_song(*cr);
  }
  else if(s=='N')
  {
    cout<<"playing next song"<<endl;
    cr++;
    if(cr==playlist.end())
    {cout<<"wrapping to the start"<<endl;
  cr=playlist.begin();}
  play_current_song(*cr);
  }
  else if(s=='P')
  {
    cout<<"playing previous song"<<endl;

    if(cr==playlist.begin())
    {
    cout<<"wrapping to the end"<<endl;
     cr=playlist.end();
    }
  cr--;
  play_current_song(*cr);
  }
  else if(s=='A')
  {
    string name,artist;
    int rating;
    cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout<<"Adding and playing new song"<<endl;
    cout<<"Enter song name"<<endl;
  getline(cin,name);
    cout<<"enter song artist"<<endl;
    getline(cin,artist);
    cout<<"enter song rating"<<endl;
    cin>>rating;
    playlist.insert(cr,song{name,artist,rating});
cr--;
play_current_song(*cr);
  }
  else if(s=='L')
  {
    cout<<endl;
    display_playlist(playlist,*cr);
  }
  else if(s=='Q')
  cout<<"quitting"<<endl;
  else
  cout<<"illegal choice"<<endl;
}while(s!='Q');
cout<<"thank u"<<endl;
return 0;
}
