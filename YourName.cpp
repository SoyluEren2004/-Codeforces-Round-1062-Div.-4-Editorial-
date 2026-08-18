#include<iostream>

void mySwap(char &a, char &b) {
    char temp = a;
    a = b;         
    b = temp;      
}

// use bubble sort
bool controlAndSort(std::string text1, std::string text2){
    int size = text1.length();
    if(text1.length()==text2.length()){
        for (int i = 0; i < size - 1; i++) {

            for (int j = 0; j < size - i - 1; j++) {
          
                if (text1[j] > text1[j + 1]){
                    mySwap(text1[j], text1[j+1]);
                } 
                if(text2[j]> text2[j+1]){
                    mySwap(text2[j],text2[j+1]);
                }   
            }
        }
        if(text1==text2){
            return true;
        }
        else{
            return false;
        }
        
    }
    else{
        return false;
    }
}
void sortStrings(){
    int nTimes;
    std::cout<<"how many times do you want the try: ";
    std::cin>>nTimes;
    std::cin.ignore();
    std::cout<<""<<std::endl;
    std::string sarray[nTimes]={};
    std::string sarray2[nTimes]={};
    for(int i=0;i<nTimes;i++){
        std::string name1;
        std::string name2;
        std::cout<<"first name: ";
        std::getline(std::cin,name1);
        sarray[i].append(name1);
        std::cout<<"second name: ";
        std::getline(std::cin,name2); 
        sarray2[i].append(name2);
    }
    for(int i =0; i<nTimes;i++){
        if(controlAndSort(sarray[i],sarray2[i])){
            std::cout<<"YES"<<std::endl;
        }
        else{
            std::cout<<"NO"<<std::endl;
        }
    }
    
    
}


int main(){
    sortStrings();
    
    return 0;
}