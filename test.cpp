#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, vector<string>> letterMap;

void initFont() {
    letterMap['C'] = {
        " #### ",
        "#    #",
        "#     ",
        "#     ",
        "#     ",
        "#    #",
        " #### "
    };
    letterMap['H'] = {
        "#    #",
        "#    #",
        "#    #",
        "######",
        "#    #",
        "#    #",
        "#    #",
    };
    letterMap['1'] = { 
        "     #",
        "#    #",
        "#    #",
        "#    #",
        "#    #",
        "#    #",
        " #### "
    };
    letterMap['M'] = {
        "#     #",
        "##   ##",
        "# # # #",
        "#  #  #",
        "#     #",
        "#     #",
        "#     #"
    };
    letterMap['2'] = {
        "   #   ",
        "#    ##",
        "#    # ",
        "#    # ",
        "#    # ",
        "#    # ",
        " ####  "
    };
    letterMap['N'] = {
        "#    #",
        "##   #",
        "# #  #",
        "#  # #",
        "#   ##",
        "#    #",
        "#    #"
    };
    letterMap['G'] = {
        " #### ",
        "#    #",
        "#     ",
        "#  ###",
        "#    #",
        "#    #",
        " #### "
    };
    letterMap['3'] = {
        " #  # ",
        "  ##  ",
        " #  # ",
        "#    #",
        "######",
        "#    #",
        "#    #"
    };
    letterMap['4'] = {
        "     #",
        " #### #",
        "#    # ",
        "#    # ",
        "#    # ",
        "#    # ",
        " ####  "
    };
    letterMap['I'] = {
        "######",
        "  ##  ",
        "  ##  ",
        "  ##  ",
        "  ##  ",
        "  ##  ",
        "######"
    };
    letterMap[' '] = {
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  ",
        "  "
    };
}

void printLineOfText(string content, string pattern, int &patternIndex) {
    int height = 7; 
    for (int row = 0; row < height; row++) {
        for (char c : content) {
            if (letterMap.find(c) != letterMap.end()) {
                string lineTemplate = letterMap[c][row];
                for (char pixel : lineTemplate) {
                    if (pixel == '#') {
                        cout << pattern[patternIndex % pattern.length()];
                        patternIndex++; 
                    } else {
                        cout << " ";
                    }
                }
                cout << "  "; 
            }
        }
        cout << endl; 
    }
}

int main() {
    initFont(); 

    string fullText = "CH1C M2NG N3M M4I"; 
    string pattern = "2026";
    int patternIndex = 0;

    cout << "\n\n";
    printLineOfText(fullText, pattern, patternIndex);
    cout << "\n\n";

    return 0;
}