#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
struct cmd{
    int   type;
    const std::string description;


    cmd(int type, std::string desc):type{type},description{desc} {

    }
};

struct studentInfo{
    float grade;
    int position;
    std::string name;

};
bool sortinfo(studentInfo info1 , studentInfo info2){
    return (info1.grade <info2.grade); 
}

int main(int argc, char* argv)
{

    const auto numCmd = 5;
    cmd cmdArr[numCmd] {{1, "Display All Grades" }, {2, "Show The Best Grade" },
                        {3,"Calculate Class Average Grade "} , {4,"Get List of Failed Students "}, {0,"Exit "} };





    std::string lineSpacer( "---------------------------------\n");
    std::cout <<lineSpacer;
    std::cout << " Class Grades Management \n"   ;
    std::cout <<lineSpacer;
    for(auto ii = 0; ii < numCmd ; ii++){
        std::cout << cmdArr[ii].type << "." << cmdArr[ii].description << "\n";
    }
    std::cout <<lineSpacer <<"\n\n";


    float grade;
    std::string name;
    std::ifstream gradeFile("grades.txt");
    auto linenum = 0;
    while(gradeFile >> grade>> name){
        linenum++;
    // std::cout <<grade << name <<"\n\n";
    }
    gradeFile.close();
    gradeFile.open("grades.txt");
    studentInfo * stList = new studentInfo[linenum];


    for(auto ii = 0; ii < linenum ; ii++){
        gradeFile >> stList[ii].grade>> stList[ii].name;
    }

    int selCmd;
    while(1){
        std::cout <<"Select Command>";
        std::cin >> selCmd;


        if(selCmd  == 1){
            for(auto ii = 0; ii < linenum ; ii++){
            std::cout << stList[ii].grade << "\t" << stList[ii].name << std::endl;

            }
        }
        else if(selCmd  == 2){
            std::sort(stList, stList+linenum, sortinfo);
            std::cout <<   "The Best Grade is " << stList[linenum-1].grade << " from " << stList[linenum-1].name << std::endl;
        }
        else if(selCmd  == 3){
            float sum {0.0};
            for(auto ii = 0; ii < linenum ; ii++){
            sum += stList[ii].grade ;

            }
            std::cout <<   "Class average grade is  " << sum/linenum << std::endl;
        }

        else if(selCmd  == 4){

            std::cout <<   "Failed Students: " << std::endl;
            for(auto ii = 0; ii < linenum ; ii++){
                if(stList[ii].grade < 10){
                        std::cout << stList[ii].grade << "\t" << stList[ii].name << std::endl;
                }

            }
            
        }
        else if(selCmd  == 0){
            break;
        }
        else{
            std::cout <<   "Invalid command " << std::endl;
        }
    }

    return 0;
}

