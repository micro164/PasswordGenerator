#include<iostream>
#include<random>
#include<map>
#include<string>
#include<ctime>
#include<fstream>


int main(int argc, char** argv){
	
std::cout<<"Written by Jonathon Bryant "
	     <<"compiled on "<<__DATE__
		 <<" at "<<__TIME__<<'\n';

//Getting file name and contents of file
std::ifstream ifstr;
std::cout << "Enter file name to be opened: ";
std::string file;
std::cin >> file;
ifstr.open(file);
ifstr.good();
         

//variable initialization 
std::map<std::string, std::string> m;
std::string s;
std::default_random_engine dre;
std::uniform_int_distribution<> d(1,6);

int loops = 0;
std::cout << "Enter how many Passwords need to be generated: ";
std::cin >> loops;

//Stores contents of file for use in program
while(getline(ifstr, s)){
    
    std::string v;
    std::string v2;
    
    for(int i = 0; i < 5; i++){
        v = v + s[i];
    }
    
    
    int ints = 6;
    while(ints < s.size()){
        v2 = v2 + s[ints];
        ints++;
    }
    
    m[v] = v2;
}

std::string phrase = "";
std::string number = "";

if(loops == 0){
    loops = 10;
}

//Loops through to create password
while(loops != 0){
for(int i = 0; i < 6; i++){
    for(int j = 0; j < 5; j++){
        switch(d(dre)){
            case 1:
                number = number + '1';
                break;
            case 2:
                number = number + '2';
                break;
            case 3:
                number = number + '3';
                break;
            case 4:
                number = number + '4';
                break;
            case 5:
                number = number + '5';
                break;
            case 6:
                number = number + '6';
                break;
        }
    }
    
    std::map<std::string,std::string>::const_iterator got = m.find(number);
    phrase = phrase + (*got).second;
    number = "";
}

std::cout << phrase << '\n';
phrase = "";
loops--;
}
  
return 0;
}
