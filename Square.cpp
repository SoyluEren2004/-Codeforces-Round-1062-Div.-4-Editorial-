#include<iostream>

std::string clearWhiteSpace(std::string text=""){
    std::string new_text="";
    for(int i=0;i<text.length();i++){
        if(text[i]!=' '){
            new_text+=text[i];
        }
    }
    return new_text;
}

int square(){
    int x;
    std::string ınput;
    std::string clean_text="";
    std::cout<<"How many times do you want the try: ";
    std::cin>>x;
    std::cin.ignore();
    std::cout<<""<<std::endl;
    std::string deneme[x]={};
    for(int i =0;i<x;i++){
        std::getline(std::cin, ınput);
        deneme[i].append(ınput);
    }
    for(int j=0;j<x;j++){
        clean_text=clearWhiteSpace(deneme[j]);
        if(clean_text.length()==4){
            if(clean_text[0]==clean_text[1] && clean_text[0] == clean_text[2] && clean_text[0]==clean_text[3]){
                std::cout<<"yes"<<std::endl;
            }
            else{
                std::cout<<"no"<<std::endl;
            }
        }
        else{
            std::cout<<"no"<<std::endl;
        } 
    }
    
    return 0;
}


int main(){
    square();


    return 0;
}