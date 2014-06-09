#include "config.h"

Config::Config(std::string fileName){
    std::ifstream File(fileName);
    if (File){
        std::string tmp;
        while(!File.eof()){
            std::getline(File, tmp);
            Buffer+= tmp;
        }
        File.close();
    }
}

void Config::parse(){
    int start = 0;
    if (!Buffer.empty()){
        std::string bufferkey;
        for (unsigned i=0; i<Buffer.length(); i++) {
            if (start == 0 && isalnum(Buffer[i])){
                bufferkey+= Buffer[i];
                start = 1;
            }
            else
                if (start == 1 && (isalnum(Buffer[i]) or Buffer.substr(i,1) == "_") )
                    bufferkey += Buffer[i];
                else
                    if (start == 1 && (!isalnum(Buffer[i]) or !(Buffer.substr(i,1) == "_")) ){
                        start = 0;
                        int pos = (int) Buffer.find("'", i);
                        if (pos > -1){
                            int pos2 = (int) Buffer.find("'", pos+1);
                            if (pos2>-1)
                                values[bufferkey] = Buffer.substr(pos+1, (pos2 - pos)-1   );
                            i = pos2;
                        }
                        bufferkey.clear();
                    }
         }
    }
}

int Config::getIntValue(std::string key,
                        int defaultValue){
    if (values.find(key) != values.end())
        return std::stoi(values[key]);
    else
        return defaultValue;

}
std::string Config::getStringValue(std::string key,
                                   std::string defaultValue){
    if (values.find(key) != values.end())
        return values[key];
    else
        return defaultValue;
}
