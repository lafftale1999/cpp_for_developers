#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>
#include <functional>

enum OperationsResult {
    SUCCESS,
    FAILED,
    EMPTY
};

/* 
WRITE TO A FILE
By standard this will overwrite everything in the file.
*/
OperationsResult writeToFile(std::string path, const std::string &stringToWrite) {
    std::ofstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    };

    file << stringToWrite << std::endl;

    file.close();

    return SUCCESS;
}

/* 
APPEND TO FILE
By adding the std::ios::app mode to the file, we choose 
to append instead of overwrite.
*/
OperationsResult appendToFile(std::string path, const std::string &stringToAppend) {
    std::ofstream file(path, std::ios::app);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    file << stringToAppend << std::endl;

    file.close();

    return SUCCESS;
}

/* 
READ FROM FILE
While our file has a next line it will read from the file
*/
OperationsResult readFromFile(std::string path, std::string& outString) {
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    };

    std::string temp;
    outString.clear();

    while (std::getline(file, temp)) {
        outString += temp + '\n';
    }

    file.close();

    if (outString.length() == 0) {
        return EMPTY;
    }

    return SUCCESS;
}

/* 
CLEAR FILE
This will make the file blank again.
*/
OperationsResult clearFile(std::string path) {
    std::ofstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    file.clear();

    file.close();

    return SUCCESS;
}

/*
PASSING BY REFERENCE AND USING A FUNCTION POINTER
By using a function pointer, we push the responsibility
of the function used withing to the caller. 
*/
OperationsResult writeSeveralStringsToFile(
    std::string filePath,
    std::vector<std::string> stringsToWrite,
    std::function<OperationsResult(std::string, std::string)> writeFunction) {
    
    OperationsResult writeStatus = FAILED;

    for (auto string : stringsToWrite) {
        try {
            writeStatus = writeFunction(filePath, string);
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }

        switch(writeStatus) {
            case SUCCESS:
                std::cout << "Successfully written to file: " << filePath << std::endl;
                break;

            case FAILED:
                std::cout << "Failed to write to file: " << filePath << std::endl;
                break;

            case EMPTY:
                std::cout << "String is empty" << std::endl;
                break;
        }
    }

    return writeStatus;
}

void checkOperationResult(OperationsResult status) {
    if (status != SUCCESS) {
        exit(1);
    }
}

int main(void) {
    // R"(string)" means raw string literal - it lets ut format a string easier without
    // the need for escaping things with '\"'.
    std::string filePath = "star_wars.txt";
    std::string dialogue1 = R"(Anakin: YOU TURNED HER AGAINST ME! 
    Obi Wan: You have done that yourself. 
    Anakin: YOU WILL NOT TAKE HER FROM ME! 
    Obi Wan: Your anger and your lust for power have already done that. You have allowed this dark lord to twist your mind until now.. until now you have become the very thing you've sworn to destroy. 
    Anakin: Don't lecture me Obi Wan. I see through the lies of the Jedi. I do not fear the dark side as you do. I have brought Peace Freedom Justice and Security to my new empire.

    Obi Wan: Your new empire? 
    Anakin: Don't make me kill you. 
    Obi Wan: Anakin, my allegiance is to the republic-to democracy!

    Anakin: If you're not with me, than you're my enemy. 
    Obi Wan: Only a Sith deals in absolutes. I will do what I must. 
    Anakin: You will try. *flips and does lightsaber thingy epic music 5 minutes later*
    )";
    
    std::string dialogue2 = R"(
    Obi Wan: I have failed you, Anakin. I have failed you. 
    Anakin: I should've known the jedi were planning to take over! 
    Obi Wan: Anakin, Chancellor Palpatine is evil! 
    Anakin: From my point of view the jedi are evil! 
    Obi Wan: Then you are lost! 
    Anakin: This is the end for you, my master. *more fighting* 
    Obi Wan: It's over, Anakin, I have the high ground! 
    Anakin: You underestimate my power... 
    Obi Wan: Don't try it. 
    Anakin: AAAAAHH *gets legs cut off* 
    Anakin: AAAAAAAHHH 
    Obi Wan: YOU WERE THE CHOSEN ONE! IT WAS SAID THAT YOU WOULD DESTROY THE SITH, NOT JOIN THEM! YOU WERE TO BRING BALANCE TO THE FORCE NOT LEAVE IT IN DARKNESS! 
    Anakin: AAAAH I HATE YOU!!! 
    Obi Wan: You were my brother, Anakin. I loved you! 
    *Anakin spontaneously combusts into flames* 
    Anakin: AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH 
    *Obi Wan looks away because he doesn't want to see his "brother" being brutally burned to death, picks up Anakin's lightsaber and leaves*
    )";

    std::string dialogue3 = R"(
    *10 minutes later* 
    Palpatine: There he is! Get him! 
    *They pick up Anakin and take him*
    )";

    std::string readFromFileString;
    std::vector<std::string> dialogues = {dialogue1, dialogue2, dialogue3};

    // WRITING TO FILE
    OperationsResult writeStatus = writeSeveralStringsToFile(filePath, dialogues, writeToFile);
    checkOperationResult(writeStatus);
    OperationsResult readStatus = readFromFile(filePath, readFromFileString);
    checkOperationResult(readStatus);

    std::cout << readFromFileString << std::endl;

    // CLEARING FILE
    try { clearFile(filePath);} 
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // APPENDING TO FILE
    writeStatus = writeSeveralStringsToFile(filePath, dialogues, appendToFile);
    checkOperationResult(writeStatus);
    OperationsResult readStatus = readFromFile(filePath, readFromFileString);
    checkOperationResult(readStatus);

    std::cout << readFromFileString << std::endl;

    return 0;
}