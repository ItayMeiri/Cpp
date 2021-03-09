#include "snowman.hpp"
#include <iostream>



namespace ariel
{

std::array<std::string, 4> hats = {
    " _===_",
    "  ___\n .....",
    "   _\n  /_\\",
    "  ___ \n (_*_)"
};
std::array<std::string, 4> noses = {",", ".", "_", " "};
std::array<std::string, 4> eyes = {".", "o", "O", "-"};
std::array<std::string, 4> base = {" : ", "\" \"", "___", "   "};
std::array<std::string, 4> torso = {" : ", "] [", "> <", "   "};
std::array<std::string, 4> leftHand = {" <", "\\ ", " /", "  "};
std::array<std::string, 4> rightHand = {" >", "/ ", " \\", "  "};


std::string snowman(int seed)
{

    // validate snowman seed, throws exception when invalid
    std::array<std::string, 8> strSeed = seedValidator(seed); // stored as the seed HNLRXYTB 

    std::string sman = 
    strSeed.at(0) + "\n" // hat
    +strSeed.at(4).at(0) + "(" // right arm, char 0
    +strSeed.at(2) + strSeed.at(1) + strSeed.at(3) + ")" // face and eyes
    +strSeed.at(5).at(0) + "\n" // left arm, char 0
    +strSeed.at(4).at(1) + "(" // right arm, char 1
    +strSeed.at(6) + ")" // torso
    +strSeed.at(5).at(1) + "\n (" // left arm, char 1
    +strSeed.at(7) + ")";


    return sman;
}

std::array<std::string, 8> seedValidator(int seed)
{
    if(seed < 0) { throw std::invalid_argument("Invalid code '5'");}
    int count = 0;
    std::array<std::string, 8> str; 
    while(seed > 0)
    {
        if (seed % 10 > 4){ // get last digit
            throw std::invalid_argument("Invalid code '5'");
        }
        int index = seed % 10;
        index--;
         if(count == 7){str.at(0) = hats.at(index);}
         else if(count == 6){str.at(1) = noses.at(index);}
         else if(count == 5){str.at(2) = eyes.at(index);} // left
         else if(count == 4){str.at(3) = eyes.at(index);} // right
         else if(count == 3){str.at(4) = leftHand.at(index);}
         else if(count == 2){str.at(5) = rightHand.at(index);}
         else if(count == 1){str.at(6) = torso.at(index);}
         else if(count == 0){str.at(7) = base.at(index);}

        seed = seed/10; // removes digit
        count++; // counts the digits
    }
    if(count != 8)
    {
        throw std::invalid_argument("Invalid code '5'");
    }
    return str;
}
}


