/*
================================================================================
    PROJECT: Dice Rolling Game with Scoring System
    AUTHOR: [Your Name]
    DATE: [Current Date]
================================================================================

CONCEPTS USED:
    - C++ Basics: Variables, Data Types, Operators, Control Structures
    - Functions: Modular programming with parameter passing and return values
    - Arrays: 2D string arrays for storing dice patterns
    - Loops: do-while loop for game continuation, for loops for iterations
    - Conditional Statements: if-else for game logic and special combinations
    - Random Number Generation: srand() and rand() for dice simulation
    - String Manipulation: String comparison and operations

LIBRARIES USED:
    <iostream>   - For input/output operations (cin, cout)
    <cstdlib>    - For random number generation (rand, srand)
    <ctime>      - For seeding random generator with current time
    <iomanip>    - For formatted output (setprecision, fixed)
    <string>     - For string data type and operations
    <limits>     - For clearing input buffer (numeric_limits)

PROGRAM STRUCTURE:
    1. displayDice()         - Displays visual representation of dice
    2. checkSpecialRoll()    - Identifies special dice combinations
    3. calculateScore()      - Computes points based on game rules
    4. displayAchievements() - Shows unlocked achievements
    5. displayStatistics()   - Displays current game statistics
    6. main()                - Main game loop and flow control

================================================================================
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// ==================== DICE DISPLAY FUNCTION ====================
void displayDice(int die1, int die2) {
    string dice[6][5] = {
        {" ------- ", "|       |", "|   O   |", "|       |", " ------- "},
        {" ------- ", "| O     |", "|       |", "|     O |", " ------- "},
        {" ------- ", "| O     |", "|   O   |", "|     O |", " ------- "},
        {" ------- ", "| O   O |", "|       |", "| O   O |", " ------- "},
        {" ------- ", "| O   O |", "|   O   |", "| O   O |", " ------- "},
        {" ------- ", "| O   O |", "| O   O |", "| O   O |", " ------- "}
    };
    
    cout << "\n    DIE 1           DIE 2\n";
    for (int i = 0; i < 5; i++) {
        cout << "  " << dice[die1 - 1][i] << "  " << dice[die2 - 1][i] << endl;
    }
}

// ==================== SPECIAL ROLL CHECKER ====================
string checkSpecialRoll(int die1, int die2, int sum) {
    if (die1 == die2) {
        if (die1 == 1) return "SNAKE EYES!";
        else if (die1 == 6) return "BOXCARS!";
        else return "DOUBLES!";
    }
    if (sum == 7) return "LUCKY SEVEN!";
    if (sum == 11) return "YO-LEVEN!";
    if (sum == 2) return "CRAPS!";
    if (sum == 3) return "ACE DEUCE!";
    if (sum == 12) return "MIDNIGHT!";
    return "";
}

// ==================== SCORE CALCULATOR ====================
int calculateScore(int die1, int die2, int sum) {
    int score = sum;
    
    if (die1 == die2) {
        score *= 2;
        if (die1 == 6) score += 10;
        if (die1 == 1) score = 5;
    }
    if (sum == 7) score += 7;
    if (sum == 11) score += 11;
    
    return score;
}

// ==================== ACHIEVEMENT DISPLAY ====================
void displayAchievements(int totalRolls, int doublesCount, int luckySevenCount, int totalScore) {
    bool hasAchievement = false;
    
    if (totalRolls >= 10) {
        cout << "  [ACHIEVEMENT] Veteran Roller!\n";
        hasAchievement = true;
    }
    if (doublesCount >= 3) {
        cout << "  [ACHIEVEMENT] Doubles Master!\n";
        hasAchievement = true;
    }
    if (luckySevenCount >= 2) {
        cout << "  [ACHIEVEMENT] Lucky Charm!\n";
        hasAchievement = true;
    }
    if (totalScore >= 100) {
        cout << "  [ACHIEVEMENT] High Scorer!\n";
        hasAchievement = true;
    }
    
    if (hasAchievement) {
        cout << endl;
    }
}

// ==================== STATISTICS DISPLAY ====================
void displayStatistics(int totalRolls, int totalScore, int highestRoll, 
                       int doublesCount, int luckySevenCount) {
    cout << "\n--------------------------------------------";
    cout << "\n[GAME STATISTICS]\n";
    cout << "  Total Rolls: " << totalRolls << endl;
    cout << "  Total Score: " << totalScore << endl;
    cout << "  Average: " << fixed << setprecision(1) 
         << (double)totalScore / totalRolls << " pts/roll" << endl;
    cout << "  Highest Roll: " << highestRoll << endl;
    cout << "  Doubles: " << doublesCount << " | Lucky Sevens: " << luckySevenCount << endl;
}

// ==================== MAIN PROGRAM ====================
int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    char choice;
    int totalRolls = 0;
    int totalScore = 0;
    int highestRoll = 0;
    int doublesCount = 0;
    int luckySevenCount = 0;
    
    // SECTION 1: WELCOME SCREEN
    cout << "\n";
    cout << "============================================\n";
    cout << "       WELCOME TO DICE MASTER 3000!        \n";
    cout << "============================================\n";
    cout << "\nROLL THE DICE AND EARN POINTS!\n";
    cout << "\n[RULES]\n";
    cout << "  - Doubles = 2x points\n";
    cout << "  - Lucky 7 = +7 bonus\n";
    cout << "  - Special rolls = Extra points!\n";
    cout << "\n============================================\n";
    
    // SECTION 2: MAIN GAME LOOP
    do {
        cout << "\nPress ENTER to roll the dice...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Generate random dice values (1-6)
        int die1 = (rand() % 6) + 1;
        int die2 = (rand() % 6) + 1;
        int sum = die1 + die2;
        
        // Display the dice
        cout << "\n--------------------------------------------\n";
        displayDice(die1, die2);
        
        // Show result
        cout << "\n  RESULT: " << die1 << " + " << die2 << " = " << sum << "\n";
        
        // Check for special combinations
        string special = checkSpecialRoll(die1, die2, sum);
        if (!special.empty()) {
            cout << "\n  *** " << special << " ***\n";
        }
        
        // Calculate and display points earned
        int rollScore = calculateScore(die1, die2, sum);
        cout << "\n  Points Earned: " << rollScore << "\n";
        
        // Update game statistics
        totalRolls++;
        totalScore += rollScore;
        if (sum > highestRoll) highestRoll = sum;
        if (die1 == die2) doublesCount++;
        if (sum == 7) luckySevenCount++;
        
        // Display current statistics
        displayStatistics(totalRolls, totalScore, highestRoll, doublesCount, luckySevenCount);
        
        // Check and display achievements
        displayAchievements(totalRolls, doublesCount, luckySevenCount, totalScore);
        
        cout << "--------------------------------------------\n";
        
        // Ask user if they want to continue
        cout << "\nRoll again? (y/n): ";
        cin >> choice;
        choice = tolower(choice);
        
    } while (choice == 'y');
    
    // SECTION 3: GAME OVER SCREEN
    cout << "\n============================================\n";
    cout << "          GAME OVER - FINAL RESULTS         \n";
    cout << "============================================\n";
    cout << "  Total Rolls: " << totalRolls << endl;
    cout << "  Final Score: " << totalScore << endl;
    cout << "  Average Score: " << fixed << setprecision(2) 
         << (double)totalScore / totalRolls << " pts/roll" << endl;
    cout << "============================================\n";
    cout << "\nThanks for playing Dice Master 3000!\n\n";
    
    return 0;
}