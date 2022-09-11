#include <iostream>
#include <string>
#include <fstream>

struct base64t{
    char str[3];
    int padding;
    base64t(char s[3], int pad):padding(pad){
        for (size_t i = 0; i < 3; i++)
        {
            str[i] = s[i];
        }
        
    }
    std::string getString(){
    
        std::string sb64("");
        for (size_t i = 0; i < 4; i++)
        {
            
        uint8_t b64;
        if( i == 0){
            b64  = (str[0] &0xFC) >> 2;
        }
        else if( i== 1){
             b64  = ((str[0] &0x03) << 4 ) |   (( str[1] & 0xFF) >>  4 ) ;
        }
         else if( i== 2){
            if(padding == 2){
                sb64+="==";
                break; 
            }
            b64  = ((str[1] &0x0F) << 2 ) |   ( (str[2] &0xFF) >>  6 ) ;
        }
        else if( i== 3){
            if(padding == 1){
                sb64+="=";
                break; 
            }
             b64  = (str[2] &0x3F)  ;
        }
    
      
        
        if(b64 < 26){
            sb64 += 'A' + b64;
        }
        else if( b64 <52){
            sb64 += 'a' + (b64-26) ;
        }
        else if(b64 < 62){
            sb64 += '0' + (b64-52);
        }
        else if(b64 == 62){
            sb64 += '+';
        } else if(b64 == 63){
            sb64 += '-';
        }
    }
    
    
    

    return sb64;

    }
};


std::string convertBase64(std::string data){
    std::string strbase64("");
    for (size_t i = 0; i < data.length(); i= i +3)
    {
        auto pad{0};
        if(i+3 >  data.length()){
            pad = 3 - data.length()%3;
        }
        char s[]{data[i], (pad==2)?'\0':data[i+1], (pad == 1)?'\0':data[i+2]};
        base64t b64(s, pad);
        strbase64 +=b64.getString();
    }
    
    
    return strbase64;
}




int main(int argc, char* argv[])
{
    //toDo check arguments
    const auto srcFileName{argv[2]};
    const auto dstFileName{argv[3]};

    std::string cmd(argv[1]);

    if(cmd == "enc"){
        std::ifstream srcFile{srcFileName};
        std::ofstream dstFile{dstFileName};
        std::string lineData;
        while(std::getline(srcFile,lineData)){
            dstFile << convertBase64(lineData) << std::endl;
        }


    } 
    else if(cmd == "dec"){
        std::cout << "There is no decoder!" << std::endl;
    }
     else{
        std::cout << "no valid argument" << std::endl;
    }
    
    return 0;
}